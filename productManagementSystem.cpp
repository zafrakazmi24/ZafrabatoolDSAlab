#include <iostream>
#include <string>

using namespace std; // Using the standard namespace

// Node structure for a product
struct Product {
    int productID;
    string productName;
    int quantity;
    double price;
    Product* next;

    // Constructor to initialize a product node
    Product(int id, string name, int qty, double pr)
        : productID(id), productName(name), quantity(qty), price(pr), next(NULL) {}
};

// Class to manage the product linked list
class ProductList {
private:
    Product* head;

public:
    ProductList() : head(NULL) {}

    // Add a product to the list
    void addProduct(int id, string name, int qty, double price) {
        Product* newProduct = new Product(id, name, qty, price);
        if (!head) {
            head = newProduct;
        } else {
            Product* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newProduct;
        }
        cout << "Product added successfully.\n";
    }

    // Update a product in the list
    void updateProduct(int id, string newName, int newQty, double newPrice) {
        Product* temp = head;
        while (temp) {
            if (temp->productID == id) {
                temp->productName = newName;
                temp->quantity = newQty;
                temp->price = newPrice;
                cout << "Product updated successfully.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Product not found.\n";
    }

    // Delete a product from the list
    void deleteProduct(int id) {
        if (!head) {
            cout << "List is empty. No products to delete.\n";
            return;
        }
        if (head->productID == id) {
            Product* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Product deleted successfully.\n";
            return;
        }
        Product* temp = head;
        while (temp->next && temp->next->productID != id) {
            temp = temp->next;
        }
        if (temp->next) {
            Product* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Product deleted successfully.\n";
        } else {
            cout << "Product not found.\n";
        }
    }

    // Display all products
    void displayProducts() {
        if (!head) {
            cout << "No products available.\n";
            return;
        }
        Product* temp = head;
        while (temp) {
            cout << "Product ID: " << temp->productID << "\n";
            cout << "Product Name: " << temp->productName << "\n";
            cout << "Quantity: " << temp->quantity << "\n";
            cout << "Price: $" << temp->price << "\n";
            cout << "------------------------\n";
            temp = temp->next;
        }
    }

    // Destructor to clean up memory
    ~ProductList() {
        while (head) {
            Product* toDelete = head;
            head = head->next;
            delete toDelete;
        }
    }
};

// Main function to demonstrate the product management system
int main() {
    ProductList inventory;
    int choice, id, qty;
    string name;
    double price;

   
        cout << "              ***********************************************" << endl;
        cout << "              *                                             *" << endl;
        cout << "              *=============================================*" << endl;
        cout << "              *        ===Product Management Module===      *" << endl;
        cout << "              *=============================================*" << endl;
        cout << "              *                                             *" << endl;
        cout << "              ***********************************************" << endl;
        cout << endl;
        
 while (true) {
 	    cout<<"===Select an option==="<<endl;
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. View Products\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
    case 1: {
        cout << "Enter Product ID (or -1 to return to menu): ";
        cin >> id;
        if (id == -1) break;
        cin.ignore();  // To consume the newline character after integer input
        cout << "Enter Product Name (or type 'menu' to return to menu): ";
        getline(cin, name);
        if (name == "menu") break;
        cout << "Enter Quantity (or -1 to return to menu): ";
        cin >> qty;
        if (qty == -1) break;
        cout << "Enter Price (or -1 to return to menu): ";
        cin >> price;
        if (price == -1) break;
        inventory.addProduct(id, name, qty, price);
        break;
    }
    case 2: {
        cout << "Enter Product ID to update (or -1 to return to menu): ";
        cin >> id;
        if (id == -1) break;
        cin.ignore();  // To consume the newline character after integer input
        cout << "Enter New Product Name (or type 'menu' to return to menu): ";
        getline(cin, name);
        if (name == "menu") break;
        cout << "Enter New Quantity (or -1 to return to menu): ";
        cin >> qty;
        if (qty == -1) break;
        cout << "Enter New Price (or -1 to return to menu): ";
        cin >> price;
        if (price == -1) break;
        inventory.updateProduct(id, name, qty, price);
        break;
    }
    case 3: {
        cout << "Enter Product ID to delete (or -1 to return to menu): ";
        cin >> id;
        if (id == -1) break;
        inventory.deleteProduct(id);
        break;
    }
    case 4:
        inventory.displayProducts();
        break;
    case 5:
        cout << "Exiting...\n";
        return 0;
    default:
        cout << "Invalid choice. Please try again.\n";
}

    }
}
