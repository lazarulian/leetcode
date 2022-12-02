#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

class node {
public:
    int data;
    node *left, *right;
    bool visited;
};

void BFSearch(node* root)
{
    queue<node*> q;
    root->visited = true;
    q.push(root);

    while (!q.empty())
    {
        node* r = q.back();
        q.pop();
        // Visit R

        // Explore More
        if (r->left->visited == false)
        {
            r->left->visited = true;
            q.push(r->left);
        }
        if (r->right->visited == false)
        {
            r->right->visited = true;
            q.push(r->right);
        }
    }
}


int main()
{
    return 0;
}