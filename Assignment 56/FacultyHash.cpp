#include <iostream>
#include <string>
using namespace std;

class Faculty_gsk {
public:
    int facultyID_gsk;
    string facultyName_gsk;
    bool isOccupied_gsk;

    Faculty_gsk() {
        facultyID_gsk = -1;
        facultyName_gsk = "";
        isOccupied_gsk = false;
    }
};

class FacultyHashTable_gsk {
    int size_gsk;
    Faculty_gsk* table_gsk;

public:
    FacultyHashTable_gsk(int s) {
        size_gsk = s;
        table_gsk = new Faculty_gsk[size_gsk];
    }

    int hashFunction_gsk(int key_gsk) {
        return key_gsk % size_gsk; // Divide method
    }

    void insertFaculty_gsk(int id_gsk, string name_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);
        int startIndex_gsk = index_gsk;

        // Linear probing with chaining (without replacement)
        while (table_gsk[index_gsk].isOccupied_gsk) {
            index_gsk = (index_gsk + 1) % size_gsk;
            if (index_gsk == startIndex_gsk) {
                cout << "Hash table is full. Cannot insert record." << endl;
                return;
            }
        }

        table_gsk[index_gsk].facultyID_gsk = id_gsk;
        table_gsk[index_gsk].facultyName_gsk = name_gsk;
        table_gsk[index_gsk].isOccupied_gsk = true;

        cout << "Inserted Faculty: " << name_gsk
             << " with ID " << id_gsk
             << " at index " << index_gsk << endl;
    }

    void searchFaculty_gsk(int id_gsk) {
        int index_gsk = hashFunction_gsk(id_gsk);
        int startIndex_gsk = index_gsk;

        while (table_gsk[index_gsk].isOccupied_gsk) {
            if (table_gsk[index_gsk].facultyID_gsk == id_gsk) {
                cout << "Faculty Found: " << table_gsk[index_gsk].facultyName_gsk
                     << " at index " << index_gsk << endl;
                return;
            }

            index_gsk = (index_gsk + 1) % size_gsk;
            if (index_gsk == startIndex_gsk)
                break;
        }

        cout << "Faculty not found." << endl;
    }

    void displayTable_gsk() {
        cout << "\nFaculty Hash Table:\n";
        for (int i = 0; i < size_gsk; i++) {
            if (table_gsk[i].isOccupied_gsk)
                cout << i << " --> ID: " << table_gsk[i].facultyID_gsk
                     << ", Name: " << table_gsk[i].facultyName_gsk << endl;
            else
                cout << i << " --> Empty\n";
        }
    }

    ~FacultyHashTable_gsk() {
        delete[] table_gsk;
    }
};

int main() {
    int size_gsk;
    cout << "Enter size of hash table: ";
    cin >> size_gsk;

    FacultyHashTable_gsk hTable_gsk(size_gsk);

    int choice_gsk;
    do {
        cout << "\n1. Insert Faculty\n2. Search Faculty\n3. Display Table\n4. Exit\nEnter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1: {
                int id_gsk;
                string name_gsk;
                cout << "Enter Faculty ID: ";
                cin >> id_gsk;
                cout << "Enter Faculty Name: ";
                cin.ignore();
                getline(cin, name_gsk);
                hTable_gsk.insertFaculty_gsk(id_gsk, name_gsk);
                break;
            }
            case 2: {
                int id_gsk;
                cout << "Enter Faculty ID to search: ";
                cin >> id_gsk;
                hTable_gsk.searchFaculty_gsk(id_gsk);
                break;
            }
            case 3:
                hTable_gsk.displayTable_gsk();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice_gsk != 4);

    return 0;
}
