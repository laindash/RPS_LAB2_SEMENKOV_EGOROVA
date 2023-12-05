#ifndef INPUT_H
#define INPUT_H

#include <conio.h> // —одержит функцию getch
#include <string>
#include <iostream>


constexpr auto KEY_ESC = 0x1B; // ¬ычисл€емый на этапе компил€ции тип данных, €вл€ющийс€ константой, дл€ клавиши ESC
constexpr auto KEY_1 = 0x31; // ¬ычисл€емый на этапе компил€ции тип данных, €вл€ющийс€ константой, дл€ клавиши 1
constexpr auto KEY_2 = 0x32; // ¬ычисл€емый на этапе компил€ции тип данных, €вл€ющийс€ константой, дл€ клавиши 2

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


int getInt();

int getPosInt();

int getRandInt(int low_bound, int up_bound);

int getKey(int key_min, int key_max);

std::string getLine(std::istream& input, std::string& line, int input_type);

#endif