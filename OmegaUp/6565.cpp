#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;

#define endl '\n'
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
const lli SQ=783;
struct segtree{
    lli l,r;
    segtree *left, *right;
    lli maxi=-1;
    segtree (lli a, lli b, vector<lli> &val): l(a), r(b){
 //       deb(l);
   //     deb(r);
        if(a==b){
            if(0<=a && a<val.size()){
                maxi=val[a];
    //            deb(a);
      //          deb(val[a]);
            }
        }
        else{
            lli m=(l+r)/2;
            if(m==r) m--;
            left=new segtree(l,m,val);
            right=new segtree(m+1,r,val);
            maxi=max(left->maxi, right->maxi);
        }
    }
    lli query(lli a, lli b){
//        deb(a);
  //      deb(b)
    //    deb(l);
      //  deb(r);
        //deb(maxi);
        if(a<=l && r<=b) return maxi;
        if(r<a || b<l) return -1;
        return max(left->query(a,b), right->query(a,b));
    }
    void update(lli p, lli v){
        if(l==r) {
            maxi=v;
            return;
        }
        lli m=(l+r)/2;
        if(p<=m) left->update(p,v);
        else right->update(p,v);
        maxi=max(left->maxi, right->maxi);
    }
};

struct Node{
    lli val;
    Node *last, *next;
};

struct Block{
    lli l,r;
    Node *f,*u;
    lli init=0;
    lli fin=0;
    vector<lli> pared;
    segtree *st;
};

void rebuild(vector<Block*> &bloques){
    for(Block* b: bloques){
        if(b->fin>=2*SQ || b->init<=-SQ){
            vector<lli> v;
            lli cont=b->init;
            Node* act=b->f;
            while(cont<=b->fin){
                v.pb(act->val);
                act=act->next;
                cont++;
            }
            b->fin-=b->init;
            b->init=0;
            
            b->st=new segtree(-SQ, 2*SQ, v);
        }
    }
}


