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