    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'



    void solve(){
        int n;
        cin>>n;
        vector<lli> a (n);
        vector<lli> b(n);
        for(lli i=0; i<n; ++i){
            cin>>a[i];
        }
        for(lli i=0; i<n; ++i){
            cin>>b[i];
        }
        int f=0;
        int s=0;
        int p=0;
        int ne=0;
        for(int i=0; i<n; ++i){
            if(a[i]!=b[i]){
                if(a[i]>b[i]){
                    f+=a[i];
                }
                else{
                    s+=b[i];
                }
            }
            else{
                if(a[i]==1) p++;
                if(a[i]==-1) ne++;
            }
//            deb(f);
  //          deb(s);
        }
        while(p>0){
            if(f>s) s++;
            else f++;
            p--;
    //        deb(f);
      //      deb(s);
        }
        while(ne>0){
            if(f>s) f--;
            else s--;
            ne--;
        //    deb(f);
          //  deb(s);
        }


        cout<<min(f,s)<<endl;
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