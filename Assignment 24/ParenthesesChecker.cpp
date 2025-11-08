#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair_gsk(char open_gsk, char close_gsk) {
    return (open_gsk == '(' && close_gsk == ')') ||
           (open_gsk == '{' && close_gsk == '}') ||
           (open_gsk == '[' && close_gsk == ']');
}

bool checkBalanced_gsk(string exp_gsk) {
    stack<char> s_gsk;
    for (char ch_gsk : exp_gsk) {
        switch (ch_gsk) {
            case '(':
            case '{':
            case '[':
                s_gsk.push(ch_gsk);
                break;
            case ')':
            case '}':
            case ']':
                if (s_gsk.empty() || !isMatchingPair_gsk(s_gsk.top(), ch_gsk))
                    return false;
                s_gsk.pop();
                break;
            default:
                // Ignore non-bracket characters
                break;
        }
    }
    return s_gsk.empty();
}

int main() {
    string exp_gsk;
    int choice_gsk;
    do {
        cout << "\n--- Balanced Parentheses Checker ---\n";
        cout << "1. Check Expression\n2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch (choice_gsk) {
            case 1:
                cout << "Enter an expression: ";
                cin >> exp_gsk;
                if (checkBalanced_gsk(exp_gsk))
                    cout << "The expression is BALANCED.\n";
                else
                    cout << "The expression is NOT BALANCED.\n";
                break;

            case 2:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice_gsk != 2);

    return 0;
}