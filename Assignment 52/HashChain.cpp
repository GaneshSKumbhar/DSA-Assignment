#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable_gsk {
    int BUCKET_gsk;
    vector<list<int>> table_gsk;

public:
    HashTable_gsk(int b_gsk) {
        BUCKET_gsk = b_gsk;
        table_gsk.resize(BUCKET_gsk);
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % BUCKET_gsk;
    }

    void insertItem_gsk(int key_gsk) {
        int index_gsk = hashFunction_gsk(key_gsk);
        table_gsk[index_gsk].push_back(key_gsk);
    }

    void deleteItem_gsk(int key_gsk) {
        int index_gsk = hashFunction_gsk(key_gsk);
        list<int>::iterator i;
        for (i = table_gsk[index_gsk].begin(); i != table_gsk[index_gsk].end(); i++) {
            if (*i == key_gsk)
                break;
        }
        if (i != table_gsk[index_gsk].end())
            table_gsk[index_gsk].erase(i);
    }

    void displayHash_gsk() {
        for (int i = 0; i < BUCKET_gsk; i++) {
            cout << i;
            for (auto x : table_gsk[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    int bucketCount_gsk, elements_gsk;
    cout << "Enter number of buckets: ";
    cin >> bucketCount_gsk;

    HashTable_gsk h_gsk(bucketCount_gsk);

    cout << "Enter number of elements to insert: ";
    cin >> elements_gsk;

    cout << "Enter elements: ";
    for (int i = 0; i < elements_gsk; i++) {
        int key_gsk;
        cin >> key_gsk;
        h_gsk.insertItem_gsk(key_gsk);
    }

    cout << "\nHash Table after insertion:\n";
    h_gsk.displayHash_gsk();

    int delKey_gsk;
    cout << "\nEnter key to delete: ";
    cin >> delKey_gsk;
    h_gsk.deleteItem_gsk(delKey_gsk);

    cout << "\nHash Table after deletion:\n";
    h_gsk.displayHash_gsk();

    return 0;
}