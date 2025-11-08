# Bubble Sort Using Doubly Linked List

## Theory
This program demonstrates sorting of a doubly linked list using the Bubble Sort algorithm:
- Each node contains a data value and pointers to the previous and next nodes.
- Bubble Sort repeatedly compares adjacent nodes and swaps their data if they are in the wrong order.
- Sorting is performed in ascending order.

---

## Algorithm

### Bubble Sort on Doubly Linked List
1. Input the number of elements.
2. Randomly generate node values and create a doubly linked list.
3. Traverse the list repeatedly:
   - Compare each node with its next node.
   - Swap data if the current node is greater than the next node.
4. Repeat until the entire list is sorted.
5. Display the sorted list.

---

## Code

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk* prev_gsk;
    Node_gsk* next_gsk;
};

class DoublyLinkedList_gsk {
    Node_gsk* head_gsk;
public:
    DoublyLinkedList_gsk() : head_gsk(nullptr) {}

    void append_gsk(int data_gsk) {
        Node_gsk* newNode_gsk = new Node_gsk{data_gsk, nullptr, nullptr};
        if (!head_gsk) {
            head_gsk = newNode_gsk;
            return;
        }
        Node_gsk* temp_gsk = head_gsk;
        while (temp_gsk->next_gsk) temp_gsk = temp_gsk->next_gsk;
        temp_gsk->next_gsk = newNode_gsk;
        newNode_gsk->prev_gsk = temp_gsk;
    }

    void display_gsk() const {
        Node_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            cout << temp_gsk->data_gsk << " ";
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }

    void bubbleSort_gsk() {
        if (!head_gsk) return;
        bool swapped_gsk;
        Node_gsk* ptr1_gsk;
        Node_gsk* lptr_gsk = nullptr;

        do {
            swapped_gsk = false;
            ptr1_gsk = head_gsk;

            while (ptr1_gsk->next_gsk != lptr_gsk) {
                if (ptr1_gsk->data_gsk > ptr1_gsk->next_gsk->data_gsk) {
                    swap(ptr1_gsk->data_gsk, ptr1_gsk->next_gsk->data_gsk);
                    swapped_gsk = true;
                }
                ptr1_gsk = ptr1_gsk->next_gsk;
            }
            lptr_gsk = ptr1_gsk;
        } while (swapped_gsk);
    }
};

int main() {
    srand(time(0));
    DoublyLinkedList_gsk dll_gsk;
    int n_gsk;
    cout << "Enter the number of elements: ";
    cin >> n_gsk;

    for (int i = 0; i < n_gsk; ++i) {
        int val_gsk = 1 + rand() % 100;
        dll_gsk.append_gsk(val_gsk);
    }

    cout << "\nOriginal List: ";
    dll_gsk.display_gsk();

    dll_gsk.bubbleSort_gsk();

    cout << "Sorted List: ";
    dll_gsk.display_gsk();

    return 0;
}
```
---

## Sample Output

```
Enter the number of elements: 5

Original List: 45 12 78 33 5 
Sorted List: 5 12 33 45 78
```