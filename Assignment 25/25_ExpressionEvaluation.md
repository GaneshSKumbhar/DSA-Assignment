# Postfix Expression Evaluation using Stack

## Theory
A **Postfix Expression** (Reverse Polish Notation) is a mathematical notation where operators come **after** operands.  
It removes the need for parentheses and is efficiently evaluated using a **stack**.

Example:  
Infix: (3 + 4) * 5  
Postfix: 3 4 + 5 *

**Working Principle:**  
- Traverse from left to right.  
- Push operands onto the stack.  
- When an operator is found, pop two operands, perform the operation, and push the result.

---

## Algorithm
1. Create an empty stack.  
2. Scan the postfix expression from left to right.  
3. If the character is a digit, push it onto the stack.  
4. If it’s an operator, pop two elements, perform the operation using switch-case, and push the result.  
5. After scanning all characters, the top of the stack holds the final result.

---

## Program Code

```cpp
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
```
---

## Sample Output

```
--- Postfix Expression Evaluation ---
1. Evaluate Expression
2. Exit
Enter your choice: 1
Enter postfix expression (single-digit operands): 34+5*
Result: 35

--- Postfix Expression Evaluation ---
1. Evaluate Expression
2. Exit
Enter your choice: 1
Enter postfix expression (single-digit operands): 82/3-
Result: 1

--- Postfix Expression Evaluation ---
1. Evaluate Expression
2. Exit
Enter your choice: 2
Exiting program...
```