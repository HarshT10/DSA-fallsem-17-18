#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void inorder(Node* root)
{
	if(!root)  return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

Node* insert(Node* root, int data)
{
	if(!root){
		root= new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
	root->left = insert(root->left, data);
	else if(data > root->data)
	root->right = insert(root->right, data);
	
	return root;
}

int Find_kthmin(int k, Node* root)
{
	for(int i=0;i<k-3;i++)
	root = root->left;
	return root->data;
}

Node* Findmin(Node* root)
{
	while(!root)
	root= root->left;
	
	return root;
}

Node* deletenode(Node* root,int data)
{
	if(root==NULL) return root;
	
	else if(data< root->data) 
	root->left = deletenode(root->left, data);
	
	else if(data> root->data)
	root->right= deletenode(root->right, data);
	
	else
	{
		if(root->left==NULL && root->right==NULL){
			delete root;
			root= NULL;
		}
		else if(root->left==NULL){
			struct Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right==NULL){
			struct Node* temp = root;
			root = root->left;
			delete temp;
		}
		else{
			struct Node *temp = Findmin(root->right);	
			root->data = temp->data;
			root->right = deletenode(root->right, temp->data);
		}
	}
	return root;
}
int main()
{
	int k,kthMin;
	Node* root = NULL;
	root = insert(root,5); root = insert(root,10);
	root = insert(root,3); root = insert(root,4); 
	root = insert(root,1); root = insert(root,11);
	cout<<"Enter Value of K: ";
	cin>>k;
	kthMin = Find_kthmin(k,root);
	cout<<"The Structure of BST"<<endl;
	inorder(root);
	cout<<endl;
	root= deletenode(root, kthMin);
	cout<<"After Deletion of kth Min element: "<<endl;
	inorder(root);
}
