#include "split.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
 
vector<int> ans;
vector<bool> visited;
void dfs(int x, vector<vector<int>>& adj, int &cont,  int &a, int &b, int &c){
 
	if(cont<a){
		ans[x]=1;
	}
	else if(cont<a+b){
		ans[x]=2;
	}
	else ans[x]=3;
	for(int y: adj[x]){
		if(visited[y]) continue;
		visited[y]=true;
		cont++;
		dfs(y, adj,cont,a,b,c);
	}
}
 
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
 
 vector<vector<int>> adj;
 
vector<int> find_split(int n, int a1, int b1, int c1, vector<int> p, vector<int> q) {
 
	vector<int> p1;
	vector<int> q1;
	
	vector<vector<int>> adj2(n);
	for(int i=0; i<p.size(); ++i){
		adj2[p[i]].pb(q[i]);
		adj2[q[i]].pb(p[i]);
	}
	vector<int> auxi;
	for(int nodo=0; nodo<n; ++nodo){
	vector<bool> visi (n);
	queue<int> que;
	visi[nodo]=true;
	
	que.push(nodo);
	while(!que.empty()){
		
		int x=que.front();
	
		que.pop();
		for(int y: adj2[x]){
			if(!visi[y]){
				p1.pb(x);
				q1.pb(y);
				visi[y]=true;
				que.push(y);
			}
		}
	}
 
 
 
 
 
	// Now it's a tree
 
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
		adj.clear();
		adj.resize(n);
		for(int i=0; i<p1.size(); ++i){
			adj[p1[i]].pb(q1[i]);
			adj[q1[i]].pb(p1[i]);
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
			auxi=ans;
			break;
		}
		if(si1!=-1){
			dfs3(0,a,b,si1,0,1);
			for(int i=0; i<b; ++i){
				ans[v1[i]]=ayuda[1].second;
			}
			for(int i=0; i<a; ++i){
				ans[v2[i]]=ayuda[0].second;
			}
			auxi=ans;
			break;
		}
	
	}
	if(auxi.size()==0){
		vector<int> mqm(n,0);
		return mqm;
	}
	return auxi;
}