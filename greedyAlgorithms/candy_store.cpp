class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int>  vect;
        sort(candies, candies + N);
        int min_count = 0;
        int n = N;
        for(int i=0;i<n;i++)
        {
            min_count = min_count + candies[i];
            n= n-K;
        }
        int max_count = 0;
        int m = 0;
        for(int i=N;i>m;i--){
            max_count = max_count + candies[i-1];
            m = m + K;
        }
        
        vect.push_back(min_count);
        vect.push_back(max_count);
        return vect;
    }
};