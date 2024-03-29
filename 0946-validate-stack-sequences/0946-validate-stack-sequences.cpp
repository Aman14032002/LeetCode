class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
       stack<int>s;
        int i=0,j=0;
        while(i<pushed.size()){
            if(!s.size()){
                s.push(pushed[i]);
                i++;
                continue;
            }
            if(j<popped.size() && s.top()==popped[j]){
                s.pop();
                j++;
            }
            else {
               s.push(pushed[i]);
               i++;
            }
        }
        while(j<popped.size()){
            if(s.top()==popped[j]){
                s.pop();j++;
            }
            else break;
        }
        if(s.size())return false;
        else return true;
    }
};

 
    
