class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }
    int wordLength = words[0].length();
    int wordsCount = words.size();
    int sLength = s.length();
    unordered_map<string, int> expectedWords;
    for (const auto& word : words) {
        expectedWords[word]++;
    }
    for (int i = 0; i < wordLength; ++i) {
        int left = i;
        int count = 0;
        unordered_map<string, int> actualWords;
        for (int j = i; j <= sLength - wordLength; j += wordLength) {
            string word = s.substr(j, wordLength);
            if (expectedWords.count(word)) {
                actualWords[word]++;
                count++;
                while (actualWords[word] > expectedWords[word]) {
                    string leftWord = s.substr(left, wordLength);
                    actualWords[leftWord]--;
                    count--;
                    left += wordLength;
                }
                if (count == wordsCount) {
                    result.push_back(left);
                    string leftWord = s.substr(left, wordLength);
                    actualWords[leftWord]--;
                    count--;
                    left += wordLength;
                }
            } else {
                actualWords.clear();
                count = 0;
                left = j + wordLength;
            }
        }
    }
    return result;
    
        
    }
};