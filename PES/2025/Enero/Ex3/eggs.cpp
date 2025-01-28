#include <bits/stdc++.h>
#include "grader.h"

using namespace std;
 #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


vector<int> euler;
vector<int> par;
int n;
bool check(int a, int b){  
    vector<bool> vis(n+1,0);
    for(int i=a; i<=b; ++i){
        int aux=euler[i];
        while(!vis[aux]){
            vis[aux]=1;
            if(aux!=1){
                aux=par[aux];
            }
        }
    }
    vector<int> preg;
    for(int i=1; i<=n; ++i){
        if(vis[i]) preg.pb(i);
    }
    return query(preg);
}

void dfs(int x, int p, vector<vector<int>> &ady){
    par[x]=p;
    euler.pb(x);
    for(int y: ady[x]){
        if(y==p) continue;
        dfs(y,x,ady);
    }
}


int findEgg (int N, vector < pair < int, int > > bridges)
{
    n=N;
    vector<vector<int>> ady(n+1);
    euler.clear();
    par.clear();
    par.resize(n+1);
    for(int i=0; i<n-1; ++i){
        int a=bridges[i].first;
        int b=bridges[i].second;
        ady[a].pb(b);
        ady[b].pb(a);
    }
    dfs(1,-1,ady);

    int l=0;
    int r=n-1;
    while(l!=r){
        int m=(l+r)/2;
        if(check(l,m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    return euler[l];
}
