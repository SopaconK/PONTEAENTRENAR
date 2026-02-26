    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    vector<vector<lli>> pd;

    void criba(){
        vector<bool> nums (2e6+7,1);
        nums[1]=0;
        nums[0]=0;
        pd.resize(2e6+7);
        for(lli i=2; i<nums.size(); ++i){
            if(!nums[i]) continue; 
            pd[i].pb(i);
            for(lli j=2*i; j<nums.size(); j+=i){
                nums[j]=0;
                pd[j].pb(i);
            }
        }
    }
    void solve(){
        lli n,m;
        cin>>n>>m;
        vector<lli> a (n);
        vector<lli> b (m);
        vector<bool> v (n+m+1,0);
        for(lli i=0; i<n; ++i){
            cin>>a[i];
            v[a[i]]=1;
        }
        for(lli i=0; i<m; ++i) cin>>b[i];
        for(lli i=1; i<=n+m; ++i){
            if(v[i]) continue;
            for(lli x: pd[i]){
                if(v[i/x]){
                    v[i]=1;
                    break;
                }
            }
        }
        
        lli d=1;
        for(lli i=0; i<n; ++i){
            d=lcm(d, a[i]);
        }
        lli x=0;
        lli y=0;
        lli z=0;
        for(lli i=0; i<m; ++i){
            if(v[b[i]]){
                if(b[i]%d==0){
                    y++;
                }
                else{
                    x++;
                }
            }
            else{
                z++;
            }
        }

        lli alice=(x+1)/2;
        alice+=y;
        lli bob=x/2;
        bob+=z;
        if(alice>bob){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
        cin>>t;
        criba();
        while(t--){
            solve();
        }
    }