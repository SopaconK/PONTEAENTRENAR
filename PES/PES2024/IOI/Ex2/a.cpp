#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    lli n=s.size();
    vector<vector<lli>> v (n+1, vector<lli> (4,0)); // W S A D
    for(lli i=n-1; i>=0; --i){
      //  deb(i);
        for(lli j=0; j<4; ++j){
            v[i][j]=v[i+1][j];
        }
        switch(s[i]){
            case 'W':
                v[i][0]++;
                v[i][1]=max(v[i][1]-1, 0ll);
                break;
            case 'S':
                v[i][1]++;
                v[i][0]=max(v[i][0]-1, 0ll);
                break;
            case 'A':
                v[i][2]++;
                v[i][3]=max(v[i][3]-1, 0ll);
                break;
            case 'D':
                v[i][3]++;
                v[i][2]=max(v[i][2]-1, 0ll);
        }
    }
    lli mw=0;
    lli ms=0;
    lli ma=0;
    lli md=0;
    lli aw=0;
    lli aa=0;
    lli ans=(v[0][0]+v[0][1]+1)*(v[0][2]+v[0][3]+1);

    for(lli i=0; i<n; ++i){
        lli val1,val2,val3,val4;
        
        val1=max(mw, v[i][0]+aw+1);
        val2=max(ms, v[i][1]-aw-1);
        val3=max(ma, v[i][2]+aa);
        val4=max(md, v[i][3]-aa);
//        deb(val1+val2+1);
  //      deb(val3+val4+1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw-1);
        val2=max(ms, v[i][1]-aw+1);
        val3=max(ma, v[i][2]+aa);
        val4=max(md, v[i][3]-aa);
    //     deb(val1+val2+1);
      //  deb(val3+val4+1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw);
        val2=max(ms, v[i][1]-aw);
        val3=max(ma, v[i][2]+aa+1);
        val4=max(md, v[i][3]-aa-1);
        // deb(val1+val2+1);
        //deb(val3+val4+1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw);
        val2=max(ms, v[i][1]-aw);
        val3=max(ma, v[i][2]+aa-1);
        val4=max(md, v[i][3]-aa+1);
//         deb(val1+val2+1);
  //      deb(val3+val4+1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        switch(s[i]){
            case 'W':
                aw++;
                mw=max(mw, aw);
                ms=max(ms, -aw);
                break;
            case 'S':
                aw--;
                mw=max(mw, aw);
                ms=max(ms, -aw);
                break;
            case 'A':
                aa++;
                ma=max(ma, aa);
                md=max(md, -aa);
                break;
            case 'D':
                aa--;
                ma=max(ma, aa);
                md=max(md, -aa);
                break;
        }
    }
    lli i=n;
    lli val1,val2,val3,val4;
        val1=max(mw, v[i][0]+aw+1);
        val2=max(ms, v[i][1]+aw-1);
        val3=max(ma, v[i][2]+aa);
        val4=max(md, v[i][3]+aa);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw-1);
        val2=max(ms, v[i][1]+aw+1);
        val3=max(ma, v[i][2]+aa);
        val4=max(md, v[i][3]+aa);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw);
        val2=max(ms, v[i][1]+aw);
        val3=max(ma, v[i][2]+aa+1);
        val4=max(md, v[i][3]+aa-1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
        val1=max(mw, v[i][0]+aw);
        val2=max(ms, v[i][1]+aw);
        val3=max(ma, v[i][2]+aa-1);
        val4=max(md, v[i][3]+aa+1);
        ans=min(ans, (val1+val2+1)*(val3+val4+1));
    cout<<ans<<endl;

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    cin>>t;
    while(t--){
        solve();
    }
}