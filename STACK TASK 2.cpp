#include <iostream>
#include <string>
using namespace std;


struct Node {
    string item;
    Node* next;
};


class GroceryList {
private:
    Node* head;  

public:
    
    GroceryList() {
        head = NULL;
    }

    
    void addItem(string newItem) {
        Node* newNode = new Node();
        newNode->item = newItem;     
        newNode->next = NULL;     

        
        if (head == NULL) {
            head = newNode;
            cout << "Add item: " << newItem  << endl;
        } else {
            
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            cout << "Add item: " << newItem << endl;
        }
    }

    
    void removeItem(string removeItem) {
        if (head == NULL) {
            cout << "The list is empty cannot remove item." << endl;
            return;
        }


        if (head->item == removeItem) {
            Node* temp = head;
            head = head->next;  
            delete temp;        
            cout << "Remove item: " << removeItem << endl;
            return;
        }


        Node* current = head;
        Node* previous = NULL;
        while (current != NULL && current->item != removeItem) {
            previous = current;
            current = current->next;
        }

        if (current != NULL) {
            previous->next = current->next;
            delete current;
            cout << "Remove item: " << removeItem  << endl;
        } else {
            cout << "Item: " << removeItem << " not found in the list." << endl;
        }
    }

    void displayList() {
        if (head == NULL) {
            cout << "The grocery list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Grocery list items: ";
        while (temp != NULL){
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    
    ~GroceryList() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    GroceryList list;


    list.addItem("Apples");
    list.addItem("Bread");
    list.addItem("Milk");


    list.displayList();

    
    list.removeItem("Bread");
    
    
    list.displayList();

 return 0;
}
