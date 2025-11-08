# Collision Resolution using Linked Lists

## Theory

When two or more keys hash to the same index in a hash table, a **collision** occurs.  
One effective way to handle collisions is through **Linked Lists (Separate Chaining)**.  

In this approach, each cell in the hash table stores a **linked list** of elements that hash to the same index.  
When inserting, if a collision occurs, the new key is added to the linked list at that index.  
During searching or deletion, traversal of the linked list is performed to find or remove the desired key.

### Advantages:
- Handles collisions efficiently.
- The number of keys can exceed the hash table size.
- Simple to implement.

### Disadvantages:
- May lead to longer chains, increasing search time.
- Requires additional memory for linked list pointers.

---

## Algorithm

1. **Initialize** a hash table with all entries as `NULL`.
2. **Hash Function:** Calculate `index = key % table_size`.
3. **Insertion:**
   - Create a new node with the given key.
   - Insert it at the beginning of the linked list at `hashTable[index]`.
4. **Search:**
   - Compute the hash index.
   - Traverse the linked list at that index to find the key.
5. **Deletion:**
   - Locate the key in the linked list.
   - Remove the corresponding node.
6. **Display:** Print all elements from each linked list in the table.

---

## Source Code

```cpp
#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class HashTable_gsk {
    int size_gsk;
    list<int>* table_gsk;

public:
    HashTable_gsk(int size) {
        size_gsk = size;
        table_gsk = new list<int>[size_gsk];
    }

    int hashFunction_gsk(int key) {
        return key % size_gsk;
    }

    void insert_gsk(int key) {
        int index = hashFunction_gsk(key);
        table_gsk[index].push_back(key);
    }

    void deleteKey_gsk(int key) {
        int index = hashFunction_gsk(key);
        table_gsk[index].remove(key);
    }

    void search_gsk(int key) {
        int index = hashFunction_gsk(key);
        bool found = false;
        for (auto it = table_gsk[index].begin(); it != table_gsk[index].end(); ++it) {
            if (*it == key) {
                found = true;
                break;
            }
        }
        if (found)
            cout << key << " found at index " << index << endl;
        else
            cout << key << " not found in hash table" << endl;
    }

    void display_gsk() {
        for (int i = 0; i < size_gsk; i++) {
            cout << i << " --> ";
            for (auto x : table_gsk[i])
                cout << x << " ";
            cout << endl;
        }
    }
};

int main() {
    int size_gsk, choice_gsk, key_gsk;
    cout << "Enter hash table size: ";
    cin >> size_gsk;

    HashTable_gsk h(size_gsk);

    do {
        cout << "\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_gsk;
                h.insert_gsk(key_gsk);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key_gsk;
                h.deleteKey_gsk(key_gsk);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key_gsk;
                h.search_gsk(key_gsk);
                break;
            case 4:
                h.display_gsk();
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!";
        }
    } while (choice_gsk != 5);

    return 0;
}
```

---

## Sample Output

```
Enter hash table size: 5

1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 12

Enter your choice: 1
Enter key to insert: 22

Enter your choice: 1
Enter key to insert: 42

Enter your choice: 4
0 --> 
1 --> 
2 --> 12 22 42 
3 --> 
4 --> 

Enter your choice: 3
Enter key to search: 22
22 found at index 2

Enter your choice: 2
Enter key to delete: 22

Enter your choice: 4
0 --> 
1 --> 
2 --> 12 42 
3 --> 
4 --> 

Enter your choice: 5
Exiting...
```
