#include <iostream>
using namespace std;

#define SIZE 10

class HashTable_gsk {
    int table_gsk[SIZE];

public:
    HashTable_gsk() {
        for (int i = 0; i < SIZE; i++)
            table_gsk[i] = -1; // -1 means empty
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % SIZE;
    }

    void insert_gsk(int key_gsk) {
        int index_gsk = hashFunction_gsk(key_gsk);
        int originalIndex_gsk = index_gsk;
        int i = 0;

        while (table_gsk[index_gsk] != -1) {
            index_gsk = (originalIndex_gsk + ++i) % SIZE;
            if (index_gsk == originalIndex_gsk) {
                cout << "Hash table is full, cannot insert key " << key_gsk << endl;
                return;
            }
        }

        table_gsk[index_gsk] = key_gsk;
        cout << "Inserted " << key_gsk << " at index " << index_gsk << endl;
    }

    void search_gsk(int key_gsk) {
        int index_gsk = hashFunction_gsk(key_gsk);
        int originalIndex_gsk = index_gsk;
        int i = 0;

        while (table_gsk[index_gsk] != -1) {
            if (table_gsk[index_gsk] == key_gsk) {
                cout << "Key " << key_gsk << " found at index " << index_gsk << endl;
                return;
            }
            index_gsk = (originalIndex_gsk + ++i) % SIZE;
            if (index_gsk == originalIndex_gsk)
                break;
        }
        cout << "Key " << key_gsk << " not found!" << endl;
    }

    void display_gsk() {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << " --> ";
            if (table_gsk[i] != -1)
                cout << table_gsk[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable_gsk ht_gsk;
    int choice_gsk, key_gsk;

    do {
        cout << "\n---- Hash Table Menu ----";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_gsk;
                ht_gsk.insert_gsk(key_gsk);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key_gsk;
                ht_gsk.search_gsk(key_gsk);
                break;

            case 3:
                ht_gsk.display_gsk();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice_gsk != 4);

    return 0;
}