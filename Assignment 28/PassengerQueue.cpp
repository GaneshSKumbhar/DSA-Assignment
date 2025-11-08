#include <iostream>
#include <string>
using namespace std;

struct Passenger_gsk {
    string name_gsk;
    Passenger_gsk* next_gsk;
};

class PassengerQueue_gsk {
    Passenger_gsk* front_gsk;
    Passenger_gsk* rear_gsk;
    int count_gsk;
public:
    PassengerQueue_gsk() {
        front_gsk = rear_gsk = nullptr;
        count_gsk = 0;
    }

    void insertPassenger_gsk(const string& name_gsk) {
        Passenger_gsk* newPassenger_gsk = new Passenger_gsk{ name_gsk, nullptr };
        if (!rear_gsk) {
            front_gsk = rear_gsk = newPassenger_gsk;
        } else {
            rear_gsk->next_gsk = newPassenger_gsk;
            rear_gsk = newPassenger_gsk;
        }
        count_gsk++;
        cout << "Passenger \"" << name_gsk << "\" added to the queue.\n";
    }

    void displayFront_gsk() {
        if (!front_gsk) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front passenger: " << front_gsk->name_gsk << "\n";
    }

    void removePassenger_gsk() {
        if (!front_gsk) {
            cout << "Queue is empty. No passenger to remove.\n";
            return;
        }
        Passenger_gsk* temp_gsk = front_gsk;
        cout << "Removing passenger: " << temp_gsk->name_gsk << "\n";
        front_gsk = front_gsk->next_gsk;
        if (!front_gsk) rear_gsk = nullptr;
        delete temp_gsk;
        count_gsk--;
    }

    void displayCount_gsk() {
        cout << "Total passengers left in queue: " << count_gsk << "\n";
    }
};

int main() {
    PassengerQueue_gsk queue_gsk;
    int choice_gsk;
    string name_gsk;

    do {
        cout << "\n--- Passenger Queue Menu ---\n";
        cout << "1. Insert Passenger\n";
        cout << "2. Display Front Passenger\n";
        cout << "3. Remove Front Passenger\n";
        cout << "4. Display Number of Passengers and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;
        cin.ignore();

        switch(choice_gsk) {
            case 1:
                cout << "Enter passenger name: ";
                getline(cin, name_gsk);
                queue_gsk.insertPassenger_gsk(name_gsk);
                break;
            case 2:
                queue_gsk.displayFront_gsk();
                break;
            case 3:
                queue_gsk.removePassenger_gsk();
                break;
            case 4:
                queue_gsk.displayCount_gsk();
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice_gsk != 4);

    return 0;
}