#include "dna.h"
#include<bits/stdc++.h>
using namespace std;
using lli=long long int;
#define pb push_back;


vector<lli> A1;
vector<lli> C1;
vector<lli> T1;
vector<lli> A2;
vector<lli> C2;
vector<lli> T2;
vector<lli> v1;
vector<lli> v2;
vector<lli> v3;
vector<lli> v4;
vector<lli> v5;
vector<lli> v6;

void init(string a, string b){
    lli n=a.size();
    A1.resize(n,0);
    C1.resize(n,0);
    T1.resize(n,0);
    A2.resize(n,0);
    C2.resize(n,0);
    T2.resize(n,0);
    v1.resize(n,0);
    v2.resize(n,0);
    v3.resize(n,0);
    v4.resize(n,0);
    v5.resize(n,0);
    v6.resize(n,0);

    for(lli i=0; i<n; ++i){
        if(i>0){
            A1[i]=A1[i-1];
            C1[i]=C1[i-1];
            T1[i]=T1[i-1];
            A2[i]=A2[i-1];
            C2[i]=C2[i-1];
            T2[i]=T2[i-1];
            v1[i]=v1[i-1];
            v2[i]=v2[i-1];
            v3[i]=v3[i-1];
            v4[i]=v4[i-1];
            v5[i]=v5[i-1];
            v6[i]=v6[i-1];
        }
        if(a[i]=='A'){
            A1[i]++;
            if(b[i]=='A'){
                A2[i]++;
            }
            if(b[i]=='C'){
                v1[i]++;
                C2[i]++;
            }
            if(b[i]=='T'){
                v2[i]++;
                T2[i]++;
            }
        }
        if(a[i]=='C'){
            C1[i]++;
            if(b[i]=='A'){
                v3[i]++;
                A2[i]++;
            }
            if(b[i]=='C'){
                
                C2[i]++;
            }
            if(b[i]=='T'){
                v4[i]++;
                T2[i]++;
            }
        }
        if(a[i]=='T'){
            T1[i]++;
            if(b[i]=='A'){
                v5[i]++;
                A2[i]++;
            }
            if(b[i]=='C'){
                v6[i]++;
                C2[i]++;
            }
            if(b[i]=='T'){
                T2[i]++;
            }
        }
    }

}



int get_distance(int x, int y){
    if(x==0){
        if(A1[y]!=A2[y]) return -1;
        if(C1[y]!=C2[y]) return -1;
        if(T1[y]!=T2[y]) return -1;
        
    }
    else{
        if(A1[y]-A1[x-1]!=A2[y]-A2[x-1]) return -1;
        if(C1[y]-C1[x-1]!=C2[y]-C2[x-1]) return -1;
        if(T1[y]-T1[x-1]!=T2[y]-T2[x-1]) return -1;
    }
    int x1,x2,x3,x4,x5,x6;
    if(x==0){
        x1=v1[y];
        x2=v2[y];
        x3=v3[y];
        x4=v4[y];
        x5=v5[y];
        x6=v6[y];
    }
    else{
         x1=v1[y]-v1[x-1];
        x2=v2[y]-v2[x-1];
        x3=v3[y]-v3[x-1];
        x4=v4[y]-v4[x-1];
        x5=v5[y]-v5[x-1];
        x6=v6[y]-v6[x-1];
    }

    int ans=0;
    int a=min(x1,x3);
    int b=min(x2,x5);
    int c=min(x4,x6);
    ans=a+b+c;
    x1-=a;
    x2-=b;
    x3-=a;
    x4-=c;
    x5-=b;
    x6-=c;
    int s=x1+x2+x3+x4+x5+x6;
    s/=3;
    s*=2;
    ans+=s;
    return ans;
    

}