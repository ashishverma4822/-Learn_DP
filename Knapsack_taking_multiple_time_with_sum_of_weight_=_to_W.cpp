#include<bits/stdc++.h>

using namespace std;
int dp[1001][1001]  ;
vector<int> w;
vector<int> v;
int n,m;
int hiAyu(int i, int x, int W){
    if(i==n){
        int sum_of_take = (W-x);
        if(sum_of_take%m==0) return 0;
        else return INT_MAX;
    }
    if(dp[i][x]!=-1) return dp[i][x];
    int ans = hiAyu(i+1, x,W);
    if(w[i]<=x){
        ans = max(ans,hiAyu(i, x-w[i],W)+v[i]);
    }
    return dp[i][x] = ans;
}

int main(){
    memset(dp, -1, sizeof(int) * 1001 * 1001);
    cin>>n;
    w.resize(n);
    v.resize(n);
    int x;
    cin>>x;
    cin>>m;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<hiAyu(0,x,x)<<endl;
    return 0;
}