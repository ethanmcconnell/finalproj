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
        int decimalCount1 = 0;
        int decimalCount2 = 0;
        bool numberOneBool = true;
        bool numberTwoBool = true;
        bool yesNo = true;

        while (numberOneBool) {
            cout << "Enter first number:" << endl;
            getline(cin, num1);
            numberOneBool = false;

                for (int i = 0; i < num1.size(); ++i) {
                    if (num1[i] == '.') {
                        decimalCount1++;
                    }
                    if (!isdigit(num1[i]) && num1[i] != '.' && num1[i] != '-' || num1[i] == ' ') {
                        numberOneBool = true;
                        cout << "Please enter a valid number." << endl;
                        break;
                    }
                    else if (decimalCount1 > 1) {
                        numberOneBool = true;
                        cout << "Please enter a valid number." << endl;
                        decimalCount1 = 0;
                        break;
                    }
                    if (num1[i] == '-' && i != 0) {
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
            getline (cin, oper);
            if (oper != "+" && oper != "-" && oper != "*" && oper != "/") {
                cout << "Invalid Operator. Try again." << endl;
            } else {
                break;
            }
        }
        theOperator.push_back(oper);

        while (numberTwoBool) {
            cout << "Enter second number" << endl;
            getline (cin, num2);
            numberTwoBool = false;

            for (int i = 0; i < num2.size(); ++i) {
                if (num2[i] == '.') {
                    decimalCount2++;
                }
                if (!isdigit(num2[i]) && num2[i] != '.' && num2[i] != '-' || num2[i] == ' ') {
                    numberTwoBool = true;
                    cout << "Please enter a valid number." << endl;
                    break;
                }
                else if (decimalCount2 > 1) {
                    numberTwoBool = true;
                    cout << "Please enter a valid number." << endl;
                    decimalCount2 = 0;
                    break;
                }
                if(num2[i] ==  '-' &&  i != 0) {
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

        while (yesNo) {
            cout << "Would you like to enter another operation: yes/no" << endl;
            getline (cin, oneMore);

            if (oneMore == "yes" || oneMore == "no") {
                yesNo = false;
            }
            else {
                cout << "Please enter yes or no" << endl;
            }
        }

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
