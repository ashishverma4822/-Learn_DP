#include<bits/stdc++.h>

using namespace std;
int dp[1001][1001];
vector<int> w;
vector<int> v;
int n,m;
int hiAyu(int i, int x, int item_left){
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans = hiAyu(i+1, x,item_left);
    if(w[i]<=x and item_left>0){
        ans = max(ans,hiAyu(i+2, x-w[i],item_left-1)+v[i]);
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