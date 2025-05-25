#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "stack/Stack.h"

// ANSI escape коды для цветов
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";

// Функция вывода справки с раскраской
void show_stack_help() {
    std::ifstream help_file("stack_help.txt");
    if (!help_file.is_open()) {
        std::cerr << RED << "Ошибка: не удалось открыть файл справки." << RESET << "\n";
        return;
    }
    std::string line;
    while (std::getline(help_file, line)) {
        std::cout << CYAN << line << RESET << '\n';
    }
    help_file.close();
}

int prog1(int argc, char *argv[]) {
    std::cout << BLUE << "=== Программа работы со стеком ===" << RESET << "\n";
    if (argc > 1) {
        std::ifstream fin(argv[1]);
        if (!fin.is_open()) {
            std::cerr << RED << "Ошибка: не удалось открыть файл '" << argv[1] << "'." << RESET << "\n";
            return 1;
        }

        int size;
        fin >> size;
        if (fin.fail() || size <= 0) {
            std::cerr << RED << "Ошибка: неверный размер стека в файле." << RESET << "\n";
            return 1;
        }

        Stack s(size);
        char cmd;
        while (fin >> cmd) {
            if (cmd == 'i') {
                char value;
                fin >> value;
                if (!s.push(value)) {
                    std::cout << YELLOW << "Ошибка: стек переполнен." << RESET << "\n";
                }
            } else if (cmd == 'p') {
                char out;
                if (s.pop(out)) {
                    std::cout << GREEN << "Извлечён: " << out << RESET << "\n";
                } else {
                    std::cout << YELLOW << "Ошибка: стек пуст." << RESET << "\n";
                }
            } else if (cmd == 'r') {
                std::cout << GREEN << "Содержимое стека: " << RESET;
                s.print(std::cout);
                std::cout << "\n";
            } else if (cmd == 'c') {
                s.clear();
                std::cout << MAGENTA << "Стек очищен." << RESET << "\n";
            } else if (cmd == 'h') {
                show_stack_help();
            } else if (cmd == 'q') {
                std::cout << BLUE << "Выход из программы." << RESET << "\n";
                break;
            } else {
                std::cout << YELLOW << "Неизвестная команда: " << cmd << RESET << "\n";
            }
        }

        fin.close();
    } else {  // Режим ввода с клавиатуры
        int size;
        std::cout << "Введите размер стека: ";
        std::cin >> size;

        if (std::cin.fail() || size <= 0) {
            std::cerr << RED << "Ошибка: размер стека должен быть положительным числом." << RESET << "\n";
            return 1;
        }

        Stack s(size);
        char cmd;
        while (true) {
            std::cout << "\n"
                      << BLUE
                      << "Команды: i(push), p(pop), r(print), c(clear), h(help), q(exit)"
                      << RESET << "\n";
            std::cout << "Введите команду: ";
            std::cin >> cmd;

            if (cmd == 'i') {
                char value;
                std::cout << "Введите символ для push: ";
                std::cin >> value;
                if (!s.push(value)) {
                    std::cout << YELLOW << "Ошибка: стек переполнен." << RESET << "\n";
                }
            } else if (cmd == 'p') {
                char out;
                if (s.pop(out)) {
                    std::cout << GREEN << "Извлечён символ: " << out << RESET << "\n";
                } else {
                    std::cout << YELLOW << "Ошибка: стек пуст." << RESET << "\n";
                }
            } else if (cmd == 'r') {
                std::cout << GREEN << "Содержимое стека: " << RESET;
                s.print(std::cout);
                std::cout << "\n";
            } else if (cmd == 'c') {
                s.clear();
                std::cout << MAGENTA << "Стек очищен." << RESET << "\n";
            } else if (cmd == 'h') {
                show_stack_help();
            } else if (cmd == 'q') {
                std::cout << BLUE << "Выход из программы." << RESET << "\n";
                break;
            } else {
                std::cout << YELLOW << "Неверная команда." << RESET << "\n";
            }
        }
    }

    return 0;
}