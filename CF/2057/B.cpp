    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        map<lli,lli> mp;
        for(lli i=0; i<n; ++i){
            lli a;
            cin>>a;
            mp[a]++;
        }
        priority_queue<lli, vector<lli>, greater<lli>> pq;
        lli ans=0;
        for(auto a: mp){
            if(a.second>0){
                pq.push(a.second);
                ans++;
            }
        }
        while(k){
            if(pq.size()>1){
                if(k>=pq.top()){
                    k-=pq.top();
                    pq.pop();
                    ans--;
                }
                else break;
            }
            else break;
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