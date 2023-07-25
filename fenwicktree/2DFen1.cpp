#include<bits/stdc++.h>
using namespace std;

// Update function in 2D BIT Tree
void Update(vector<vector<int>>&BIT,int i,int j,int diff,int n,int m){
    while(i<=n){
        int t=j;
        while(t<=m){
            BIT[i][t]+=diff;
            t+=(t&(-t));
        }
        i+=(i&(-i));
    }
}

// Query function in Fenwick Tree
int query(vector<vector<int>>&BIT,int i,int j){
    int sum=0;

    while(i>0){
        int t=j;
        while(t>0){
            sum+=BIT[i][t];
            //remove the first set bit or right most set bit of i
            t-=(t&(-t));
        }
        i-=(i&(-i));
    }
    return sum;
}

int main(){

    int arr[][6] = {{0,0,0,0,0,0},
                    {0,0,2,4,1,6},
                    {0,5,8,1,3,2},
                    {0,7,9,4,6,2},
                    {0,1,2,4,6,7}};

    int n = 5,m=6;

    // 2D BIT 
    vector<vector<int>>BIT(n+5,vector<int>(m+5,0));

    //Build a tree
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            Update(BIT,i,j,arr[i][j],n,m);
        }
    }

     
    /*---------------Query 2D BIT-------------*/
    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1){
            int x1,y1,x2,y2;
            cin >>x1>>y1>>x2>>y2;
            int ans = query(BIT,x2,y2)-query(BIT,x2,y1-1)-query(BIT,x1-1,y2)+query(BIT,x1-1,y1-1);
            cout << "sum of the ractangle  is : " << ans << endl;
        }
        else{
            int i,j,val;
            cin >> i >>j>> val;

            /*------------Update in 2D BIT --------*/
            Update(BIT,i,j,val-arr[i][j],n,m);
            arr[i][j]=val;
        }
    }
    return 0;
}