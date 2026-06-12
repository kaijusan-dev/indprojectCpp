#include "io.h"
#include "InputException.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <string>

void clearScreen() {
    system("cls");
}

void printHeader() {
    using namespace std;

    cout << "\n\n\n";
    cout << "#############################################################\n";
    cout << "#                                                           #\n";
    cout << "#      ПРОГРАММА ПРОВЕРКИ СКОБОЧНЫХ ПОСЛЕДОВАТЕЛЬНОСТЕЙ     #\n";
    cout << "#                                                           #\n";
    cout << "#############################################################\n\n";
}

void waitKey() {
    using namespace std;
    cout << "\nНажмите Enter для продолжения...";
    string tmp;
    getline(cin, tmp);
}

void menu() {
    using namespace std;

    cout << " 1. Проверить последовательность\n";
    cout << " 2. Запустить тесты\n";
    cout << " 3. Подсказка\n";
    cout << " 0. Выход\n\n";
    cout << " Выбор: ";
}

void showHelp() {
    using namespace std;

    cout << "\n=============================================================\n";
    cout << "                         ПОДСКАЗКА\n";
    cout << "=============================================================\n\n";

    cout << "Скобочная последовательность — это строка, состоящая только из скобок\n";
    cout << "(например: (), [], {}).\n\n";

    cout << "Главная задача — определить, является ли последовательность правильной.\n\n";

    cout << "Правильная последовательность (ПСП) должна удовлетворять условиям:\n\n";

    cout << "1. Каждая открывающая скобка имеет соответствующую закрывающую\n";
    cout << "2. Скобки закрываются в правильном порядке (строгая вложенность)\n";
    cout << "   Например, ([)] — НЕВЕРНО\n\n";

    cout << "3. Баланс:\n";
    cout << "   При чтении строки слева направо\n";
    cout << "   закрывающих скобок не должно быть больше, чем открывающих\n\n";

    cout << "Пример корректных строк:\n";
    cout << "  ()  ({[]})  {{[()]}}\n\n";

    cout << "Пример ошибок:\n";
    cout << "  ([)]  )))  (((" << "\n";

    cout << "\n=============================================================\n";

    cout << "\nНажмите Enter для возврата...";
    string tmp;
    getline(cin, tmp);
}

int getInt() {
    using namespace std;

    string s;
    getline(cin, s);

    if (s.empty()) throw InputException("Пустая строка");

    for (int i = 0; i < (int)s.size(); i++) {
        if (!isdigit(s[i])) throw InputException("Введите число!");
    }

    return stoi(s);
}

std::string inputConsole() {
    using namespace std;

    while (true) {

        cout << "\n=============================================================\n";
        cout << "                      ВВОД С КЛАВИАТУРЫ\n";
        cout << "=============================================================\n";
        cout << "Введите последовательность:\n> ";

        string s;
        getline(cin, s);

        if (s.empty()) {
            cout << "\nОшибка: строка не может быть пустой\n";
            waitKey();
            clearScreen();
            continue;
        }

        return s;
    }
}

std::string inputFile() {
    using namespace std;

    while (true) {

        cout << "\n=============================================================\n";
        cout << "                       ЧТЕНИЕ ИЗ ФАЙЛА\n";
        cout << "=============================================================\n";
        cout << "Введите имя файла:\n> ";

        string name;
        getline(cin, name);

        ifstream f(name);

        if (!f) {
            cout << "\nОшибка: файл не найден\n";
            waitKey();
            clearScreen();
            continue;
        }

        string s;
        getline(f, s);

        if (s.empty()) {
            cout << "Ошибка: файл пуст\n";
            waitKey();
            clearScreen();
            continue;
        }

        cout << "\nФайл успешно прочитан.\n";
        cout << "Последовательность: " << s << "\n";

        return s;
    }
}

std::string inputRandom() {
    using namespace std;

    const string brackets = "()[]{}";

    while (true) {
        cout << "\n=============================================================\n";
        cout << "                    СЛУЧАЙНАЯ ГЕНЕРАЦИЯ\n";
        cout << "=============================================================\n";
        cout << "Введите длину последовательности:\n> ";

        int length;
        try {
            length = getInt();
        } catch (const InputException& e) {
            cout << "\nОшибка ввода: " << e.getMessage() << "\n";
            waitKey();
            clearScreen();
            continue;
        }

        if (length <= 0) {
            cout << "\nОшибка: длина должна быть > 0\n";
            waitKey();
            clearScreen();
            continue;
        }

        string s;
        for (int i = 0; i < length; i++) {
            s += brackets[rand() % brackets.size()];
        }

        cout << "\nСгенерированная последовательность: " << s << "\n";
        return s;
    }
}

std::string getSequence() {
    using namespace std;

    int choice;

    do {
        cout << "\n=============================================================\n";
        cout << "                       СПОСОБ ВВОДА\n";
        cout << "=============================================================\n";
        cout << "1. Ввод с клавиатуры\n";
        cout << "2. Загрузка из файла\n";
        cout << "3. Случайная генерация\n";
        cout << "0. Назад\n\n";
        cout << "Выбор: ";

        try {
            choice = getInt();
        } catch (const InputException& e) {
            cout << "\nОшибка ввода: " << e.getMessage() << "\n";
            waitKey();
            clearScreen();
            continue;
        }

        switch (choice) {
            case 0:
                return "";
            case 1:
                return inputConsole();
            case 2:
                return inputFile();
            case 3:
                return inputRandom();
            default:
                cout << "\nОшибка: неверный пункт меню\n";
                waitKey();
                clearScreen();
        }
    } while (choice != 0);

    return "";
}