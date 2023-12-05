#include "input.h"
#include "wchar.h"


/// <summary>
/// Функция для получения целочисленного ввода от пользователя.
/// </summary>
int getInt() {
    int input{};

    // Ввод значения с клавиатуры
    std::cin >> input;

    // Проверка наличия ошибок ввода
    do {
        // Если ввод не является целым числом
        if (std::cin.fail()) {
            // Вывод сообщения об ошибке
            std::cout << "Неверный ввод, повторите попытку!" << std::endl;

            // Сброс флага ошибки ввода
            std::cin.clear();

            // Очистка буфера ввода до символа новой строки
            // Первый аргумент - количество игнорируемых символов, второй - разделитель между игнорируемыми символами
            std::cin.ignore(INT_MAX, '\n');

            // Повторный ввод значения
            std::cin >> input;
        }
    } 
    while (std::cin.fail()); // Повторять, пока ввод содержит ошибку

    // Очистка буфера ввода после успешного ввода значения
    std::cin.ignore(INT_MAX, '\n');

    // Возвращение полученного целочисленного значения
    return input;
}


/// <summary>
/// Функция для получения положительного целочисленного ввода от пользователя.
/// </summary>
int getPosInt() {
    int num = 0;

    // Повторять, пока не будет введено положительное целое число, не превышающее INT_MAX
    do {
        // Получение целого числа от пользователя
        num = getInt();

        // Если введено отрицательное число, взять его по модулю
        if (num < 0) {
            std::cout << "Взято значение по модулю!" << std::endl;
            num = abs(num);
        }

        // Проверка на превышение максимального значения типа int
        if (num > INT_MAX) {
            std::cout << "Вводимое значение должно быть не больше чем " << std::fixed << INT_MAX << std::endl;
            continue; // Продолжить цикл, чтобы пользователь ввел корректное значение
        }

        // Если введено значение равное 0, вывести сообщение об ошибке
        else if (num == 0) {
            std::cout << "Вводимое значение не должно быть равно 0. Повторите попытку!" << std::endl;
        }
    } 
    while (num <= 0 || num > INT_MAX); // Повторять, пока ввод не является положительным числом, не превышающим INT_MAX

    return num;
}


/// <summary>
/// Функция для получения клавишного ввода в заданном диапазоне.
/// </summary>
int getKey(int key_min, int key_max) {
    int key = 0;

    // Повторять, пока не будет введена клавиша в заданном диапазоне
    do {
        // Получение клавишного ввода без ожидания нажатия Enter (или другого символа)
        key = _getch();

        // Если нажата клавиша ESC, возвращаем ее значение без ожидания остального ввода
        if (key == KEY_ESC) {
            return key;
        }
    } 
    while ((key < key_min) || (key > key_max)); // Повторять, пока введенная клавиша не находится в заданном диапазоне

    return key;
}


/// <summary>
/// Функция для получения случайного целого числа в заданном диапазоне.
/// </summary>
int getRandInt(int low_bound, int up_bound) {
    // Генерация случайного числа в заданном диапазоне
    return (rand() % (up_bound - low_bound) + low_bound);
}


/// <summary>
/// Функция для корректного ввода строк.
/// </summary>
std::string getLine(std::istream &input, std::string &line, int input_type) {
    bool valid_input = true;

    // Цикл повторяется, пока не будет введена корректная строка
    do {
        std::getline(input, line);

        // Проверка на наличие ошибок ввода
        do {
            if (std::cin.fail()) {
                // Сброс флага ошибки ввода
                input.clear();

                // Очистка буфера ввода до символа новой строки
                // Первый аргумент - количество игнорируемых символов, второй - разделитель между игнорируемыми символами
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Некорректный ввод, повторите попытку!" << std::endl;
                std::getline(input, line);

                // Повторный ввод значения
                if (input_type == FILE_INPUT) {
                    valid_input = false;
                }
            }
        } 
        while (std::cin.fail() && input_type != FILE_INPUT); // Повторять, пока ввод содержит ошибку
       
        // Если ввод происходит из файла и была ошибка, помечаем, что ввод некорректен
        if (input_type == FILE_INPUT && !valid_input) {
            break;
        }
   
        if (line.empty() && input_type != FILE_INPUT) {
            std::cout << "Вводимое значение не должно быть пустым!" << std::endl;
            valid_input = false;
            continue;
        }

        int space_position(0);
        int character_position(0);

        // Проверка на отсутствие непечатных символов и начало строки с пробела
        for (const unsigned char c : line) {
            // Проверка является ли символ непечатным, используются "широкие" символы, т.к. необходима кириллица
            if (!iswprint(c)) {
                valid_input = false;
                std::cout << "Вводимое значение не должно содержать непечатные символы!" << std::endl;
                break;
            }

            if (c == ' ') {
                space_position++;
            }

            if (c != ' ') {
                character_position++;
            }

            if (space_position > character_position) {
                valid_input = false;
                std::cout << "Вводимое значение не должно начинаться с пробела!" << std::endl;
                break;
            }

            else {
                valid_input = true;
            }
        }
    } 
    while (!valid_input && input_type == MANUAL_INPUT);

    // Если ввод из файла и была ошибка, возвращаем пустую строку
    if (!valid_input && input_type == FILE_INPUT) {
        line = "";
    }

    // Возвращение полученной строки
    return line;
}
