#include <iostream>
using namespace std;
struct Node {
int data;
Node* next;
};
Node* head = nullptr;
void insert(int val) {
Node* newNode = new Node();
newNode->data = val;
if (head == nullptr) {
head = newNode;
newNode->next = head;
} else {
Node* temp = head;
while (temp->next != head) {
temp = temp->next;
}
temp->next = newNode;
newNode->next = head;
}
}
void deleteStart() {
if (head == nullptr) {
cout<<"List is empty, cannot delete."<<endl;
return;
}
if (head->next == head) {
delete head;
head = nullptr;
} else {
Node* temp = head;
while (temp->next != head) {
temp = temp->next;
}
temp->next = head->next;
delete head;
head = temp->next;
}
}
void deleteMid(int pos) {
if (head == nullptr) {
cout << "List is empty!" << endl;
return;
}
if(pos == 0) {
Node* temp = head;
if(head->next == head) {
head = nullptr;
} else {
Node* last = head;
while (last->next != head) {
last = last->next;
}
last->next = head->next;
head = head->next;
}
delete temp;
return;
}
Node* temp = head;
for (int i = 0; i < pos; i++) {
temp = temp->next;
if (temp == head) {
cout << "Position out of bounds!" << endl;
return;
}
}
Node* toDelete = temp;
Node* prev = head;
while (prev->next != toDelete) {
prev = prev->next;
}
prev->next = temp->next;
delete toDelete;
}
void deleteEnd() {
if (head == nullptr) {
cout <<"List is empty, cannot delete."<< endl;
return;
}
if (head->next == head) {
delete head;
head = nullptr;
return;
}
Node* temp = head;
while (temp->next->next != head) {
temp = temp->next;
}
delete temp->next;
temp->next = head;
}
void display() {
if (head == nullptr) {
cout << "List is empty." << endl;
return;
}
Node* temp = head;
do {
cout << "Data: " << temp->data << endl;
temp = temp->next;
} while (temp != head);
}
int main() {
while (true) {
cout << "****************" << endl;
cout << "Circular Linked List Menu" << endl;
cout << "****************" << endl;
cout << "1) Insert Node" << endl;
cout << "2) Delete Node from Start" << endl;
cout << "3) Delete Node from Middle" << endl;
cout << "4) Delete Node from End" << endl;
cout << "5) Display List" << endl;
cout << "0) Exit" << endl;
cout << "Enter your choice: ";
int choice;
cin >> choice;
int val, pos;
switch (choice) {
case 1:
cout << "Enter value to insert: ";
cin >> val;
insert(val);
break;
case 2:
deleteStart();
break;
case 3:
cout << "Enter position to delete from (starting from 0): ";
cin >> pos;
deleteMid(pos);
break;
case 4:
deleteEnd();
break;
case 5:
display();
break;
case 0:
exit(0);
default:
cout << "Invalid choice!" << endl;
}
}
return 0;
}

