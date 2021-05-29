#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n = s.length();
  stack<int> st;
  for(int i=0;i<n;i++){
    if(s[i] == ')'){
      bool flag = true;
      top = st.top();
      st.pop();
      while(!st.empty() && top == '('){
          if(top == '*' || top == '+' || top == '-' || top == '/'){
            flag = false;
            top = st.top();
            st.pop();
          }
          if(flag) {
            cout<<"Yes";
            return 0;
          }
      }
    }
    else{
      st.push(s[i]);
      cout<<"No";
      return 0;
    }
  }
}
