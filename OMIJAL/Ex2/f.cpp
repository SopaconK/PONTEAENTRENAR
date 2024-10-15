#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;




void solve(){
    lli n;
    cin>>n;
    vector<lli> v(n);
    map<lli,vector<lli>> mp;
    for(lli i=0; i<n; ++i){
        cin>>v[i];
        mp[v[i]].pb(i);
    }
    
    vector<lli> ans;
    lli c1=-1;
    lli c2=-1;

    vector<lli> values (n+1,-1);
    lli sz=0;
    vector<lli> donde (n, -1);
    for(lli i=0; i<1000; ++i){
        for(lli j=mp[i].size()-1; j>=0; --j){
            lli x=mp[i][j];
            lli left=0;
            lli right=sz;
            while(left<right){
                lli m=(left+right+1)/2;
                if(values[m]<x){
                    left=m;
                }
                else{
                    right=m-1;
                }
            }
            left++;
            if(values[left]>x || values[left]==-1){
                values[left]=x;
            }
          
            sz=max(sz, left);
            donde[x]=left;
        }
    }
    lli last=1e9;
    lli sch=sz;
    for(lli i=n-1; i>=0; --i){
      //  deb(donde[i]);
        if(donde[i]==sch){
            if(v[i]<last){
                ans.pb(last);
                sch--;
                last=v[i];
            }
        }
    }
    reverse (ans.begin(),ans.end());
    for(lli a=0; a<n; ++a){
        for(lli b=a+1; b<n; ++b){
            swap(v[a], v[b]);

            vector<lli> values (n+1,-1);
    lli sz=0;
    vector<lli> donde (n, -1);
    for(lli i=0; i<1000; ++i){
        for(lli j=mp[i].size()-1; j>=0; --j){
            lli x=mp[i][j];
            lli left=0;
            lli right=sz-1;
            while(left<right){
                lli m=(left+right+1)/2;
                if(values[m]<x){
                    left=m;
                }
                else{
                    right=m-1;
                }
            }
            left++;
            if(values[left]>x){
                values[left]=x;
            }
            sz=max(sz, left);
            donde[x]=left;
        }
    }
    vector<lli> aux;
    lli last=1e9;
    lli sch=sz;
    for(lli i=n-1; i>=0; --i){
        if(donde[i]==sch){
            if(v[i]<last){
                aux.pb(last);
                sch--;
                last=v[i];
            }
        }
    }
    reverse (aux.begin(),aux.end());
         if(aux.size()>ans.size()){
                ans=aux;
                c1=a+1;
                c2=b+1;
            }
            else if(aux.size()==ans.size()){
                for(lli k=0; k<ans.size(); ++k){
                    if(aux[k]==ans[k]) continue;
                    if(aux[k]<ans[k]){
                        ans=aux;
                        c1=a+1;
                        c2=b+1;
                    }
                    break;
                }
            }


            swap(v[a], v[b]);
        }
    }

    
cout<<c1<<" "<<c2<<" "<<ans.size()<<endl;
    for(lli x: ans){
        cout<<x<<" ";
    }
    cout<<endl;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}