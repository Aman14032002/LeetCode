class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        char ch;

        while(i<s.length()){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                ch=st.top();
                st.pop();
                if((s[i]==')' && ch!='(') || (s[i]=='}' && ch!='{') || (s[i]==']' && ch!='['))
                return false;
            }
            i++;
        }
        if( st.empty())
        return true;

        return false;



    }
};