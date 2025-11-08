
#include <iostream>
#include <algorithm>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk* left_gsk;
    Node_gsk* right_gsk;
    Node_gsk(int val_gsk) {
        data_gsk = val_gsk;
        left_gsk = right_gsk = nullptr;
    }
};

// Insert a new node into the BST
Node_gsk* insertNode_gsk(Node_gsk* root_gsk, int val_gsk) {
    if (root_gsk == nullptr)
        return new Node_gsk(val_gsk);
    if (val_gsk < root_gsk->data_gsk)
        root_gsk->left_gsk = insertNode_gsk(root_gsk->left_gsk, val_gsk);
    else if (val_gsk > root_gsk->data_gsk)
        root_gsk->right_gsk = insertNode_gsk(root_gsk->right_gsk, val_gsk);
    return root_gsk;
}

// Count total number of nodes
int countNodes_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return 0;
    return 1 + countNodes_gsk(root_gsk->left_gsk) + countNodes_gsk(root_gsk->right_gsk);
}

// Compute height of BST
int heightBST_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return -1;  // or return 0 if you prefer counting nodes instead of edges
    return 1 + max(heightBST_gsk(root_gsk->left_gsk), heightBST_gsk(root_gsk->right_gsk));
}

// Mirror the BST
void mirrorTree_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    swap(root_gsk->left_gsk, root_gsk->right_gsk);
    mirrorTree_gsk(root_gsk->left_gsk);
    mirrorTree_gsk(root_gsk->right_gsk);
}

// Inorder traversal (Left → Root → Right)
void inorderTraversal_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    inorderTraversal_gsk(root_gsk->left_gsk);
    cout << root_gsk->data_gsk << " ";
    inorderTraversal_gsk(root_gsk->right_gsk);
}

int main() {
    Node_gsk* root_gsk = nullptr;
    int choice_gsk, val_gsk;

    cout << "Binary Search Tree Operations\n";
    cout << "1. Insert Node\n2. Count Total Nodes\n3. Compute Height\n4. Mirror Tree\n5. Display Inorder\n6. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val_gsk;
                root_gsk = insertNode_gsk(root_gsk, val_gsk);
                break;

            case 2:
                cout << "Total number of nodes: " << countNodes_gsk(root_gsk) << endl;
                break;

            case 3:
                cout << "Height of the BST: " << heightBST_gsk(root_gsk) << endl;
                break;

            case 4:
                mirrorTree_gsk(root_gsk);
                cout << "Mirror image of BST created successfully.\n";
                break;

            case 5:
                cout << "Inorder Traversal: ";
                inorderTraversal_gsk(root_gsk);
                cout << endl;
                break;

            case 6:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
