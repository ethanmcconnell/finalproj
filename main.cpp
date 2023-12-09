#include <iostream>
#include <vector>
using namespace std;
#include <string>

double NumsResult (double num1, std::string operation, double num2);
bool isfirstaletter(const string & string);

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
        bool yesNo = true;

        while (numberOneBool) 
        {
            cout << "Enter first number:" << endl;
          
                getline(cin, num1); //Used getline instead of cin because we need the whole line a user might input  

                if (isfirstaletter(num1))
                {
                    cout << "invalid number" << endl;
                }
                else 
                {
                    numberOneBool = false;
                    break;
                }
                
             
           
        }
        double numOneDouble = std::stod(num1);
        firstNum.push_back(numOneDouble);

        while (true) {
            cout << "Enter operator: +, -, *, /" << endl;
            getline(cin, oper);
            if (oper != "+" && oper != "-" && oper != "*" && oper != "/") {
                cout << "Invalid Operator. Try again." << endl;
            } else {
                break;
            }
        }
        theOperator.push_back(oper);

        while (numberTwoBool) {
            cout << "Enter second number" << endl;
            getline(cin, num2);
            //cin >> num2;
             if (isfirstaletter(num2))
                {
                    cout << "invalid number" << endl;
                }
                else 
                {
                    numberTwoBool = false;
                    break;
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
            getline(cin, oneMore);
            //cin >> oneMore;

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
double NumsResult (double num1, std::string oper, double num2) {

    double result = 0;

    if (oper == "+") {
        result = num1 + num2;
    }
    else if (oper == "-") {
        result = num1 - num2;
    }
    else if (oper == "*") {
        result = num1 * num2;
    }
    else if (oper == "/") {
        result = num1 / num2;
    }
    return result;
}

bool isfirstaletter(const string & string) {
    for (int i = 0; i < string.length(); i++)
    {
        char c = string[i]; // John 5
        //      john 5
         if (i == 0 && (c == ' ' || c == '\t')) {
            continue; 
        }
         // J != digit
         if (!isdigit(c) && c != '.' && c != '-') {
            return true;
        }
    }
        return false;
    }
    
