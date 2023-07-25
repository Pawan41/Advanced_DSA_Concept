#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[][5] = {
        {0,2,4,1,6},
        {5,8,1,3,2},
        {7,9,4,6,2},
        {1,2,4,6,7}};

    int n = 4,m=5;

    // 2D BIT 
    vector<vector<int>>pref(n,vector<int>(m,0));
    
    pref[0][0]=arr[0][0];

    //fill the row
    for(int i=0;i<n;i++){
        pref[0][i]=pref[0][i-1]+arr[0][i];
    }

    //fill the col
    for(int j=0;j<m;j++){
        pref[j][0]=pref[j-1][0]+arr[j][0];
    }

    //fill the complete
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+arr[i][j];
        }
    }
     
    /*---------------Query 2D BIT-------------*/
    int q;
    cin >> q;

    while (q--){
        int x1,y1,x2,y2;
        cin >>x1>>y1>>x2>>y2;
        int ans = pref[x2][y2]-(y1-1>=0?pref[x2][y1-1]:0)-(x1-1>=0?pref[x1-1][y2]:0)+(x1-1>=0 && y1-1>=0?pref[x1-1][y1-1]:0);
        cout << "sum of the ractangle  is : " << ans << endl;
    }
    
    return 0;
}


