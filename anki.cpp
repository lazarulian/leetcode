#include <iostream>
#include <cmath>

int myAtoi(string s) 
    {
        // Things to Address: White Space, Leading Zeroes, Positive / Negative Numbers, Non-Digits

        int i = 0;
        const int size = s.size();
        int sign = 0;
        int result = 0;
        int res = INT_MIN;
        
        // Skipping the White Space
        while (s[i] == ' ' && i < size)
        {
            i++;
        }
        
        // Positive or Negative Sign
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        else if (s[i] == '+') {
            sign = 1;
            i++;
        }
        else
        {
            sign = 1;
        }

        // Read Characters Until Non-Digit Character
        while (i < size)
        {
            char curr = s[i];
            i++;
            if (!isdigit(curr))
                break;
            else
            { // Is Digit
                if (result == 0)
                    result += curr - '0';
                else
                {
                    int diff = curr - '0';
                    if (result*sign > (INT_MAX/10))
                        return INT_MAX;
                    else if (result*sign < (INT_MIN/10)-diff)
                        return (res);
                    result *= 10;
                    if (result*sign > INT_MAX-diff)
                        return INT_MAX;
                    else if (result*sign <= INT_MIN+diff)
                        return INT_MIN;
                    result += diff;
                }
            } // End Digit Else
        } // End While Loop
        
        return result*sign;
    }