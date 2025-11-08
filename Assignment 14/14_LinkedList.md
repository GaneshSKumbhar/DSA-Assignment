# Student Sports Set Operations using Linked List with Menu (User Inputs Numbers)

## Theory
This program manages two sets of students based on their favorite sports using linked lists:

- **Set A (Cricket)**: Students who like cricket (represented by numbers).  
- **Set B (Football)**: Students who like football (represented by numbers).  

Operations supported via menu:

1. **Display Set A or Set B**.  
2. **Intersection**: Students who like both Cricket and Football.  
3. **Symmetric Difference**: Students who like either Cricket or Football, but not both.  
4. **Complement**: Number of students who like neither Cricket nor Football.  

---

## Algorithm

### Intersection
1. For each student number in Set A, check if it exists in Set B.  
2. If yes, add it to the intersection list.

### Symmetric Difference
1. For each student number in Set A, add to result if not in Set B.  
2. For each student number in Set B, add to result if not in Set A.

### Complement
1. Count total students.  
2. Subtract the union of Set A and Set B to get students who like neither sport.

---

## Code

```cpp
#include <iostream>
using namespace std;

struct Student_gsk {
    int id_gsk;
    Student_gsk* next_gsk;
};

class StudentSet_gsk {
    Student_gsk* head_gsk;
public:
    StudentSet_gsk() : head_gsk(nullptr) {}

    void addStudent_gsk(int id_gsk) {
        Student_gsk* newStudent_gsk = new Student_gsk{id_gsk, nullptr};
        if (!head_gsk) {
            head_gsk = newStudent_gsk;
        } else {
            Student_gsk* temp_gsk = head_gsk;
            while (temp_gsk->next_gsk) temp_gsk = temp_gsk->next_gsk;
            temp_gsk->next_gsk = newStudent_gsk;
        }
    }

    bool contains_gsk(int id_gsk) {
        Student_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            if (temp_gsk->id_gsk == id_gsk) return true;
            temp_gsk = temp_gsk->next_gsk;
        }
        return false;
    }

    void display_gsk() {
        Student_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            cout << temp_gsk->id_gsk << " ";
            temp_gsk = temp_gsk->next_gsk;
        }
        cout << endl;
    }

    Student_gsk* getHead_gsk() { return head_gsk; }

    int count_gsk() {
        int count = 0;
        Student_gsk* temp_gsk = head_gsk;
        while (temp_gsk) {
            count++;
            temp_gsk = temp_gsk->next_gsk;
        }
        return count;
    }
};

StudentSet_gsk intersection_gsk(StudentSet_gsk& A_gsk, StudentSet_gsk& B_gsk) {
    StudentSet_gsk result_gsk;
    Student_gsk* temp_gsk = A_gsk.getHead_gsk();
    while (temp_gsk) {
        if (B_gsk.contains_gsk(temp_gsk->id_gsk))
            result_gsk.addStudent_gsk(temp_gsk->id_gsk);
        temp_gsk = temp_gsk->next_gsk;
    }
    return result_gsk;
}

StudentSet_gsk symmetricDifference_gsk(StudentSet_gsk& A_gsk, StudentSet_gsk& B_gsk) {
    StudentSet_gsk result_gsk;
    Student_gsk* temp_gsk = A_gsk.getHead_gsk();
    while (temp_gsk) {
        if (!B_gsk.contains_gsk(temp_gsk->id_gsk))
            result_gsk.addStudent_gsk(temp_gsk->id_gsk);
        temp_gsk = temp_gsk->next_gsk;
    }
    temp_gsk = B_gsk.getHead_gsk();
    while (temp_gsk) {
        if (!A_gsk.contains_gsk(temp_gsk->id_gsk))
            result_gsk.addStudent_gsk(temp_gsk->id_gsk);
        temp_gsk = temp_gsk->next_gsk;
    }
    return result_gsk;
}

int main() {
    StudentSet_gsk cricket_gsk, football_gsk;
    int nTotal_gsk, nCricket_gsk, nFootball_gsk;
    int id_gsk, choice_gsk;

    cout << "Enter total number of students in class: ";
    cin >> nTotal_gsk;

    cout << "Enter number of students who like Cricket: ";
    cin >> nCricket_gsk;
    cout << "Enter student numbers for Cricket: ";
    for (int i = 0; i < nCricket_gsk; i++) {
        cin >> id_gsk;
        cricket_gsk.addStudent_gsk(id_gsk);
    }

    cout << "Enter number of students who like Football: ";
    cin >> nFootball_gsk;
    cout << "Enter student numbers for Football: ";
    for (int i = 0; i < nFootball_gsk; i++) {
        cin >> id_gsk;
        football_gsk.addStudent_gsk(id_gsk);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Cricket Set\n";
        cout << "2. Display Football Set\n";
        cout << "3. Display Students who like both\n";
        cout << "4. Display Students who like either but not both\n";
        cout << "5. Display number of students who like neither\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_gsk;

        switch(choice_gsk) {
            case 1:
                cout << "Cricket Set: ";
                cricket_gsk.display_gsk();
                break;
            case 2:
                cout << "Football Set: ";
                football_gsk.display_gsk();
                break;
            case 3: {
                StudentSet_gsk both_gsk = intersection_gsk(cricket_gsk, football_gsk);
                cout << "Students who like both: ";
                both_gsk.display_gsk();
                break;
            }
            case 4: {
                StudentSet_gsk either_gsk = symmetricDifference_gsk(cricket_gsk, football_gsk);
                cout << "Students who like either but not both: ";
                either_gsk.display_gsk();
                break;
            }
            case 5: {
                StudentSet_gsk both_gsk = intersection_gsk(cricket_gsk, football_gsk);
                int neither_gsk = nTotal_gsk - (cricket_gsk.count_gsk() + football_gsk.count_gsk() - both_gsk.count_gsk());
                cout << "Number of students who like neither: " << neither_gsk << endl;
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
```
---

## Sample Output

```
Enter total number of students in class: 6
Enter number of students who like Cricket: 3
Enter student numbers for Cricket: 1 2 3
Enter number of students who like Football: 3
Enter student numbers for Football: 2 4 5

Menu:
1. Display Cricket Set
2. Display Football Set
3. Display Students who like both
4. Display Students who like either but not both
5. Display number of students who like neither
0. Exit
Enter your choice: 3
Students who like both: 2

Enter your choice: 4
Students who like either but not both: 1 3 4 5

Enter your choice: 5
Number of students who like neither: 1

Enter your choice: 0
Exiting program.

```