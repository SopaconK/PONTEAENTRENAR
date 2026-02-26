    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<lli> v (n);
        for(lli i=0; i<n; ++i) cin>>v[i];
        lli ans=0;
        stack<lli> sk;
        sk.push(-1);
        for(lli i=0; i<n; ++i){
            while(1){
                if(sk.top()==-1){
                    break;
                }
                if(v[sk.top()]>=v[i]){
                    sk.pop();
                }
                else if(v[sk.top()]<v[i]-1){
                    sk.pop();
                }
                else break;
            }
            ans+=(i-sk.top())*(n-i);
       //     deb((i-sk.top())*(n-i));
            sk.push(i);
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        while(t--){
            solve();
        }
    }