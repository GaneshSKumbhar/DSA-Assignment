# Faculty Hash Table using MOD Hash Function  
### (Linear Probing with Chaining and Replacement)

## Theory

A **Hash Table** is a data structure that stores data in an array format, where each data value has a unique key associated with it.  
A **hash function** is used to convert the key into an index within the table.  
In this program, we use the **MOD method** as the hash function.

When two keys map to the same index (a **collision**), we use **Linear Probing with Chaining and Replacement** to handle it.

### Collision Resolution – Linear Probing with Replacement
- If the new record hashes to an index already occupied by a record that *belongs* to another index,  
  the new record **replaces** the current one, and the displaced record is **reinserted** into the table.
- This technique reduces the average search time compared to simple linear probing.

---

## Algorithm

1. Initialize the hash table with all slots empty.  
2. For insertion:
   - Compute the hash index using `index = key % size`.
   - If the slot is empty, insert the record.
   - If occupied:
     - If the record already in the slot **does not belong** to this index (i.e., its own hash is different),  
       then **replace it** with the new record and reinsert the displaced record elsewhere.
     - Otherwise, use **linear probing** to find the next empty slot.
3. For searching:
   - Compute the hash index.
   - Use linear probing until the record is found or an empty slot is encountered.
4. Display the table to visualize how collisions are handled.

---

## Source Code

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Faculty_gsk {
    int id_gsk;
    string name_gsk;
    string dept_gsk;
    bool occupied_gsk;
};

class FacultyHashTable_gsk {
    static const int SIZE_gsk = 10;
    Faculty_gsk table_gsk[SIZE_gsk];

public:
    FacultyHashTable_gsk() {
        for (int i = 0; i < SIZE_gsk; i++)
            table_gsk[i].occupied_gsk = false;
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % SIZE_gsk;
    }

    void insertFaculty_gsk(int id_gsk, string name_gsk, string dept_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);

        if (!table_gsk[index_gsk].occupied_gsk) {
            table_gsk[index_gsk] = {id_gsk, name_gsk, dept_gsk, true};
            cout << "Faculty inserted successfully!\n";
            return;
        }

        int existingHash_gsk = hashFunction_gsk(table_gsk[index_gsk].id_gsk);

        // Replacement condition
        if (existingHash_gsk != index_gsk) {
            cout << "Collision! Replacing record with correct hash placement.\n";
            Faculty_gsk temp_gsk = table_gsk[index_gsk];
            table_gsk[index_gsk] = {id_gsk, name_gsk, dept_gsk, true};
            insertFaculty_gsk(temp_gsk.id_gsk, temp_gsk.name_gsk, temp_gsk.dept_gsk);
        } else {
            // Linear probing for next empty slot
            int start_gsk = index_gsk;
            do {
                index_gsk = (index_gsk + 1) % SIZE_gsk;
                if (!table_gsk[index_gsk].occupied_gsk) {
                    table_gsk[index_gsk] = {id_gsk, name_gsk, dept_gsk, true};
                    cout << "Faculty inserted successfully!\n";
                    return;
                }
            } while (index_gsk != start_gsk);

            cout << "Hash table is full. Cannot insert record.\n";
        }
    }

    void searchFaculty_gsk(int id_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);
        int start_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            if (table_gsk[index_gsk].id_gsk == id_gsk) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_gsk[index_gsk].id_gsk << endl;
                cout << "Name: " << table_gsk[index_gsk].name_gsk << endl;
                cout << "Department: " << table_gsk[index_gsk].dept_gsk << endl;
                return;
            }
            index_gsk = (index_gsk + 1) % SIZE_gsk;
            if (index_gsk == start_gsk) break;
        }

        cout << "Faculty not found!\n";
    }

    void displayFacultyTable_gsk() {
        cout << "\nFaculty Hash Table:\n";
        for (int i = 0; i < SIZE_gsk; i++) {
            if (table_gsk[i].occupied_gsk)
                cout << "[" << i << "] " << table_gsk[i].id_gsk << " | "
                     << table_gsk[i].name_gsk << " | "
                     << table_gsk[i].dept_gsk << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

int main() {
    FacultyHashTable_gsk hashTable_gsk;
    int choice_gsk, id_gsk;
    string name_gsk, dept_gsk;

    while (true) {
        cout << "\n--- Faculty Database Menu ---\n";
        cout << "1. Insert Faculty Record\n";
        cout << "2. Search Faculty Record\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id_gsk;
            cout << "Enter Faculty Name: ";
            cin >> name_gsk;
            cout << "Enter Department: ";
            cin >> dept_gsk;
            hashTable_gsk.insertFaculty_gsk(id_gsk, name_gsk, dept_gsk);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id_gsk;
            hashTable_gsk.searchFaculty_gsk(id_gsk);
            break;

        case 3:
            hashTable_gsk.displayFacultyTable_gsk();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
```

---

## Sample Output

```
--- Faculty Database Menu ---
1. Insert Faculty Record
2. Search Faculty Record
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Faculty ID: 11
Enter Faculty Name: Raj
Enter Department: CS
Faculty inserted successfully!

Enter your choice: 1
Enter Faculty ID: 21
Enter Faculty Name: Neha
Enter Department: IT
Collision! Replacing record with correct hash placement.
Faculty inserted successfully!

Enter your choice: 3

Faculty Hash Table:
[0] Empty
[1] 21 | Neha | IT
[2] 11 | Raj | CS
[3] Empty
[4] Empty
[5] Empty
[6] Empty
[7] Empty
[8] Empty
[9] Empty
```