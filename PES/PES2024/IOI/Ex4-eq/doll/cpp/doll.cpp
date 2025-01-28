#include "doll.h"
#include<bits/stdc++.h>
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using namespace std;
using lli=long long;

void create_circuit(int M, vector<int> A) {
  A.pb(0);
  answer(A, {}, {});
}
