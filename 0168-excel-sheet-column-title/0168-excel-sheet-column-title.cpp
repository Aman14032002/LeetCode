class Solution {
public:
    string convertToTitle(int columnNumber) {
        
    std::string columnTitle = "";

       while (columnNumber > 0) {
        columnNumber--; // Adjust to 0-based index
        int remainder = columnNumber % 26;
        columnTitle = char('A' + remainder) + columnTitle;
        columnNumber /= 26;
    }

    return columnTitle;
  
    }
};