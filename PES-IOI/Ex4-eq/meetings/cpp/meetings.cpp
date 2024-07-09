#include "meetings.h"
#include<bits/stdc++.h>
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using namespace std;
using lli=long long;

vector<long long> minimum_costs(vector<int> H, vector<int> L,
                                     vector<int> R) {
  lli N=H.size();
  vector<vector<lli>> v (N, vector<lli> (N));
  for(lli i=0; i<N; ++i){
    v[i][i]=H[i];
    lli maxi=H[i];
    for(lli j=i+1; j<N; ++j){
      v[i][j]=v[i][j-1]+max(maxi, (lli) H[j]);
      maxi=max(maxi, (lli) H[j]);
    }
    maxi=H[i];
    for(lli j=i-1; j>=0; --j){
      maxi=max(maxi,(lli) H[j]);
      v[i][j]=v[i][j+1]+maxi;
    }
  }
 // deb("hi");
  lli Q=L.size();
  vector<lli> sv;
  for(lli ind=0; ind<Q; ++ind){
    lli ans=1e18;
    //deb(L[ind]);
   // deb(R[ind]);
    for(lli i=L[ind]; i<=R[ind]; ++i){

      ans=min(ans, v[i][L[ind]]+v[i][R[ind]]-H[i]);
    }
    //deb(ans);
    sv.pb(ans);
  }
  return sv;
}
