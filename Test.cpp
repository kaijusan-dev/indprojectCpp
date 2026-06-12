#include "BracketChecker.h"
#include "InputException.h"
#include "StackException.h"
#include <iostream>
#include "Test.h"

void separator() {
    using namespace std;
    cout << "\n-------------------------------------------------------------\n";
}

void runTest(
    BracketChecker& checker,
    const std::string& sequence,
    bool expected) {

    using namespace std;

    cout << "\nПоследовательность: " << sequence << endl;
    cout << "Ожидаемый результат: "
         << (expected ? "Корректна" : "Ошибка") << endl;

    bool result = false;

    try {
        result = checker.check(sequence);
    }
    catch (StackException& e) {
        cout << "\nОшибка стека: " << e.getMessage() << "\n";
    }
    catch (InputException& e) {
        cout << "\nОшибка ввода: " << e.getMessage() << "\n";
    }
    catch (...) {
        cout << "\nНеизвестная ошибка\n";
    }

    cout << "\nФактический результат: "
         << (result ? "Корректна" : "Ошибка") << endl;
}

void runTests() {
    using namespace std;

    BracketChecker checker;

    cout << "\n#############################################################\n";
    cout << "#                АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ                #\n";
    cout << "#############################################################\n";

    cout << "\nКОРРЕКТНЫЕ ПОСЛЕДОВАТЕЛЬНОСТИ\n";

    runTest(checker, "()", true); separator();
    runTest(checker, "({[]})", true); separator();
    runTest(checker, "{{[()]}}", true); separator();
    runTest(checker, "()[]{}()[]{}", true); separator();
    runTest(checker, "{[()()()][{}{}]}", true); separator();
    runTest(checker, "(((([[]]))))", true);

    cout << "\n=============================================================\n";
    cout << "\nОШИБКИ СКОБОК\n";

    runTest(checker, "([)]", false); separator();
    runTest(checker, "{[(]}", false); separator();
    runTest(checker, ")))", false); separator();
    runTest(checker, "{[()]}]", false); separator();
    runTest(checker, "(((()]))", false); separator();
    runTest(checker, "{[{[(())]}])}", false);

    cout << "\n=============================================================\n";
    cout << "\nНЕЗАКРЫТЫЕ СКОБКИ\n";

    runTest(checker, "(((", false); separator();
    runTest(checker, "({[", false); separator();
    runTest(checker, "{{{{{{", false); separator();
    runTest(checker, "{[({[({[(", false); separator();
    runTest(checker, "(()(()(()", false);

    cout << "\n=============================================================\n";
    cout << "\nНЕКОРРЕКТНЫЕ СИМВОЛЫ\n";

    runTest(checker, "abc", false); separator();
    runTest(checker, "(a)", false); separator();
    runTest(checker, "[]1{}", false); separator();
    runTest(checker, "{hello}", false);

    cout << "\n#############################################################\n";
    cout << "#                  ТЕСТИРОВАНИЕ ЗАВЕРШЕНО                   #\n";
    cout << "#############################################################\n";
}