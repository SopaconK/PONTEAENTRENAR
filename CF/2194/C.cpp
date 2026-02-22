    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n,k;
        cin>>n>>k;
        vector<vector<bool>> pos (n, vector<bool> (30, 0));
        for(lli i=0; i<k; ++i){
            string s;
            cin>>s;
            for(lli j=0; j<n; ++j){
                pos[j][s[j]-'a']=1;
            }
        }

        for(lli d=1; d<=n; ++d){
            if(n%d!=0) continue;
            string ans="";
            bool funciona=true;
            for(lli i=0; i<d; ++i){
                bool jala=false;
                for(lli l=0; l<30; ++l){
                    bool works=true;
                    for(lli j=i; j<n; j+=d){
                        if(!pos[j][l]){
                            works=false;
                            break;
                        }
                    }
                    if(works){
                        ans+=(l+'a');
                        jala=true;
                        break;
                    }
                }
                if(!jala){
                    funciona=false;
                    break;
                }
            }
            if(funciona){
                string s="";
                for(lli i=0; i<n/d; ++i) s+=ans;
                cout<<s<<endl;
                return;
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