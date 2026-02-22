    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'

    lli query(lli x, lli y){
        x++;
        y++;
        cout<<"? "<<x<<" "<<y<<endl;
        lli s;
        cin>>s;
        return s;
    }

    void solve(){
        lli n;
        cin>>n;
        lli s=query(0, n-1);
        lli l=0;
        lli r=n-1;
        while(l!=r){
            
            lli a=l;
            lli b=r;
            lli goal=s/2;
            while(a!=b){
                
                lli m=(a+b)/2;
                lli aux=query(l, m);
                if(aux<goal){
                    a=m+1;
                }
                if(aux==goal){
                    a=m;
                    b=m;
                }
                if(aux>goal){
                    b=m-1;
                }
            }
            if(a-l+1 <=r-a) {
                r=a;
            }     
            else{
                l=a+1;
            }
            s/=2;
        }
        lli ans=query(l,l);
        cout<<"! "<<ans<<endl;
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