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
