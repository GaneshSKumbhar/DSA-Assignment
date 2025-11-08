# Store and Retrieve Student Records Using Roll Numbers

## Theory

A **student record management system** is used to store and retrieve information about students efficiently.  
Each student record contains attributes such as **roll number, name, and marks** (or other data).  

To make the process efficient, we use a **hash table** where each roll number is hashed to a unique index.  
This allows **constant-time insertion and retrieval (O(1))** on average.  

Collisions are handled using **linear probing** — if the computed hash index is occupied, we sequentially check the next available index in the table.

---

## Algorithm

### Steps:

1. **Start**
2. Define a structure `Student` with fields:
   - `roll` (integer)
   - `name` (string)
   - `marks` (float)
3. Create an array (hash table) of fixed size, initialized to `NULL`.
4. Define a **hash function**:  
   `index = roll % table_size`
5. **Insertion:**
   - Compute the hash index using the roll number.
   - If the index is occupied, move to the next index (linear probing).
   - Store the student record.
6. **Search:**
   - Compute the hash index using the roll number.
   - Traverse until the record with the same roll number is found or an empty slot is reached.
7. **Display** all stored student records.
8. **End**

---

## Source Code

```cpp
#include <iostream>
#include <string>
using namespace std;

const int SIZE_gsk = 10;

struct Student_gsk {
    int roll_gsk;
    string name_gsk;
    float marks_gsk;
    bool occupied_gsk;
};

class HashTable_gsk {
    Student_gsk table_gsk[SIZE_gsk];

public:
    HashTable_gsk() {
        for (int i = 0; i < SIZE_gsk; i++)
            table_gsk[i].occupied_gsk = false;
    }

    int hashFunction_gsk(int roll_gsk) {
        return roll_gsk % SIZE_gsk;
    }

    void insertRecord_gsk(int roll_gsk, string name_gsk, float marks_gsk) {
        int index_gsk = hashFunction_gsk(roll_gsk);
        int startIndex_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            index_gsk = (index_gsk + 1) % SIZE_gsk;
            if (index_gsk == startIndex_gsk) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        table_gsk[index_gsk].roll_gsk = roll_gsk;
        table_gsk[index_gsk].name_gsk = name_gsk;
        table_gsk[index_gsk].marks_gsk = marks_gsk;
        table_gsk[index_gsk].occupied_gsk = true;
        cout << "Record inserted successfully!" << endl;
    }

    void searchRecord_gsk(int roll_gsk) {
        int index_gsk = hashFunction_gsk(roll_gsk);
        int startIndex_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            if (table_gsk[index_gsk].roll_gsk == roll_gsk) {
                cout << "\nRecord Found:\n";
                cout << "Roll: " << table_gsk[index_gsk].roll_gsk
                     << "\nName: " << table_gsk[index_gsk].name_gsk
                     << "\nMarks: " << table_gsk[index_gsk].marks_gsk << endl;
                return;
            }
            index_gsk = (index_gsk + 1) % SIZE_gsk;
            if (index_gsk == startIndex_gsk)
                break;
        }

        cout << "Record not found!" << endl;
    }

    void display_gsk() {
        cout << "\nStored Records:\n";
        for (int i = 0; i < SIZE_gsk; i++) {
            if (table_gsk[i].occupied_gsk)
                cout << "Index " << i << " -> Roll: " << table_gsk[i].roll_gsk
                     << ", Name: " << table_gsk[i].name_gsk
                     << ", Marks: " << table_gsk[i].marks_gsk << endl;
            else
                cout << "Index " << i << " -> Empty\n";
        }
    }
};

int main() {
    HashTable_gsk ht_gsk;
    int choice_gsk;

    while (true) {
        cout << "\n1. Insert Record\n2. Search Record\n3. Display Records\n4. Exit\nEnter choice: ";
        cin >> choice_gsk;

        if (choice_gsk == 1) {
            int roll_gsk;
            string name_gsk;
            float marks_gsk;
            cout << "Enter Roll No, Name, and Marks: ";
            cin >> roll_gsk >> name_gsk >> marks_gsk;
            ht_gsk.insertRecord_gsk(roll_gsk, name_gsk, marks_gsk);
        }
        else if (choice_gsk == 2) {
            int roll_gsk;
            cout << "Enter Roll No to search: ";
            cin >> roll_gsk;
            ht_gsk.searchRecord_gsk(roll_gsk);
        }
        else if (choice_gsk == 3) {
            ht_gsk.display_gsk();
        }
        else if (choice_gsk == 4) {
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
```

---

## Sample Output

```
1. Insert Record
2. Search Record
3. Display Records
4. Exit
Enter choice: 1
Enter Roll No, Name, and Marks: 12 Ganesh 85
Record inserted successfully!

Enter choice: 1
Enter Roll No, Name, and Marks: 22 Shankar 90
Record inserted successfully!

Enter choice: 3

Stored Records:
Index 2 -> Roll: 12, Name: Ganesh, Marks: 85
Index 3 -> Roll: 22, Name: Shankar, Marks: 90

Enter choice: 2
Enter Roll No to search: 12
Record Found:
Roll: 12
Name: Ganesh
Marks: 85
```
