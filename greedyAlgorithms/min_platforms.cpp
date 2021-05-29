class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector< pair <int,char> > vect;
        for(int i=0;i<n;i++)
        {
            vect.push_back(make_pair(arr[i], 'A'));
        }
        for(int i=0;i<n;i++)
        {
            vect.push_back(make_pair(dep[i], 'D'));
        }
        sort(vect.begin(), vect.end());
        
        int max_count = 0;
        int count = 0;
        for(int i=0;i<2*n;i++){
            if(vect[i].second == 'A') count++;
            if(vect[i].second == 'D') count--;
            
            max_count = max(max_count, count);
        }
        return max_count;


    }
};