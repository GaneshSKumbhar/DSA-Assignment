# Balanced Parentheses Checker using Stack (C++)

## Theory
A **balanced parentheses** string is one in which every opening bracket (`(`, `{`, `[`) has a corresponding closing bracket (`)`, `}`, `]`) and they appear in the correct order.

This problem is efficiently solved using a **stack** data structure:
- Push each opening bracket onto the stack.
- For each closing bracket, pop the top of the stack and verify it matches.
- At the end, if the stack is empty, the string is balanced.

---

## Algorithm
1. Create a stack to store opening brackets.
2. Traverse the input string character by character.
3. Use a **switch case** to:
   - **Push** opening brackets.
   - **Pop** and check matching pairs for closing brackets.
4. If a mismatch occurs or the stack becomes empty incorrectly → string is **unbalanced**.
5. After traversal, if the stack is empty → string is **balanced**.

---

## Code

```cpp
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
```
---

## Sample Output

```
--- Balanced Parentheses Checker ---
1. Check Expression
2. Exit
Enter your choice: 1
Enter an expression: {[()]}
The expression is BALANCED.

--- Balanced Parentheses Checker ---
1. Check Expression
2. Exit
Enter your choice: 1
Enter an expression: {[(])}
The expression is NOT BALANCED.

--- Balanced Parentheses Checker ---
1. Check Expression
2. Exit
Enter your choice: 2
Exiting program...
```