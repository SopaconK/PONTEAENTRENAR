    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        vector<pair<lli,lli>> z;
        vector<pair<lli,lli>> w;
        for(lli i=0; i<n; ++i){
            string s;
            cin>>s;
            string s2;
            cin>>s2;
            lli ini=0;
            lli fin=0;
            if(s2[1]==':'){
                ini+=(s2[0]-'0')*60;
                ini+=(s2[2]-'0')*10+(s2[3]-'0');
                if(s2[7]==':'){
                    fin+=(s2[6]-'0')*60;
                    fin+=(s2[8]-'0')*10+(s2[9]-'0');
                }
                else{
                    fin+=((s2[6]-'0')*10+(s2[7]-'0'))*60;
                fin+=(s2[9]-'0')*10+(s2[10]-'0');
                }
            }
            else{
                ini+=((s2[0]-'0')*10+(s2[1]-'0'))*60;
                ini+=(s2[3]-'0')*10+(s2[4]-'0');
            //     deb(s2[8]);
                 if(s2[8]==':'){
                    fin+=(s2[7]-'0')*60;
                    fin+=(s2[9]-'0')*10+(s2[10]-'0');
                }
                else{
                    fin+=((s2[7]-'0')*10+(s2[8]-'0'))*60;
                fin+=(s2[10]-'0')*10+(s2[11]-'0');
                }
            }
           
            if(fin<ini){
                    fin+=1440;
            }
            
            if(s[0]=='Z'){
                
                
                z.pb({ fin, ini});
      //          z.pb({ fin+1440, ini+1440});
        //        z.pb({ fin+2880, ini+2880});
            }
            else{
                w.pb({ini,fin});
                w.pb({ini+1440, fin+1440});
            //     w.pb({ini+2880, fin+2880});
            }
        }

        sort(z.begin(), z.end());
        sort(w.begin(), w.end());

        lli inimax=-1;
        lli punt=0;
        lli ans=10000000000;
        for(lli i=0; i<w.size(); ++i){
       //     deb(z[punt].first);
         //   deb(w[i].first);
            while(punt<z.size() && z[punt].first < w[i].first){
                inimax=max(inimax, z[punt].second);
                punt++;
            }
           // deb(inimax);
            if(inimax!=-1){
                ans=min(ans, w[i].second-inimax);
             //   deb(inimax);
               // deb(w[i].second);
            }

        }
        if(ans==10000000000){
            cout<<"NEMOGUCE"<<endl;
        }
        else{
            ans++;
            lli hora=ans/60;
            lli min=ans%60;
            cout<<hora<<":"<<min<<endl;
        }
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        solve();
        
    }