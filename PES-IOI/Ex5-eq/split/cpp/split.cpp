#include "split.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

vector<int> ans;
vector<bool> visited;

vector<vector<int>> sons;
vector<int> sz;
void dfs2(int x, int p, vector<vector<int>> &adj){
	sz[x]++;
	for(int y: adj[x]){
		if(y==p) continue;
		sons[x].pb(y);
		dfs2(y,x,adj);
		sz[x]+=sz[y];
	}
}

vector<int> v1;
vector<int> v2;
void dfs3(int x, int &a, int &b, int s, bool ya, bool whch){

	if(ya){
		v1.pb(x);
		for(int y:sons[x]){
			dfs3(y,a,b,s,ya,whch);
		}
			
		
	}
	else{
		if(x==s){
			dfs3(x,a,b,s,1,whch);
			return;
		}
		
		v2.pb(x);
		
		for(int y:sons[x]){
			dfs3(y,a,b,s,ya,whch);
		}

	}
}

vector<int> find_split(int n, int a1, int b1, int c1, vector<int> p, vector<int> q) {
	
		vector<pair<int,int>> ayuda;
		ayuda.pb({a1,1});
		ayuda.pb({b1,2});
		ayuda.pb({c1,3});
		sort(ayuda.begin(), ayuda.end());
		int a=ayuda[0].first;
		int b=ayuda[1].first;
		int c=ayuda[2].first;
		ans.clear();
		sons.clear();
		sz.clear();
//		visited.clear();
		ans.resize(n,ayuda[2].second);
//		visited.resize(n,0);
		//visited[0]=true;
		sons.resize(n);
		sz.resize(n,0);
		
		vector<vector<int>> adj(n);
		for(int i=0; i<p.size(); ++i){
			adj[p[i]].pb(q[i]);
			adj[q[i]].pb(p[i]);
		}
		dfs2(0,-1,adj);
		lli si0=-1;
		lli si1=-1;
		for(lli i=0; i<n; ++i){
	//		deb(sz[i]);
			if(sz[i]>=a && n-sz[i]>=b) si0=i;
			if(sz[i]>=b && n-sz[i]>=a) si1=i;
		}
	//	deb(si0);
	//	deb(si1);
	//	si0=-1;
		if(si0!=-1){
			dfs3(0,a,b,si0,0,0);
			for(int i=0; i<a; ++i){
				ans[v1[i]]=ayuda[0].second;
			}
			for(int i=0; i<b; ++i){
				ans[v2[i]]=ayuda[1].second;
			}
			return ans;
		}
		if(si1!=-1){
			dfs3(0,a,b,si1,0,1);
			for(int i=0; i<b; ++i){
				ans[v1[i]]=ayuda[1].second;
			}
			for(int i=0; i<a; ++i){
				ans[v2[i]]=ayuda[0].second;
			}
			return ans;
		}
		vector<int> mqm(n,0);
		return mqm;


	
}
