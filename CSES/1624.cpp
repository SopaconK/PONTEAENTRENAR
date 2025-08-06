#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

vector<vector<lli>> st (8, vector<lli> (8,0));
lli ans=0;

void bt (lli i, lli j, lli &v){
    if(st[i][j]==0){
        st[i][j]=1;
        for(lli x=0; x<8; ++x){
            if(st[x][j]>=0) st[x][j]++;
            if(st[i][x]>=0) st[i][x]++;
            if(i-x>=0){
                if(j-x>=0 && st[i-x][j-x]>=0) st[i-x][j-x]++;
                if(j+x<8 && st[i-x][j+x]>=0) st[i-x][j+x]++;
            }
            if(i+x<8){
                if(j-x>=0 && st[i+x][j-x]>=0) st[i+x][j-x]++;
                if(j+x<8 && st[i+x][j+x]>=0) st[i+x][j+x]++;
            }
        }
        v++;
         if(j==7){
           if(i==7){
                if(v==8) ans++;
            }
            else{
                bt(i+1,0,v);
            }
        }
        else{
            bt(i,j+1,v);
        }
        st[i][j]--;
        for(lli x=0; x<8; ++x){
            if(st[x][j]>=0) st[x][j]--;
            if(st[i][x]>=0) st[i][x]--;
            if(i-x>=0){
                if(j-x>=0 && st[i-x][j-x]>=0) st[i-x][j-x]--;
                if(j+x<8 && st[i-x][j+x]>=0) st[i-x][j+x]--;
            }
            if(i+x<8){
                if(j-x>=0 && st[i+x][j-x]>=0) st[i+x][j-x]--;
                if(j+x<8 && st[i+x][j+x]>=0) st[i+x][j+x]--;
            }
        }
        v--;
        if(j==7){
           if(i==7){
                if(v==8) ans++;
            }
            else{
                bt(i+1,0,v);
            }
        }
        else{
            bt(i,j+1,v);
        }
    }
    else{
        if(j==7){
           if(i==7){
                if(v==8) ans++;
            }
            else{
                bt(i+1,0,v);
            }
        }
        else{
            bt(i,j+1,v);
        }
    }
   
}


void solve(){
   
    
    for(lli i=0; i<8; ++i){
        string s;
        cin>>s;
        for(lli j=0; j<8; ++j){
            if(s[j]=='*') st[i][j]=-1;
        }
    }
    lli v=0;
    bt(0,0,v);
    cout<<ans<<endl;
    

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while (t--){
        solve();
    }
}