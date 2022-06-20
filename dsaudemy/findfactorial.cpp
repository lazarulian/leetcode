#include <iostream>

using namespace std;


// Find Factorial : Iteratively


int iterativeFactorial(int input)
{
    int factorial = 1;
    for (int i = input; i > 0; i--)
    {
        factorial *= i;
    }
    return factorial;
}


// Find Factorial : Recursively 

int recursiveFactorial(int input)
{
    // Base Case
    if (input == 0)
    {
        return 1;
    }
    else
    {
        return input*recursiveFactorial(input-1);
    }
}


int main()
{

    assert(iterativeFactorial(5) == 120);
    assert(recursiveFactorial(5) == 120);

    cout << "Passed all test cases" << endl;

}