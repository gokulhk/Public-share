//created structure
//insert nodes
//build and run detect cycle

#include<iostream>

using namespace std;


struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int data){

	struct Node *newNode = (struct Node*)malloc( sizeof(struct Node) );
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Node* insertNode(struct Node *head, int data){

	struct Node* newNode = createNode(data);

	//case -1 : empty list 
	if(!head){
		head = newNode;
		return head;
	}

	//case 2: contains atleast one node already
	//find last node
	struct Node *temp = head;
	while( temp->next != NULL ){ temp = temp->next; }

	//connectt temp and new node
	temp->next = newNode;
	return head;
}

void printList(struct Node* head){

	//cout<<"Inside Print List"<<endl;

	if(!head){
		cout<<"List already empty!"<<endl;
		return;
	}

	struct Node *temp = head;
	int count =0;
	//cout<<"Before while Loop"<<endl;
	while(temp && count < 7){
		//cout<<"Inside while Loop"<<endl;
		cout<<temp->data<<" ";
		temp = temp->next;
		++count;
	}
}

bool cycleExists(struct Node* head){

	if(!head || !head->next){ //List empty or only one node cases
		return false;
	}

	//guarantees atleast two elem exists
	//two pointer approach 
	struct Node *lead, *follow;
	lead = head; follow = head;

	while( lead->next->next ){
		if( lead->next->next == follow->next  ){
			return true;
		}
		lead = lead->next->next;
		follow = follow->next;
	}
	return	false;
}

int main(){

	struct Node *head= NULL;

	//insert datas
	head = insertNode(head, 1);

	
	//printList(head);
	head = insertNode(head, 2);

	//printList(head);
	head = insertNode(head, 3);
	//printList(head);
	head = insertNode(head, 4);
	head = insertNode(head, 5);
	head = insertNode(head, 6);

	struct Node* temp = head;
	// while( temp->next){
	// 	temp = temp->next;
	// }

	// temp->next = head;

	temp = temp->next->next;
	temp->next = head;

	//print Nodes 
	printList(head);
	cout<<endl;

	//check for cycles
	(cycleExists(head)) ? cout<<"cycleExists" : cout<<"cycle doesn't Exists";
	cout<<endl;

}