#include<iostream>

using namespace std;

//tree nodes
struct Node{
	int data;
	struct Node *left, *right;
};

struct Node* createNode(int data){

	struct Node* newNode = (struct Node*)malloc( sizeof(struct Node) );
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insertBSTNode(struct Node** root, int data){

	struct Node* newNode = createNode(data);

	//tree empty case 
	if(!*root){
		*root = newNode;
		return;
	}

	//atleast node case 
	//1.find node spot
	struct Node *lead, *follow;
	lead = *root; follow;

	while(lead){
		follow = lead;
		lead = ( lead->data > data) ? lead->left : lead->right;
	}

	//2.place new node in spot
	if( follow->data > data ){
		follow->left = newNode;
	}
	else{
		follow->right = newNode;
	}
}

class Queue{ //implemented using circular array concept

private:
	struct Node **queue;
	int front, rear;
	int count;
	int capacity;

public: 
	Queue(int capacity){
		queue =  new struct Node*[capacity];
		front = 0;
		rear = -1;
		count = 0;
		this->capacity = capacity;
	}

	void enqueue(struct Node* now){

		//Overflow check
		if( count == capacity ){
			cout<<"Queue Already Full!"<<endl;
			return;
		}

		//space exists
		rear =  ( rear + 1 ) % capacity;
		queue[rear] = now;
		++count;
	}

	struct Node* dequeue(){

		//underflow check
		if( count == 0 ){
			cout<<"Queue Undeflow"<<endl;
			return NULL;
		}

		struct Node* now = queue[front];
		front = ( front + 1) % capacity;
		--count;
		return now;
	}

	int size(){
		return count;
	}
};


void inOrderTraversal(struct Node* root){

	//cout<<"Service by inOrderTraversal"<<endl;
	//case 1 : empty root case 
	if(!root){
		//cout<<"Tree Empty !"<<endl;
		return;
	}

	//case 2 : atleast one node exists
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

void preOrderTraversal(struct Node* root){

	//empty case 
	if(!root){
		return;
	}

	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(struct Node* root){

	//empty case 
	if(!root){
		return;
	}

	//recursion body
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

int DFT(struct Node* root, int size, int count){

	//cycle detection case & empty node check
	if( count > size || !root){
		return count;
	}

	++count;
	count = DFT( root->left, size, count ); //left sidecheck
	count = DFT( root->right, size, count);

	return count;
}


int BFT(struct Node* root, int size, int count){

	//cycle detection case & empty node check
	if( count > size || !root){
		return count;
	}

	count =  ( root->left ) ? count +1 :  count;
	count =  ( root->right ) ? count +1 :  count;

	count = BFT( root->left, size, count );
	count = BFT( root->right, size, count);

	return count;

}

int main(){

	struct Node *root = NULL;

	cout<<"Insertion starts"<<endl;
	//insert nodes 
	insertBSTNode(&root, 6);
	insertBSTNode(&root, 4);
	insertBSTNode(&root, 8);
	insertBSTNode(&root, 2);
	insertBSTNode(&root, 5);
	insertBSTNode(&root, 7);
	insertBSTNode(&root, 9);
	insertBSTNode(&root, 1);
	insertBSTNode(&root, 3);

	cout<<"Insertion ends"<<endl;


	cout<<"Call to preOrder  traversal"<<endl;
	preOrderTraversal(root);
	cout<<endl;

	//call inorder traversal - prints in ascending order
	cout<<"Call to Inorder  traversal"<<endl;
	inOrderTraversal(root);
	cout<<endl;

	cout<<"Call to postOrder  traversal"<<endl;
	postOrderTraversal(root);
	cout<<endl;

	//BFT - Cycle check
	int size = 9; 

	//cycle making 
	root->left->right->left = root->left->left;
	root->left->left->right->right = root->left->right;

	int val = DFT(root, size, 0) ;

	cout<<"DFT : Val returned : "<<val<<endl;
	if( val > size ){
		cout<<"DFT : Cycle Exists";
	}
	else{
		cout<<"DFT : No Cycle Exists";
	}
	cout<<endl;

	int val2 = BFT(root, size, 0) ;

	cout<<"BFT : Val returned : "<<val2<<endl;
	if( val2 > size ){
		cout<<"BFT : Cycle Exists";
	}
	else{
		cout<<"BFT : No Cycle Exists";
	}

	cout<<endl;
}