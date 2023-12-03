class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
     
        if (str1 + str2 != str2 + str1) {
        
        return "";
    }

    // Calculate the greatest common divisor using Euclidean algorithm
    size_t len1 = str1.length();
    size_t len2 = str2.length();
    size_t gcd = 1;

    while (len2 != 0) {
        size_t temp = len2;
        len2 = len1 % len2;
        len1 = temp;
    }

    gcd = len1;

    return str1.substr(0, gcd);
}
    
};