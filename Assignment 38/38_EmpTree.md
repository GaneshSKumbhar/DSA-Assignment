# Employee Record Management using Tree Data Structure  
*(Search and Sort Employee Data by Employee ID)*

## Theory

A **Binary Search Tree (BST)** is an efficient data structure for organizing and searching records.  
Each node in a BST contains a key (here, `Employee ID`) and associated information (like `Name`, `Designation`, etc.).

**Key Properties of BST:**
- Left child < Parent < Right child
- Enables efficient searching, insertion, and sorting operations.
- Inorder traversal of BST gives records in **ascending order** of keys.

This program stores **employee records** in a BST and allows efficient searching and sorting based on **Employee ID**.

---

## Algorithm

1. Start  
2. Define a structure `Employee` containing:
   - `emp_id`
   - `name`
   - `designation`
   - pointers to left and right subtrees  
3. Implement the following:
   - **Insert:** Add a new employee maintaining BST order by `emp_id`.  
   - **Search:** Locate an employee record by their `emp_id`.  
   - **Display (Sort):** Use inorder traversal to display employees sorted by `emp_id`.  
4. Use a menu-driven program to perform operations.  
5. End

---

## Code

```cpp
#include <iostream>
#include <string>
using namespace std;

// Structure for Employee node
struct Employee_gsk {
    int emp_id_gsk;
    string name_gsk;
    string designation_gsk;
    Employee_gsk *left_gsk, *right_gsk;

    Employee_gsk(int id_gsk, string name_gsk, string desg_gsk) {
        emp_id_gsk = id_gsk;
        this->name_gsk = name_gsk;
        this->designation_gsk = desg_gsk;
        left_gsk = right_gsk = nullptr;
    }
};

// Insert employee into BST
Employee_gsk* insertEmployee_gsk(Employee_gsk* root_gsk, int id_gsk, string name_gsk, string desg_gsk) {
    if (root_gsk == nullptr)
        return new Employee_gsk(id_gsk, name_gsk, desg_gsk);

    if (id_gsk < root_gsk->emp_id_gsk)
        root_gsk->left_gsk = insertEmployee_gsk(root_gsk->left_gsk, id_gsk, name_gsk, desg_gsk);
    else if (id_gsk > root_gsk->emp_id_gsk)
        root_gsk->right_gsk = insertEmployee_gsk(root_gsk->right_gsk, id_gsk, name_gsk, desg_gsk);

    return root_gsk;
}

// Search employee by ID
Employee_gsk* searchEmployee_gsk(Employee_gsk* root_gsk, int id_gsk) {
    if (root_gsk == nullptr || root_gsk->emp_id_gsk == id_gsk)
        return root_gsk;
    if (id_gsk < root_gsk->emp_id_gsk)
        return searchEmployee_gsk(root_gsk->left_gsk, id_gsk);
    else
        return searchEmployee_gsk(root_gsk->right_gsk, id_gsk);
}

// Display employee records in ascending order of emp_id
void inorderDisplay_gsk(Employee_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    inorderDisplay_gsk(root_gsk->left_gsk);
    cout << "Emp ID: " << root_gsk->emp_id_gsk
         << " | Name: " << root_gsk->name_gsk
         << " | Designation: " << root_gsk->designation_gsk << endl;
    inorderDisplay_gsk(root_gsk->right_gsk);
}

int main() {
    Employee_gsk* root_gsk = nullptr;
    int choice_gsk, id_gsk;
    string name_gsk, desg_gsk;

    while (true) {
        cout << "\n--- Employee Record Management ---\n";
        cout << "1. Insert Employee\n2. Search Employee\n3. Display All (Sorted by Emp ID)\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter Employee ID: ";
                cin >> id_gsk;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name_gsk);
                cout << "Enter Designation: ";
                getline(cin, desg_gsk);
                root_gsk = insertEmployee_gsk(root_gsk, id_gsk, name_gsk, desg_gsk);
                cout << "Employee record inserted successfully.\n";
                break;

            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> id_gsk;
                {
                    Employee_gsk* result = searchEmployee_gsk(root_gsk, id_gsk);
                    if (result)
                        cout << "Record Found -> ID: " << result->emp_id_gsk
                             << ", Name: " << result->name_gsk
                             << ", Designation: " << result->designation_gsk << endl;
                    else
                        cout << "Employee not found.\n";
                }
                break;

            case 3:
                cout << "\nEmployee Records (Sorted by ID):\n";
                inorderDisplay_gsk(root_gsk);
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
```
---

## Sample Output

```
--- Employee Record Management ---
1. Insert Employee
2. Search Employee
3. Display All (Sorted by Emp ID)
4. Exit
Enter your choice: 1
Enter Employee ID: 102
Enter Name: Rahul
Enter Designation: Manager
Employee record inserted successfully.

Enter your choice: 1
Enter Employee ID: 101
Enter Name: Neha
Enter Designation: Developer
Employee record inserted successfully.

Enter your choice: 3

Employee Records (Sorted by ID):
Emp ID: 101 | Name: Neha | Designation: Developer
Emp ID: 102 | Name: Rahul | Designation: Manager

Enter your choice: 2
Enter Employee ID to search: 102
Record Found -> ID: 102, Name: Rahul, Designation: Manager
```
