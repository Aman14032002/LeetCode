class Solution {
public:
     bool check_vowel(char c){
        c=tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' );
  
    }
    string reverseVowels(string s) {
        int start=0;
        int end=s.size()-1;
        while(start<=end){
            if(check_vowel(s[start]) && check_vowel(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }
           else
            {
                check_vowel(s[start])?end--:start++;
            }
        }
        return s;
    }
};