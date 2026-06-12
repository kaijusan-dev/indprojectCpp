#pragma once
#include <string>

void clearScreen();
void printHeader();
void waitKey();
void menu();
void showHelp();

std::string inputConsole();
std::string inputFile();
std::string inputRandom();
std::string getSequence();

int getInt();