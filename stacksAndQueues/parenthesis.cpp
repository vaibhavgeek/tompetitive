class Solution{
  public:
    // Function to return if the paranthesis are balanced or not
    bool ispar(string x)
    {
        stack<char> s;
        char temp;
        for(int i = 0;i<x.length();i++){
            if(x[i] == '(' || x[i] == '[' || x[i] == '{'){
                s.push(x[i]);
                continue;
            }
            
            if(s.empty()) return false;
            
            if( x[i] == ')'){
                temp = s.top();
                s.pop();
                if(temp == '{' || temp == '[')
                    return false;
            }
            
            if( x[i] == '}'){
                temp = s.top();
                s.pop();
                if(temp == '(' || temp == '[')
                    return false;
            }
            
            
            if( x[i] == ']'){
                temp = s.top();
                s.pop();
                if(temp == '{' || temp == '(')
                    return false;
            }
            
            
        }
        if(s.empty()) return true;

    }

};