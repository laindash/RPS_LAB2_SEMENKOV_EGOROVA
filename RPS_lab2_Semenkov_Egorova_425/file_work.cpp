#include <filesystem>
#include <fstream>
#include "input.h"
#include "main_algorithms.h"


bool isDataCorrect(std::ifstream &file) {
    int test_int{};

    // ��������, ���� ���� ����
    if (file.eof()) {
        std::cout << "���� ����!";
    }

    // ������ ������ �� �����
    while (!file.eof()) {
        // ���������� �������������� �������� �� �����
        file >> test_int;

        // �������� �� ���������� ������������� �������� ���� int
        if (test_int > INT_MAX) {
            std::cout << "������ ���������� ��������, ��������� ������������ ��������!" << std::endl;
            return false;
        }

        // �������� �� ������ ���������� ��������
        if (file.fail()) {
            std::cout << "������ ���������� �������� ������!" << std::endl;
            return false;
        }
    }

    // ��������� ��������� ������ � ������ �����
    file.seekg(0, std::ios::beg);

    // ����������� true, ���� ������ ���������
    return true;
}


std::string checkFile() {
    // ������, ������� ������������ ��� ������������� ������ � ���� ����
    std::error_code error{};

    std::string path{};
    bool is_loaded = false;

    // ������� �������� �����
    std::ifstream file;

    // ���������, ���� �� ����� ������� ������ ���� � ����������� �������
    do {
        // ������ ���� � ����� �� ������������
        std::cout << "������� ���� � �����: ";
        getLine(std::cin, path, MANUAL_INPUT);

        // �������� ������� ����� �� ���������� ����
        if (!std::ifstream(path)) {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        // ��������, �������� �� ��������� ���� �����������������
        if (!std::filesystem::is_regular_file(path, error)) {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        // ������� ������� ����
        file.open(path);

        // �������� ��������� �������� �����
        if (!file) {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }

        // �������� ������������ ������ � �����
        else if (!isDataCorrect(file)) {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }

        // ���� ���� ������� ������ � ����������� �������, ��������� ����
        else
            is_loaded = true;
    } 
    while (!is_loaded);

    // ����� ��������� �� �������� �������� �����
    std::cout << "���� ������!" << std::endl;

    // �������� ����� ����� ��������� ����
    file.close();

    // ����������� ���� � ��������� �����
    return path;
}


void getArraysFromFile(std::vector<std::vector<int>>& arrays, std::string& path) {
    // �������� �����
    std::ifstream file(path);
    size_t number_of_arrays{}, amount_of_elements{};

    // ������ ������ ���������� ��������
    file >> number_of_arrays;

    // �������� �� ������������� ���������� ��������
    if (number_of_arrays < 0) {
        std::cout << "� ����� �� �������� ������ ��� ������ �������������, ����� �������� �� ������!";
        number_of_arrays = abs(static_cast<int>(number_of_arrays));
    }

    // �������� �� ���������� �������� ������ 0
    if (number_of_arrays == 0) {
        std::cout << "� ����� �� �������� ������ ��� ������ ������ 0, ��������� ����!";
        file.close();
        return;
    }

    // �������������� ����� ��� �������� �������
    arrays.resize(number_of_arrays);

    // ������ ������� �������
    for (size_t i = 0; i < number_of_arrays; i++) {
        // ������ ���������� ��������� � ������� �������
        file >> amount_of_elements;

        // �������� �� ������������� ���������� ���������
        if (amount_of_elements < 0) {
            std::cout << "� ����� �� �������� ���������� ��������� ���� ������� �������������, ����� �������� �� ������!";
            amount_of_elements = abs(static_cast<int>(amount_of_elements));
        }

        // �������� �� ���������� ��������� ������ 0
        if (amount_of_elements == 0) {
            std::cout << "� ����� �� �������� ���������� ��������� ���� ������� ������ 0, ��������� ����!";
            file.close();
            return;
        }

        // �������������� ����� ��� ��������� �������� �������
        arrays[i].resize(amount_of_elements);

        // ������ ��������� �������� �������
        for (size_t j = 0; j < amount_of_elements; j++) {
            file >> arrays[i][j];
        }
    }

    std::cout << "������� ���������!" << std::endl;

    // �������� �����
    file.close();
}


void saveToFile(std::vector<std::vector<int>> &arrays) {
    std::ofstream file;
    std::string path{};
    bool is_opened = false;

    std::error_code error{};

    // ���������, ���� �� ����� ������� ������ ���� ��� ������
    do {
        std::cout
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        getLine(std::cin, path, MANUAL_INPUT);

        // �������� ������������� �����
        if (std::ifstream(path)) {

            // ��������, �������� �� ��������� ���� �����������������
            if (!std::filesystem::is_regular_file(path, error)) {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            // ���������������� ���� ��� ������ ��������
            if (getKey(RESET, ANOTHER) == ANOTHER) {
                continue;
            }
        }

        // �������� ����� ��� ������ (���� �� ����������, ���������)
        file.open(path, std::ios::trunc);

        // �������� ��������� �������� �����
        if (!file) {
            std::cout << "������ �������� �����!" << std::endl;
        }
        else {
            is_opened = true;
        }
    } 
    while (!is_opened);
    // ��������� ���������� ��������
    size_t number_of_arrays = arrays.size(), amount_of_elements{};

    // ������ ������� ������� � ����
    for (size_t i = 0; i < number_of_arrays; i++) {
        // ��������� ���������� ��������� � �������
        amount_of_elements = arrays[i].size();

        file
            << std::endl
            << "������ # " << i + 1 << std::endl
            << "���������� ���������: " << amount_of_elements << std::endl
            << "***********************************************************************" << std::endl;

        for (int j = 0; j < amount_of_elements; j++) {
            file << arrays[i][j] << ' ';
        }

        file << std::endl;
    }

    file << "***********************************************************************" << std::endl;
    std::cout 
        << std::endl
        << "������� ��������� � " << path << std::endl;

    // �������� �����
    file.close();
}
