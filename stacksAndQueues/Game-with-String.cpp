//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        int n = str.length(); 
        int freq[26] = {0};
        for(int i=0;i<n;i++)
            freq[s[i] - 'a']++;
        
        priority_queue<int> q;
            for (int i = 0; i < 26; i++)
                q.push(freq[i]);

        while(k--){
            int temp = q.top();
            q.pop();
            temp--;
            q.push(temp);
        }

        int answer = 0;
        while(!q.empty()){
            int temp = q.top();
            answer = answer + (temp * temp);
            q.pop();
        }
        return answer;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends