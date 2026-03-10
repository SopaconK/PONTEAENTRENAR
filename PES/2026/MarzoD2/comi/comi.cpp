#include "comi_lib.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define deb(x) cout<<#x<<": "<<x<<endl;
#define pb push_back
#define endl '\n'

vector<vector<lli>> sons;
vector<lli> par;
vector<vector<lli>> ady;
void dfs(lli x, lli p, vector<vector<lli>> &ady){
	par[x]=p;
	if(p!=-1) sons[p].pb(x);
	for(lli y: ady[x]){
		if(y!=p){
			dfs(y, x, ady);
		}
	}
}


vector<lli> nb;
void escribirnum(){
	queue<pair<lli,lli>> q;
	for(lli i=0; i<sons.size(); ++i){
		if(sons[i].size()==0){
			q.push({i,11});
			nb[i]=11;
		}
	}
	while(!q.empty()){
		lli x=q.front().first;
		lli y=q.front().second;
		q.pop();
		
		if(par[x]==-1) continue;
		if(y==0) y=12;
		if(nb[par[x]]==-1 || nb[par[x]]>y-1){
			nb[par[x]]=y-1;
			q.push({par[x], y-1});
		}
	}
}

vector<lli> donde;
lli ind=0;
void decirdonde(lli x){
	if(x==0){
		for(lli y: sons[x]){
		decirdonde(y);
	}
	return;
	}
	if(nb[x]==0){
		donde[x]=ind;
		ind+=9;
	}
	else{
		donde[x]=ind;
		ind++;
	}
	for(lli y: sons[x]){
		decirdonde(y);
	}
}


vector<lli> qn;
int n;

vector<lli> st;

vector<lli> res;

void respuestas(lli x){
	if(x==0) res[x]=0;
	for(lli y: sons[x]){
		res[y]=res[x]+st[y];
		respuestas(y);
	}
}
map<lli,lli> mp;
void escribir(lli x){
	if(x==0){
		for(lli y: sons[x]){
		escribir(y);
	}
	return;
	}

	if(nb[x]==0){
		lli aux=res[x];
		lli dnd=donde[x];
		for(lli i=0; i<9; ++i){
			
			if(donde[x]+i<1000)Guardar(donde[x]+i, aux%2);
			aux/=2;
		}
	}
	else{
		if(st[x]){
			// while(donde[x]<0 || donde[x]>=1000){
			// 		deb("AAA");
			// 	}
			if(donde[x]<1000) Guardar(donde[x], 1);
		}
	}
	for(lli y: sons[x]){
		escribir(y);
	}
}


void InitSebas(int N , int A[] , int B[]) {
	n=N;
	sons.clear();
	sons.resize(n);
	par.clear();
	par.resize(n);
	ady.clear();
	ady.resize(n);
	for(lli i=0; i<n-1; ++i){
		ady[A[i]].pb(B[i]);
		ady[B[i]].pb(A[i]);
	}
	nb.clear();
	nb.resize(n, -1);
	donde.clear();
	donde.resize(n);
	ind=0;
	dfs(0, -1, ady);
	escribirnum();
	decirdonde(0);
	qn.clear();
	qn.resize(n-1);
	for(lli i=0; i<n-1; ++i){
		if(par[A[i]]==B[i]){
			qn[i]=A[i];
		}
		else qn[i]=B[i];
	}
	st.clear();
	st.resize(n,0);
	res.clear();
	res.resize(n, 0);

}

void Sebas(int C[]) {
	for(lli i=0; i<n; ++i) st[i]=0;
	for(lli i=0; i<n-1; ++i){
		if(C[i]==1){
			st[qn[i]]=1;
		}
	}	
	for(lli i=0; i<n; ++i) res[i]=0;
	respuestas(0);
	escribir(0);

}

void InitJuan(int N , int A[] , int B[]) {
	n=N;
	sons.clear();
	sons.resize(n);
	par.clear();
	par.resize(n);
	ady.clear();
	ady.resize(n);
	for(lli i=0; i<n-1; ++i){
		ady[A[i]].pb(B[i]);
		ady[B[i]].pb(A[i]);
	}
	nb.clear();
	nb.resize(n, -1);
	donde.clear();
	donde.resize(n);
	ind=0;
	dfs(0, -1, ady);
	escribirnum();
	decirdonde(0);


}

int Juan(int ciudad) {
	int ans=0;
	lli cant=0;
	while(ciudad!=0 && nb[ciudad]!=0){
	//	deb(ciudad);
	//	deb(donde[ciudad]);
	// while(donde[ciudad]<0 || donde[ciudad]>=1000){
	// 	deb("AAAAA DONDE CIUDAD");
	// }
		if(donde[ciudad]<1000)ans+=Leer(donde[ciudad]);
		cant++;
		ciudad=par[ciudad];
	}
	if(ciudad!=0){
		lli mult=1;
		for(lli i=0; i<9; ++i){
			
			if(donde[ciudad]+i<1000) ans+=mult*Leer(donde[ciudad]+i);
			mult*=2;
			cant++;
		}
	}
	while(cant>20){
		deb(cant);
	}
	return ans;
}
