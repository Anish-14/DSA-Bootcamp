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
