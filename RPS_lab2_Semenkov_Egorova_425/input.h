#ifndef INPUT_H
#define INPUT_H

#include <conio.h> // Содержит функцию getch
#include <string>
#include <iostream>


constexpr auto KEY_ESC = 0x1B; // Вычисляемый на этапе компиляции тип данных, являющийся константой, для клавиши ESC
constexpr auto KEY_1 = 0x31; // Вычисляемый на этапе компиляции тип данных, являющийся константой, для клавиши 1
constexpr auto KEY_2 = 0x32; // Вычисляемый на этапе компиляции тип данных, являющийся константой, для клавиши 2

enum InputMenu {
    FILE_INPUT = KEY_1,
    RANDOM_INPUT = KEY_2,
    MANUAL_INPUT
};

enum OutputMenu {
    SHOW = KEY_1,
    SAVE = KEY_2
};

enum ConstValues {
    LOW_BOUND_FOR_RANDOM = -1000,
    UP_BOUND_FOR_RANDOM = 1000,
    LOW_BOUND_FOR_QUANTITY = 3,
    UP_BOUND_FOR_QUANTITY = 100
};

enum BoolMenu {
    RESET = KEY_1,
    ANOTHER = KEY_2,
    QUIT = KEY_ESC
};

enum BoolInput {
    ALL_TYPES,
    ONLY_DIGITS,
};

/// <summary>
/// Функция для получения целочисленного ввода от пользователя.
/// </summary>
int getInt();

/// <summary>
/// Функция для получения положительного целочисленного ввода от пользователя.
/// </summary>
int getPosInt();

/// <summary>
/// Функция для получения клавишного ввода в заданном диапазоне.
/// </summary>
int getKey(int key_min, int key_max);

/// <summary>
/// Функция для получения случайного целого числа в заданном диапазоне.
/// </summary>
int getRandInt(int low_bound, int up_bound);

/// <summary>
/// Функция для корректного ввода строк.
/// </summary>
std::string getLine(std::istream& input, std::string& line, int input_type);


#endif