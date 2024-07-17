#include "split.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) ;

 
 vector<vector<int>> adj;
 vector<vector<int>> tree;
 vector<bool> vis;
	vector<int> sz;
	vector<int> par;
 void dfs(int x){
	deb(x);
	sz[x]++;
	vis[x]=true;
	for(int y: adj[x]){
		if(vis[y]) continue;
		tree[x].pb(y);
		par[y]=x;
		dfs(y);
		sz[x]+=sz[y];
	}
 }

vector<bool> prn;
lli ind;
void dfs2(int x, int &a){
	deb(x);
	ind=x;
	for(int y: tree[x]){
		if(sz[y]>=a){
			prn[x]=true;
			dfs2(y,a);
			break;
		}
	}
}

vector<bool> pos;
vector<bool> cnc;
int sz1, sz2;
void dfs3(int x, int p, int &a){
	if(sz[x]>=a){
		for(int y: tree[x]){
			dfs3(y, x, a);
		}
		return;
	}
		for(int y: tree[x]){
			dfs3(y,x,a);
		}
		for(int y: adj[x]){
			if(y==p) continue;
			
			if(prn[y]){
				cnc[x]=true;
				pos[x]=true;
				break;
			}
		}
		for(int y: tree[x]){
			if(pos[y]) pos[x]=true;
		}
		deb("_---");
		deb(x);
		deb(pos[x]);
		deb(cnc[x]);

}

void dfs4(int x, int &b, int s, vector<int> &ans){
	//if(x==ind) return;
	if(b<=0) return;
	ans[x]=s;
	b--;
	for(int y: tree[x]){
		if(y==ind) continue;
		dfs4(y,b,s,ans);
	}
}

vector<int> add;
void dfs5(int x){
	if(cnc[x]) add.pb(x);
	for(int y: tree[x]){
		dfs5(y);
	}
}

void dfs6(int x, int a){
	for(int y: tree[x]){
		if(pos[y]){
			sz1+=sz[y];
			sz2-=sz[y];
			deb(y);
			deb(sz1);
			deb(sz2);
			dfs5(y);
			if(sz1>=a) break;
		}
	}
}
int extra;
void dfs7(int x, int &a, int s, vector<int> &ans){

	if(ans[x]!=extra) return;
	if(a<=0) return;
	deb(x);
	deb(a);
	ans[x]=s;
	a--;
	for(int y: tree[x]){
		if(y==ind) continue;
		dfs7(y,a,s,ans);
	}
}

void dfs8(int x, int &a, int s, vector<int> &ans){
	if(ans[x]!=extra) return;
	if(a<=0) return;
	if(x==ind) return;
	deb("HHHIIII");
	deb(x);
	deb(a);
	deb(s);
	ans[x]=s;
	a--;
	for(int y: tree[x]){
		dfs7(y,a,s,ans);
	}
	dfs8(par[x], a, s, ans);
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
	adj.clear();
	adj.resize(n);
	int m=p.size();
	for(int i=0; i<m; ++i){
		adj[p[i]].pb(q[i]);
		adj[q[i]].pb(p[i]);
	}
	sz.clear();
	vis.clear();
	tree.clear();
	sz.resize(n,0);
	vis.resize(n,0);
	tree.resize(n);
	par.clear();
	par.resize(n,-1);
	dfs(0);
	prn.clear();
	prn.resize(n,0);
	ind=0;
	deb("----------");
	dfs2(0,a);
	sz1=n-sz[ind];
	sz2=sz[ind];
	deb(sz1);
	deb(sz2);
	pos.clear();
	cnc.clear();
	pos.resize(n,0);
	cnc.resize(n,0);
	vector<int> ans (n,ayuda[2].second);
	if(n-sz[ind]>=a){
		
		if(sz[ind]>=n-sz[ind]){
			dfs4(0, a, ayuda[0].second, ans);
			dfs4(ind, b, ayuda[1].second, ans);
		}
		else{
			dfs4(0, b, ayuda[1].second, ans);
			dfs4(ind, a, ayuda[0].second, ans);
		}
		return ans;
	}
	dfs3(ind, -1, a);
	add.clear();
	dfs6(ind, a);
	extra=ayuda[2].second;
	deb(extra);
	if(sz1<a){
		vector<int> no(n,0);
		return no;
	}
	if(sz1>=sz2){
		dfs7(0, b, ayuda[1].second, ans);
		for(int x: add){
			dfs8(x, b, ayuda[1].second, ans);
		}
		dfs7(ind, a, ayuda[0].second, ans);
	}
	else{
		dfs7(0, a, ayuda[0].second, ans);
		for(int x: add){
			dfs8(x, a, ayuda[0].second, ans);
		}
		dfs7(ind, b, ayuda[1].second, ans);
	}
	return ans;


}