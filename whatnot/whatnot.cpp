#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;
 
vector<string> split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
} 


string cleanString(vector<int> input)
{
    string t = "Banana Republic";
    string s = "nana";

    string::size_type i = t.find(s);

    if (i != std::string::npos) t.erase(i, s.length());
    return t;
}


string buildString(vector<string> input)
{
    string output = "";
    for (int i = 0; i < input.size(); i++)
    {
        output += input[i];
        output += ' ';
    }
}



int main()
{
    return 0;
}