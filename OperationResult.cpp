#include <string>
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
