#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define endl '\n'


vector<int> countScans(vector<int> A,vector<int> X,vector<int> V){
	int n=A.size();
    int q=X.size();
    vector<int> sv;
    for(int i=0; i<q; ++i){
        A[X[i]]=V[i];
        int ans=0;
        for(int j=0; j<n; ++j){
            int aux=0;
            for(int k=0; k<j; ++k){
                if(A[k]>A[j]){
                    aux++;
                }
            }
            ans=max(ans, aux);
        }
        sv.pb(ans);
    }
    return sv;
}



//Grader Malo
/*
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
      int n,q;
      cin>>n>>q;
      vector<int> A (n);
      for(int i=0; i<n; ++i){
        cin>>A[i];
      }
      vector<int> X(q);
      vector<int> V(q);
      for(int i=0; i<q; ++i){
        cin>>X[i]>>V[i];
      }
      vector<int> ans=countScans(A,X,V);
      for(int x: ans){
        cout<<x<<endl;
      }
    }
}*/