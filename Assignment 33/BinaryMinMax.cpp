#include <iostream>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk* left_gsk;
    Node_gsk* right_gsk;
};

// Create a new node
Node_gsk* createNode_gsk(int value_gsk) {
    Node_gsk* newNode_gsk = new Node_gsk;
    newNode_gsk->data_gsk = value_gsk;
    newNode_gsk->left_gsk = newNode_gsk->right_gsk = nullptr;
    return newNode_gsk;
}

// Insert node into BST
Node_gsk* insertNode_gsk(Node_gsk* root_gsk, int value_gsk) {
    if (root_gsk == nullptr)
        return createNode_gsk(value_gsk);
    if (value_gsk < root_gsk->data_gsk)
        root_gsk->left_gsk = insertNode_gsk(root_gsk->left_gsk, value_gsk);
    else if (value_gsk > root_gsk->data_gsk)
        root_gsk->right_gsk = insertNode_gsk(root_gsk->right_gsk, value_gsk);
    return root_gsk;
}

// Search for a value in BST
bool searchNode_gsk(Node_gsk* root_gsk, int key_gsk) {
    if (root_gsk == nullptr)
        return false;
    if (root_gsk->data_gsk == key_gsk)
        return true;
    else if (key_gsk < root_gsk->data_gsk)
        return searchNode_gsk(root_gsk->left_gsk, key_gsk);
    else
        return searchNode_gsk(root_gsk->right_gsk, key_gsk);
}

// Find minimum value node
Node_gsk* findMin_gsk(Node_gsk* root_gsk) {
    while (root_gsk && root_gsk->left_gsk != nullptr)
        root_gsk = root_gsk->left_gsk;
    return root_gsk;
}

// Find maximum value node
Node_gsk* findMax_gsk(Node_gsk* root_gsk) {
    while (root_gsk && root_gsk->right_gsk != nullptr)
        root_gsk = root_gsk->right_gsk;
    return root_gsk;
}

// Display BST using Inorder Traversal
void inorderTraversal_gsk(Node_gsk* root_gsk) {
    if (root_gsk != nullptr) {
        inorderTraversal_gsk(root_gsk->left_gsk);
        cout << root_gsk->data_gsk << " ";
        inorderTraversal_gsk(root_gsk->right_gsk);
    }
}

// Main Function
int main() {
    Node_gsk* root_gsk = nullptr;
    int choice_gsk, value_gsk;

    while (true) {
        cout << "\n--- Binary Search Tree Operations ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
        cout << "5. Display Inorder Traversal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value_gsk;
                root_gsk = insertNode_gsk(root_gsk, value_gsk);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value_gsk;
                if (searchNode_gsk(root_gsk, value_gsk))
                    cout << value_gsk << " found in the BST.\n";
                else
                    cout << value_gsk << " not found in the BST.\n";
                break;

            case 3:
                if (root_gsk)
                    cout << "Minimum value in BST: " << findMin_gsk(root_gsk)->data_gsk << endl;
                else
                    cout << "BST is empty.\n";
                break;

            case 4:
                if (root_gsk)
                    cout << "Maximum value in BST: " << findMax_gsk(root_gsk)->data_gsk << endl;
                else
                    cout << "BST is empty.\n";
                break;

            case 5:
                cout << "Inorder Traversal (sorted order): ";
                inorderTraversal_gsk(root_gsk);
                cout << endl;
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}