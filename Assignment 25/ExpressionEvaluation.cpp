#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;
    for (char ch : exp) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            int result = 0;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default: cout << "Invalid Operator\n"; return -1;
            }

            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string exp;
    int choice;
    do {
        cout << "\n--- Postfix Expression Evaluation ---\n";
        cout << "1. Evaluate Expression\n2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression (single-digit operands): ";
                cin >> exp;
                cout << "Result: " << evaluatePostfix(exp) << endl;
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}