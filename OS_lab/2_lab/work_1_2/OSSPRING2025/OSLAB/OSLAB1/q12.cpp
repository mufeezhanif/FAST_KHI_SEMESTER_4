#include <iostream>
#include <cstring>  

using namespace std;

bool isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main(int argc, char *argv[]) {
    
    if (isPalindrome(argv[1])) {
        cout << "palindrome" << endl;
    } else {
        cout << "not a palindrome" << endl;
    }

    return 0;
}

