#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "queue/Queue.h"

// ANSI коды цветов
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";

void displayQueueHelp() {
    std::ifstream file("queue_help.txt");
    if (!file) {
        std::cerr << RED << "Ошибка: не удалось открыть файл справки." << RESET << "\n";
        return;
    }
    std::string text;
    while (std::getline(file, text)) {
        std::cout << CYAN << text << RESET << "\n";
    }
    file.close();
}

// Функция для работы с очередью, когда переданы аргументы командной строки (файл)
int runQueueFromFile(int argc, char* argv[]) {
    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cerr << RED << "Ошибка: не удалось открыть файл '" << argv[1] << "'." << RESET << "\n";
        return 1;
    }
    int capacity;
    in >> capacity;
    if (in.fail() || capacity <= 0) {
        std::cerr << RED << "Ошибка: неверно указан размер очереди." << RESET << "\n";
        return 1;
    }

    // Создаем очередь с резервом для разграничения состояний
    Queue myQueue(capacity + 1);
    char userCmd;
    while (in >> userCmd) {
        if (userCmd == 'i') {
            char ch;
            in >> ch;
            if (!myQueue.push(ch)) {
                std::cout << RED << "Ошибка: очередь переполнена." << RESET << "\n";
            }
        } else if (userCmd == 'p') {
            char popped;
            if (myQueue.pop(popped)) {
                std::cout << GREEN << "Извлечён: " << popped << RESET << "\n";
            } else {
                std::cout << RED << "Ошибка: очередь пуста." << RESET << "\n";
            }
        } else if (userCmd == 'r') {
            std::cout << GREEN << "Содержимое очереди: " << RESET;
            myQueue.print(std::cout);
            std::cout << "\n";
        } else if (userCmd == 'c') {
            myQueue.clear();
            std::cout << MAGENTA << "Очередь очищена." << RESET << "\n";
        } else if (userCmd == 'h') {
            displayQueueHelp();
        } else if (userCmd == 'q') {
            std::cout << BLUE << "Выход из программы." << RESET << "\n";
            break;
        } else {
            std::cout << YELLOW << "Неопознанная команда: " << userCmd << RESET << "\n";
        }
    }
    in.close();
    return 0;
}

// Функция для работы с очередью в интерактивном режиме (без файла)
int runQueueInteractive() {
    int capacity;
    std::cout << "Введите размер очереди: ";
    std::cin >> capacity;
    if (std::cin.fail() || capacity <= 0) {
        std::cerr << RED << "Ошибка: размер очереди должен быть положительным числом." << RESET << "\n";
        return 1;
    }

    Queue myQueue(capacity + 1);
    char command;

    while (true) {
        std::cout << "\n"
                  << BLUE
                  << "Команды: i(push), p(pop), r(print), c(clear), h(help), q(exit)"
                  << RESET << "\n";
        std::cout << "Введите команду: ";
        std::cin >> command;

        if (command == 'i') {
            char item;
            std::cout << "Введите символ для push: ";
            std::cin >> item;
            if (!myQueue.push(item)) {
                std::cout << RED << "Ошибка: очередь переполнена." << RESET << "\n";
            }
        } else if (command == 'p') {
            char item;
            if (myQueue.pop(item)) {
                std::cout << GREEN << "Извлечён символ: " << item << RESET << "\n";
            } else {
                std::cout << RED << "Ошибка: очередь пуста." << RESET << "\n";
            }
        } else if (command == 'r') {
            std::cout << GREEN << "Содержимое очереди: " << RESET;
            myQueue.print(std::cout);
            std::cout << "\n";
        } else if (command == 'c') {
            myQueue.clear();
            std::cout << MAGENTA << "Очередь очищена." << RESET << "\n";
        } else if (command == 'h') {
            displayQueueHelp();
        } else if (command == 'q') {
            std::cout << BLUE << "Выход из программы." << RESET << "\n";
            break;
        } else {
            std::cout << YELLOW << "Неверная команда." << RESET << "\n";
        }
    }
    return 0;
}

int prog2(int argc, char* argv[]) {
    std::cout << BLUE << "=== Программа работы с очередью ===" << RESET << "\n";

    if (argc > 1) {
        return runQueueFromFile(argc, argv);
    } else {
        return runQueueInteractive();
    }
}
