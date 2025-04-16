#include <iostream>
#include <string>
using namespace std;

class Login {
public:
    bool authenticate(string username, string password) {
        if (username == "khizra" && password == "semes-4") {
            return true;
        }
        return false;
    }
};

struct ProductNode {
    string productName;
    int productID;
    int quantity;
    float price;
    ProductNode* next;
};

class ProductList {
public:
    ProductNode* head;

    ProductList() {
        head = NULL;
    }

    void addProduct(string name, int id, int qty, float price) {
        ProductNode* newProduct = new ProductNode;
        newProduct->productName = name;
        newProduct->productID = id;
        newProduct->quantity = qty;
        newProduct->price = price;
        newProduct->next = NULL;

        if (head == NULL) {
            head = newProduct;
        } else {
            ProductNode* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
    }

    void removeProduct(int productID) {
        if (head == NULL) {
            return;
        }
        if (head->productID == productID) {
            ProductNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        ProductNode* temp = head;
        while (temp->next != NULL && temp->next->productID != productID) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            return;
        } else {
            ProductNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void displayProducts() {
        if (head == NULL) {
            return;
        }
        ProductNode* temp = head;
        while (temp != NULL) {
            cout << "Product ID: " << temp->productID
                 << ", Name: " << temp->productName
                 << ", Quantity: " << temp->quantity
                 << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    ProductNode* searchProduct(int productID) {
        ProductNode* temp = head;
        while (temp != NULL) {
            if (temp->productID == productID) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
};

class OrderManagement {
public:
    void placeOrder(ProductList& productList, int productID, int qty) {
        ProductNode* product = productList.searchProduct(productID);
        if (product != NULL) {
            if (product->quantity >= qty) {
                product->quantity -= qty;
                cout << "Order placed successfully for " << qty << " of " << product->productName << endl;
            } else {
                cout << "Not enough stock available.\n";
            }
        } else {
            cout << "Product not found.\n";
        }
    }
};

int main() {
    Login login;
    string username, password;

    cout << "Welcome to the Inventory Management System\n";
    cout << "Please enter username: ";
    cin >> username;
    cout << "Please enter password: ";
    cin >> password;

    if (!login.authenticate(username, password)) {
        cout << "Invalid login credentials.\n";
        return 0;
    }

    ProductList productList;
    OrderManagement orderManagement;
    int choice;

    while (true) {
        cout << "\n1. Add Product\n2. Remove Product\n3. Display Products\n4. Place Order\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id, qty;
            float price;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter quantity: ";
            cin >> qty;
            cout << "Enter price: ";
            cin >> price;

            productList.addProduct(name, id, qty, price);
            cout << "Product added successfully.\n";
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter product ID to remove: ";
            cin >> id;

            productList.removeProduct(id);
        }
        else if (choice == 3) {
            productList.displayProducts();
        } 
        else if (choice == 4) {
            int id, qty;
            cout << "Enter product ID to order: ";
            cin >> id;
            cout << "Enter quantity: ";
            cin >> qty;

            orderManagement.placeOrder(productList, id, qty);
        } 
        else if (choice == 5) {
            cout << "Exiting Inventory Management System...\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

