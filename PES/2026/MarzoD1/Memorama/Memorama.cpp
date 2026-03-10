#include "Memorama_lib.h"
#include <bits/stdc++.h>

#define rep(a,b,c) for(int a=b; a<c; a++)
#define repa(a,b) for(auto a: b)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using lli=int;
using namespace std;
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;

void Resolver(int T, int N){
	// deb(T);
	// deb(N);
	vector<lli> ans (2*N,-1);
	vector<vector<lli>> query( 2*N, vector<lli> (2*N, -1));
	stack<lli> sk;
	for(lli i=0; i<2*N; ++i) sk.push(i);
	while(sk.size()>=3){
	//	deb(sk.size());
		lli a=sk.top();
		sk.pop();
		lli b=sk.top();
		sk.pop();
		lli c=sk.top();
		sk.pop();
		lli x,y,z;
		if(query[a][b]==-1) query[a][b]=Voltea(a,b);
		if(query[a][c]==-1) query[a][c]=Voltea(a,c);
		if(query[b][a]==-1) query[b][a]=query[a][b];
		
		if(query[c][a]==-1) query[c][a]=query[a][c];
		
		x=query[a][b];
		y=query[a][c];
		//  deb(a);
		//  deb(b);
		//  deb(c);
		//  deb(x);
		//  deb(y);

		
		


		if(query[b][c]==-1) query[b][c]=Voltea(b,c);
		if(query[c][b]==-1) query[c][b]=query[c][b];
		z=query[b][c];
	//	deb(z);
		if(x==y && y==z){
			lli d;
			if(!sk.empty()){
				d=sk.top();
				sk.pop();
			}
			else{
				for(lli i=0; i<2*N; ++i){
					if(ans[i]!=-1){
						d=i;
						break;
					}
				}
			}
			
	//		deb(d);
			if(query[a][d]==-1) query[a][d]=Voltea(a,d);
			if(query[d][a]==-1) query[d][a]=query[a][d];
			if(query[b][d]==-1) query[b][d]=Voltea(b,d);
			if(query[d][b]==-1) query[d][b]=query[b][d];
		//	deb(query[a][d]);
		//	deb(query[b][d]);
			if(query[a][d]==x){
				ans[a]=x;
			
				
				if(query[b][d]==x){
					ans[b]=x;
					sk.push(d);
					sk.push(c);
				}
				else{
					ans[c]=x;
					sk.push(d);
					sk.push(b);
				}
			}
			else{
				if(query[a][d]==query[b][d]){
					ans[d]=query[a][d];
					sk.push(c);
					sk.push(b);
					sk.push(a);
					continue;
				}
				else{
					if(query[c][d]==-1) query[c][d]=Voltea(c,d);
					if(query[d][c]==-1) query[d][c]=query[c][d];
					if(query[a][d]==query[c][d]){
							ans[d]=query[a][d];
							sk.push(c);
							sk.push(b);
							sk.push(a);
							continue;
					}
					ans[b]=x;
					ans[c]=x;
					sk.push(d);
					sk.push(a);
					continue;

				}
			}
			continue;
		}
		if(x==y){
			ans[a]=x;
			sk.push(b);
			sk.push(c);
		}
		else if(x==z){
			ans[b]=z;
			sk.push(a);
			sk.push(c);
		}
		else{
			ans[c]=z;
			sk.push(a);
			sk.push(b);
		}
	}
//	deb(sk.size());
	if(sk.size()==1){
		vector<lli> v (N, 0);
		for(lli i=0; i<2*N; ++i){
			if(ans[i]!=-1) v[ans[i]]++;
		}
		for(lli i=0; i<N; ++i){
			if(v[i]<2){
				ans[sk.top()]=i;
				break;
			}
		}
	}
	if(sk.size()==2){
		vector<lli> v (N, 0);
		for(lli i=0; i<2*N; ++i){
			if(ans[i]!=-1) v[ans[i]]++;
		}
	//	deb("Hi");
		lli x=-1;
		lli y=-1;
		for(lli i=0; i<N; ++i){
			if(v[i]==0){
				x=i;
				break;
			}
			if(v[i]==1){
				if(x==-1) x=i;
				else y=i;
			}
		}
		// deb(x);
		// deb(y);
		if(y==-1){
			
			while(!sk.empty()){
				// deb(sk.size());
				// deb(sk.empty());
				// deb(sk.top());
				ans[sk.top()]=x;
				sk.pop();
			}
		}
		else{
			lli a,b;
			for(lli i=0; i<2*N; ++i){
				if(ans[i]==x) a=i;
				if(ans[i]==y) b=i;
			}
			lli v1=Voltea(a, sk.top());
			lli v2=Voltea(b, sk.top());
			if(v1==v2){
				ans[sk.top()]=v1;
				sk.pop();
				if(v1==x){
					ans[sk.top()]=y;
				}
				else ans[sk.top()]=x;
			}
			else{
				lli aux=sk.top();
				sk.pop();
				lli v3=Voltea(a, sk.top());
				ans[sk.top()]=v3;
				if(v3==x){
					ans[aux]=y;
				}
				else ans[aux]=x;
			}

		}

	}

	vector<vector<lli>> env (N);
	for(lli i=0; i<2*N; ++i){
	//	deb(ans[i]);
		 env[ans[i]].pb(i);
	}
	for(lli i=0; i<N; ++i){
		Respuesta(env[i][0], env[i][1], i);
	}


	return;
}
