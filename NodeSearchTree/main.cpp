#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void addNode(int num, Node *node)
{
    if (node->data < num)
    {
        if (node->right == nullptr)
        {
            node->right = createNode(num);
        }
        else
        {
            addNode(num, node->right);
        }
    }
    else
    {
        if (node->left == nullptr)
        {
            node->left = createNode(num);
        }
        else
        {
            addNode(num, node->left);
        }
    }
}

void preorder(Node *node)
{

    if (node)
    {
        cout << node->data << ", ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node)
{
    if (node)
    {
        inorder(node->left);
        cout << node->data << ", ";
        inorder(node->right);
    }
}

void postorder(Node *node)
{
    if (node)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << ", ";
    }
}

int main()
{
    Node *root = nullptr;
    int list[15] = {50, 75, 25, 15, 60, 35, 90, 42, 20, 27, 5, 55, 95, 80, 70};
    for (int i = 0; i < 15; i++)
    {
        if (root)
        {
            addNode(list[i], root);
        }
        else
        {
            root = createNode(list[i]);
        }
    }
    cout << "Preorder:";
    preorder(root);
    cout << "\nInorder:";
    inorder(root);
    cout << "\nPostorder:";
    postorder(root);

    return 0;
}
