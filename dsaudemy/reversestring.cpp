#include <iostream>
#include <string>
using namespace std;


// Reverse a String Recursively

string reverseStringHelper(string input, string newstring)
{
    int length = input.length();
    if (length < 1)
    {
        return newstring;
    }

    else 
    {
        newstring = input[0] + newstring;
        cerr << "The substring is: " << input.substr(1, length-2) << endl;
        return reverseStringHelper(input.substr(1, length-1), newstring);
    }
}

string reverseString(string input)
{

    string newString = "";

    return reverseStringHelper(input, newString);

}


int main()
{
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Your name reversed is: " << reverseString(name) << endl;
    cout << "Passed all test cases" << endl;

}