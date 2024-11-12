#include<bits/stdc++.h>

using namespace std;
int dp[1001][1001];
vector<int> w;
vector<int> v;
int n;
int hiAyu(int i, int x){
    if(i==n) return 0;
    if(dp[i][x]!=-1) return dp[i][x];
    int ans = hiAyu(i+1,x);
    if(w[i]<=x){
        ans = max(ans,v[i]+hiAyu(i+1,x-w[i]));
    }
    return dp[i][x] = ans;
}
vector<int> sol;
void generate(int i,int x){
    if(i==n) return;
    else{
        int donttake = hiAyu(i+1,x);
        if(w[i]<=x){
            int take = hiAyu(i+1,x-w[i])+v[i];
            if(donttake>take){
                generate(i+1,x);
            }
            else{
                sol.push_back(i);
                generate(i+1,x-w[i]);
            }
        }
        else{
            generate(i+1,x);
        }
    }
}

int main(){
    sol.clear();
    memset(dp, -1, sizeof(int) * 1001 * 1001);
    cin>>n;
    w.resize(n);
    v.resize(n);
    int x;
    cin>>x;
    for(int i=0;i<n;i++) cin>>w[i];
    for(int i=0;i<n;i++) cin>>v[i];
    generate(0,x);
    for(auto i: sol) cout<<i<<" ";
    return 0;
}