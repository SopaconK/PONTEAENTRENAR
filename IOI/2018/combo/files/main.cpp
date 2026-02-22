#include "combo.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back;

string guess_sequence(int n){

    vector<char> v ={'A','B','X','Y'};
    int prin=3;
  //  cout<<n<<endl;
    if(press("AB")>0){
        if(press("A")>0) prin=0;
        else prin=1;
    }
    else{
        if(press("X")>0) prin=2;
        else prin=3;
    }
    //cout<<"HI"<<endl;
    swap(v[0], v[prin]);
  //  cout<<v[0]<<endl;
    string ans="";
    ans+=v[0];
//    cout<<ans<<endl;
    int val=-1;
    
    for(int i=2; i<n; ++i){

        string query=ans+v[1]+v[1]+ans+v[1]+v[2]+ans+v[1]+v[3]+ans+v[2];
        val=press(query);
        if(val==i-1) ans+=v[3];
        if(val==i) ans+=v[2];
        if(val>i) ans+=v[1];
    }
    if(n>1){
    if(press(ans+v[1]+ans+v[2])==n){
        if(press(ans+v[1])==n) ans+=v[1];
        else ans+=v[2];
    }
    else ans+=v[3];
    }
    return ans;

}
