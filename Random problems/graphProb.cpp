#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6+3;
vector<int> g[N];
bool vis[N];

void dfs(int u){
    vis[u] = 1;
    for(int v: g[u]){
        if(vis[v])  continue;
        dfs(v);
    }
}

int main(){
    freopen("inp.txt","r",stdin);
    int n,m,u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if(vis[5])  cout<<"Yes"<<endl;
    else    cout<<"We can't"<<endl;
    return 0;
}
