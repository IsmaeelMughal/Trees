#include <iostream>
#include <vector>
#include <queue>

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

void postOrder(struct Node* root)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " - ";
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

vector<int> levelOrder(Node* node)
{
	vector<int> res;
	queue<Node*> q;
	if (node != NULL)
	{
		q.push(node);
	}
	Node* temp = NULL;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		res.push_back(temp->data);
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
	return res;
}

//Function to find the height of a binary tree.
int height(struct Node* node) {
	if (node == NULL)
	{
		return 0;
	}

	int leftHeight = height(node->left);
	int rightHeight = height(node->right);

	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}

int main()
{
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << endl << "PREODER : ";
	preOrder(root);
	cout << endl;

	cout << endl << "POSTODER : ";
	postOrder(root);
	cout << endl;

	cout << endl << "InODER : ";
	inOrder(root);
	cout << endl;

	return 0;
}