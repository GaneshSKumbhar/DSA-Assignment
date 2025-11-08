#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int SIZE_gsk = 10;

struct Employee_gsk {
    int id_gsk;
    string name_gsk;
    string dept_gsk;
    bool occupied_gsk;
};

class HashTable_gsk {
    Employee_gsk table_gsk[SIZE_gsk];

public:
    HashTable_gsk() {
        for (int i = 0; i < SIZE_gsk; i++)
            table_gsk[i].occupied_gsk = false;
    }

    int midSquareHash_gsk(int key_gsk) {
        long long square_gsk = (long long)key_gsk * key_gsk;
        string sqStr_gsk = to_string(square_gsk);
        int len_gsk = sqStr_gsk.length();
        int mid_gsk = len_gsk / 2;

        // Extract 2 middle digits
        string midDigits_gsk = sqStr_gsk.substr(max(0, mid_gsk - 1), 2);
        int index_gsk = stoi(midDigits_gsk) % SIZE_gsk;

        return index_gsk;
    }

    void insertRecord_gsk(int id_gsk, string name_gsk, string dept_gsk) {
        int index_gsk = midSquareHash_gsk(id_gsk);
        int startIndex_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            index_gsk = (index_gsk + 1) % SIZE_gsk;
            if (index_gsk == startIndex_gsk) {
                cout << "Hash Table is full!\n";
                return;
            }
        }

        table_gsk[index_gsk].id_gsk = id_gsk;
        table_gsk[index_gsk].name_gsk = name_gsk;
        table_gsk[index_gsk].dept_gsk = dept_gsk;
        table_gsk[index_gsk].occupied_gsk = true;

        cout << "Record inserted successfully!\n";
    }

    void searchRecord_gsk(int id_gsk) {
        int index_gsk = midSquareHash_gsk(id_gsk);
        int startIndex_gsk = index_gsk;

        while (table_gsk[index_gsk].occupied_gsk) {
            if (table_gsk[index_gsk].id_gsk == id_gsk) {
                cout << "\nEmployee Found:\n";
                cout << "ID: " << table_gsk[index_gsk].id_gsk << endl;
                cout << "Name: " << table_gsk[index_gsk].name_gsk << endl;
                cout << "Department: " << table_gsk[index_gsk].dept_gsk << endl;
                return;
            }
            index_gsk = (index_gsk + 1) % SIZE_gsk;
            if (index_gsk == startIndex_gsk)
                break;
        }

        cout << "Employee not found!\n";
    }

    void displayTable_gsk() {
        cout << "\nEmployee Hash Table:\n";
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
    HashTable_gsk ht_gsk;
    int choice_gsk, id_gsk;
    string name_gsk, dept_gsk;

    while (true) {
        cout << "\n--- Employee Database Menu ---\n";
        cout << "1. Insert Employee Record\n";
        cout << "2. Search Employee Record\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id_gsk;
            cout << "Enter Employee Name: ";
            cin >> name_gsk;
            cout << "Enter Department: ";
            cin >> dept_gsk;
            ht_gsk.insertRecord_gsk(id_gsk, name_gsk, dept_gsk);
            break;
        case 2:
            cout << "Enter Employee ID to search: ";
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