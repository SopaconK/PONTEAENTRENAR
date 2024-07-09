#include "seats.h"
#include<bits/stdc++.h>
using namespace std;

vector<int> r;
vector<int> c;
int h,w;

void give_initial_chart(int H, int W, vector<int> R, vector<int> C) {
  r = R;
  c = C;
  h=H;
  w=W;
}

int swap_seats(int a, int b) {
  swap(r[a], r[b]);
  swap(c[a], c[b]);
  int ans=0;
  int minr=1e9;
  int maxr=0;
  int minc=1e9;
  int maxc=0;
  for(int i=0; i<r.size(); ++i){
    minr=min(minr, r[i]);
    maxr=max(maxr, r[i]);
    minc=min(minc, c[i]);
    maxc=max(maxc, c[i]);
    int sz=(maxr-minr+1)*(maxc-minc+1);
    if(sz-1==i){
      ans++;
    }
  }
  return ans;
}
