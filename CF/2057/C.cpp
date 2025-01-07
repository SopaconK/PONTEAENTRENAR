    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
 //   #define endl '\n'


    void solve(){
        lli l,r;
        cin>>l>>r;
        vector<lli> v1;
        vector<lli> v2;
        lli a=r;
        lli b=0;
        lli c=0;
        lli ind=0;
        while(r>0){
            ind++;
            r/=2;
        }
        r=a;
        a=0;
       ind--;
        

        while(ind>=0){
            lli xd=1<<ind;
        //    deb(xd);
           bool b1=(a+xd<=r);
           bool b2=(a+xd-1>=l+2);
           bool b3=(b+xd<=r-1);
           bool b4(b+xd-1>=l+1);
           bool b5=(c+xd<=r-2);
           bool b6=(c+xd-1>=l);
           bool c1=0;
           bool c2=0;
           bool c3=0;
           bool st1=0;
           bool st2=0;
           bool st3=0;
       
           if(!b1){
            c1=1;
           }
           else{
            if(!b2){
                st1=1;
                a+=xd;
                c1=1;
            }
           }
           if(!b3){
            c2=1;
           }
           else{
            if(!b4){
                st2=1;
                b+=xd;
                c2=1;
            }
           }
           if(!b5){
            c3=1;
           }
           else{
            if(!b6){
                st3=1;
                c+=xd;
                c3=1;
            }
           }
           lli no=st1+st2+st3;
            if(!c1){
                if(no<2){
                    a+=xd;
                    no++;
                }
            }
            if(!c2){
                if(no<2){
                    b+=xd;
                    no++;
                }
            }
            if(!c3){
                if(no<2){
                    c+=xd;
                    no++;
                }
            }
           
            ind--;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
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