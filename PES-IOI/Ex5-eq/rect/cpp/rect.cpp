#include "rect.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

long long count_rectangles(vector<vector<int> > a) {
	lli n=a.size();
	lli m=a[0].size();
	lli ans=0;
	for(lli i=1; i<n-1; ++i){
		for(lli j=i; j<n-1; ++j){
			for(lli k=1; k<m-1; ++k){
				for(lli l=k; l<m-1; ++l){
					bool pos=true;
					for(lli x=i; x<=j; ++x){
						if(!pos) break;
						for(lli y=k; y<=l; ++y){
							if(a[x][y]>=a[i-1][y] || a[x][y]>= a[x][l+1] || a[x][y]>=a[j+1][y] || a[x][y]>=a[x][k-1]){
								pos=false;
								break;
							}
						}
					}
					if(pos) ans++;
				}
			}
		}
	}
	return ans;
}
