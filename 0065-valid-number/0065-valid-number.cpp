class Solution {
public:
    bool isNumber(string s) {
  int n = s.length();
    int i = 0;
    bool isNumeric = false;

    // Leading whitespaces ko chhodo
    while (i < n && isspace(s[i])) {
        i++;
    }

    // Optional sign (+/-) check karo
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        i++;
    }

    // Decimal point se pahle digits ko dekho
    while (i < n && isdigit(s[i])) {
        i++;
        isNumeric = true;
    }

    // Optional decimal point check karo
    if (i < n && s[i] == '.') {
        i++;

        // Decimal point ke baad ke digits ko dekho
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }
    }

    // Optional exponent (e/E) check karo
    if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
        i++;

        // Exponent (e/E) ke baad ke optional sign ko check karo
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }

        // Exponent (e/E) ke baad ke digits ko check karo
        while (i < n && isdigit(s[i])) {
            i++;
        }

        // Agar exponent (e/E) ke baad koi digits nahi hain, toh valid number nahi hai
        if (!isdigit(s[i - 1])) {
            return false;
        }
    }

    // Trailing whitespaces ko chhodo
    while (i < n && isspace(s[i])) {
        i++;
    }

    // Agar hum string ke end tak pohoch gaye hain aur kam se kam ek numeric character hai,
    // toh yeh ek valid number hai
    return isNumeric && i == n;

    }
};