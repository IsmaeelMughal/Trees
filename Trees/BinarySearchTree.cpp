#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

struct Node* insert(struct Node* node, int key)
{
	if (node == NULL)
	{
		return new Node(key);
	}

	if (key < node->data)
	{
		node->left = insert(node->left, key);
	}
	else
	{
		node->right = insert(node->right, key);
	}
	return node;
}

void inOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	inOrder(root->left);
	cout << root->data << " - ";
	inOrder(root->right);
}

void preOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " - ";
	preOrder(root->left);
	preOrder(root->right);
}

Node* BSTSuccessor(Node* root)
{
	Node* temp = root;

	while (temp && temp->left != NULL)
	{
		temp = temp->left;
	}
	return temp;
}

// Function to delete a node from BST.
Node* deleteNode(Node* root, int X) {
	// your code goes here
	if (root == NULL)
	{
		return NULL;
	}

	if (X < root->data)
	{
		root->left = deleteNode(root->left, X);
	}
	else if (X > root->data)
	{
		root->right = deleteNode(root->right, X);
	}
	else
	{
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = BSTSuccessor(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
		return root;
	}
	return root;
}

int main()
{
	Node* root = new Node(1);
	insert(root, 6);
	insert(root, 4);
	insert(root, 3);
	insert(root, 7);
	insert(root, 8);
	insert(root, 2);
	insert(root, 9);
	insert(root, 5);
	cout << endl << "PREORDER : ";
	preOrder(root);
	cout << endl;

	cout << endl << "INORDER : ";
	inOrder(root);
	cout << endl;
	return 0;
}