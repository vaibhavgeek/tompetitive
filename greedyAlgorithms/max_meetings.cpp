bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
        {
            return (a.second < b.second);
        }
class Solution{
    public:
        
        int maxMeetings(int start[], int end[], int n) {
        
        vector< pair <int,int> > vect;
        for(int i=0;i<n;i++){
            vect.push_back( make_pair(start[i],end[i]) );
        }
        sort(vect.begin(), vect.end(), sortbysec);
        vector< pair <int,int> > result;
        result.push_back(make_pair(vect[0].first, vect[0].second));
        
        int count = 1;
        int j = 1;
        for(int i=1;i<n;i++){

            if(vect[i].first > result[j-1].second){
                count++;
                j++;
                result.push_back(make_pair(vect[i].first, vect[i].second));

            }
        }
        return count;

    }
};