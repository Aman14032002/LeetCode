class Solution {
public:
    int repeatedStringMatch(string a, string b) {
 string s=a;
        int c=1;
        while(a.size()<b.size()){
            a+=s;
            c++;
        }
        if(a.find(b)!=-1){
            return c;
        }
        a+=s;
        c++;
        if(a.find(b)!=-1){
            return c;
        }
        else{
            return -1;
        }
    }
};