void solve(){
    lli n;
    cin>>n;
    vector<lli> values (n);
    for(lli i=0; i<n; ++i){
        cin>>values[i];
    }
    vector<Block*> bloques;
    while(bloques.size()*SQ <n){
//        deb(bloques.size());
        Block* aux=new Block();
        aux->l=bloques.size()*SQ;
        aux->r=aux->l+SQ-1;
        aux->f=new Node();
        Node* act=aux->f;
        vector<lli> v;
        for(lli i=aux->l; i<=min(n-1, aux->r); ++i){
  //          deb(i);
            act->val=values[i];
            act->next= new Node();
            act->next->last=act;
            act=act->next;
            v.pb(values[i]);
        }
        for(lli i=min(n-1, aux->r)+1; i<=aux->r; ++i){
            act->val=-1;
            act->next= new Node();
            act->next->last=act;
            act=act->next;
          //  v.pb(values[i]);
        }
        act->val=-1;
        aux->u=act->last;
        aux->fin=aux->r-aux->l;
    //    deb("xd");
        aux->st=new segtree(-SQ, 2*SQ, v);
        bloques.pb(aux);
    }
    
    lli Q;
    cin>>Q;
    while(Q--){
        lli type;
        cin>>type;
    //    deb(type);
        if(type==0){
            lli p1,p2;
            cin>>p1>>p2;
      //      deb(p1);
        //    deb(p2);
            lli ans=-1;
            for(Block* b: bloques){
                lli x=max(b->l, p1);
                lli y=min(b->r, p2);
     //           deb(x);
       //         deb(y);
         //       deb(b->init);
                if(x<=y){
                    ans=max(ans, b->st->query(x-b->l+b->init,y-b->l+b->init));
                }
          //      deb(ans);
            }
            cout<<ans<<endl;
        }
        else if(type==1){
            lli p;
            cin>>p;
            bool mv=false;
            for(lli ind=0; ind<bloques.size(); ++ind){
                Block* b=bloques[ind];
                if(b->l<=ind && ind<=b->r ){
                    lli pos=1e9;
                    for(lli x: b->pared){
                        if(x>=p){
                            pos=x;
                            break;
                        }
                    }
           //         deb(pos);
                    lli cont=b->l;
                    Node* act=b->f;
                    bool chng=false;
                    while(cont<b->l+b->fin-b->init){
             //           deb(cont);
                        if(cont==pos){
                            act->val=-1;
                            b->st->update(cont-b->l+b->init, -1);
                            chng=false;
                        }
                        else if(cont==p){
                            act->val=act->next->val;
                            b->st->update(cont-b->l+b->init, act->val);
                            chng=true;
                        }
                        else if(chng && cont<b->l+b->fin-b->init){
                            act->val=act->next->val;
                            b->st->update(cont-b->l+b->init, act->val);
                        }

               //         deb(act->val);
                        cont++;
                        act=act->next;
                    }
                    if(cont==p){
                        chng=true;
                    }
                    if(chng){
                        if(ind<bloques.size()-1){
                            act->val=bloques[ind+1]->f->val;
                            b->st->update(cont-b->l+b->init, act->val);
                            mv=true;
                        }
                        else{
                            act->val=-1;
                            b->st->update(cont-b->l+b->init, act->val);
                        }
                    }
                 //   deb(act->val);
                }
                else if(mv){
                    Block* b=bloques[ind];
                   // deb(ind);
                  //  deb(b->pared.size());
                    if(b->pared.size()==0){
                        b->init++;
                        b->fin++;
                        b->f=b->f->next;
                        b->u->next=new Node();
                        b->u=b->u->next;
                        if(ind <bloques.size()-1){
                            b->u->val=bloques[ind+1]->f->val;
                            b->st->update(b->fin, b->u->val);
                        }
                        else{
                             b->u->val=-1;
                            b->st->update(b->fin, b->u->val);
                        }
                    }
                    else{
                        mv=false;
                        lli pos=b->pared[0];
                        Node* act=b->f;
                        lli cont=b->l;
                        while(cont<pos){
                            act->val=act->next->val;
                            b->st->update(cont-b->l+b->init, act->val);
                            cont++;
                            deb(act->val);
                            act=act->next;
                        }
                        act->val=-1;
 //                       deb(act->val);
                         b->st->update(cont-b->l+b->init, act->val);
                    }
                }
            }
            rebuild(bloques);
        }
        else if(type==2){
            lli p1,p2;
            cin>>p1>>p2;
            lli ind=(p1)/SQ;
            lli ind2=(p2)/SQ;
   //         deb(ind);
     //       deb(ind2);

            if(p1<=p2){
                if(ind==ind2){
                    Block *b=bloques[ind];
                    lli cont=b->l;
                    lli val;
                    Node* act=b->f;
                    bool chng=false;
                    while(cont<=p2){
                        if(cont==p1){
                            val=act->val;
                            chng=true;
                        }
                        if(cont==p2){
                            act->val=val;
                             b->st->update(cont-b->l+b->init, act->val);
                            chng=false;
                        }
                        if(chng){
                            act->val=act->next->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
                        cont++;
                        act=act->next;
                    }
                }
                else{
                    
                    
                    Block *b=bloques[ind];
                    lli cont=b->l;
                    lli val;
                    Node* act=b->f;
                    bool chng=false;
                    while(cont<b->r){
                        if(cont==p1){
                            val=act->val;
                            chng=true;
                        }
                        if(chng){
                            act->val=act->next->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
                        cont++;
                        act=act->next;
                    }
                     act->val=bloques[ind+1]->f->val;
                    b->st->update(cont-b->l+b->init, act->val);
                    for(lli indi=ind+1; indi<ind2; ++indi){
                        b=bloques[indi];
                        b->init++;
                        b->fin++;
                        b->f=b->f->next;
                        b->u->next=new Node();
                        b->u=b->u->next;
                        
                            b->u->val=bloques[indi+1]->f->val;
                            b->st->update(b->fin, b->u->val);
                       
                    }
                    b=bloques[ind2];
                    cont=b->l;
                    act=b->f;
  //                  bool chng=false;
                    while(cont<=p2){
                        if(cont==p2){
                            act->val=val;
                             b->st->update(cont-b->l+b->init, act->val);
                            chng=false;
                        }
                        if(chng){
                            act->val=act->next->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
                        cont++;
                        act=act->next;
                    }
                }
            }
            else{
                if(ind==ind2){
                    Block *b=bloques[ind];
                    lli cont=b->r;
                    lli val;
                    Node* act=b->u;
                    bool chng=false;
                    while(cont>=p2){
             //           deb(cont);
                        if(cont==p1){
                            val=act->val;
                            chng=true;
                        }
                        if(cont==p2){
                            act->val=val;
                             b->st->update(cont-b->l+b->init, act->val);
                            chng=false;
                        }
                        if(chng){
                            act->val=act->last->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
                        cont--;
                        act=act->last;
                    }
                }
                else{
                    
                    
                    Block *b=bloques[ind];
                    lli cont=b->r;
                    lli val;
                    Node* act=b->u;
                    bool chng=false;
                    while(cont>b->l){

                        if(cont==p1){
                            val=act->val;
                            chng=true;
                        }
                        if(chng){
                            act->val=act->last->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
       //                 deb(act->val);
                        cont--;
                        act=act->last;
                    }
                    if(cont==p1){
                            val=act->val;
                            chng=true;
                    }
                     act->val=bloques[ind-1]->u->val;
         //            deb(act->val);
                    b->st->update(cont-b->l+b->init, act->val);
                    for(lli indi=ind-1; indi>ind2; --indi){
                        b=bloques[indi];
                        b->init--;
                        b->fin--;
                        b->u=b->u->last;
                        b->f->last=new Node();
                        b->f=b->f->last;
                    
                            b->f->val=bloques[indi-1]->u->val;
                            b->st->update(b->init, b->f->val);
                       
       //                 deb(b->u->val);
         //               deb(b->f->val);
                    }
                    b=bloques[ind2];
                    cont=b->r;
                    act=b->u;
//                    bool chng=false;
                    while(cont>=p2){
           //             deb(cont);
                        if(cont==p2){
                            act->val=val;
                             b->st->update(cont-b->l+b->init, act->val);
                            chng=false;
                        }
                        if(chng){
                            act->val=act->last->val;
                             b->st->update(cont-b->l+b->init, act->val);
                        }
             //           deb(act->val);
                        cont--;
                        act=act->last;
                    }
               //     deb(act->val);
                }   
            }

            rebuild(bloques);
        }
        else if(type==3){
            lli p;
            cin>>p;
            lli ind=(p)/SQ;
            //deb(ind);
            bloques[ind]->pared.pb(p-bloques[ind]->l);
            sort(bloques[ind]->pared.begin(), bloques[ind]->pared.end());
        }
    }
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