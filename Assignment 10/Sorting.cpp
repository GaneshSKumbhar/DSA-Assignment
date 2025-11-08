#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;

struct Employee_gsk {
    string name_gsk;
    float height_gsk;
    float weight_gsk;
    float avg_gsk() const {
        return (height_gsk + weight_gsk) / 2;
    }
};

void printEmployees_gsk(const vector<Employee_gsk>& employees_gsk) {
    cout << "Name\tHeight\tWeight\tAverage\n";
    for (const auto& e_gsk : employees_gsk) {
        cout << e_gsk.name_gsk << "\t" << e_gsk.height_gsk << "\t" << e_gsk.weight_gsk << "\t" << e_gsk.avg_gsk() << "\n";
    }
    cout << endl;
}

void selectionSort_gsk(vector<Employee_gsk>& arr_gsk) {
    int n_gsk = arr_gsk.size();
    for (int i_gsk = 0; i_gsk < n_gsk - 1; ++i_gsk) {
        int max_idx_gsk = i_gsk;
        for (int j_gsk = i_gsk + 1; j_gsk < n_gsk; ++j_gsk) {
            if (arr_gsk[j_gsk].avg_gsk() > arr_gsk[max_idx_gsk].avg_gsk())
                max_idx_gsk = j_gsk;
        }
        if (max_idx_gsk != i_gsk)
            swap(arr_gsk[i_gsk], arr_gsk[max_idx_gsk]);
    }
}

void merge_gsk(vector<Employee_gsk>& arr_gsk, int left_gsk, int mid_gsk, int right_gsk) {
    int n1_gsk = mid_gsk - left_gsk + 1, n2_gsk = right_gsk - mid_gsk;
    vector<Employee_gsk> L_gsk(n1_gsk), R_gsk(n2_gsk);

    for (int i_gsk = 0; i_gsk < n1_gsk; ++i_gsk)
        L_gsk[i_gsk] = arr_gsk[left_gsk + i_gsk];
    for (int j_gsk = 0; j_gsk < n2_gsk; ++j_gsk)
        R_gsk[j_gsk] = arr_gsk[mid_gsk + 1 + j_gsk];

    int i_gsk = 0, j_gsk = 0, k_gsk = left_gsk;
    while (i_gsk < n1_gsk && j_gsk < n2_gsk) {
        if (L_gsk[i_gsk].avg_gsk() >= R_gsk[j_gsk].avg_gsk()) {
            arr_gsk[k_gsk++] = L_gsk[i_gsk++];
        } else {
            arr_gsk[k_gsk++] = R_gsk[j_gsk++];
        }
    }
    while (i_gsk < n1_gsk) arr_gsk[k_gsk++] = L_gsk[i_gsk++];
    while (j_gsk < n2_gsk) arr_gsk[k_gsk++] = R_gsk[j_gsk++];
}

void mergeSort_gsk(vector<Employee_gsk>& arr_gsk, int left_gsk, int right_gsk) {
    if (left_gsk < right_gsk) {
        int mid_gsk = left_gsk + (right_gsk - left_gsk) / 2;
        mergeSort_gsk(arr_gsk, left_gsk, mid_gsk);
        mergeSort_gsk(arr_gsk, mid_gsk + 1, right_gsk);
        merge_gsk(arr_gsk, left_gsk, mid_gsk, right_gsk);
    }
}

int main() {
    srand((unsigned)time(0));
    int n_gsk;
    cout << "Enter the number of employees: ";
    cin >> n_gsk;

    vector<Employee_gsk> employees_gsk(n_gsk);

    // Sample names pool for random assignment
    vector<string> sample_names_gsk = {
        "Alice", "Bob", "Charlie", "Diana", "Ethan",
        "Fiona", "George", "Hannah", "Ivan", "Julia"
    };

    // Generate random employee data
    for (int i_gsk = 0; i_gsk < n_gsk; ++i_gsk) {
        employees_gsk[i_gsk].name_gsk = sample_names_gsk[rand() % sample_names_gsk.size()];
        employees_gsk[i_gsk].height_gsk = 150 + static_cast<float>(rand() % 51); // 150-200 cm
        employees_gsk[i_gsk].weight_gsk = 50 + static_cast<float>(rand() % 51); // 50-100 kg
    }

    cout << "\nGenerated Employee List:\n";
    printEmployees_gsk(employees_gsk);

    // Selection Sort timing
    vector<Employee_gsk> sel_sorted_gsk = employees_gsk;
    auto start_sel_gsk = high_resolution_clock::now();
    selectionSort_gsk(sel_sorted_gsk);
    auto end_sel_gsk = high_resolution_clock::now();
    auto sel_duration_gsk = duration_cast<microseconds>(end_sel_gsk - start_sel_gsk);

    cout << "Employees sorted by Selection Sort (descending avg):\n";
    printEmployees_gsk(sel_sorted_gsk);
    cout << "Selection Sort Time: " << sel_duration_gsk.count() << " microseconds\n";

    // Merge Sort timing
    vector<Employee_gsk> merge_sorted_gsk = employees_gsk;
    auto start_merge_gsk = high_resolution_clock::now();
    mergeSort_gsk(merge_sorted_gsk, 0, n_gsk - 1);
    auto end_merge_gsk = high_resolution_clock::now();
    auto merge_duration_gsk = duration_cast<microseconds>(end_merge_gsk - start_merge_gsk);

    cout << "Employees sorted by Merge Sort (descending avg):\n";
    printEmployees_gsk(merge_sorted_gsk);
    cout << "Merge Sort Time: " << merge_duration_gsk.count() << " microseconds\n";

    // Conclusion
    cout << "\nConclusion:\n";
    if (sel_duration_gsk < merge_duration_gsk)
        cout << "Selection Sort took less time.\n";
    else if (merge_duration_gsk < sel_duration_gsk)
        cout << "Merge Sort took less time.\n";
    else
        cout << "Both sorting algorithms took similar time.\n";

    return 0;
}
