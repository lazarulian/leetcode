#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// Bubble Sort


vector<int> insertionSort(vector<int> input)
{

int tempMax = input[0];
int tempMin = input[0];

vector<int> newArr;
for (int i = 0; i < input.size(); i++)
{
    // Check Max / Min & Place it There if so
    if (input[i] >= tempMax)
    {
        newArr.push_back(input[i]);
        tempMax = input[i];
        continue;
    }
    else if (input[i] <= tempMin)
    {
        vector<int>::iterator it = newArr.begin();
        newArr.insert(it, input[i]);
        tempMin = input[i];
        continue;
    }

    // Go through New Array and Place it there if so
    else 
    { // value has reached the maximum point 
        for (int j = 1; j < newArr.size(); j++)
        {
            vector<int>::iterator it = newArr.begin();
            it+= j;
            if (input[i] <= newArr[j] && input[i] >= newArr[j-1])
            {
                newArr.insert(it, input[i]);
                break;
            }
            else 
                continue;
        }
    }
}

return newArr;
}


int main()
{

vector<int> narnia;
for (int i = 0; i < 10; i++)
{
    narnia.push_back(rand() % 100);
}
vector<int> sorted = insertionSort(narnia);
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