#include "input.h"
#include "lab_info.h"
#include "file_work.h"
#include "main_algorithms.h"
#include "comb_sort.h"


void startProgram(void) {
    int user_choice{}; // ���������� ��� �������� ������ ������������

    // ����������� ���� ������ ���������
    for (;;) {
        std::vector<std::vector<int>> arrays{};  // ������ �������� ��� �������� ��������
        std::string file_path{}; // ������ ��� �������� ���� � �����
        size_t number_of_arrays{}; // ���������� ��������, �������� �������������

        // ����� ���� ������ ��������� ����� ������
        showInputMenu();

        // ��������� ������ ������������
        switch (user_choice = getKey(FILE_INPUT, RANDOM_INPUT)) {
            case FILE_INPUT:
                file_path = checkFile();  // �������� ����� � ���� ���� � �����
                getArraysFromFile(arrays, file_path); // ��������� �������� �� �����
                break;

            case RANDOM_INPUT:
                std::cout << "������� ���������� ��������: ";
                number_of_arrays = getPosInt(); // ���� ���������� �������� ��� ���������
                generateRandomArrays(arrays, number_of_arrays); // ��������� ��������� ��������
                break;

            case QUIT:
                break;
        }

        // ����� ����������������� ��������
        std::cout
            << std::endl
            << "����������� �������: " << std::endl;

        showArrays(arrays);

        // ������ ����������
        startSorting(arrays);

        // ���� ������ ���� ������ ���������� ��������
        while (user_choice != QUIT) {
            // ����� ���� ������ ������ ������
            showOutputMenu();

            // ��������� ������ ������������
            switch (user_choice = getKey(SHOW, SAVE)) {
                case SHOW:
                    std::cout << "��������������� �������: " << std::endl;
                    showArrays(arrays); // ����� ��������������� ��������
                    break;

                case SAVE:
                    saveToFile(arrays); // ���������� ��������������� �������� � ����
                    break;

                case QUIT:
                    break;
            }
        }

        // ����� ����� ��� ����������� ��������� ��� ����������
        std::cout << "1 - ������������� ���������, ESC - ��������� ������ ���������." << std::endl;
        user_choice = getKey(RESET, RESET);

        // ���������� ��������� ��� ������ ������
        if (user_choice == QUIT) {
            exit(EXIT_SUCCESS);
        }
    }
}