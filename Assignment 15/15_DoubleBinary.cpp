#include <iostream>
using namespace std;

struct Node_gsk {
    int bit_gsk;
    Node_gsk* prev_gsk;
    Node_gsk* next_gsk;
};

class BinaryNumber_gsk {
    Node_gsk* head_gsk;
    Node_gsk* tail_gsk;
public:
    BinaryNumber_gsk() : head_gsk(nullptr), tail_gsk(nullptr) {}

    void addBit_gsk(int bit_gsk) {
        Node_gsk* newNode_gsk = new Node_gsk{bit_gsk, tail_gsk, nullptr};
        if (!head_gsk) head_gsk = newNode_gsk;
        if (tail_gsk) tail_gsk->next_gsk = newNode_gsk;
        tail_gsk = newNode_gsk;
    }

    void display_gsk() {
        Node_gsk* temp_gsk = head_gsk;
        while(temp_gsk) {
            cout << temp_gsk->bit_gsk;
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }

    void onesComplement_gsk() {
        Node_gsk* temp_gsk = head_gsk;
        cout << "1's Complement: ";
        while(temp_gsk) {
            cout << (temp_gsk->bit_gsk == 0 ? 1 : 0);
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }

    void twosComplement_gsk() {
        Node_gsk* temp_gsk = tail_gsk;
        bool carry_gsk = true;
        cout << "2's Complement: ";
        while(temp_gsk) {
            int bit_gsk = temp_gsk->bit_gsk;
            if(carry_gsk) {
                if(bit_gsk == 0) { bit_gsk = 1; carry_gsk = false; }
                else bit_gsk = 0;
            }
            temp_gsk->bit_gsk = bit_gsk;
            temp_gsk = temp_gsk->prev_gsk;
        }
        display_gsk();
    }

    static BinaryNumber_gsk addBinary_gsk(BinaryNumber_gsk& a_gsk, BinaryNumber_gsk& b_gsk) {
        BinaryNumber_gsk result_gsk;
        Node_gsk* p1_gsk = a_gsk.tail_gsk;
        Node_gsk* p2_gsk = b_gsk.tail_gsk;
        int carry_gsk = 0;

        while(p1_gsk || p2_gsk || carry_gsk) {
            int sum_gsk = carry_gsk;
            if(p1_gsk) { sum_gsk += p1_gsk->bit_gsk; p1_gsk = p1_gsk->prev_gsk; }
            if(p2_gsk) { sum_gsk += p2_gsk->bit_gsk; p2_gsk = p2_gsk->prev_gsk; }
            result_gsk.addBit_gsk(sum_gsk % 2);
            carry_gsk = sum_gsk / 2;
        }

        // Reverse the result
        Node_gsk* curr_gsk = result_gsk.head_gsk;
        Node_gsk* prev_gsk = nullptr;
        Node_gsk* next_gsk;
        while(curr_gsk) {
            next_gsk = curr_gsk->next_gsk;
            curr_gsk->next_gsk = prev_gsk;
            curr_gsk->prev_gsk = next_gsk;
            prev_gsk = curr_gsk;
            curr_gsk = next_gsk;
        }
        result_gsk.tail_gsk = result_gsk.head_gsk;
        result_gsk.head_gsk = prev_gsk;

        return result_gsk;
    }
};

int main() {
    BinaryNumber_gsk bin1_gsk, bin2_gsk;
    int n1_gsk, n2_gsk, bit_gsk, choice_gsk;

    cout << "Enter number of bits for first binary number: ";
    cin >> n1_gsk;
    cout << "Enter bits for first binary number (MSB to LSB): ";
    for(int i=0;i<n1_gsk;i++) { cin >> bit_gsk; bin1_gsk.addBit_gsk(bit_gsk); }

    cout << "Enter number of bits for second binary number: ";
    cin >> n2_gsk;
    cout << "Enter bits for second binary number (MSB to LSB): ";
    for(int i=0;i<n2_gsk;i++) { cin >> bit_gsk; bin2_gsk.addBit_gsk(bit_gsk); }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display first binary number\n";
        cout << "2. Display second binary number\n";
        cout << "3. 1's Complement of first binary number\n";
        cout << "4. 2's Complement of first binary number\n";
        cout << "5. Add two binary numbers\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch(choice_gsk) {
            case 1:
                cout << "First Binary Number: ";
                bin1_gsk.display_gsk();
                break;
            case 2:
                cout << "Second Binary Number: ";
                bin2_gsk.display_gsk();
                break;
            case 3:
                bin1_gsk.onesComplement_gsk();
                break;
            case 4:
                bin1_gsk.twosComplement_gsk();
                break;
            case 5: {
                BinaryNumber_gsk sum_gsk = BinaryNumber_gsk::addBinary_gsk(bin1_gsk, bin2_gsk);
                cout << "Sum of Binary Numbers: ";
                sum_gsk.display_gsk();
                break;
            }
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while(choice_gsk != 0);

    return 0;
}
