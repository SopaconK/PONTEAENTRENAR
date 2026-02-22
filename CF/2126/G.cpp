    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void printEdge(lli a, lli b){
        cout<<a<<" "<<b<<endl;
    }

    void solve(){
        lli n;
        cin>>n;
        if(n==2){
            cout<<-1<<endl;
            return;
        }
        if(n==3){
            printEdge(1,3);
            printEdge(2,3);
            return;
        }
        if(n==4){
            printEdge(1,2);
            printEdge(3,1);
            printEdge(4,1);
            return;
        }
        if(n==5){
            printEdge(1,3);
            printEdge(3,2);
            printEdge(3,4);
            printEdge(3,5);
            return;
        }

        lli s=((n)*(n+1))/2;
        s--;
        lli x=sqrt(s);
        if(x*x==s){
            for(lli i=2; i<=n; ++i){
                printEdge(1,i);
            }
            return;
        }
        x++;
        lli d=x*x-s;
        if(d<=2){
            x++;
            d=x*x-s;
        }
        if(d<=n){
            for(lli i=2; i<=n; ++i){
                if(i==d) continue;
                printEdge(1,i);
            }
            printEdge(2,d);
            return;
        }
        else{
            lli x=-1;
            lli y=-1;
            for(lli i=3; i<=n; ++i){
                if(d-i<=n && d-i!=i && d-i>2){
                    x=i;
                    y=d-i;
                    break;
                }
            }
            for(lli i=2; i<=n; ++i){
                if(i==x || i==y) continue;
                printEdge(1,i);
            }
            printEdge(2,x);
            printEdge(2,y);
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