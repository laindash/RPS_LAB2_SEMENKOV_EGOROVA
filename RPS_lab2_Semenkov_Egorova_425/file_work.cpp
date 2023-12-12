#include <filesystem>
#include <fstream>
#include "input.h"
#include "main_algorithms.h"


bool isDataCorrect(std::ifstream &file) {
    int test_int{};

    // Проверка, если файл пуст
    if (file.eof()) {
        std::cout << "Файл пуст!";
    }

    // Чтение данных из файла
    while (!file.eof()) {
        // Считывание целочисленного значения из файла
        file >> test_int;

        // Проверка на превышение максимального значения типа int
        if (test_int > INT_MAX) {
            std::cout << "Ошибка считывания значения, превышено максимальное значение!" << std::endl;
            return false;
        }

        // Проверка на ошибку считывания значения
        if (file.fail()) {
            std::cout << "Ошибка считывания значения ячейки!" << std::endl;
            return false;
        }
    }

    // Установка указателя чтения в начало файла
    file.seekg(0, std::ios::beg);

    // Возвращение true, если данные корректны
    return true;
}


std::string checkFile() {
    // Объект, который используется для представления ошибок в виде кода
    std::error_code error{};

    std::string path{};
    bool is_loaded = false;

    // Входной файловый поток
    std::ifstream file;

    // Повторять, пока не будет успешно открыт файл с корректными данными
    do {
        // Запрос пути к файлу от пользователя
        std::cout << "Введите путь к файлу: ";
        getLine(std::cin, path, MANUAL_INPUT);

        // Проверка наличия файла по указанному пути
        if (!std::ifstream(path)) {
            std::cout << "Указанный файл не найден!" << std::endl;
            continue;
        }

        // Проверка, является ли указанный файл зарезервированным
        if (!std::filesystem::is_regular_file(path, error)) {
            std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
            continue;
        }

        // Попытка открыть файл
        file.open(path);

        // Проверка успешного открытия файла
        if (!file) {
            std::cout << "Ошибка открытия файла!" << std::endl;
            file.close();
        }

        // Проверка корректности данных в файле
        else if (!isDataCorrect(file)) {
            std::cout << "Данные некорректны!" << std::endl;
            file.close();
        }

        // Если файл успешно открыт с корректными данными, завершаем цикл
        else
            is_loaded = true;
    } 
    while (!is_loaded);

    // Вывод сообщения об успешном открытии файла
    std::cout << "Файл открыт!" << std::endl;

    // Закрытие файла перед возвратом пути
    file.close();

    // Возвращение пути к открытому файлу
    return path;
}


void getArraysFromFile(std::vector<std::vector<int>>& arrays, std::string& path) {
    // Открытие файла
    std::ifstream file(path);
    size_t number_of_arrays{}, amount_of_elements{};

    // Чтение общего количества массивов
    file >> number_of_arrays;

    // Проверка на отрицательное количество массивов
    if (number_of_arrays < 0) {
        std::cout << "В одном из массивов размер был указан отрицательным, взято значение по модулю!";
        number_of_arrays = abs(static_cast<int>(number_of_arrays));
    }

    // Проверка на количество массивов равное 0
    if (number_of_arrays == 0) {
        std::cout << "В одном из массивов размер был указан равный 0, исправьте файл!";
        file.close();
        return;
    }

    // Резервирование места для массивов вектора
    arrays.resize(number_of_arrays);

    // Чтение каждого массива
    for (size_t i = 0; i < number_of_arrays; i++) {
        // Чтение количества элементов в текущем массиве
        file >> amount_of_elements;

        // Проверка на отрицательное количество элементов
        if (amount_of_elements < 0) {
            std::cout << "В одном из массивов количество элементов было указано отрицательным, взято значение по модулю!";
            amount_of_elements = abs(static_cast<int>(amount_of_elements));
        }

        // Проверка на количество элементов равное 0
        if (amount_of_elements == 0) {
            std::cout << "В одном из массивов количество элементов было указано равным 0, исправьте файл!";
            file.close();
            return;
        }

        // Резервирование места для элементов текущего массива
        arrays[i].resize(amount_of_elements);

        // Чтение элементов текущего массива
        for (size_t j = 0; j < amount_of_elements; j++) {
            file >> arrays[i][j];
        }
    }

    std::cout << "Массивы загружены!" << std::endl;

    // Закрытие файла
    file.close();
}


void saveToFile(std::vector<std::vector<int>> &arrays) {
    std::ofstream file;
    std::string path{};
    bool is_opened = false;

    std::error_code error{};

    // Повторять, пока не будет успешно открыт файл для записи
    do {
        std::cout
            << "Введите путь к файлу для сохранения. "
            << "Если указать только имя и расширение файла, стандартным путём будет являться путь к исходному коду программы." << std::endl;
        getLine(std::cin, path, MANUAL_INPUT);

        // Проверка существования файла
        if (std::ifstream(path)) {

            // Проверка, является ли указанный файл зарезервированным
            if (!std::filesystem::is_regular_file(path, error)) {
                std::cout << "Ошибка, недопустимый адрес файла!" << std::endl;
                continue;
            }

            std::cout
                << "Данный файл уже существует!." << std::endl
                << "1 - Перезаписать." << std::endl
                << "2 - Выбрать другой." << std::endl;

            // Пользовательский ввод для выбора действия
            if (getKey(RESET, ANOTHER) == ANOTHER) {
                continue;
            }
        }

        // Открытие файла для записи (если не существует, создается)
        file.open(path, std::ios::trunc);

        // Проверка успешного открытия файла
        if (!file) {
            std::cout << "Ошибка открытия файла!" << std::endl;
        }
        else {
            is_opened = true;
        }
    } 
    while (!is_opened);
    // Вычисляем количество массивов
    size_t number_of_arrays = arrays.size(), amount_of_elements{};

    // Запись каждого массива в файл
    for (size_t i = 0; i < number_of_arrays; i++) {
        // Вычисляем количество элементов в массиве
        amount_of_elements = arrays[i].size();

        file
            << std::endl
            << "Массив # " << i + 1 << std::endl
            << "Количество элементов: " << amount_of_elements << std::endl
            << "***********************************************************************" << std::endl;

        for (int j = 0; j < amount_of_elements; j++) {
            file << arrays[i][j] << ' ';
        }

        file << std::endl;
    }

    file << "***********************************************************************" << std::endl;
    std::cout 
        << std::endl
        << "Успешно сохранено в " << path << std::endl;

    // Закрытие файла
    file.close();
}
