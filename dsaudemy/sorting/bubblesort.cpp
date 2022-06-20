#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// Bubble Sort


vector<int> bubbleSort(vector<int> input)
{
    // Base Case
    bool isSorted = false;
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i-1] <= input[i]) {
            isSorted = true;
            continue;
        }
        else 
        {
            isSorted = false;
            break;
        }
    }

    if (isSorted == true)
        return input;
    else 
    {
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] < input[i-1])
            {
                int temp = input[i];
                input[i] = input[i-1];
                input[i-1] = temp;
            }
            else
                continue;
        }
        return bubbleSort(input);
    }
}


int main()
{

vector<int> narnia;
for (int i = 0; i < 10; i++)
{
    narnia.push_back(rand() % 100);
}
vector<int> sorted = bubbleSort(narnia);
cout << "Unsorted Array: ";
for (int i = 0; i < narnia.size(); i++)
{
    cout << narnia[i] << ", ";
} 
cout << endl;
cout << "Sorted Array: ";
for (int i = 0; i < sorted.size(); i++)
{
    cout << sorted[i] << ", ";
} 
cout << endl;

}