#include "vision.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;



void construct_network(int H, int W, int K) {
	vector<int> sv;
	int cont=0;
	for(int i=0; i<H; ++i){
		for(int j=0; j<W; ++j){
			for(int k=0; k<H; ++k){
				for(int l=0; l<W; ++l){
					if(abs(k-i)+abs(l-j)==K){
						add_and({i*W+j,k*W+l});
						sv.pb(H*W+cont);
						cont++;
					}
				}
			}
		}
	}
	add_or(sv);
}
