#include <iostream>
#include "BracketChecker.h"
#include "Stack.h"
#include "InputException.h"

bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isClose(char c) {
    return c == ')' || c == ']' || c == '}';
}

bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool BracketChecker::check(const std::string& s) {
    using namespace std;

    Stack st;

    for (int i = 0; i < s.size(); i++) {

        char c = s[i];

        if (!isOpen(c) && !isClose(c)) {
            throw InputException("Недопустимый символ в позиции " + std::to_string(i + 1));
        }

        if (isOpen(c)) {
            st.push(c, i + 1);
        }
        else {

            if (st.isEmpty()) {
                cout << "Ошибка на позиции " << (i + 1) << ". Лишняя закрывающая скобка\n";
                return false;
            }

            char top = st.peek();

            if (!match(top, c)) {
                std::cout << "Ошибка на позиции " << i + 1 << ": ожидалось '" << top << "', получена '" << c << "'\n";
                return false;
            }

            st.pop();
        }
    }

    if (!st.isEmpty()) {
        std::cout << "Ошибка: не закрыта открывающая скобка на позиции " << st.topPosition() << "\n";
        return false;
    }

    return true;
}