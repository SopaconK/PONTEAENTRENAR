    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    using lli=long long int;
    #define deb(x) cout<<#x<<": "<<x<<endl;
    #define endl '\n'

    struct Node{
        lli val;
        lli weight; 
        lli size;
        Node *left, *right;
        Node(lli c){
            val=c;
            weight=rand();
            size=1;
            left=NULL;
            right=NULL;
        }
    };

    lli sz(Node *treap){
        if(!treap) return 0;
        return treap->size;
    }

    void split(Node *treap, Node *&left, Node *&right, int val){
        if(!treap){
            left=right=NULL;
            return;
        }

        if(sz(treap->left)<val){
            split(treap->right, treap->right, right,val-sz(treap->left)-1);
            left=treap;
        }
        else{
            split(treap->left, left, treap->left, val);
            right=treap;
        }
        treap->size=1+sz(treap->left)+sz(treap->right);
    }

    void merge(Node *&treap, Node* left, Node *right){
        if(left==NULL){
            treap=right;
            return;
        }
        if(right==NULL){
            treap=left;
            return;
        }

        if(left->weight<right->weight){
            merge(left->right, left->right, right);
            treap=left;
        }
        else{
            merge(right->left, left, right->left);
            treap=right;
        }
        treap->size=1+sz(treap->left)+sz(treap->right);
    }

    lli find(Node *treap, lli x){
        if(treap->val==x){
            return 1;
        }
        if(treap->val)
    }

    void solve(){
        lli n,m,q;
        cin>>n>>m>>q;
        segtree *tree=new segtree(1, n);
        vector<bool> vis (n+1);
        lli ans=0;
        while(q--){
            lli x;
            cin>>x;
            if(!vis[x]){
                ans+=tree->query(x);
                tree->update(x);
                vis[x]=true;
            }
        }
        cout<<ans<<endl;
    }




    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int t=1;
  //      cin>>t;
        while(t--){
            solve();
        }
    }