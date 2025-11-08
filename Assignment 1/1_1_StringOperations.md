# Basic String Operations without Built-in Functions

## Theory

Strings in C are represented as arrays of characters ending with a null character `'\0'`. Basic string operations such as length calculation, copy, reverse, and concatenation can be implemented manually by iterating over the character array.

- **Length calculation:** Traverse the array until the null character is found, counting the characters.
- **String copy:** Copy each character from the source array to the destination until the null character.
- **String reverse:** Swap characters starting from the ends moving towards the center.
- **String concatenation:** Append characters of the second string to the end of the first before the null terminator.

Implementing these operations without library functions helps in understanding the internal mechanics of string handling and provides flexibility for custom or constrained environments.


## Algorithm

1. Input two strings from the user.  
2. Find the length of both strings manually by traversing until `\0`.  
3. Copy the first string into another array character by character.  
4. Reverse the first string by swapping characters from start and end.  
5. Concatenate the second string to the end of the first string.  
6. Print the results of each operation.  

## Code

```cpp
#include <iostream>
using namespace std;

// Calculate length of string (excluding '\0')
int stringLength(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Copy source string into destination
void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// Reverse string in place
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

// Concatenate src string at the end of dest string
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

```

## Sample Output

**Input:**  
```
Enter first string: hello
Enter second string: world
```

**Output:**  
```
Length of first string: 5
Length of second string: 5
Copy of first string: hello
Reversed first string: olleh
Concatenated string (first + second): ollehworld
```
