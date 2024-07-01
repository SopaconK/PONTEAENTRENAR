#include<bits/stdc++.h>
using namespace std;
#define pb push_back
using lli=long long int;
#define deb(x) ;
//#define endl '\n'


auto comp=[](pair<lli,lli> a, pair<lli,lli> b){
    if(a.first!=b.first){
        return a.first > b.first;
    }
    return a.second < b.second;
};


struct segtree{
    lli l, r;
    segtree *left, *right;
    lli sum1=0;
    lli sum2=0;
    segtree(lli a, lli b): l(a), r(b){
        if(l!=r){
            lli m=(l+r)/2;
            left=new segtree(l, m);
            right=new segtree(m+1, r);
        }
    }

    void add1(lli a, lli b, lli c){
        if(a>b) return;
        deb("sum-----------------");
        deb(a);
        deb(b);
        deb(c);
        deb(l);
        deb(r);
        if(a<=l && r<=b){
            sum1+=c;
            return;
        }
        if(r<a || b<l) return;
        left->add1(a,b,c);
        right->add1(a,b,c);
    }  

    void add2(lli a, lli b, lli c){
        if(a>b) return;
        if(a<=l && r<=b){
            sum2+=c;
            return;
        }
        if(r<a || b<l) return;
        left->add2(a,b,c);
        right->add2(a,b,c);
    }  

    lli val1(lli ind){
        if(ind<l || r<ind) return 0;
         deb(ind);
        deb(l);
        deb(r);
        deb(sum1);
        if(l==r) return sum1;
        return sum1+left->val1(ind)+right->val1(ind);
    }
    lli val2(lli ind){
        if(ind<l || r<ind) return 0;
       
        if(l==r) return sum2;
        return sum2+left->val2(ind)+right->val2(ind);
    }
};


const lli limi=15;

void solve(){
    lli n;
    cin >>n;
    vector<pair<lli,lli>> v (n);
    for(lli i=0; i<n; ++i){
        lli c,q;
        cin>>c>>q;
        v.pb({q,c});
    }
    lli k;
    cin>>k;
    vector<pair<lli,lli>> queries (k);
    for(lli i=0; i<k; ++i){
        lli ayuda;
        cin>>ayuda;
        queries[i]={ayuda, i};
    } 
    sort(v.begin(), v.end(), comp);
    sort(queries.begin(), queries.end());
    vector<lli> ans (k,0);

    lli cont=0;
 //   vector<lli> aux (k,0);
    segtree *tree= new segtree(0,k-1);
    vector<pair<lli,lli>> rangos;
    rangos.pb({0,k-1});
    for(lli asdas=0; asdas<n; ++asdas){
        cont++;
        if(cont==15){
            cont=1;
            for(lli i=0; i<k; ++i){
                ans[queries[i].second]+=tree->val1(i);
                queries[i].first-=tree->val2(i);
            }
            tree=new segtree(0,k-1);
            rangos={{0,k-1}};
            sort(queries.begin(), queries.end());
        }
        lli ini=v[asdas].second;
        vector<pair<lli,lli>> rangos2;
        deb(ini);
        for(lli i=0; i<rangos.size(); ++i){
            lli l=rangos[i].first;
            lli r=rangos[i].second;
            lli cost=ini+tree->val2(l);
            deb(l);
            deb(r);
            deb(cost);
            while(l<r-1){
                lli m=(l+r)/2;
                if(queries[m].first<cost){
                    l=m;
                }
                else{
                    r=m-1;
                }
            }
            deb(l);
            deb(r);
            deb(queries[l].first);
            deb(queries[r].first);
            if(queries[r].first<cost){
                l=r;
            }
            if(queries[l].first<cost){
                tree->add1(l+1, rangos[i].second,1 );
                tree->add2(l+1, rangos[i].second,ini);
                rangos2.pb({rangos[i].first, l});
                if(l+1<=rangos[i].second){
                    rangos2.pb({l+1,rangos[i].second});
                }
                deb("xd");
            }
            else{
               tree->add1(l, rangos[i].second,1 );
                tree->add2(l, rangos[i].second,ini);
//                rangos2.pb({rangos[i].first, l});
                if(l<=rangos[i].second){
                    rangos2.pb({l,rangos[i].second});
                }
            }
        }
        rangos=rangos2;
    }
    for(lli i=0; i<k; ++i){
            deb(queries[i].second);
            deb(tree->val1(i));
                ans[queries[i].second]+=tree->val1(i);
           //     queries[i].first-=tree->val2(i);
            }
    for(lli i=0; i<k; ++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    

}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lli t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}