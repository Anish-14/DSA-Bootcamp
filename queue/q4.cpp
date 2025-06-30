// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2, 0);
        for (int student : students)
            counts[student]++;

        int remaining = sandwiches.size();
        for (int sandwich : sandwiches) {
            if (counts[sandwich] == 0)
                break;
            // actually we don't need this condition as the number of sandwiches is equal to the number of students, so it will become zero only when all the sandwiches 
            // distributed
            if (remaining == 0)
                break;
            counts[sandwich]--;
            remaining--;
        }

        return remaining;
    }
};
