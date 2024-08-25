#include "pyramids.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
vector<lli> pref1;
vector<lli> pref2;
void init(std::vector<int> A, std::vector<int> B) {
  int n=A.size();
  pref1.clear();
  pref1.resize(n+1,0);
  pref2.clear();
  pref2.resize(n+1,0);
  for(int i=0; i<n; ++i){
    pref1[i+1]=pref1[i]+A[i];
    pref2[i+1]=pref2[i]+B[i];
  }

}

bool can_transform(int L, int R, int X, int Y) {
  if(pref1[R+1]-pref1[L]==pref2[Y+1]-pref2[X]) return true;
  return false;
}
