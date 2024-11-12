#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
int t;
int hiAyu(int i, int x){
    iF(x>t) 
    if(i==n){
        if(t==x) return 1;
        else return 0;
    }
    if(dp[i][t]!=x) return dp[i][t];
    int ans = 0;
    if(hiAyu(i+1,x)==1){
        ans = 1;
    }else if(hiAyu(i+1,x+v[i])){
        ans = 1;
    }
    return dp[i][x] = ans;
}

int main()[
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cin>>t;
    cout<<hiAyu(0,0)<<endl;
]