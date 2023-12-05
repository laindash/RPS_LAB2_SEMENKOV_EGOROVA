#include "input.h"
#include "wchar.h"


/// <summary>
/// ������� ��� ��������� �������������� ����� �� ������������.
/// </summary>
int getInt() {
    int input{};

    // ���� �������� � ����������
    std::cin >> input;

    // �������� ������� ������ �����
    do {
        // ���� ���� �� �������� ����� ������
        if (std::cin.fail()) {
            // ����� ��������� �� ������
            std::cout << "�������� ����, ��������� �������!" << std::endl;

            // ����� ����� ������ �����
            std::cin.clear();

            // ������� ������ ����� �� ������� ����� ������
            // ������ �������� - ���������� ������������ ��������, ������ - ����������� ����� ������������� ���������
            std::cin.ignore(INT_MAX, '\n');

            // ��������� ���� ��������
            std::cin >> input;
        }
    } 
    while (std::cin.fail()); // ���������, ���� ���� �������� ������

    // ������� ������ ����� ����� ��������� ����� ��������
    std::cin.ignore(INT_MAX, '\n');

    // ����������� ����������� �������������� ��������
    return input;
}


/// <summary>
/// ������� ��� ��������� �������������� �������������� ����� �� ������������.
/// </summary>
int getPosInt() {
    int num = 0;

    // ���������, ���� �� ����� ������� ������������� ����� �����, �� ����������� INT_MAX
    do {
        // ��������� ������ ����� �� ������������
        num = getInt();

        // ���� ������� ������������� �����, ����� ��� �� ������
        if (num < 0) {
            std::cout << "����� �������� �� ������!" << std::endl;
            num = abs(num);
        }

        // �������� �� ���������� ������������� �������� ���� int
        if (num > INT_MAX) {
            std::cout << "�������� �������� ������ ���� �� ������ ��� " << std::fixed << INT_MAX << std::endl;
            continue; // ���������� ����, ����� ������������ ���� ���������� ��������
        }

        // ���� ������� �������� ������ 0, ������� ��������� �� ������
        else if (num == 0) {
            std::cout << "�������� �������� �� ������ ���� ����� 0. ��������� �������!" << std::endl;
        }
    } 
    while (num <= 0 || num > INT_MAX); // ���������, ���� ���� �� �������� ������������� ������, �� ����������� INT_MAX

    return num;
}


/// <summary>
/// ������� ��� ��������� ���������� ����� � �������� ���������.
/// </summary>
int getKey(int key_min, int key_max) {
    int key = 0;

    // ���������, ���� �� ����� ������� ������� � �������� ���������
    do {
        // ��������� ���������� ����� ��� �������� ������� Enter (��� ������� �������)
        key = _getch();

        // ���� ������ ������� ESC, ���������� �� �������� ��� �������� ���������� �����
        if (key == KEY_ESC) {
            return key;
        }
    } 
    while ((key < key_min) || (key > key_max)); // ���������, ���� ��������� ������� �� ��������� � �������� ���������

    return key;
}


/// <summary>
/// ������� ��� ��������� ���������� ������ ����� � �������� ���������.
/// </summary>
int getRandInt(int low_bound, int up_bound) {
    // ��������� ���������� ����� � �������� ���������
    return (rand() % (up_bound - low_bound) + low_bound);
}


/// <summary>
/// ������� ��� ����������� ����� �����.
/// </summary>
std::string getLine(std::istream &input, std::string &line, int input_type) {
    bool valid_input = true;

    // ���� �����������, ���� �� ����� ������� ���������� ������
    do {
        std::getline(input, line);

        // �������� �� ������� ������ �����
        do {
            if (std::cin.fail()) {
                // ����� ����� ������ �����
                input.clear();

                // ������� ������ ����� �� ������� ����� ������
                // ������ �������� - ���������� ������������ ��������, ������ - ����������� ����� ������������� ���������
                input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "������������ ����, ��������� �������!" << std::endl;
                std::getline(input, line);

                // ��������� ���� ��������
                if (input_type == FILE_INPUT) {
                    valid_input = false;
                }
            }
        } 
        while (std::cin.fail() && input_type != FILE_INPUT); // ���������, ���� ���� �������� ������
       
        // ���� ���� ���������� �� ����� � ���� ������, ��������, ��� ���� �����������
        if (input_type == FILE_INPUT && !valid_input) {
            break;
        }
   
        if (line.empty() && input_type != FILE_INPUT) {
            std::cout << "�������� �������� �� ������ ���� ������!" << std::endl;
            valid_input = false;
            continue;
        }

        int space_position(0);
        int character_position(0);

        // �������� �� ���������� ���������� �������� � ������ ������ � �������
        for (const unsigned char c : line) {
            // �������� �������� �� ������ ����������, ������������ "�������" �������, �.�. ���������� ���������
            if (!iswprint(c)) {
                valid_input = false;
                std::cout << "�������� �������� �� ������ ��������� ���������� �������!" << std::endl;
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
                std::cout << "�������� �������� �� ������ ���������� � �������!" << std::endl;
                break;
            }

            else {
                valid_input = true;
            }
        }
    } 
    while (!valid_input && input_type == MANUAL_INPUT);

    // ���� ���� �� ����� � ���� ������, ���������� ������ ������
    if (!valid_input && input_type == FILE_INPUT) {
        line = "";
    }

    // ����������� ���������� ������
    return line;
}
