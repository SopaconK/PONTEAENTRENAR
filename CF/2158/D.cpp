    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    //#define endl '\n'


    void solve(){
        lli n;
        cin>>n;
        string s1,t1;
        cin>>s1>>t1;
        vector<bool> s (n);
        vector<bool> t (n);
        for(lli i=0; i<n; ++i){
            s[i]=(s1[i]=='1');
            t[i]=(t1[i]=='1');
        }
        vector<pair<lli,lli>> mov1;
        vector<pair<lli,lli>> mov2;
        lli ind=-1;
        for(lli i=0; i<n-1; ++i){
            if(s[i]==s[i+1]) ind=i;
        }
        if(ind==-1){
            mov1.pb({2,4});
            s[1]=!s[1];
            s[2]=!s[2];
            s[3]=!s[3];
            ind=0;
        }
        lli l=ind; 
        lli r=ind+1;
        while(l!=0 || r!=n-1){
           
            while(l>0 && s[l-1]==s[l]) l--;
            while(r<n-1 && s[r+1]==s[r])r++;
            if(l!=0 || r!=n-1){
                mov1.pb({l+1, r+1});
                for(lli i=l; i<=r; ++i) s[i]=!s[i];
            }
        }
        if(s[0]==1){
            mov1.pb({1, n});
        }


        ind=-1;
        for(lli i=0; i<n-1; ++i){
            if(t[i]==t[i+1]) ind=i;
        }
        if(ind==-1){
            mov2.pb({2,4});
            t[1]=!t[1];
            t[2]=!t[2];
            t[3]=!t[3];
            ind=0;
        }
        l=ind; 
        r=ind+1;
        while(l!=0 || r!=n-1){
           
            while(l>0 && t[l-1]==t[l]) l--;
            while(r<n-1 && t[r+1]==t[r])r++;
            if(l!=0 || r!=n-1){
                mov2.pb({l+1, r+1});
               for(lli i=l; i<=r; ++i) t[i]=!t[i];
            }
        }
        if(t[0]==1){
            mov2.pb({1, n});
        }

        lli cant=mov1.size()+mov2.size();
        cout<<cant<<endl;
        for(lli i=0; i<mov1.size(); ++i){
            cout<<mov1[i].first<<" "<<mov1[i].second<<endl;
        }
        for(lli i=mov2.size()-1; i>=0; --i){
            cout<<mov2[i].first<<" "<<mov2[i].second<<endl;
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