class Solution {
  public:
    int findMaxLen(string s) {
     stack<long long int> stk;
        stk.push(-1);
        long long int result = 0;
        long long int n = str.length();
        for(long long int i =0;i<n;i++){
            if(str[i] == '('){
                stk.push(i);
            }
            else if(str[i] == ')')
            {
                if(!stk.empty()){
                    stk.pop();
                }
                
                if(!stk.empty())
                 result = max(result, i - stk.top());
                else stk.push(i);
                
            }
        }
        
        return result;
    }
};
