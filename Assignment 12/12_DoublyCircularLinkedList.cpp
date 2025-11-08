#include <iostream>
#include <cstdlib>
using namespace std;

struct Seat_gsk {
    int seat_no_gsk;
    char status_gsk;
    Seat_gsk* next_gsk;
    Seat_gsk* prev_gsk;
};

class Multiplex_gsk {
    Seat_gsk* head_gsk[8]; // 8 rows

public:
    Multiplex_gsk() {
        for (int i_gsk = 0; i_gsk < 8; i_gsk++)
            head_gsk[i_gsk] = nullptr;
        createSeats_gsk();
    }

    void createSeats_gsk() {
        for (int i_gsk = 0; i_gsk < 8; i_gsk++) {
            Seat_gsk* last_gsk = nullptr;
            for (int j_gsk = 1; j_gsk <= 8; j_gsk++) {
                Seat_gsk* newSeat_gsk = new Seat_gsk;
                newSeat_gsk->seat_no_gsk = j_gsk;
                newSeat_gsk->status_gsk = (rand() % 2 == 0) ? 'A' : 'B'; // Randomly booked
                newSeat_gsk->next_gsk = newSeat_gsk->prev_gsk = nullptr;

                if (!head_gsk[i_gsk]) {
                    head_gsk[i_gsk] = newSeat_gsk;
                    newSeat_gsk->next_gsk = newSeat_gsk->prev_gsk = newSeat_gsk;
                    last_gsk = newSeat_gsk;
                } else {
                    newSeat_gsk->next_gsk = head_gsk[i_gsk];
                    newSeat_gsk->prev_gsk = last_gsk;
                    last_gsk->next_gsk = newSeat_gsk;
                    head_gsk[i_gsk]->prev_gsk = newSeat_gsk;
                    last_gsk = newSeat_gsk;
                }
            }
        }
    }

    void displaySeats_gsk() {
        cout << "\n=== Current Seat Availability ===\n";
        for (int i_gsk = 0; i_gsk < 8; i_gsk++) {
            cout << "Row " << i_gsk + 1 << ": ";
            Seat_gsk* temp_gsk = head_gsk[i_gsk];
            if (!temp_gsk) continue;
            do {
                cout << temp_gsk->seat_no_gsk << "(" << temp_gsk->status_gsk << ") ";
                temp_gsk = temp_gsk->next_gsk;
            } while (temp_gsk != head_gsk[i_gsk]);
            cout << endl;
        }
    }

    void bookSeat_gsk(int row_gsk, int seatNum_gsk) {
        if (row_gsk < 1 || row_gsk > 8 || seatNum_gsk < 1 || seatNum_gsk > 8) {
            cout << "Invalid seat or row number!\n";
            return;
        }
        Seat_gsk* temp_gsk = head_gsk[row_gsk - 1];
        do {
            if (temp_gsk->seat_no_gsk == seatNum_gsk) {
                if (temp_gsk->status_gsk == 'B') {
                    cout << "Seat " << seatNum_gsk << " in Row " << row_gsk << " is already booked.\n";
                    return;
                } else {
                    temp_gsk->status_gsk = 'B';
                    cout << "Seat " << seatNum_gsk << " in Row " << row_gsk << " booked successfully!\n";
                    return;
                }
            }
            temp_gsk = temp_gsk->next_gsk;
        } while (temp_gsk != head_gsk[row_gsk - 1]);
    }

    void cancelSeat_gsk(int row_gsk, int seatNum_gsk) {
        if (row_gsk < 1 || row_gsk > 8 || seatNum_gsk < 1 || seatNum_gsk > 8) {
            cout << "Invalid seat or row number!\n";
            return;
        }
        Seat_gsk* temp_gsk = head_gsk[row_gsk - 1];
        do {
            if (temp_gsk->seat_no_gsk == seatNum_gsk) {
                if (temp_gsk->status_gsk == 'A') {
                    cout << "Seat " << seatNum_gsk << " in Row " << row_gsk << " is not booked.\n";
                    return;
                } else {
                    temp_gsk->status_gsk = 'A';
                    cout << "Booking for Seat " << seatNum_gsk << " in Row " << row_gsk << " cancelled.\n";
                    return;
                }
            }
            temp_gsk = temp_gsk->next_gsk;
        } while (temp_gsk != head_gsk[row_gsk - 1]);
    }
};

int main() {
    Multiplex_gsk galaxy_gsk;
    int choice_gsk, row_gsk, seat_gsk;

    do {
        cout << "\n===== Galaxy Multiplex Ticket Reservation =====\n";
        cout << "1. Display Seat Availability\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Seat\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
        case 1:
            galaxy_gsk.displaySeats_gsk();
            break;
        case 2:
            cout << "Enter row (1-8) and seat number (1-8) to book: ";
            cin >> row_gsk >> seat_gsk;
            galaxy_gsk.bookSeat_gsk(row_gsk, seat_gsk);
            break;
        case 3:
            cout << "Enter row (1-8) and seat number (1-8) to cancel: ";
            cin >> row_gsk >> seat_gsk;
            galaxy_gsk.cancelSeat_gsk(row_gsk, seat_gsk);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice_gsk != 4);

    return 0;
}
