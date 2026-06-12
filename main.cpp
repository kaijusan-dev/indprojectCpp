#include <iostream>
#include <ctime>
#include <windows.h>
#include "io.h"
#include "BracketChecker.h"
#include "StackException.h"
#include "InputException.h"
#include "Test.h"

int main() {
    using namespace std;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    BracketChecker checker;
    int choice;

    while (true) {

        try {
            clearScreen();
            printHeader();
            menu();

            choice = getInt();

        }
        catch (InputException& e) {
            cout << "\nОшибка ввода: " << e.getMessage() << "\n";
            waitKey();
            continue;
        }

        switch (choice) {

            case 1: {
                try {
                    string s = getSequence();

                    if (s.empty()) break;

                    if (checker.check(s)) {
                        cout << "\nПоследовательность корректна\n";
                    }
                }
                catch (StackException& e) {
                    cout << "\nОшибка стека: " << e.getMessage() << "\n";
                }
                catch (InputException& e) {
                    cout << "\nОшибка ввода: " << e.getMessage() << "\n";
                }

                waitKey();
                break;
            }

            case 2: {
                runTests();
                waitKey();
                break;
            }
             

            case 3: {
                showHelp();
                clearScreen();
                break;
            }
                

            case 0: {
                cout << "\n Выход...\n";
                return 0;
            }
               
            default:
                cout << "\nОшибка: Неверный пункт\n";
                waitKey();
        }
    }
}