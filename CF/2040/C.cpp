    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'


    void solve(){
        lli n, k;
        cin>>n>>k;
        queue<lli> q;
        stack<lli> sk;
        stack <lli> pot;
        lli powtwo=1;
        pot.push(powtwo);
        pot.push(powtwo);
        for(lli i=1; i<n-1; ++i){
            powtwo*=2;
      //      deb(powtwo);
        //    deb(k);
            powtwo=min(k+1, powtwo);
            pot.push(powtwo);
        }
        if(n==1){
            if(k==1){
                cout<<1<<endl;
                return;
            }
            cout<<-1<<endl;
            return;
        }
        if(2*powtwo<k){
            cout<<-1<<endl;
            return;
        }
        lli act=0;
     
        for(lli i=1; i<=n; ++i){
            lli xd=pot.top();
            pot.pop();
            if(k<=xd){
                q.push(i);
            }
            else{
                sk.push(i);
                k-=xd;
            }
        }
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        while(!sk.empty()){
            cout<<sk.top()<<" ";
            sk.pop();
        }

    
        
        cout<<endl;


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