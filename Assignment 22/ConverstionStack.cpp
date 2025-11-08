#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int precedence_gsk(char op_gsk) {
    if (op_gsk == '+' || op_gsk == '-') return 1;
    if (op_gsk == '*' || op_gsk == '/') return 2;
    if (op_gsk == '^') return 3;
    return 0;
}

bool isOperator_gsk(char ch_gsk) {
    return ch_gsk == '+' || ch_gsk == '-' || ch_gsk == '*' || ch_gsk == '/' || ch_gsk == '^';
}

string showStack_gsk(const vector<char>& stk_gsk) {
    if (stk_gsk.empty()) return "[]";
    string s_gsk = "[";
    for (size_t i = 0; i < stk_gsk.size(); ++i) {
        s_gsk += stk_gsk[i];
        if (i + 1 < stk_gsk.size()) s_gsk += ", ";
    }
    s_gsk += "]";
    return s_gsk;
}

int main() {
    string expr_gsk;
    cout << "Enter infix expression (e.g. a-b*c-d/e+f): ";
    getline(cin, expr_gsk);

    string input_gsk;
    for (char c : expr_gsk) if (c != ' ') input_gsk.push_back(c);

    vector<char> stack_gsk;
    string output_gsk;
    int step_gsk = 1;

    cout << "\\nStep-by-step conversion:\\n";
    cout << "-------------------------------------------------------------\\n";
    cout << "Step | Read | Action                            | Stack | Output\\n";
    cout << "-------------------------------------------------------------\\n";

    for (size_t i = 0; i < input_gsk.size(); ++i) {
        char ch_gsk = input_gsk[i];
        string action_gsk;

        if (isalnum((unsigned char)ch_gsk)) {
            output_gsk.push_back(ch_gsk);
            action_gsk = "Operand -> append to output";
            cout << step_gsk++ << "    |  " << ch_gsk << "   | " << action_gsk;
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        } else if (ch_gsk == '(') {
            stack_gsk.push_back(ch_gsk);
            action_gsk = "Push '('";
            cout << step_gsk++ << "    |  " << ch_gsk << "   | " << action_gsk;
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        } else if (ch_gsk == ')') {
            action_gsk = "Pop until '(' -> ";
            cout << step_gsk++ << "    |  " << ch_gsk << "   | ";
            while (!stack_gsk.empty() && stack_gsk.back() != '(') {
                output_gsk.push_back(stack_gsk.back());
                action_gsk += string(1, stack_gsk.back()) + " ";
                stack_gsk.pop_back();
            }
            if (!stack_gsk.empty() && stack_gsk.back() == '(') stack_gsk.pop_back();
            cout << action_gsk;
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        } else if (isOperator_gsk(ch_gsk)) {
            action_gsk = "Process operator";
            cout << step_gsk++ << "    |  " << ch_gsk << "   | " << action_gsk;
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";

            while (!stack_gsk.empty() && stack_gsk.back() != '(') {
                char top_gsk = stack_gsk.back();
                int precTop_gsk = precedence_gsk(top_gsk);
                int precCh_gsk = precedence_gsk(ch_gsk);

                if (precTop_gsk > precCh_gsk || (precTop_gsk == precCh_gsk && ch_gsk != '^')) {
                    stack_gsk.pop_back();
                    output_gsk.push_back(top_gsk);
                    cout << "      Pop op " << top_gsk << " -> output";
                    cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
                } else {
                    break;
                }
            }
            stack_gsk.push_back(ch_gsk);
            cout << "      Push op " << ch_gsk << " ";
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        } else {
            cout << step_gsk++ << "    |  " << ch_gsk << "   | ignored (unknown char)";
            cout << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        }
    }

    cout << "-------------------------------------------------------------\\n";
    cout << "Final steps: pop remaining operators from stack\\n";
    while (!stack_gsk.empty()) {
        if (stack_gsk.back() == '(' || stack_gsk.back() == ')') {
            stack_gsk.pop_back();
        } else {
            char op_gsk = stack_gsk.back();
            stack_gsk.pop_back();
            output_gsk.push_back(op_gsk);
            cout << "Pop op " << op_gsk << " | " << showStack_gsk(stack_gsk) << " | " << output_gsk << "\\n";
        }
    }

    cout << "\\nPostfix expression: " << output_gsk << "\\n";
    return 0;
}