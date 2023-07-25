#include<bits/stdc++.h>
using namespace std;

void buildSQRT(vector<int>&box,int arr[] ,int n,int b){
    for(int i=0;i<n;i++){
        box[i/b]+=arr[i];
    }
}

void Update(vector<int>&box,int arr[],int n,int b,int index,int x){
    box[index/b]=box[index/b]-arr[index]+x;
    arr[index]=x;
}

int query(vector<int>&box,int arr[],int rs,int re,int n,int b){
    int sum=0;

    //  1 [rs,rs+b-rs%b)
    for(int i=rs;i<=min(re,rs+b-rs%b-1);i++){
        sum+=arr[i];
    }

    if(rs/b==re/b){
        return sum;
    }

    // 2. [rs+b-rs%b re-re%b)
    for(int i=(rs+b-rs%b)/b;i<(re-re%b)/b;i++){
        sum+=box[i];
    }

    // 3 [re-re%b,r]
    for(int i=max(rs,re-re%b);i<=re;i++){
       sum+=arr[i];
    }
    return sum;

}

int main(){

    int arr[] = {2, 4, 1, 6, 5, 8, 10, 30};
    int n = 8;

    int b=sqrt(n);
    vector<int> box(ceil(n/b),0);

    buildSQRT(box,arr,n,b);

    /*---------------Query in SQRT-------------*/
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

            int ans = query(box,arr,rs,re,n,b);
            cout << "sum in the range " << rs << " to " << re << " is : " << ans << endl;
        }
        else
        {
            int i,val;
            cin >> i >> val;

            /*------------Update in SQRT Decomposition --------*/
            Update(box,arr,n,b,i, val);
        }
    }

    return 0;
}