# Binary Tree – Recursive Operations  
*(Inorder, Preorder, Leaf Count, Mirror Image – Recursive)*

## Theory

A **Binary Tree** is a hierarchical data structure in which each node has at most **two children** — a **left** and a **right** child.  
Recursion provides a natural and simple way to traverse and manipulate binary trees, as each subtree of a node is itself a binary tree.

### Operations Performed
- **Inorder Traversal (Recursive):** Visit Left → Root → Right  
- **Preorder Traversal (Recursive):** Visit Root → Left → Right  
- **Count Leaf Nodes:** Count nodes with no children.  
- **Mirror Image:** Swap the left and right subtrees of each node recursively.

---

## Algorithm

1. **Start**  
2. Define a structure `Node` with fields `data`, `left`, and `right`.  
3. Input number of nodes `n`.  
4. Create the Binary Tree in **level-order** fashion using a queue and user input.  
5. Implement recursive functions:
   - `inorderTraversal(root)`
   - `preorderTraversal(root)`
   - `countLeafNodes(root)`
   - `mirrorImage(root)`
6. Perform and display results of all operations.  
7. **End**

---

## Code

```cpp
#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node_gsk {
    int data_gsk;
    Node_gsk *left_gsk, *right_gsk;
    Node_gsk(int val_gsk) {
        data_gsk = val_gsk;
        left_gsk = right_gsk = nullptr;
    }
};

// Create Binary Tree using level order input
Node_gsk* createTree_gsk(int n_gsk) {
    if (n_gsk <= 0) return nullptr;

    int val_gsk;
    cout << "Enter value for root node: ";
    cin >> val_gsk;

    Node_gsk* root_gsk = new Node_gsk(val_gsk);
    queue<Node_gsk*> q_gsk;
    q_gsk.push(root_gsk);
    int count_gsk = 1;

    while (count_gsk < n_gsk) {
        Node_gsk* curr_gsk = q_gsk.front();
        q_gsk.pop();

        int leftVal_gsk, rightVal_gsk;

        cout << "Enter left child of " << curr_gsk->data_gsk << " (-1 for no child): ";
        cin >> leftVal_gsk;
        if (leftVal_gsk != -1) {
            curr_gsk->left_gsk = new Node_gsk(leftVal_gsk);
            q_gsk.push(curr_gsk->left_gsk);
            count_gsk++;
            if (count_gsk == n_gsk) break;
        }

        cout << "Enter right child of " << curr_gsk->data_gsk << " (-1 for no child): ";
        cin >> rightVal_gsk;
        if (rightVal_gsk != -1) {
            curr_gsk->right_gsk = new Node_gsk(rightVal_gsk);
            q_gsk.push(curr_gsk->right_gsk);
            count_gsk++;
        }
    }

    return root_gsk;
}

// Recursive Inorder Traversal
void inorderTraversal_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    inorderTraversal_gsk(root_gsk->left_gsk);
    cout << root_gsk->data_gsk << " ";
    inorderTraversal_gsk(root_gsk->right_gsk);
}

// Recursive Preorder Traversal
void preorderTraversal_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    cout << root_gsk->data_gsk << " ";
    preorderTraversal_gsk(root_gsk->left_gsk);
    preorderTraversal_gsk(root_gsk->right_gsk);
}

// Count Leaf Nodes (Recursive)
int countLeafNodes_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return 0;
    if (root_gsk->left_gsk == nullptr && root_gsk->right_gsk == nullptr)
        return 1;
    return countLeafNodes_gsk(root_gsk->left_gsk) + countLeafNodes_gsk(root_gsk->right_gsk);
}

// Mirror Image (Recursive)
void mirrorImage_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    swap(root_gsk->left_gsk, root_gsk->right_gsk);
    mirrorImage_gsk(root_gsk->left_gsk);
    mirrorImage_gsk(root_gsk->right_gsk);
}

int main() {
    int n_gsk;
    cout << "Enter total number of nodes in the tree: ";
    cin >> n_gsk;

    Node_gsk* root_gsk = createTree_gsk(n_gsk);

    cout << "\n--- Binary Tree Recursive Operations ---\n";

    cout << "Inorder Traversal: ";
    inorderTraversal_gsk(root_gsk);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal_gsk(root_gsk);
    cout << endl;

    cout << "Number of Leaf Nodes: " << countLeafNodes_gsk(root_gsk) << endl;

    cout << "\nCreating Mirror Image of the Tree...\n";
    mirrorImage_gsk(root_gsk);

    cout << "Inorder Traversal of Mirror Image: ";
    inorderTraversal_gsk(root_gsk);
    cout << endl;

    return 0;
}
```
---

## Sample Output

```
Enter total number of nodes in the tree: 7
Enter value for root node: 1
Enter left child of 1 (-1 for no child): 2
Enter right child of 1 (-1 for no child): 3
Enter left child of 2 (-1 for no child): 4
Enter right child of 2 (-1 for no child): 5
Enter left child of 3 (-1 for no child): 6
Enter right child of 3 (-1 for no child): 7

--- Binary Tree Recursive Operations ---
Inorder Traversal: 4 2 5 1 6 3 7 
Preorder Traversal: 1 2 4 5 3 6 7 
Number of Leaf Nodes: 4

Creating Mirror Image of the Tree...
Inorder Traversal of Mirror Image: 7 3 6 1 5 2 4
```
