#include "input.h"
#include "lab_info.h"
#include "file_work.h"
#include "main_algorithms.h"
#include "comb_sort.h"


void startProgram(void) {
    int user_choice{}; // Переменная для хранения выбора пользователя

    // Бесконечный цикл работы программы
    for (;;) {
        std::vector<std::vector<int>> arrays{};  // Вектор векторов для хранения массивов
        std::string file_path{}; // Строка для хранения пути к файлу
        size_t number_of_arrays{}; // Количество массивов, вводимое пользователем

        // Вывод меню выбора источника ввода данных
        showInputMenu();

        // Получение выбора пользователя
        switch (user_choice = getKey(FILE_INPUT, RANDOM_INPUT)) {
            case FILE_INPUT:
                file_path = checkFile();  // Проверка файла и ввод пути к файлу
                getArraysFromFile(arrays, file_path); // Получение массивов из файла
                break;

            case RANDOM_INPUT:
                std::cout << "Введите количество массивов: ";
                number_of_arrays = getPosInt(); // Ввод количества массивов для генерации
                generateRandomArrays(arrays, number_of_arrays); // Генерация случайных массивов
                break;

            case QUIT:
                break;
        }

        // Вывод неотсортированных массивов
        std::cout
            << std::endl
            << "Изначальные массивы: " << std::endl;

        showArrays(arrays);

        // Запуск сортировки
        startSorting(arrays);

        // Цикл вывода меню выбора дальнейших действий
        while (user_choice != QUIT) {
            // Вывод меню выбора вывода данных
            showOutputMenu();

            // Получение выбора пользователя
            switch (user_choice = getKey(SHOW, SAVE)) {
                case SHOW:
                    std::cout << "Отсортированные массивы: " << std::endl;
                    showArrays(arrays); // Вывод отсортированных массивов
                    break;

                case SAVE:
                    saveToFile(arrays); // Сохранение отсортированных массивов в файл
                    break;

                case QUIT:
                    break;
            }
        }

        // Вывод опции для перезапуска программы или завершения
        std::cout << "1 - Перезапустить программу, ESC - Завершить работу программы." << std::endl;
        user_choice = getKey(RESET, RESET);

        // Завершение программы при выборе выхода
        if (user_choice == QUIT) {
            exit(EXIT_SUCCESS);
        }
    }
}