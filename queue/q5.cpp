// https://leetcode.com/problems/time-needed-to-buy-tickets/


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int start = 0;

        while(tickets[k] != 0){
            tickets[start]--;
            time++;
            
            if(start < tickets.size() - 1){
                start++;
            }
            else{
                start = 0;
            }
            while(start != k && tickets[start] == 0){
                start++;
                if(start == tickets.size()){
                    start = 0;
                }
            } 
        }

        return time;
    }   
};
