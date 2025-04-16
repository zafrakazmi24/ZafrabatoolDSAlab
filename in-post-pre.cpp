#include <iostream>
#include <string>
using namespace std;
class EmployeeNode {
public:
int employeeNumber;
string name;
double salary;
EmployeeNode* left;
EmployeeNode* right;
EmployeeNode(int empNo, string empName, double empSalary) {
employeeNumber = empNo;
name = empName;
salary = empSalary;
left = right = NULL;
}
};
EmployeeNode* insert(EmployeeNode* root, int empNo, string name, double salary) {
if (root == NULL) {
return new EmployeeNode(empNo, name, salary);
}
if (empNo < root->employeeNumber) {
root->left = insert(root->left, empNo, name, salary);
} else if (empNo > root->employeeNumber) {
root->right = insert(root->right, empNo, name, salary);
}
return root;
}
EmployeeNode* search(EmployeeNode* root, int empNo) {
if (root == NULL || root->employeeNumber == empNo) {
return root;
}
if (empNo < root->employeeNumber) {
return search(root->left, empNo);
} else {
return search(root->right, empNo);
}
}
EmployeeNode* findMin(EmployeeNode* root) {
while (root->left != NULL) {
root = root->left;
}
return root;
}
EmployeeNode* deleteEmployee(EmployeeNode* root, int empNo) {
if (root == NULL) return root;
if (empNo < root->employeeNumber) {
root->left = deleteEmployee(root->left, empNo);
} else if (empNo > root->employeeNumber) {
root->right = deleteEmployee(root->right, empNo);
} else {
if (root->left == NULL) {
EmployeeNode* temp = root->right;
delete root;
return temp;
} else if (root->right == NULL) {
EmployeeNode* temp = root->left;
delete root;
return temp;
}
EmployeeNode* temp = findMin(root->right);
root->employeeNumber = temp->employeeNumber;
root->name = temp->name;
root->salary = temp->salary;
root->right = deleteEmployee(root->right, temp->employeeNumber);
}
return root;
}
void inOrder(EmployeeNode* root) {
if (root == NULL) return;
inOrder(root->left);
cout << root->employeeNumber << " " << root->name << " " << root->salary << endl;
inOrder(root->right);
}
void preOrder(EmployeeNode* root) {
if (root == NULL) return;
cout << root->employeeNumber << " " << root->name << " " << root->salary << endl;
preOrder(root->left);
preOrder(root->right);
}
void postOrder(EmployeeNode* root) {
if (root == NULL) return;
postOrder(root->left);
postOrder(root->right);
cout << root->employeeNumber << " " << root->name << " " << root->salary << endl;
}
int main() {
EmployeeNode* root = NULL;
root = insert(root, 101, "Hoor", 55000.00);
root = insert(root, 102, "Fatima", 45000.00);
root = insert(root, 103, "Amna", 75000.00);
root = insert(root, 104, "Saleha", 60000.00);
cout << "In-order Traversal:" << endl;
inOrder(root);
cout << "\nPre-order Traversal:" << endl;
preOrder(root);
cout << "\nPost-order Traversal:" << endl;
postOrder(root);
int searchEmpNo = 102;
EmployeeNode* found = search(root, searchEmpNo);
if (found != NULL) {
cout << "\nEmployee Found:\n";
cout << found->employeeNumber << " " << found->name << " " << found->salary<<endl;
} else {
cout << "\nEmployee with Number " << searchEmpNo << " not found." << endl;
}
int deleteEmpNo = 103;
root = deleteEmployee(root, deleteEmpNo);
cout << "\nAfter deleting employee with Number " << deleteEmpNo << ":\n";
inOrder(root);
return 0;
}
