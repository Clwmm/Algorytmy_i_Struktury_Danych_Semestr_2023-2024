// Mateusz Kałwa
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include "LinkedStack.h"

// Checking if a string is a number
bool isNumber(const std::string& str)
{
    if (str.empty())
        return false;

    if (str.size() == 1 && (str == "-" || str == "."))
        return false;

    for (char x : str)
        if (!std::isdigit(x) && x != '-' && x != '.')
            return false;

    return true;
}

// checking if string is an operator
bool isOperator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/";
}

// Checking if the first operator has higher priority
bool hasHigherPriority(const std::string& op1, const std::string& op2) {
    if ((op1 == "*" || op1 == "/") && (op2 == "+" || op2 == "-"))
        return true;

    return false;
}

// Conversion from arithmetic expression to ONP
std::string arith_to_onp(std::string& arith_expr) {
    std::istringstream iss(arith_expr);

    // Create additional variables to pick up and store words given in airth_expr
    std::string word;
    std::vector<std::string> words;

    while (iss >> word)
        words.push_back(word);

    LinkedStack<std::string, 1000000> stack;
    std::stringstream rpn;

    // Main loop
    for (std::string x : words) {

        if (isNumber(x))
            rpn << x << " ";

        else if (x == "(")
            stack.push(x);

        else if (x == ")")
        {
            while (!stack.empty() && stack.top() != "(")
                rpn << stack.pop() << " ";
            stack.pop();
        }
        else if (isOperator(x))
        {
            while (!stack.empty() && hasHigherPriority(stack.top(), x))
                rpn << stack.pop() << " ";

            stack.push(x);
        }
    }

    while (!stack.empty())
        rpn << stack.pop() << " ";

    std::string ret = rpn.str();

    if (!ret.empty())
        ret.pop_back();

    return ret;
}

auto main() -> int
{
    std::ios::sync_with_stdio(false);
    std::string arith_expr;
    std::getline(std::cin, arith_expr);

    std::string onp_expr = arith_to_onp(arith_expr);
    std::cout << onp_expr << std::endl;
}