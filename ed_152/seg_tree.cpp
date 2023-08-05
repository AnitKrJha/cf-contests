#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int start;
    int end;
    Node *left;
    Node *right;
    Node(int start, int end)
    {
        this->start = start;
        this->end = end;
        data = 0;
        left = nullptr;
        right = nullptr;
    }
};
Node *root;

Node *constructTree(int arr[], int start, int end)
{
    if (start >= end)
    {
        Node *leafNode = new Node(start, end);
        leafNode->data = arr[start];
        return leafNode;
    }
    int mid = (start + end) / 2;
    Node *root = new Node(start, end);
    root->left = constructTree(arr, start, mid);
    root->right = constructTree(arr, mid + 1, end);
    root->data = root->left->data + root->right->data;
    return root;
}

void prettyPrint(Node *root, int indent = 0, char symbol = ' ')
{
    if (root == nullptr)
    {
        return;
    }

    const int spacesPerIndent = 16;

    // Print the right subtree with proper indentation
    prettyPrint(root->right, indent + spacesPerIndent, '/');

    // Print the current node with its range
    for (int i = 0; i < indent; ++i)
    {
        std::cout << ' ';
    }
    std::cout << symbol << "[" << root->start << ", " << root->end << "] : " << root->data << std::endl
              << '\n';

    // Print the left subtree with proper indentation
    prettyPrint(root->left, indent + spacesPerIndent, '\\');
}

// int rangeSum(int start,int end,int sum){

//     if(end){
//         return
//     }

//     rangeSum(node)
// }

int main()
{

    int arr[] = {1, 3, 4, 2, 4};
    int n = 5;

    root = constructTree(arr, 0, n - 1);
    prettyPrint(root);

    // find the sum of the range 2 ,4

    return 0;
}