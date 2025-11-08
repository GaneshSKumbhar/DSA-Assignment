#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Appointment_gsk {
    string startTime_gsk;
    string endTime_gsk;
    bool booked_gsk;
    Appointment_gsk* next_gsk;
};

class AppointmentList_gsk {
    Appointment_gsk* head_gsk;
public:
    AppointmentList_gsk() : head_gsk(nullptr) {}

    void createSchedule_gsk(int n_gsk) {
        srand(time(0));
        for (int i_gsk = 0; i_gsk < n_gsk; i_gsk++) {
            int startHour_gsk = rand() % 9 + 9; // Random start between 9 AM - 5 PM
            int duration_gsk = (rand() % 3 + 1); // 1-3 hours
            int endHour_gsk = startHour_gsk + duration_gsk;
            if (endHour_gsk > 18) endHour_gsk = 18;

            string start_gsk = to_string(startHour_gsk) + ":00";
            string end_gsk = to_string(endHour_gsk) + ":00";

            Appointment_gsk* newAppt_gsk = new Appointment_gsk{start_gsk, end_gsk, false, nullptr};
            if (!head_gsk) head_gsk = newAppt_gsk;
            else {
                Appointment_gsk* temp_gsk = head_gsk;
                while (temp_gsk->next_gsk) temp_gsk = temp_gsk->next_gsk;
                temp_gsk->next_gsk = newAppt_gsk;
            }
        }
    }

    void displayAvailable_gsk() {
        Appointment_gsk* temp_gsk = head_gsk;
        cout << "\nAvailable Slots:\n";
        while (temp_gsk) {
            if (!temp_gsk->booked_gsk)
                cout << temp_gsk->startTime_gsk << " - " << temp_gsk->endTime_gsk << "\n";
            temp_gsk = temp_gsk->next_gsk;
        }
    }

    void bookAppointment_gsk(const string& start_gsk) {
        Appointment_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            if (temp_gsk->startTime_gsk == start_gsk && !temp_gsk->booked_gsk) {
                temp_gsk->booked_gsk = true;
                cout << "Appointment booked for " << temp_gsk->startTime_gsk << " - " << temp_gsk->endTime_gsk << "\n";
                return;
            }
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << "Slot unavailable or already booked.\n";
    }

    void cancelAppointment_gsk(const string& start_gsk) {
        Appointment_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            if (temp_gsk->startTime_gsk == start_gsk && temp_gsk->booked_gsk) {
                temp_gsk->booked_gsk = false;
                cout << "Appointment canceled for " << temp_gsk->startTime_gsk << " - " << temp_gsk->endTime_gsk << "\n";
                return;
            }
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << "No matching booked appointment found.\n";
    }

    void displayAll_gsk() {
        cout << "\nAll Appointment Slots:\n";
        Appointment_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            cout << temp_gsk->startTime_gsk << " - " << temp_gsk->endTime_gsk << " : "
                 << (temp_gsk->booked_gsk ? "Booked" : "Available") << "\n";
            temp_gsk = temp_gsk->next_gsk;
        }
    }
};

int main() {
    AppointmentList_gsk schedule_gsk;
    int n_gsk;
    cout << "Enter number of appointment slots: ";
    cin >> n_gsk;

    schedule_gsk.createSchedule_gsk(n_gsk);

    int choice_gsk;
    string time_gsk;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display all slots\n";
        cout << "2. Display available slots\n";
        cout << "3. Book an appointment\n";
        cout << "4. Cancel an appointment\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch(choice_gsk) {
            case 1:
                schedule_gsk.displayAll_gsk();
                break;
            case 2:
                schedule_gsk.displayAvailable_gsk();
                break;
            case 3:
                cout << "Enter start time to book (e.g., 10:00): ";
                cin >> time_gsk;
                schedule_gsk.bookAppointment_gsk(time_gsk);
                break;
            case 4:
                cout << "Enter start time to cancel (e.g., 10:00): ";
                cin >> time_gsk;
                schedule_gsk.cancelAppointment_gsk(time_gsk);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice_gsk != 0);

    return 0;
}
