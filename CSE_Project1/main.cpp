#include <iostream>
#include <string>

using namespace std;

/// basic functions for encode
string* createArray(string base) {
    /// creates an array with the base string and the shifted strings
    string* baseArray = new string[base.length()];
    baseArray[0] = base;
    for(int x = 1; x < base.length(); x++) {
        baseArray[x] += baseArray[x-1][base.length() - 1];
        for(int y = 0; y < base.length() - 1; y++) {
            baseArray[x] += baseArray[x-1][y];
        }
    }
    return baseArray;
}

void reverseArray(string* base) {
    /// intended for use on the shifted line arrays
    int size = base[0].length();
    /// size is the length of the original string
    for(int x = 0; x < size; x++) {
        for(int y = 0; y < (size / 2); y++) {
            /// reverses the string
            char temp = base[x][y];
            base[x][y] = base[x][size - (y + 1)];
            base[x][size - (y + 1)] = temp;
        }
    }
}

int getIndex(string base, string* array) {
    /// finds the index that contains the base string
    for(int n = 0; n < base.length(); n++) {
        if(base == array[n]) {
            return n;
        }
    }
    /// when base cannot be found in the array
    cout << "base string is not in the array" << endl;
    return -1;
}

string encode(string* base) {
    /// creates the encoded string from the sorted array
    int size = base[0].length();
    int count = 1;
    string first;
    string code;
    /// creates the string 'first'
    for(int a = 0; a < size; a++) {
        first += base[a][0];
    }
    /// if 'first' is empty, the function will return '\n' back
    if(first == "") {
        return "\n";
    } else {
        /// otherwise, it would produce the encoded string
        for(int b = 0; b < size - 1; b++) {
            if(first[b] == first[b+1]) {
                /// if there is repeating letters, we count the number of them
                count++;
            } else {
                /// if there is no more repeating letters, or it's just one letter cluster
                /// we append the count + the letter into the code string
                code += to_string(count);
                code += ' ';
                code += first[b];
                code += ' ';
                /// reset the count
                count = 1;
            }
        }
        code += to_string(count);
        code += ' ';
        code += first[size - 1];
        code += '\n';
    }
    /// returns the encoded string
    return code;
}

/// sorting algorithms
void insertionSort(string* base) {
    /// intended on use for the shifted strings array
    /// based on textbook example
    int size = base[0].length();
    int n;
    string key;
    for (int x = 1; x < size; x++)
    {
        key = base[x];
        n = x - 1;
        while (n >= 0 && base[n] > key)
        {
            base[n + 1] = base[n];
            n = n - 1;
        }
        base[n + 1] = key;
    }
}

int main(int argc, char * argv[]) {
    int sort = 0;
    string input;
    string* base;
    int index;
    string code;
    if (argc > 1) {
        if (string(argv[1]) == "insertion") {
            sort = 1;
        } else if (string(argv[1]) == "mergesort") {
            sort = 2;
        }
    } else {
        cout << "Wrong command argument entered. Please try again" << endl;
        return 0;
    }
    while (!cin.eof()) {
        getline(cin, input);
        if(input == "") {
            cout << "\n";
        } else {
            base = createArray(input);
            reverseArray(base);
            if(sort == 1) {
                insertionSort(base);
            } else if (sort == 2){
                cout << "Mergesort" << endl;
                return 0;
            }
            reverseArray(base);
            index = getIndex(input, base);
            code = encode(base);
            cout << index << endl << code;
        }
    }
    return 0;
}