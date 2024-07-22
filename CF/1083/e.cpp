#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
using lli=long long int;
using ld=long double;



struct rect{
    lli p; 
    lli q;
    lli a;
};

bool cmp(rect a, rect b){
    return a.p >b.p;
};
struct line{
    lli m;
    lli b;
    lli eval (lli x){
        return m*x+b;
    }
    ld intersect (line l){
        return (ld) (l.b-b)/(m-l.m);
    }

};
void solve(){
    lli n;
    cin>>n;
    vector<rect> rects;
    for(lli i=0; i<n; ++i){
        lli x,y,a;
        cin>>x>>y>>a;
        rects.pb({x,y,a});
    }
    sort(rects.begin(), rects.end(), cmp);
    deque<line> dq;
    dq.push_back({0,0});
    lli ans=0;
    for(lli i=n-1; i>=0; --i){
      
        while(dq.size()>=2 && dq.back().eval(rects[i].q)<=dq[dq.size()-2].eval(rects[i].q)){
            dq.pop_back();
        }
        lli f=dq.back().eval(rects[i].q)+rects[i].p*rects[i].q-rects[i].a;
        ans=max(ans, f);
        line aux={-rects[i].p, f};
        while(dq.size()>=2 && aux.intersect(dq[0]) >=dq[0].intersect(dq[1])){
            dq.pop_front();
        }
        dq.push_front(aux);
    }
    cout<<ans<<endl;
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