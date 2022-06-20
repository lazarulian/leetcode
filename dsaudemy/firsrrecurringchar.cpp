#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;



int hashfunction(int input)
{
    hash<int> hash_char;
    return hash_char(input);
}


int first_recurring(const vector<int> &input)
{ // o(n)
    unordered_map<int, int> m;
    for (int i = 0; i < input.size(); i++)
    {
        if (m.find(hashfunction(input[i])) == m.end())
        {
            m[hashfunction(input[i])] = input[i];
            continue;
        }
        else 
        {
            return input[i];
        }
    }

    return -1;
}



int main()
{
    int m_arr[8] = {1, 2, 3, 4, 5, 6, 12, 12};
    vector<int> m;
    for (int i = 0; i < 8; i++)
    {
        m.push_back(m_arr[i]);
    }
    assert(first_recurring(m) == 12);
    cout << "Passed all test cases!" << endl;
}