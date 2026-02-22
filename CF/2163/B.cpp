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
        for(lli i=0; i<n; ++i){
            cin>>v[i];
        }
        string s;
        cin>>s;
        bool pos=1;
        if(s[0]=='1') pos=0;
        if(s[n-1]=='1') pos=0;
        lli a=0, b=0;
        for(lli i=0; i<n; ++i){
            if(v[i]==1) a=i;
            if(v[i]==n) b=i;
        }
        if(s[a]=='1') pos=0;
        if(s[b]=='1') pos=0;
        a++;
        b++;
        if(pos){
            cout<<5<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<a<<endl;
            cout<<a<<" "<<n<<endl;
            cout<<1<<" "<<b<<endl;
            cout<<b<<" "<<n<<endl;
        }
        else{
            cout<<-1<<endl;
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