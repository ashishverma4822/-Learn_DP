#include<bits/stdc++.h>
using namespace std;
int n,x,k;
vector<int>t;
vector<int>m;
int dp[101][101][101];
int hiAyu(int level, int time_taken, int item_taken){
    if(level==n) return 0;
    if(dp[level][time_taken][item_taken]!=-1) return dp[level][time_taken][item_taken];
    int ans = hiAyu(level+1, time_taken, item_taken);
    if(time_taken+t[level]<=x and item_taken+m[level]<=k){
        ans = min(ans,hiAyu(level+1,time_taken+t[level], item_taken+m[level])+1);
    }
    return dp[level][time_taken][item_taken] = ans;
}
int main(){
    cin>>n;
    t.resize(n);
    m.resize(n);
    cin>>x;
    cin>>k;
    for(int i=0;i<n;i++) cin>>t[i];
    for(int i=0;i<n;i++) cin>>m[i];
    memset(dp,-1,sizeof(dp));
    cout<<hiAyu(0,0,0)<<endl;
    return 0;
}