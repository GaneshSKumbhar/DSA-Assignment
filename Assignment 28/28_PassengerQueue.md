# Passenger Queue Management using Linked List

## Theory
A **queue of passengers** waiting to see a ticket agent can be implemented using a **linked list**.  
The queue operates on a **First-Come, First-Served (FCFS)** basis, where passengers join at the rear and are served from the front.

Key Points:
- Insert passengers at the **rear**.
- Display the passenger at the **front**.
- Remove passengers from the **front**.
- Keep track of **total passengers left** in the queue.

---

## Algorithm

1. **Start**
2. Initialize an empty linked list for the queue.
3. Display menu:
   - 1. Insert Passenger
   - 2. Display Front Passenger
   - 3. Remove Front Passenger
   - 4. Display Number of Passengers and Exit
4. **Insert Passenger:**
   - Create a new node with passenger details.
   - If queue empty, set front and rear to the new node.
   - Else, insert at rear and update rear.
5. **Display Front Passenger:**
   - Check if queue is empty.
   - Display the passenger at the front node.
6. **Remove Front Passenger:**
   - Check if queue is empty.
   - Remove the front node and update front pointer.
   - If queue becomes empty, set front and rear to NULL.
7. Repeat until user chooses Exit.
8. **End**

---

## Program Code

```cpp
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
```

---

## Sample Output

```--- Passenger Queue Menu ---
1. Insert Passenger
2. Display Front Passenger
3. Remove Front Passenger
4. Display Number of Passengers and Exit
Enter your choice: 1
Enter passenger name: Ganesh
Passenger "Ganesh" added to the queue.

Enter your choice: 1
Enter passenger name: Riya
Passenger "Riya" added to the queue.

Enter your choice: 2
Front passenger: Ganesh

Enter your choice: 3
Removing passenger: Ganesh

Enter your choice: 2
Front passenger: Riya

Enter your choice: 4
Total passengers left in queue: 1
Exiting program...


--- Passenger Queue Menu ---
1. Insert Passenger
2. Display Front Passenger
3. Remove Front Passenger
4. Display Number of Passengers and Exit
Enter your choice: 1
Enter passenger name: Ganesh
Passenger "Ganesh" added to the queue.

Enter your choice: 1
Enter passenger name: Riya
Passenger "Riya" added to the queue.

Enter your choice: 2
Front passenger: Ganesh

Enter your choice: 3
Removing passenger: Ganesh

Enter your choice: 2
Front passenger: Riya

Enter your choice: 4
Total passengers left in queue: 1
Exiting program...

```