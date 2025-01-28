#include "shoes.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

struct segtree{
	lli l,r;
	lli sum;
	segtree *left, *right;
	segtree(lli a, lli b): l(a), r(b){
		if(l==r){
			sum=1;
		}
		else{
			lli m=(l+r)/2;
			left=new segtree(l,m);
			right=new segtree(m+1,r);
			sum=left->sum+right->sum;
		}
	}
	void update(lli p, lli val){
		if(l==r){
			sum=val;
			return;
		}
		lli m=(l+r)/2;
		if(p<=m) left->update(p, val);
		else right->update(p,val);
		sum=left->sum+right->sum;
	}
	lli query(lli a, lli b){
		if(a<=l && r<=b) return sum;
		if(b<l || r<a) return 0;
		return left->query(a,b)+right->query(a,b);
	}

};

long long count_swaps(vector<int> s) {
	map<lli, queue<lli>> mp;
	lli n=s.size();
	for(lli i=0; i<n; ++i){
		mp[s[i]].push(i);
	}
	segtree tree(0,n-1);
	lli ans=0;
	vector<bool> visited(n, false);
	for(lli i=0; i<n; ++i){
		if(visited[i]) continue;
		mp[s[i]].pop();
		lli x=mp[-s[i]].front();
		mp[-s[i]].pop();
	
		ans+=tree.query(i+1, x-1);
		if(s[i]>0) ans++;
		tree.update(i,0);
		tree.update(x,0);
		visited[x]=true;
	}
	return ans;

}
