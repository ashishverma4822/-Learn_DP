#include<bits/stdc++.h>

using namespace std;
int dp[1001][1001];
vector<int> w;
vector<int> v;
int n;
int hiAyu(int i, int x){
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans = 0;
    for(int num_of_times = 0;num_of_times<=x/w[i];num_of_times++){
        ans = max(ans,hiAyu(i+1,x-num_of_times*w[i])+v[i]*num_of_times);
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
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<hiAyu(0,x)<<endl;
    return 0;
}