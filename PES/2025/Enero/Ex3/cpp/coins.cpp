#include "coins.h"

#include <bits/stdc++.h>

using namespace std;
 #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

std::vector<int> coin_flips(std::vector<int> b, int c) {
    vector<int> ans;
    for(int i=0; i<64; ++i){
        if(b[i]) c^=i;
    }
    ans.pb(c);
    return ans;
}

int find_coin(std::vector<int> b) {
    int ans=0;
   for(int i=0; i<64; ++i){
    if(b[i]) ans^=i;
   }
    return ans;
}
