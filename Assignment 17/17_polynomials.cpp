#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Term_gsk {
    int coeff_gsk;
    int exp_gsk;
    Term_gsk* next_gsk;
};

class Polynomial_gsk {
    Term_gsk* head_gsk;
public:
    Polynomial_gsk() : head_gsk(nullptr) {}

    void addTerm_gsk(int coeff_gsk, int exp_gsk) {
        Term_gsk* newTerm_gsk = new Term_gsk{coeff_gsk, exp_gsk, nullptr};
        if (!head_gsk || exp_gsk > head_gsk->exp_gsk) {
            newTerm_gsk->next_gsk = head_gsk;
            head_gsk = newTerm_gsk;
            return;
        }
        Term_gsk* temp_gsk = head_gsk;
        while (temp_gsk->next_gsk && temp_gsk->next_gsk->exp_gsk >= exp_gsk)
            temp_gsk = temp_gsk->next_gsk;
        if (temp_gsk->exp_gsk == exp_gsk) {
            temp_gsk->coeff_gsk += coeff_gsk;
            delete newTerm_gsk;
        } else {
            newTerm_gsk->next_gsk = temp_gsk->next_gsk;
            temp_gsk->next_gsk = newTerm_gsk;
        }
    }

    void display_gsk() const {
        if (!head_gsk) {
            cout << "0";
            return;
        }
        Term_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            if (temp_gsk->coeff_gsk > 0 && temp_gsk != head_gsk) cout << " + ";
            if (temp_gsk->coeff_gsk != 0) {
                cout << temp_gsk->coeff_gsk;
                if (temp_gsk->exp_gsk != 0) cout << "x^" << temp_gsk->exp_gsk;
            }
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }

    Polynomial_gsk add_gsk(const Polynomial_gsk& other_gsk) const {
        Polynomial_gsk result_gsk;
        Term_gsk* t1_gsk = head_gsk;
        Term_gsk* t2_gsk = other_gsk.head_gsk;

        while (t1_gsk && t2_gsk) {
            if (t1_gsk->exp_gsk > t2_gsk->exp_gsk) {
                result_gsk.addTerm_gsk(t1_gsk->coeff_gsk, t1_gsk->exp_gsk);
                t1_gsk = t1_gsk->next_gsk;
            } else if (t2_gsk->exp_gsk > t1_gsk->exp_gsk) {
                result_gsk.addTerm_gsk(t2_gsk->coeff_gsk, t2_gsk->exp_gsk);
                t2_gsk = t2_gsk->next_gsk;
            } else {
                result_gsk.addTerm_gsk(t1_gsk->coeff_gsk + t2_gsk->coeff_gsk, t1_gsk->exp_gsk);
                t1_gsk = t1_gsk->next_gsk;
                t2_gsk = t2_gsk->next_gsk;
            }
        }

        while (t1_gsk) {
            result_gsk.addTerm_gsk(t1_gsk->coeff_gsk, t1_gsk->exp_gsk);
            t1_gsk = t1_gsk->next_gsk;
        }
        while (t2_gsk) {
            result_gsk.addTerm_gsk(t2_gsk->coeff_gsk, t2_gsk->exp_gsk);
            t2_gsk = t2_gsk->next_gsk;
        }

        return result_gsk;
    }
};

int main() {
    srand(time(0));
    Polynomial_gsk poly1_gsk, poly2_gsk;
    int n_gsk;

    cout << "Enter number of terms for Polynomial 1: ";
    cin >> n_gsk;
    for (int i = 0; i < n_gsk; ++i) {
        int coeff_gsk = 1 + rand() % 10;
        int exp_gsk = rand() % 6;
        poly1_gsk.addTerm_gsk(coeff_gsk, exp_gsk);
    }

    cout << "Enter number of terms for Polynomial 2: ";
    cin >> n_gsk;
    for (int i = 0; i < n_gsk; ++i) {
        int coeff_gsk = 1 + rand() % 10;
        int exp_gsk = rand() % 6;
        poly2_gsk.addTerm_gsk(coeff_gsk, exp_gsk);
    }

    cout << "\nPolynomial 1: ";
    poly1_gsk.display_gsk();

    cout << "Polynomial 2: ";
    poly2_gsk.display_gsk();

    Polynomial_gsk sum_gsk = poly1_gsk.add_gsk(poly2_gsk);
    cout << "Sum of Polynomials: ";
    sum_gsk.display_gsk();

    return 0;
}