#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    double num1 = atoi(argv[1]);
    double num2 = atoi(argv[3]);
    char op = argv[2][0];

    double result;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            cout << "Error" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}

