int maxSubarraySum(int arr[], int n){
        
        int prefix_sum[n];
        prefix_sum[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        }
        int min_prefix_sum = 0;
        int max_prefix_sum=0;
        
        
        for(int i=0;i<n;i++)
        {
            max_prefix_sum = max(max_prefix_sum, prefix_sum[i] - min_prefix_sum);
            min_prefix_sum = min(min_prefix_sum, prefix_sum[i]);
        }
        return max_prefix_sum;
    }
