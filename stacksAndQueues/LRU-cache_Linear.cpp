class LRUCache
{
    private:
    int size;
    deque<int> q;
    map<int, int> m;
    public:
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        
         q.clear();
        m.clear();
        size = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
       if(m.find(key) == m.end()){
            return -1;
        }else{
            auto i = q.begin();
            while(*i != key){
                i++;
            }
            q.erase(i);
            q.push_front(key);
            return m[key];
        }
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
         if(m.find(key) == m.end()){
            if(q.size() == size){
                m.erase(q.back());
                q.pop_back();
            }
        }else{
            auto i = q.begin();
            while(*i!=key){
                i++;
            }
            q.erase(i);
            m.erase(key);
        }

        q.push_front(key);
        m[key] = value;

    
    }
};
