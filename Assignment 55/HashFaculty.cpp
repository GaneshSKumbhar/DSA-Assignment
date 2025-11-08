#include <iostream>
#include <string>
using namespace std;

struct Faculty_gsk {
    int id_gsk;
    string name_gsk;
    string department_gsk;
    bool occupied_gsk;
};

class HashTable_gsk {
    Faculty_gsk table_gsk[10];
    int size_gsk;

public:
    HashTable_gsk() {
        size_gsk = 10;
        for (int i = 0; i < size_gsk; i++) {
            table_gsk[i].occupied_gsk = false;
        }
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % size_gsk; // Divide method
    }

    void insertRecord_gsk(int id_gsk, string name_gsk, string dept_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);
        int start_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            index_gsk = (index_gsk + 1) % size_gsk;
            if (index_gsk == start_gsk) {
                cout << "Hash Table is full!" << endl;
                return;
            }
        }

        table_gsk[index_gsk].id_gsk = id_gsk;
        table_gsk[index_gsk].name_gsk = name_gsk;
        table_gsk[index_gsk].department_gsk = dept_gsk;
        table_gsk[index_gsk].occupied_gsk = true;

        cout << "Record inserted successfully!" << endl;
    }

    void searchRecord_gsk(int id_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);
        int start_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            if (table_gsk[index_gsk].id_gsk == id_gsk) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table_gsk[index_gsk].id_gsk << endl;
                cout << "Name: " << table_gsk[index_gsk].name_gsk << endl;
                cout << "Department: " << table_gsk[index_gsk].department_gsk << endl;
                return;
            }
            index_gsk = (index_gsk + 1) % size_gsk;
            if (index_gsk == start_gsk)
                break;
        }

        cout << "Faculty not found!" << endl;
    }

    void displayTable_gsk() {
        cout << "\nFaculty Hash Table:\n";
        for (int i = 0; i < size_gsk; i++) {
            if (table_gsk[i].occupied_gsk)
                cout << "[" << i << "] "
                     << table_gsk[i].id_gsk << " | "
                     << table_gsk[i].name_gsk << " | "
                     << table_gsk[i].department_gsk << endl;
            else
                cout << "[" << i << "] Empty\n";
        }
    }
};

int main() {
    HashTable_gsk ht_gsk;
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
            ht_gsk.insertRecord_gsk(id_gsk, name_gsk, dept_gsk);
            break;
        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id_gsk;
            ht_gsk.searchRecord_gsk(id_gsk);
            break;
        case 3:
            ht_gsk.displayTable_gsk();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
