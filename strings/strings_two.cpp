#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t>0){
            string str;
            cin>>str;
            int k = str.length();
            int arraystr1[25] = {0};
            int arraystr2[25] = {0};
            if(k%2 == 0)
            {
                for(int j=0;j<k/2;j++)
                {
                    int aaa = (int)str[j];
                    int index = aaa - 96;
                    arraystr1[index]++;
                }
                for(int p=k/2;p<k;p++)
                {
                    int bbb = (int)str[p];
                    int  index2 = bbb - 96;
                    arraystr2[index2]++;
                }
            }
             else
            {
                for(int q=0;q<k/2;q++)
                {
                     int aaa = (int)str[q];
                    int index = aaa - 96;
                    arraystr1[index]++;
                }
                for(int t=(k/2 + 1);t<k;t++)
                {
                     int bbb = (int)str[t];
                    int  index2 = bbb - 96;
                    arraystr2[index2]++;
                }
            } 
            for(int h=0;h<25;h++)
            {
                if(arraystr1[h] == arraystr2[h])
                {
                    if(h==24)
                     { cout<<"YES"<<endl; }
                }
                else if(arraystr1[h] != arraystr2[h])
                {
                    cout<<"NO"<<endl;
                    break;
                }
            }
            t--;
        }
}
