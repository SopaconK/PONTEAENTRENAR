#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'



void solve(){
   lli n;
   cin>>n;
   string s1,s2;
   cin>>s1>>s2;
   bool a=0;
   bool b=0;
   lli ind;
   lli blacks=0;
   for(lli i=0; i<n; ++i){
    if(s1[i]=='B') blacks++;
    if(s2[i]=='B') blacks++;
   }
   for(lli i=0; i<n; ++i){
    if(s1[i]==s2[i] && s1[i]=='W') continue;
    ind=i;
    break;

   }
   lli cant;

   //first
    cant=0;
   if(s1[ind]=='B'){
    a=1;
    cant=1;
    if(s2[ind]=='B'){
        swap(a,b);
        cant++;
    }
    for(lli i=ind+1; i<n; ++i){
        if(a){
            if(s1[i]=='B'){
                cant++;
                if(s2[i]=='B'){
                    cant++;
                    swap(a,b);
                }
            }
            else{
                a=0;
            }
        }
        else if(b) {
             if(s2[i]=='B'){
                cant++;
                if(s1[i]=='B'){
                    cant++;
                    swap(a,b);
                }
            }
            else{
                b=0;
            }
        }
    }
    if(cant==blacks){
        cout<<"YES"<<endl;
        return;
    }
   }

   //second 
    cant=0;
   if(s2[ind]=='B'){
    b=1;
    cant=1;
    if(s1[ind]=='B'){
        swap(a,b);
        cant++;
    }
    for(lli i=ind+1; i<n; ++i){
        if(a){
            if(s1[i]=='B'){
                cant++;
                if(s2[i]=='B'){
                    cant++;
                    swap(a,b);
                }
            }
            else{
                a=0;
            }
        }
        else if(b) {
             if(s2[i]=='B'){
                cant++;
                if(s1[i]=='B'){
                    cant++;
                    swap(a,b);
                }
            }
            else{
                b=0;
            }
        }
    }
    if(cant==blacks){
        cout<<"YES"<<endl;
        return;
    }
   }
   cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    while (t--){
        solve();
    }
}