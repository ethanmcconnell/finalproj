#include <iostream>
#include "OperationResult.h"
#include <vector>
using namespace std;

int main () {

    bool anotherOperation = true;

    vector <double> firstNum;
    vector <string> theOperator;
    vector <double> secondNum;
    vector<double> previousVals;

    while (anotherOperation) {
        string num1, num2;
        double result;
        string oper;
        string oneMore;
        bool numberOneBool = true;
        bool numberTwoBool = true;

        while (numberOneBool) {
            cout << "Enter first number:" << endl;
            cin >> num1;
            numberOneBool = false;

            for (int i = 0; i < num1.size(); ++i) {
                if (!isdigit(num1[i])) {
                    numberOneBool = true;
                    cout << "Please enter a valid number." << endl;
                    break;
                }
            }
        }
        double numOneDouble = std::stod(num1);
        firstNum.push_back(numOneDouble);

        while (true) {
            cout << "Enter operator: +, -, *, /" << endl;
            cin >> oper;
            if (oper != "+" && oper != "-" && oper != "*" && oper != "/") {
                cout << "Invalid Operator. Try again." << endl;
            } else {
                break;
            }
        }
        theOperator.push_back(oper);

        while (numberTwoBool) {
        cout << "Enter second number" << endl;
        cin >> num2;
        numberTwoBool = false;

            for (int i = 0; i < num2.size(); ++i) {
                if (!isdigit(num2[i])) {
                    numberTwoBool = true;
                    cout << "Please enter a valid number." << endl;
                    break;
                }
            }
        }
        double numTwoDouble = std::stod(num2);
        secondNum.push_back(numTwoDouble);

        result = NumsResult(numOneDouble, oper, numTwoDouble);

        if (oper == "+") {
            cout << "The sum is: " << result << endl;
        } else if (oper == "-") {
            cout << "The difference is: " << result << endl;
        } else if (oper == "*") {
            cout << "The product is: " << result << endl;
        } else if (oper == "/") {
            cout << "The quotient is: " << result << endl;
        }

        previousVals.push_back(result);

        cout << "Would you like to enter another operation: yes/no" << endl;
        cin >> oneMore;

        if (oneMore == "no") {
            anotherOperation = false;
            cout << endl << endl;
            cout << "Previous answers: " << endl;
                for (int i = 0; i < previousVals.size(); ++i) {
                    cout << firstNum.at(i) << " " << theOperator.at(i) << " " << secondNum.at(i) << " = " << previousVals.at(i) << endl;
                }
            cout << endl;
            cout << "Goodbye" << endl;

        }
    }




    return 0;
}
