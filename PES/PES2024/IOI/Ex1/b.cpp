#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define endl '\n'


vector<int> countScans(vector<int> A,vector<int> X,vector<int> V){
	int n=A.size();
    int q=X.size();
    vector<int> sv;
    vector<int> val (n);
    for(int j=0; j<n; ++j){
        int aux=0;
        for(int k=0; k<j; ++k){
            if(A[k]>A[j]){
                aux++;
            }
        }
        val[j]=aux;
    }
    for(int i=0; i<q; ++i){

        for(int j=0; j<X[i]; ++j){
            if(A[j]>A[X[i]]){
                val[X[i]]--;
            }
            if(A[j]>V[i]){
                val[X[i]]++;
            }
        }
        for(int j=X[i]+1; j<n; ++j){
            if(A[X[i]]>A[j]){
                val[j]--;
            }
            if(V[i]>A[j]){
                val[j]++;
            }
        }
        int ans=0;
        for(int x: val){
            ans=max(ans, x);
        }
        sv.pb(ans);
        A[X[i]]=V[i];

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