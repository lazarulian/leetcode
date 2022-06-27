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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    { // o(n)
        int counter = 0;
        ListNode *sortedList = new ListNode;
        ListNode *head;
        head = sortedList;

        // Initial Declaration of the Variables
        ListNode *p;
        ListNode *m;

        // Having them access the list
        p = list1;
        m = list2;

        // Empty Lists
        if (p == nullptr)
            return list2;
        if (m == nullptr)
            return list1;

        // If the Value in List 1 Greater than List2
        if (p->val <= m->val)
        {
            sortedList->val = p->val;
            p = p->next;
        }
        // If the Value in List 2 Greater than List 1
        else
        {
            sortedList->val = m->val;
            m = m->next;
        }
        while (p != nullptr && m != nullptr)
        {
            if (p->val <= m->val)
            {
                // Configuring New Node
                ListNode *newNode = new ListNode;
                newNode->val = p->val;
                p = p->next;

                // Setting the Next in the List
                sortedList->next = newNode;
                sortedList = sortedList->next;

                continue;
            }
            // If the Value in List 2 Greater than List 1
            else
            {
                // Configuring New Node
                ListNode *newNode = new ListNode;
                newNode->val = m->val;
                m = m->next;

                // Setting the Next in the List
                sortedList->next = newNode;
                sortedList = sortedList->next;

                continue;
            }
        }

        // Adding the Rest of the Longer List
        if (p == nullptr && m != nullptr)
        {
            while (m != nullptr)
            {
                ListNode *k = new ListNode;
                k->val = m->val;
                sortedList->next = k;
                m = m->next;
                sortedList = sortedList->next;
            }
        }
        else if (p != nullptr && m == nullptr)
        {
            while (p != nullptr)
            {
                ListNode *k = new ListNode;
                k->val = p->val;
                sortedList->next = k;
                p = p->next;
                sortedList = sortedList->next;
            }
        }

        // Returning the Head
        return head;
    }
};

int main()
{
    Solution x;

    return 0;
}