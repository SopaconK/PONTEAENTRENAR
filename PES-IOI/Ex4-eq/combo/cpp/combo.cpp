#include "combo.h"
#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<#x<<": "<<x<<endl;
string guess_sequence(int N) {
  string ans="";
  while(ans.size()<N){
    if(ans.size()==N-1){
       string aux=ans+"A"+ans+"B";
       if(press(aux)==N){
          aux=ans+"A";
          if(press(aux)==N){
            ans+="A";
          }
          else{
            ans+="B";
          }
       } 
       else{
        aux=ans+"X";
        if(press(aux)==N){
          ans+="X";
        }
        else{
          ans+="Y";
        }
       }
    }
    else if(ans.size()==0){
      string aux=ans+"A"+ans+"B";
 //     deb(aux);
   //   deb(press(aux));
       if(press(aux)>=1){
          aux=ans+"A";
          if(press(aux)==1){
            ans+="A";
          }
          else{
            ans+="B";
          }
       } 
       else{
        aux=ans+"X";
        if(press(aux)==1){
          ans+="X";
        }
        else{
          ans+="Y";
        }
       }
    }
    else{
      char c1,c2,c3;

      if(ans[0]=='A'){
        c1='B';
        c2='X';
        c3='Y';
      }
       if(ans[0]=='B'){
        c1='A';
        c2='X';
        c3='Y';
      }
       if(ans[0]=='X'){
        c1='B';
        c2='A';
        c3='Y';
      }
       if(ans[0]=='Y'){
        c1='B';
        c2='X';
        c3='A';
      }
      string aux=ans+c1+ans+c2+c1+ans+c2+c2+ans+c2+c3;
      int v=press(aux);
      if(v==ans.size()){
        ans+=c3;
      }
      else if(v==ans.size()+1){
        ans+=c1;
      }
      else{
        ans+=c2;
      }
    }
 //   cout<<ans<<endl;
  }
  return ans;
}
