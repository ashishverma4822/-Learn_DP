#include<bits/stdc++.h>

using namespace std;
int dp[1001][1001];
int hiAyu(int&n ,vector<int>& w, vector<int>& v,int i, int x){
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans = hiAyu(n,w,v,i+1,x);
    if(w[i]<=x){
        ans = max(ans,v[i]+hiAyu(n,w,v,i+1,x-w[i]));
    }
    return dp[i][x] = ans;
}

int main(){
    memset(dp, -1, sizeof(int) * 1001 * 1001);
    int n;
    cin>>n;
    vector<int> w(n);
    vector<int> v(n);
    int x;
    cin>>x;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<hiAyu(n,w,v,0,x);
    return 0;
}