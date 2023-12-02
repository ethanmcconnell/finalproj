#include <iostream>
#include "OperationResult.h"
using namespace std;

int main () {
    double num1, num2, result;
    string oper;

    cout << "Enter first number:" << endl;
    cin >> num1;

    while (true) {
        cout << "Enter operator: +, -, *, /" << endl;
        cin >> oper;
        if (oper != "+" && oper != "-" && oper != "*" && oper != "/") {
            cout << "Invalid Operator. Try again." << endl;
        }
        else {
            break;
        }
    }

    cout << "Enter second number" << endl;
    cin >> num2;

    result = NumsResult(num1, oper, num2);

    if (oper == "+") {
        cout << "The sum is: " << result << endl;
    }
    else if (oper == "-") {
        cout << "The difference is: " << result << endl;
    }
    else if (oper == "*") {
        cout << "The product is: " << result << endl;
    }
    else if (oper == "/"){
        cout << "The quotient is: " << result << endl;
    }


    return 0;
}
