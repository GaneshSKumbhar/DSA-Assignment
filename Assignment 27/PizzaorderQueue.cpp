#include <iostream>
#include <string>
using namespace std;

class PizzaQueue_gsk {
    int front_gsk, rear_gsk, max_gsk;
    string* orders_gsk;
public:
    PizzaQueue_gsk(int n_gsk) {
        max_gsk = n_gsk;
        orders_gsk = new string[max_gsk];
        front_gsk = rear_gsk = -1;
    }

    bool isFull_gsk() {
        return ((rear_gsk + 1) % max_gsk == front_gsk);
    }

    bool isEmpty_gsk() {
        return (front_gsk == -1);
    }

    void placeOrder_gsk(string order_gsk) {
        if (isFull_gsk()) {
            cout << "Order limit reached! Cannot accept more orders.\n";
            return;
        }
        if (isEmpty_gsk()) front_gsk = rear_gsk = 0;
        else rear_gsk = (rear_gsk + 1) % max_gsk;

        orders_gsk[rear_gsk] = order_gsk;
        cout << "Order \"" << order_gsk << "\" placed successfully.\n";
    }

    void serveOrder_gsk() {
        if (isEmpty_gsk()) {
            cout << "No orders to serve.\n";
            return;
        }
        cout << "Serving order: " << orders_gsk[front_gsk] << "\n";
        if (front_gsk == rear_gsk) front_gsk = rear_gsk = -1;
        else front_gsk = (front_gsk + 1) % max_gsk;
    }

    void displayOrders_gsk() {
        if (isEmpty_gsk()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "\n--- Pending Orders ---\n";
        int i_gsk = front_gsk;
        while (true) {
            cout << orders_gsk[i_gsk] << "\n";
            if (i_gsk == rear_gsk) break;
            i_gsk = (i_gsk + 1) % max_gsk;
        }
    }
};

int main() {
    int n_gsk, choice_gsk;
    string order_gsk;

    cout << "Enter maximum number of orders the parlour can accept: ";
    cin >> n_gsk;

    PizzaQueue_gsk parlour_gsk(n_gsk);

    do {
        cout << "\n--- Pizza Parlour FCFS System ---\n";
        cout << "1. Place Order\n2. Serve Order\n3. Display Pending Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch(choice_gsk) {
            case 1:
                cout << "Enter order details: ";
                cin.ignore();
                getline(cin, order_gsk);
                parlour_gsk.placeOrder_gsk(order_gsk);
                break;
            case 2:
                parlour_gsk.serveOrder_gsk();
                break;
            case 3:
                parlour_gsk.displayOrders_gsk();
                break;
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice_gsk != 4);

    return 0;
}