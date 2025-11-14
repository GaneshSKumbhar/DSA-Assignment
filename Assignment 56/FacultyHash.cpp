#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Faculty_gsk {
    int id_gsk;
    string name_gsk;
    int next_gsk;

    Faculty_gsk() {
        id_gsk = -1;
        name_gsk = "";
        next_gsk = -1;
    }
};

class FacultyHashTable_gsk {
    vector<Faculty_gsk> table_gsk;
    int size_gsk;

public:
    FacultyHashTable_gsk(int size) {
        size_gsk = size;
        table_gsk.resize(size_gsk);
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % size_gsk;
    }

    void insertFaculty_gsk(int id_gsk, string name_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);

        if (table_gsk[index_gsk].id_gsk == -1) {
            table_gsk[index_gsk].id_gsk = id_gsk;
            table_gsk[index_gsk].name_gsk = name_gsk;
            cout << "Inserted at index " << index_gsk << endl;
            return;
        }

        int tempIndex_gsk = index_gsk;

        while (table_gsk[tempIndex_gsk].next_gsk != -1) {
            tempIndex_gsk = table_gsk[tempIndex_gsk].next_gsk;
        }

        int newIndex_gsk = (tempIndex_gsk + 1) % size_gsk;

        while (table_gsk[newIndex_gsk].id_gsk != -1 && newIndex_gsk != index_gsk) {
            newIndex_gsk = (newIndex_gsk + 1) % size_gsk;
        }

        if (newIndex_gsk == index_gsk) {
            cout << "Hash table is full. Cannot insert record." << endl;
            return;
        }

        table_gsk[newIndex_gsk].id_gsk = id_gsk;
        table_gsk[newIndex_gsk].name_gsk = name_gsk;
        table_gsk[tempIndex_gsk].next_gsk = newIndex_gsk;

        cout << "Inserted with chaining at index " << newIndex_gsk << endl;
    }

    void searchFaculty_gsk(int id_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);

        while (index_gsk != -1) {
            if (table_gsk[index_gsk].id_gsk == id_gsk) {
                cout << "Faculty found: " << table_gsk[index_gsk].name_gsk
                     << " at index " << index_gsk << endl;
                return;
            }
            index_gsk = table_gsk[index_gsk].next_gsk;
        }

        cout << "Faculty not found.";
    }

    void displayTable_gsk() {
        cout << "\nFaculty Hash Table:\n";
        cout << "Index\tID\tName\tNext\n";
        for (int i = 0; i < size_gsk; i++) {
            cout << i << "\t" << table_gsk[i].id_gsk << "\t"
                 << table_gsk[i].name_gsk << "\t" << table_gsk[i].next_gsk << endl;
        }
    }
};

int main() {
    int size_gsk;
    cout << "Enter hash table size: ";
    cin >> size_gsk;

    FacultyHashTable_gsk h_gsk(size_gsk);

    int n_gsk;
    cout << "Enter number of faculty records: ";
    cin >> n_gsk;

    for (int i = 0; i < n_gsk; i++) {
        int id_gsk;
        string name_gsk;
        cout << "Enter Faculty ID and Name: ";
        cin >> id_gsk >> name_gsk;
        h_gsk.insertFaculty_gsk(id_gsk, name_gsk);
    }

    h_gsk.displayTable_gsk();

    int searchID_gsk;
    cout << "\nEnter Faculty ID to search: ";
    cin >> searchID_gsk;
    h_gsk.searchFaculty_gsk(searchID_gsk);

    return 0;
}