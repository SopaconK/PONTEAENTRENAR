#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back
#define deb(x) cout<<#x<<": "<<x<<endl;
#define endl '\n'

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
mt19937 rnd(112);

struct Node{
    lli val, weight, sz;
    lli maxi;
    Node *left, *right;
    Node (lli v):val(v), maxi(v), weight(rnd()), sz(1), left(NULL), right(NULL){} 
};

lli size (Node *t){
    if(!t) return 0;
    return t->sz;
}

lli maxim(Node *t){
    if(!t) return -1;
    return t->maxi;
}

void split (Node *treap, Node *&left, Node *&right, lli val){
    if(!treap){
        left=right=NULL;
        return;
    }
    if(size(treap->left)< val){
        split(treap->right, treap->right, right, val-size(treap->left)-1);
        left=treap;
    }
    else{
        split(treap->left, left, treap->left, val);
        right=treap;
    }
    treap->maxi=max(treap->val, maxim(treap->left));
    treap->maxi=max(treap->maxi, maxim(treap->right));
    treap->sz=1+size(treap->left)+size(treap->right);
}

void merge(Node *&treap, Node *left, Node *right) {
//	deb("hi");
  //  deb(size(treap));
    if (left == NULL) {
      //  deb("hi");
		treap = right;
		return;
	}
	if (right == NULL) {
		treap = left;
		return;
	}

	if (left->weight < right->weight) {
		merge(left->right, left->right, right);
		treap = left;
	} else {
		merge(right->left, left, right->left);
		treap = right;
	}
    treap->maxi=max(treap->val, maxim(treap->left));
    treap->maxi=max(treap->maxi, maxim(treap->right));

	treap->sz = 1 + size(treap->left) + size(treap->right);
}

void insert(Node *&treap, lli pos, lli val){
    Node *a, *b;
    split(treap, a,b,pos-1);
    Node *aux= new Node(val);
    merge(a,a,aux);
    merge(a,a,b);
    treap=a;
}

void del(Node *&treap, lli pos){
    Node *a,*b,*c;
    split(treap, a, b, pos-1);
    split(b, b,c,1);
    merge(treap,a,c);
}

lli query(Node *&treap, lli l, lli r){
    Node *a, *b, *c;
    split(treap, a,b, l-1);
    split(b, b,c, r-l+1);
    lli ans= maxim(b);
    merge(a,a,b);
    merge(treap,a,c);
    return ans;
}

lli valor(Node *treap, lli pos){
 //   deb(pos);
   // deb(treap->val);
  //  deb(size(treap));
  //  deb(size(treap->left));
    
    if(size(treap->left)==pos-1) return treap->val;
    if(size(treap->left)>=pos) return valor(treap->left, pos);
    return valor(treap->right, pos-size(treap->left)-1);
}
void solve(){
    lli n;
    cin>>n;
    for(lli i=0; i<n; ++i){
        cout<<rnd()<<endl;
    }
    Node *tr=new Node(-1);
    for(lli i=0; i<n; ++i){
        lli x;
        cin>>x;
        
        Node *aux =new Node(x);
        merge(tr, tr, aux);

    }
    del(tr, 0);
    set<lli> pared;
    pared.insert(n);
    lli Q;
    cin>>Q;
    while(Q--){
        lli type;
        cin>>type;
       
        if(type==0){
            lli l,r;
            cin>>l>>r;
            l++;
            r++;
            cout<<query(tr, l,r)<<endl;
        }
        else if(type==1){
            lli p;
            cin>>p;
            p++;
            lli val=*pared.lower_bound(p);
            del(tr, p);
            insert(tr, val, -1);
        }
        else if(type==2){
            lli a,b;
            cin>>a>>b;
            a++;
            b++;
            lli v=valor(tr, a);
            del(tr, a);
            insert(tr, b, v);
        }
        else{
            lli p;
            cin>>p;
            p++;
            pared.insert(p);
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