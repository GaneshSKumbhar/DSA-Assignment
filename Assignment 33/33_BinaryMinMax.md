# Binary Search Tree (BST) Operations  
*(Create, Search, Find Minimum and Maximum)*

## Theory

A **Binary Search Tree (BST)** is a special kind of binary tree where every node follows the **BST property**:

1. The value of each node in the **left subtree** is **less than** the value of the root node.  
2. The value of each node in the **right subtree** is **greater than** the value of the root node.  
3. Both left and right subtrees are also Binary Search Trees.

BSTs allow **efficient searching, insertion, and deletion** with an average time complexity of **O(log n)** for balanced trees.

### Operations Performed
- **Create BST:** Insert nodes into the tree following BST rules.  
- **Search:** Locate a given element in the tree.  
- **Find Minimum:** Return the smallest value by traversing left until a leaf is reached.  
- **Find Maximum:** Return the largest value by traversing right until a leaf is reached.

---

## Algorithm

1. **Start**  
2. Create a structure `Node` with `data`, `left`, and `right` pointers.  
3. Implement functions:  
   - `insertNode()` → inserts elements maintaining BST property.  
   - `searchNode()` → searches for a specific element.  
   - `findMin()` → finds the leftmost node (minimum value).  
   - `findMax()` → finds the rightmost node (maximum value).  
4. In `main()`:  
   - Create an empty BST.  
   - Insert multiple nodes.  
   - Allow user to:  
     - Search for a value.  
     - Find Minimum or Maximum element.  
     - Display tree in Inorder (sorted order).  
5. **End**

---

## Code

```cpp

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk *left_gsk, *right_gsk;
    Node_gsk(int val_gsk) {
        data_gsk = val_gsk;
        left_gsk = right_gsk = nullptr;
    }
};

// Create Binary Tree in Level Order using user input
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

// Nonrecursive Inorder Traversal
void inorderTraversal_gsk(Node_gsk* root_gsk) {
    stack<Node_gsk*> s_gsk;
    Node_gsk* curr_gsk = root_gsk;

    cout << "Inorder Traversal: ";
    while (curr_gsk != nullptr || !s_gsk.empty()) {
        while (curr_gsk != nullptr) {
            s_gsk.push(curr_gsk);
            curr_gsk = curr_gsk->left_gsk;
        }
        curr_gsk = s_gsk.top();
        s_gsk.pop();
        cout << curr_gsk->data_gsk << " ";
        curr_gsk = curr_gsk->right_gsk;
    }
    cout << endl;
}

// Nonrecursive Preorder Traversal
void preorderTraversal_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;

    stack<Node_gsk*> s_gsk;
    s_gsk.push(root_gsk);

    cout << "Preorder Traversal: ";
    while (!s_gsk.empty()) {
        Node_gsk* curr_gsk = s_gsk.top();
        s_gsk.pop();
        cout << curr_gsk->data_gsk << " ";

        if (curr_gsk->right_gsk)
            s_gsk.push(curr_gsk->right_gsk);
        if (curr_gsk->left_gsk)
            s_gsk.push(curr_gsk->left_gsk);
    }
    cout << endl;
}

// Count Leaf Nodes
int countLeafNodes_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return 0;

    stack<Node_gsk*> s_gsk;
    s_gsk.push(root_gsk);
    int count_gsk = 0;

    while (!s_gsk.empty()) {
        Node_gsk* curr_gsk = s_gsk.top();
        s_gsk.pop();

        if (curr_gsk->left_gsk == nullptr && curr_gsk->right_gsk == nullptr)
            count_gsk++;

        if (curr_gsk->right_gsk)
            s_gsk.push(curr_gsk->right_gsk);
        if (curr_gsk->left_gsk)
            s_gsk.push(curr_gsk->left_gsk);
    }
    return count_gsk;
}

// Mirror Image of Tree
void mirrorImage_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;

    swap(root_gsk->left_gsk, root_gsk->right_gsk);
    mirrorImage_gsk(root_gsk->left_gsk);
    mirrorImage_gsk(root_gsk->right_gsk);
}

// Display Inorder Traversal (for mirror verification)
void displayInorder_gsk(Node_gsk* root_gsk) {
    if (root_gsk == nullptr)
        return;
    displayInorder_gsk(root_gsk->left_gsk);
    cout << root_gsk->data_gsk << " ";
    displayInorder_gsk(root_gsk->right_gsk);
}

int main() {
    int n_gsk;
    cout << "Enter total number of nodes in the tree: ";
    cin >> n_gsk;

    Node_gsk* root_gsk = createTree_gsk(n_gsk);

    cout << "\n--- Binary Tree Operations ---\n";
    inorderTraversal_gsk(root_gsk);
    preorderTraversal_gsk(root_gsk);

    cout << "Number of Leaf Nodes: " << countLeafNodes_gsk(root_gsk) << endl;

    cout << "\nCreating Mirror Image of the Tree...\n";
    mirrorImage_gsk(root_gsk);

    cout << "Inorder Traversal of Mirror Image: ";
    displayInorder_gsk(root_gsk);
    cout << endl;

    return 0;
}
```
---

## Sample Output

```
Binary Search Tree Operations
1. Insert Node
2. Search Node
3. Find Minimum
4. Find Maximum
5. Display Inorder
6. Exit

Enter your choice: 1
Enter value to insert: 50
Enter your choice: 1
Enter value to insert: 30
Enter your choice: 1
Enter value to insert: 70
Enter your choice: 1
Enter value to insert: 20
Enter your choice: 1
Enter value to insert: 40
Enter your choice: 1
Enter value to insert: 60
Enter your choice: 1
Enter value to insert: 80

Enter your choice: 5
Inorder Traversal: 20 30 40 50 60 70 80 

Enter your choice: 2
Enter value to search: 60
60 found in the BST.

Enter your choice: 3
Minimum value in BST: 20

Enter your choice: 4
Maximum value in BST: 80

Enter your choice: 6
Exiting...
```