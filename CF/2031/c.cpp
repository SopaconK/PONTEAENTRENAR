    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        if(n%2==0){
            for(lli i=1; 2*i<=n; ++i){
                cout<<i<<" "<<i<<" ";
            }
            cout<<endl;
        }
        else{
            if(n<=25){
                cout<<-1<<endl;
            }
            else{
                vector<lli> ans (n+1, -1);
                for(lli i=1; i<=9; ++i){
                    ans[i]=i;
                    ans[i+9]=i;
                }
                ans[19]=10;
                ans[20]=10;
                ans[21]=11;
                ans[22]=11;
                ans[23]=12;
                ans[24]=13;
                ans[25]=13;
                ans[26]=1;
                ans[27]=12;
                lli cont=14;
                for(lli i=28; i<=n; ++i){
                    if(i%2==0){
                        ans[i]=cont;
                    }
                    else{
                        ans[i]=cont;
                        cont++;
                    }
                }
                for(lli i=1; i<=n; ++i){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;

            }
        }
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