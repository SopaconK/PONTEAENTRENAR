    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        lli n2=n;
        while(n2%2==0){
            n2/=2;
        }
        if(n2==1){
            cout<<-1<<endl;
            return;
        }
        vector<lli> ans (n+1);
        if(n%2==1){
        
        ans[n-1]=1;
        ans[n]=1^(n-1);
        vector<bool> used (n+1,0);
        for(lli i=2; i<n-1; ++i){
            ans[i]=1^i;
        }
       
            ans[1]=n-1;
        
        }
        else{
           ans[n-1]=n;
           ans[n]=n^(n-1);
           lli powtwo=1;
           while(powtwo<=n){
            powtwo*=2;
           }
           powtwo/=2;
           for(lli i=powtwo; i<n-1; ++i){
            ans[i]=i^(n);
            ans[i^n]=i;
           }
           ans[n^(n-1)]=n-1;
           for(lli i=1; i<n; ++i) 
           {if(ans[i]==0){ans[i]=i;}
            else{
                break;
            }
            }
            for(lli i=1; i<n; ++i){
                if(ans[i]==0){
                    ans[i]=i^ans[n];
                }
            }
        }
        for(lli i=1; i<=n; ++i){
            cout<<ans[i]<<" ";
        }
        
        cout<<endl;
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