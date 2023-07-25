#include<bits/stdc++.h>
using namespace std;

// Update function in Fenwick Tree
void Update(vector<int>&BIT,int index,int diff,int n){
    while(index<=n){
        BIT[index]+=diff;
        index+=(index&(-index));
    }
}

// Query function in Fenwick Tree
int query(vector<int>&BIT,int i){
    int sum=0;

    while(i>0){
        sum+=BIT[i];
        //remove the first set bit or right most set bit of i
        i-=(i&(-i));
    }
    return sum;
}

int main(){

    // 0-based indexing
    int arr[] = {0,2, 4, 1, 6, 5, 8, 10, 30,32,7,9,45,67,23,12};
    int n = 16;

    // In Fenwick tree we use the 1 based indexing 
    vector<int>BIT(n,0);

    // gernerate the fenwick tree array
    for(int i=1;i<n;i++){
        Update(BIT,i,arr[i],n);
    }

    /*---------------Query in Fenwick Tree-------------*/
    int q;
    cin >> q;

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int rs, re;
            cin >> rs >> re;

            int ans = query(BIT,re)-query(BIT,rs-1);
            cout << "sum in the range " << rs << " to " << re << " is : " << ans << endl;
        }
        else
        {
            int i,val;
            cin >> i >> val;

            /*------------Update in Fenwick Tree --------*/
            Update(BIT,i,val-arr[i],n);
            arr[i]=val;
        }
    }
    return 0;
}


