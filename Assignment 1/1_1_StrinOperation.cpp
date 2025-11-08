#include <iostream>
using namespace std;


int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringReverse(char str[]) {
    int len = stringLength(str);
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void stringConcat(char dest[], const char src[]) {
    int dest_len = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
}

int main() {
    char str1[100], str2[100], dest[200];

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // Length
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    cout << "Length of first string: " << len1 << endl;
    cout << "Length of second string: " << len2 << endl;

    // Copy
    stringCopy(dest, str1);
    cout << "Copy of first string: " << dest << endl;

    // Reverse
    stringReverse(str1);
    cout << "Reversed first string: " << str1 << endl;

    // Concatenate
    stringConcat(str1, str2);
    cout << "Concatenated string (first + second): " << str1 << endl;

    return 0;
}
