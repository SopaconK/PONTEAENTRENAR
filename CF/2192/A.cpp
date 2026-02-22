    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n;
        string s;
        cin>>n>>s;
        if(n==1){
            cout<<1<<endl;
            return; 
        }
        lli c=s[0];
        lli tm=1;
        lli tmmx=1;
        lli cant=1;
        for(lli i=1; i<n; ++i){
            if(s[i]!=c){
                c=s[i];
                tm=1;
                cant++;
            }
            else{
                tm++;
                tmmx=max(tm, tmmx);
            }
        }
        if(s[0]==s[n-1]){
            cout<<cant<<endl;
            return;
        }
        if(tmmx==1){
            cout<<cant<<endl;
            return;
        }
        cout<<cant+1<<endl;
        return;
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