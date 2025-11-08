#include <iostream>
using namespace std;

struct Node_gsk {
    int data_gsk;
    Node_gsk* next_gsk;
};

class LinkedList_gsk {
    Node_gsk* head_gsk;
public:
    LinkedList_gsk() : head_gsk(nullptr) {}

    void append_gsk(int val_gsk) {
        Node_gsk* newNode_gsk = new Node_gsk{val_gsk, nullptr};
        if (!head_gsk) {
            head_gsk = newNode_gsk;
            return;
        }
        Node_gsk* temp_gsk = head_gsk;
        while (temp_gsk->next_gsk) temp_gsk = temp_gsk->next_gsk;
        temp_gsk->next_gsk = newNode_gsk;
    }

    void frontBackSplit_gsk(LinkedList_gsk &front_gsk, LinkedList_gsk &back_gsk) {
        if (!head_gsk || !head_gsk->next_gsk) {
            front_gsk.head_gsk = head_gsk;
            back_gsk.head_gsk = nullptr;
            return;
        }
        Node_gsk* slow_gsk = head_gsk;
        Node_gsk* fast_gsk = head_gsk->next_gsk;

        while (fast_gsk) {
            fast_gsk = fast_gsk->next_gsk;
            if (fast_gsk) {
                slow_gsk = slow_gsk->next_gsk;
                fast_gsk = fast_gsk->next_gsk;
            }
        }

        front_gsk.head_gsk = head_gsk;
        back_gsk.head_gsk = slow_gsk->next_gsk;
        slow_gsk->next_gsk = nullptr;
    }

    void display_gsk() const {
        Node_gsk* temp_gsk = head_gsk;
        if (!temp_gsk) {
            cout << "List is empty\n";
            return;
        }
        while (temp_gsk) {
            cout << temp_gsk->data_gsk << " ";
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }
};

int main() {
    LinkedList_gsk list_gsk, front_gsk, back_gsk;
    int n_gsk;

    cout << "Enter number of elements in the list: ";
    cin >> n_gsk;

    for (int i = 1; i <= n_gsk; i++) {
        list_gsk.append_gsk(i); 
    }

    list_gsk.frontBackSplit_gsk(front_gsk, back_gsk);

    cout << "Front List: ";
    front_gsk.display_gsk();
    cout << "Back List: ";
    back_gsk.display_gsk();

    return 0;
}