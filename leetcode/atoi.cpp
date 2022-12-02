#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int myAtoi(string s) 
{
    size_t i = 0;
    const int n = s.size();
    int result, sign = 0;
    
    while (s[i] == ' ' && i < n) i++;
    if (s[i] == '+' || s[i] == '-') 
    {
        s[i] == '-' ? sign = -1 : sign = 1;
        i++;
    }

    while (i < n)
    {
        char curr = s[i];
        int value = curr - '0';
        i++;
        if (!isdigit(curr)) break;
        if (result == 0) result += value;
        else
        {
            if (result*sign > INT_MAX/10) return INT_MAX;
            else if (result*sign < INT_MIN/10) return INT_MIN;
            result *= 10;
            if (result*sign > INT_MAX-value) return INT_MAX;
            else if (result*sign <= INT_MIN+value) return INT_MIN;
            result += value;
        }
        return result*sign;
    }
    
    
    

}