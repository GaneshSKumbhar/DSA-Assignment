#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student_gsk {
    string name_gsk;
    int roll_no_gsk;
    float total_marks_gsk;
};

const string sample_names_gsk[] = {
    "Rohan", "Isha", "Priya", "Kabir", "Tanvi", "XYZ", "Arjun", "Anaya", "Neha", "Salman"
};
const int NAMES_SIZE_gsk = sizeof(sample_names_gsk) / sizeof(sample_names_gsk[0]);

void printStudents_gsk(const Student_gsk arr_gsk[], int n_gsk) {
    for (int i_gsk = 0; i_gsk < n_gsk; ++i_gsk) {
        cout << "Roll No: " << arr_gsk[i_gsk].roll_no_gsk << ", Name: " << arr_gsk[i_gsk].name_gsk << ", Total Marks: " << arr_gsk[i_gsk].total_marks_gsk << endl;
    }
    cout << endl;
}

void bubbleSort_gsk(Student_gsk arr_gsk[], int n_gsk, int& swapCount_gsk) {
    swapCount_gsk = 0;
    cout << "\nBubble Sort Steps:\n";
    for (int i_gsk = 0; i_gsk < n_gsk - 1; ++i_gsk) {
        bool swapped_gsk = false;
        cout << "Pass " << i_gsk + 1 << ":\n";
        for (int j_gsk = 0; j_gsk < n_gsk - i_gsk - 1; ++j_gsk) {
            cout << "  Comparing roll_no " << arr_gsk[j_gsk].roll_no_gsk << " and " << arr_gsk[j_gsk + 1].roll_no_gsk << ": ";
            if (arr_gsk[j_gsk].roll_no_gsk > arr_gsk[j_gsk + 1].roll_no_gsk) {
                cout << "swapping\n";
                swap(arr_gsk[j_gsk], arr_gsk[j_gsk + 1]);
                swapCount_gsk++;
                swapped_gsk = true;

                // Print array after swap
                cout << "    Array now: ";
                for (int k_gsk = 0; k_gsk < n_gsk; ++k_gsk) cout << arr_gsk[k_gsk].roll_no_gsk << " ";
                cout << endl;
            }
            else {
                cout << "no swap\n";
            }
        }
        if (!swapped_gsk) {
            cout << "No swaps in this pass, array is sorted.\n";
            break;
        }
    }
}

int partition_gsk(Student_gsk arr_gsk[], int low_gsk, int high_gsk, int& swapCount_gsk) {
    int pivot_gsk = arr_gsk[high_gsk].roll_no_gsk;
    int i_gsk = low_gsk - 1;
    cout << "Partitioning with pivot roll_no " << pivot_gsk << " from index " << low_gsk << " to " << high_gsk << endl;
    for (int j_gsk = low_gsk; j_gsk < high_gsk; ++j_gsk) {
        cout << "  Comparing " << arr_gsk[j_gsk].roll_no_gsk << " with pivot " << pivot_gsk << ": ";
        if (arr_gsk[j_gsk].roll_no_gsk < pivot_gsk) {
            ++i_gsk;
            swap(arr_gsk[i_gsk], arr_gsk[j_gsk]);
            swapCount_gsk++;
            cout << "swapped positions " << i_gsk << " and " << j_gsk << endl;
        } else {
            cout << "no swap\n";
        }
    }
    swap(arr_gsk[i_gsk + 1], arr_gsk[high_gsk]);
    swapCount_gsk++;
    cout << "Swapped pivot with element at position " << (i_gsk + 1) << endl;

    // Print array after partition
    cout << "Array now (roll_no): ";
    for (int k_gsk = low_gsk; k_gsk <= high_gsk; ++k_gsk) cout << arr_gsk[k_gsk].roll_no_gsk << " ";
    cout << endl;

    return i_gsk + 1;
}

void quickSort_gsk(Student_gsk arr_gsk[], int low_gsk, int high_gsk, int& swapCount_gsk) {
    if (low_gsk < high_gsk) {
        int pi_gsk = partition_gsk(arr_gsk, low_gsk, high_gsk, swapCount_gsk);
        quickSort_gsk(arr_gsk, low_gsk, pi_gsk - 1, swapCount_gsk);
        quickSort_gsk(arr_gsk, pi_gsk + 1, high_gsk, swapCount_gsk);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int n_gsk;
    cout << "Enter number of students: ";
    cin >> n_gsk;
    Student_gsk* arr_gsk = new Student_gsk[n_gsk];

    // Generate random student data
    for (int i_gsk = 0; i_gsk < n_gsk; ++i_gsk) {
        arr_gsk[i_gsk].name_gsk = sample_names_gsk[rand() % NAMES_SIZE_gsk];
        arr_gsk[i_gsk].roll_no_gsk = 1 + rand() % 100;
        arr_gsk[i_gsk].total_marks_gsk = 40.0f + static_cast<float>(rand() % 61);
    }

    cout << "\nOriginal Array:\n";
    printStudents_gsk(arr_gsk, n_gsk);

    // Bubble Sort
    Student_gsk* arr_bubble_gsk = new Student_gsk[n_gsk];
    for (int i_gsk = 0; i_gsk < n_gsk; ++i_gsk) arr_bubble_gsk[i_gsk] = arr_gsk[i_gsk];
    int bubbleSwaps_gsk = 0;
    bubbleSort_gsk(arr_bubble_gsk, n_gsk, bubbleSwaps_gsk);
    cout << "\nAfter Bubble Sort:\n";
    printStudents_gsk(arr_bubble_gsk, n_gsk);
    cout << "Total swaps in Bubble Sort: " << bubbleSwaps_gsk << "\n\n";

    // Quick Sort
    Student_gsk* arr_quick_gsk = new Student_gsk[n_gsk];
    for (int i_gsk = 0; i_gsk < n_gsk; ++i_gsk) arr_quick_gsk[i_gsk] = arr_gsk[i_gsk];
    int quickSwaps_gsk = 0;
    cout << "Quick Sort Steps:\n";
    quickSort_gsk(arr_quick_gsk, 0, n_gsk - 1, quickSwaps_gsk);
    cout << "\nAfter Quick Sort:\n";
    printStudents_gsk(arr_quick_gsk, n_gsk);
    cout << "Total swaps in Quick Sort: " << quickSwaps_gsk << "\n";

    delete[] arr_gsk;
    delete[] arr_bubble_gsk;
    delete[] arr_quick_gsk;
    return 0;
}
