    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli x;
        cin>>x;
        lli s=0;
        priority_queue<lli> pq;
        while(x>0){
            s+=x%10;
            if(x<10){
                pq.push(x-1);
            }
            else{
                pq.push(x%10);
            }
            x/=10;
        }
        lli ans=0;
        while(s>=10){
            s-=pq.top();
            pq.pop();
            ans++;
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