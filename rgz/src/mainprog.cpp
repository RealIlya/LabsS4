#include <iostream>

extern void prog1(int argc, char *argv[]);  // Реализовано в prog1.o (Stack + обёртка prog1.cpp)
void prog2(int argc, char *argv[]);         // Реализовано в prog2.o (Queue + обёртка prog2.cpp)
void show_help();

int main(int argc, char *argv[]) {
    int choice = 0;

    while (true) {
        std::cout << "\n=== Главное меню ===\n";
        std::cout << "1. Запустить Программу_1 (стек)\n";
        std::cout << "2. Запустить Программу_2 (очередь)\n";
        std::cout << "3. Просмотреть справочную информацию\n";
        std::cout << "4. Завершить программу\n";
        std::cout << "Выберите пункт: ";

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка: введите число.\n";
            std::cin.clear();                                                    // сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // удаление неверного ввода
            continue;                                                            // переходим к следующей итерации
        }

        switch (choice) {
            case 1:
                prog1(argc, argv);
                break;

            case 2:
                prog2(argc, argv);
                break;

            case 3:
                show_help();
                break;

            case 4:
                std::cout << "Завершение работы mainprog.\n";
                return 0;

            default:
                std::cout << "Неверный выбор. Попробуйте ещё раз.\n";
                break;
        }
    }

    return 0;
}

void show_help() {
    std::cout << "\n=== Справочная информация ===\n";
    std::cout << "Программа предназначена для демонстрации работы с меню и обработки пользовательского ввода.\n";
    std::cout << "Возможности программы:\n";
    std::cout << "  1. Запуск Программы_1 (работа со стеком).\n";
    std::cout << "  2. Запуск Программы_2 (работа с очередью).\n";
    std::cout << "  3. Просмотр этой справкой.\n";
    std::cout << "  4. Завершение работы программы.\n\n";
    std::cout << "Запуск с файлом:\n";
    std::cout << "Вы можете запустить программу с указанием имени файла в качестве аргумента командной строки.\n";
    std::cout << "Пример запуска:\n";
    std::cout << "  ./mainprog input.txt\n";
}