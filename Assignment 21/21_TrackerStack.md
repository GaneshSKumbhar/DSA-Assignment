# Stock Price Tracker using Stack (Linked List)

## Theory

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.  
In this program, a stack is implemented using a **linked list** to record daily stock prices entered by the user.  
The most recent price is always at the **top** of the stack.

### Operations Implemented
1. **record(price)** – Push a new stock price onto the stack.  
2. **remove()** – Pop the most recent stock price from the stack.  
3. **latest()** – Peek at the top element without removing it.  
4. **isEmpty()** – Check whether the stack is empty.

---

## Algorithm

1. Create a structure `Node_gsk` with `data_gsk` (price) and pointer `next_gsk`.
2. Maintain a `top_gsk` pointer to track the top of the stack.
3. For each operation:
   - **record(price)**: Create a new node and push it to the top.
   - **remove()**: Pop the top node and return its value.
   - **latest()**: Return the value at the top node.
   - **isEmpty()**: Return true if `top_gsk == nullptr`.
4. Display a menu using `switch` to perform user-selected operations repeatedly.

---

## Code

```cpp
#include <iostream>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk* next_gsk;
};

class StockTracker_gsk {
    Node_gsk* top_gsk;
public:
    StockTracker_gsk() : top_gsk(nullptr) {}

    // 1. record(price)
    void record_gsk(int price_gsk) {
        Node_gsk* newNode_gsk = new Node_gsk{price_gsk, top_gsk};
        top_gsk = newNode_gsk;
        cout << "Recorded stock price: " << price_gsk << endl;
    }

    // 2. remove()
    void remove_gsk() {
        if (isEmpty_gsk()) {
            cout << "No prices to remove.\n";
            return;
        }
        Node_gsk* temp_gsk = top_gsk;
        cout << "Removed most recent price: " << top_gsk->data_gsk << endl;
        top_gsk = top_gsk->next_gsk;
        delete temp_gsk;
    }

    // 3. latest()
    void latest_gsk() const {
        if (isEmpty_gsk()) {
            cout << "No prices recorded yet.\n";
            return;
        }
        cout << "Latest recorded price: " << top_gsk->data_gsk << endl;
    }

    // 4. isEmpty()
    bool isEmpty_gsk() const {
        return top_gsk == nullptr;
    }

    void display_gsk() const {
        if (isEmpty_gsk()) {
            cout << "No stock prices recorded.\n";
            return;
        }
        cout << "Stock price history (most recent first): ";
        Node_gsk* temp_gsk = top_gsk;
        while (temp_gsk) {
            cout << temp_gsk->data_gsk << " ";
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }
};

int main() {
    StockTracker_gsk tracker_gsk;
    int choice_gsk, price_gsk;

    do {
        cout << "\n--- Stock Price Tracker Menu ---\n";
        cout << "1. Record new stock price\n";
        cout << "2. Remove most recent price\n";
        cout << "3. View latest price\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Display all recorded prices\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter stock price to record: ";
                cin >> price_gsk;
                tracker_gsk.record_gsk(price_gsk);
                break;
            case 2:
                tracker_gsk.remove_gsk();
                break;
            case 3:
                tracker_gsk.latest_gsk();
                break;
            case 4:
                cout << (tracker_gsk.isEmpty_gsk() ? "No prices recorded.\n" : "Prices are recorded.\n");
                break;
            case 5:
                tracker_gsk.display_gsk();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice_gsk != 6);

    return 0;
}
```
---

## Sample Output

```
--- Stock Price Tracker Menu ---
1. Record new stock price
2. Remove most recent price
3. View latest price
4. Check if stack is empty
5. Display all recorded prices
6. Exit
Enter your choice: 1
Enter stock price to record: 1020
Recorded stock price: 1020

Enter your choice: 1
Enter stock price to record: 1045
Recorded stock price: 1045

Enter your choice: 5
Stock price history (most recent first): 1045 1020

Enter your choice: 3
Latest recorded price: 1045

Enter your choice: 2
Removed most recent price: 1045

Enter your choice: 4
Prices are recorded.

Enter your choice: 6
Exiting program...
```