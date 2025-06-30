// https://leetcode.com/problems/number-of-recent-calls/


class RecentCounter {
public:
    queue<int>q; 
    RecentCounter() {
        int counter = 0 ; 
    }
    int ping(int t) {
        if(q.empty()){
            q.push(t) ;
            return 1 ; 
        }
        // we don't need unnecessary comparison for q.front() > t as it will always be 
        // because we are having input in increasing order
        while(!q.empty()&&q.front()<t-3000){      
            q.pop() ; 
        }

        q.push(t) ;
        return q.size() ;  
    }
};



// we can use vector also but memory wise it is not that effective because we are wasting the memory as we are just increasing the index
// but in queue we are deleting the unnecessary starting entries.
class RecentCounter {
private:
    vector<int> request;
    int start = 0;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        request.push_back(t);
        pair<int,int> range = make_pair(t-3000, t);


        while(request[start] < range.first){
            start++;
        }
       
        return request.size() - start;
    }
};

