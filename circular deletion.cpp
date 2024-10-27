#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int value) {
        data = value;
        next = NULL;
    }
};

void insertAtEnd(node *&head, int value) {
    node *newnode = new node(value);
    if (head == NULL) {
        head = newnode;
        newnode->next = head; 
    } else {
        node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; 
    }
}

void deleteAtStart(node *&head) {
    if (head == NULL) return;

    node *temp = head;
    if (head->next == head) { 
        delete head;
        head = NULL;
    } else {
    
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = head->next;
        delete head;
        head = temp->next;
    }
}

void deleteAtEnd(node *&head) {
    if (head == NULL) return;

    node *temp = head;
    if (head->next == head) { 
        delete head;
        head = NULL;
    } else {
        node *prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp; 
    }
}

void deleteAtMid(node *&head, int position) {
    if (head == NULL || position < 1) return; 

    if (position == 1) {
        deleteAtStart(head);
        return;
    }

    node *temp = head;
    node *prev = NULL;
    int count = 1;

    while (temp->next != head && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == position) {
        prev->next = temp->next; 
        delete temp; 
    } else {
        cout << "Position out of bounds!" << endl;
    }
}

void printList(node *head) {
    if (head == NULL) return; 

    node *temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head: " << head->data << ")" << endl; 
}

int main() {
    node *head = NULL;
    int value;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    
    cout << "List before any deletion:" << endl;
    printList(head);

    deleteAtStart(head);
    cout << "List after deleting at start:" << endl;
    printList(head);

    
    deleteAtEnd(head);
    cout << "List after deleting at end:" << endl;
    printList(head);

    
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    insertAtEnd(head, 60);
    cout << "List before mid deletion:" << endl;
    printList(head);

    
    int position;
    cout << "Enter position to delete : ";
    cin >> position;
    deleteAtMid(head, position);
    
    cout << "List after deleting at position " << position << ":" << endl;
    printList(head);

    return 0;
}

