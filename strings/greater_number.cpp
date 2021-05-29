vector<int> nextPermutation(int N, vector<int> arr){
     vector<int> temp = arr;
     sort(temp.begin(), temp.end());

     if(arr == temp) {
         int tempo = arr[N-2];
         arr[N-2] = arr[N-1];
         arr[N-1] = tempo;
         return arr;
     }
     
    sort(temp.begin(), temp.end(), greater<int>());

     if(arr == temp)
     {
          sort(temp.begin(), temp.end());
         return temp;
     }

     int i,j;
     for(i=N-1;i>0;i--){
         if(arr[i] > arr[i-1]){ 
                break;
         }
     }


    int x = arr[i-1], smallest = i; 
    for (j = i+1; j < N; j++) 
        if (arr[j] > x && arr[j] < arr[smallest]) 
            smallest = j; 
  
    int tempo = arr[i-1];
    arr[i-1] = arr[smallest];
    arr[smallest] = tempo;
    sort(arr.begin() + i, arr.end()); 
    return arr;
     
     
    }