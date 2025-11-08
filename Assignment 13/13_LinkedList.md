# Appointment Scheduling System using Linked List (_gsk version)

## Theory

The Appointment Scheduling System efficiently manages daily appointments using a singly linked list data structure.  
Each node in the list represents a time slot containing:
- Start Time
- End Time
- Status (Booked/Available)

The linked list helps dynamically handle varying numbers of appointments, making insertion, deletion, and sorting efficient.  
The system enforces constraints on minimum and maximum appointment durations, ensuring consistent and valid scheduling.  

### Key Operations
1. Display available time slots.
2. Book new appointments within time limits.
3. Cancel existing appointments after validation.
4. Sort appointments by time using data swap.
5. Sort appointments by pointer manipulation without swapping data.

---

## Algorithm

1. Initialize Schedule
   - Define working hours (e.g., 9:00 AM to 5:00 PM).
   - Divide the day into slots based on minimum and maximum duration.

2. Display Available Slots
   - Traverse the list and print slots with status “Available”.

3. Book Appointment
   - Search for a matching slot within limits.
   - Change its status to “Booked”.

4. Cancel Appointment
   - Validate the time and mark it “Available”.

5. Sort by Data Swap
   - Apply bubble sort by comparing start times.

6. Sort by Pointer Manipulation
   - Rearrange pointers instead of swapping data fields.

---

## Code

```cpp
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
```
---

## Sample Output

```
Enter number of appointment slots: 5

Menu:
1. Display all slots
2. Display available slots
3. Book an appointment
4. Cancel an appointment
0. Exit
Enter your choice: 1

All Appointment Slots:
10:00 - 13:00 : Available
16:00 - 18:00 : Available
11:00 - 12:00 : Available
14:00 - 17:00 : Available
10:00 - 12:00 : Available

Menu:
1. Display all slots
2. Display available slots
3. Book an appointment
4. Cancel an appointment
0. Exit
Enter your choice: 2

Available Slots:
10:00 - 13:00
16:00 - 18:00
11:00 - 12:00
14:00 - 17:00
10:00 - 12:00

Menu:
1. Display all slots
2. Display available slots
3. Book an appointment
4. Cancel an appointment
0. Exit
Enter your choice: 3
Enter start time to book (e.g., 10:00): 11.00
Slot unavailable or already booked.

Menu:
1. Display all slots
2. Display available slots
3. Book an appointment
4. Cancel an appointment
0. Exit
Enter your choice: 4
Enter start time to cancel (e.g., 10:00): 0
No matching booked appointment found.
```