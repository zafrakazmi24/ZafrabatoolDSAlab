#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;
    Node* pre;

    Node(int val){
        this->data = val;
        this->next = NULL;
        this->pre  = NULL;
    }
};

void insertAtHead(Node* &head,int val){
	Node *newNode=new Node(val);
	if(head==NULL){
            head=newNode;
            newNode->next=head;
            newNode->pre=head;
        }

        newNode->next=head;
        newNode->pre=head->pre;
        newNode->pre->next=newNode;
        head->pre=newNode;
        head=newNode;	
}

void insertAt(Node* &head, int val, int index){
	
	Node *newNode=new Node(val);
	Node *last=head->pre;
	
	if(index==0){
		newNode->next=head;
	head->pre=newNode;
	newNode->pre=last;
	last->next=newNode;
	head=newNode;
	return;
	}
	
	int count=0;
	Node*temp=head;
	while(temp->next!=head){
		if(count==index-1){
			newNode->next=temp->next;
			newNode->pre=temp;
			temp->next->pre=newNode;
			temp->next=newNode;
			return;
		}
		
		count++;
		temp=temp->next;
	}
	
	if(temp->next=head){
		last->next=newNode;
		newNode->pre=last;
		newNode->next=head;
		head->pre=newNode;	
	}
	
}

void display(Node* &head){
	Node*temp2=head;
	
	while(temp2!=NULL){
		cout<<temp2->data<<" ";
		temp2=temp2->next;
		if(temp2==head){
			break;
			return;
		}
	}
}
int main(){
	Node* head=NULL;
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	
	cout<<"Existing linked list: \n";
	display(head);
	
	insertAt(head,6,0);
	cout<<"\nlinked list after insertion at head \n";
	display(head);
	
	insertAt(head,9,2);
	cout<<"\nlinked list after insertion at mid \n";
	display(head);
	
	insertAt(head,8,6);
	cout<<"\nlinked list after insertion at head \n";
	display(head);
	
	return 0;
}

