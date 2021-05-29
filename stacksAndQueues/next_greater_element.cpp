 vector<long long> nextLargerElement(vector<long long> arr, int n){
        deque<long long int> window(n);
        vector<long long int> vec(n,0);
        
        for(int i = 0;i<n;i++){
            if(window.empty()){
                window.push_back(i);
            }
            
            while(!window.empty() && arr[i] > arr[window.back()]){
                vec[window.back()] = arr[i];
                window.pop_back();
            }
            window.push_back(i);
        }
        
        while(!window.empty()){
            vec[window.back()] = -1;
            window.pop_back();
        }
        return vec;
    }
