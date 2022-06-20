#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  


using namespace std;


vector<int> selectionSort(vector<int> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        int min = i;
        int temp = input[i];
        for (int j = i+1; j < input.size(); j++)
        {
            if (input[j] < input[min])
            {
                min = j;
            }

        }
        input[i] = input[min];
        input[min] = temp;
    }
    return input;
}

int main()
{

vector<int> narnia;
for (int i = 0; i < 10; i++)
{
    narnia.push_back(rand() % 1000);
}
vector<int> sorted = selectionSort(narnia);
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