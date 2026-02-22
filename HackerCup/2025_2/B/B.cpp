#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define endl '\n'
#define deb(x) cout<<#x<<": "<<x<<endl;


bool pos(lli k,vector<lli> v, vector<lli> c){
    lli n=v.size();
    vector<lli> cant (n,0);
    lli ind=0;
    while(ind<n-1 && v[ind+1]>=k) ind++;
 //   deb(k);
   // deb(ind);
    cant[ind]=1;
    
    while(ind>0){
        ind--;
        if(v[ind]==v[ind+1]) cant[ind]=cant[ind+1];
        else{
            cant[ind]=cant[ind+1]+1;
        }
    }
    lli m=c.size();
  
    if(cant[0]>m) return false;
    vector<lli> aux (m,0);
    for(lli i=0; i<n; ++i) if(cant[i]>0) aux[cant[i]-1]++;
    vector<lli> lasteq(m);
    lasteq[m-1]=m-1;
    for(lli i=m-2; i>=0; --i){
        if(c[i]==c[i+1]) lasteq[i]=lasteq[i+1];
        else lasteq[i]=i;
    }
    lli cnt=0;
    cout<<"-----------------------------"<<endl;
    for(lli i=m-1; i>=0; --i){
       lli cnt2=cnt;
        deb(i);
        deb(aux[i]);
        deb(c[i]);

        while(aux[i]>0 || cnt2>0){
            if(cnt2>0){
             cnt2--;   
            }
            else{
            cnt++;
            aux[i]--;
            }
            if(i==m-1) c[i]--;
            else{
                if(c[i]==c[i+1]) lasteq[i]=lasteq[i+1];
                else lasteq[i]=i;
                if(c[i]==c[i+1]+1){
                    c[i]--;
                    lasteq[i]=lasteq[i+1];
                }
                else if(c[i]==c[i+1]){
                    c[lasteq[i]]--;
                    if(lasteq[i]!=m-1){
                        if(c[lasteq[i]]==c[lasteq[i]+1]){
                            lasteq[lasteq[i]]=lasteq[lasteq[i]+1];
                        }
                        else{
                            lasteq[lasteq[i]]=lasteq[i];
                        }
                    }
                    lasteq[i]--;
                }
                else{
                    c[i]--;
                }
            }
              for(lli i=0; i<m; ++i){
        cout<<c[i]<<" ";
    }
    cout<<endl;
        }
    }
  cout<<"-----------------------------"<<endl;
   if(c[c.size()-1]>=0) return true;
   return false;
}


void solve(lli t){
    lli n,m;
    cin>>n>>m;
    lli ans=0;
    vector<lli> v (n);
    vector<lli> c (m);
    for(lli i=0; i<n; ++i) cin>>v[i];
    for(lli i=0; i<m; ++i) cin>>c[i];
    sort(v.rbegin(), v.rend());
    sort(c.rbegin(), c.rend());


    

    lli l=v[v.size()-1];
    lli r=v[0];
    deb(pos(l,v,c));
   
    if(!pos(r,v,c)){
        ans=0;
    }
    else if(pos(l,v,c)){
        ans=n;
    }
    else{
     while(l!=r){
         lli m=(l+r)/2;
     
        
         if(pos(m, v, c)){
             r=m;
         }
         else{
             l=m+1;
         }
     }

      ans=0;
    while(ans<n-1 && v[ans+1]>=l) ans++;
    ans++;
     
    }

     cout<<"Case #"<<t<<": "<<ans<<endl;   
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    for(lli i=1; i<=t; ++i) solve(i);
}