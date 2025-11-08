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