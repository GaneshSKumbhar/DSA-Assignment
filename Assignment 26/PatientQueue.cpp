#include <iostream>
#include <string>
using namespace std;

struct Patient_gsk {
    int id_gsk;
    string name_gsk;
    Patient_gsk* next_gsk;
};

class ClinicQueue_gsk {
    Patient_gsk* front_gsk;
    Patient_gsk* rear_gsk;
public:
    ClinicQueue_gsk() {
        front_gsk = rear_gsk = nullptr;
    }

    void addPatient_gsk(int id_gsk, string name_gsk) {
        Patient_gsk* newPatient_gsk = new Patient_gsk();
        newPatient_gsk->id_gsk = id_gsk;
        newPatient_gsk->name_gsk = name_gsk;
        newPatient_gsk->next_gsk = nullptr;

        if (rear_gsk == nullptr) {
            front_gsk = rear_gsk = newPatient_gsk;
            cout << "Patient " << name_gsk << " added to the queue.\n";
            return;
        }

        rear_gsk->next_gsk = newPatient_gsk;
        rear_gsk = newPatient_gsk;
        cout << "Patient " << name_gsk << " added to the queue.\n";
    }

    void assignDoctor_gsk() {
        if (front_gsk == nullptr) {
            cout << "No patients waiting.\n";
            return;
        }

        Patient_gsk* temp_gsk = front_gsk;
        cout << "Patient " << temp_gsk->name_gsk << " (ID: " << temp_gsk->id_gsk << ") assigned to doctor.\n";
        front_gsk = front_gsk->next_gsk;

        if (front_gsk == nullptr) rear_gsk = nullptr;
        delete temp_gsk;
    }

    void displayQueue_gsk() {
        if (front_gsk == nullptr) {
            cout << "No patients currently waiting.\n";
            return;
        }

        Patient_gsk* temp_gsk = front_gsk;
        cout << "\n--- Current Waiting List ---\n";
        while (temp_gsk != nullptr) {
            cout << "Patient ID: " << temp_gsk->id_gsk << ", Name: " << temp_gsk->name_gsk << endl;
            temp_gsk = temp_gsk->next_gsk;
        }
    }
};

int main() {
    ClinicQueue_gsk clinic_gsk;
    int choice_gsk, id_gsk;
    string name_gsk;

    do {
        cout << "\n--- Medical Clinic Queue System ---\n";
        cout << "1. Add New Patient\n2. Assign Patient to Doctor\n3. Display Waiting List\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id_gsk;
                cout << "Enter Patient Name: ";
                cin >> name_gsk;
                clinic_gsk.addPatient_gsk(id_gsk, name_gsk);
                break;
            case 2:
                clinic_gsk.assignDoctor_gsk();
                break;
            case 3:
                clinic_gsk.displayQueue_gsk();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice_gsk != 4);

    return 0;
}
