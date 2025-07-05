// https://leetcode.com/problems/flatten-nested-list-iterator/description/
// remember NestedInteger is a built-in class in cpp, have a look at that before understanding this code

class NestedIterator {
public:
    stack<NestedInteger> stack;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i>=0; i--){
            stack.push(nestedList[i]);
        }
    }
    
    int next() {
        int result = stack.top().getInteger();
        stack.pop();
        return result;
    }
    
    bool hasNext() {
        while(!stack.empty()){
            NestedInteger current = stack.top();
            if(current.isInteger()){
                return true;
            }
            stack.pop();
            vector<NestedInteger> nestedList = current.getList();
            for(int i = nestedList.size()-1; i>=0; i--){
                stack.push(nestedList[i]);
            }
        }
        return false;
    }
};




// anothere mehod

class NestedIterator {
    int idx;
    vector<int>flatten;

    vector<int> flattenList(vector<NestedInteger> &nestedList){
        vector<int>res;
        for(auto it: nestedList){
            if(it.isInteger()){
                res.push_back(it.getInteger());
            }
            else{
                auto subList = flattenList(it.getList());
                for(auto v: subList){
                    res.push_back(v);
                }
            }
        }

        return res;
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten = flattenList(nestedList);
        this->idx = 0;
    }
    
    int next() {
        return hasNext()? flatten[idx++]: -1;
    }
    
    bool hasNext() {
        return idx < flatten.size();
    }
};

