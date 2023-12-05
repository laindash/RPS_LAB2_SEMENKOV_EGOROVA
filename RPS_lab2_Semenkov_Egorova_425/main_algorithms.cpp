#include "input.h"
#include "comb_sort.h"


/// <summary>
///    ������� ����������� � ��������������� �������.
/// </summary>
/// <param name="arrays">
///    ������ ��������, � ������� �������� �������.
/// </param>
void showArrays(const std::vector<std::vector<int>> &arrays) {
    // ��������� ���������� ��������, �������������� ���������� �������� ���������� ���������
    size_t number_of_arrays = arrays.size(), amount_of_elements{};

    // ������� ����, ���������� �� ���������� ��������
    for (size_t i = 0; i < number_of_arrays; i++) {
        // ��������� ���������� ��������� � �������
        amount_of_elements = arrays[i].size();

        std::cout
            << std::endl
            << "������ # " << i + 1 << std::endl
            << "���������� ���������: " << amount_of_elements << std::endl
            << "***********************************************************************" << std::endl;

        // ���������� ����, ���������� �� ���������� ���������
        for (size_t j = 0; j < amount_of_elements; j++) {
            std::cout << arrays[i][j] << ' ';
        }
        std::cout << std::endl
            << "***********************************************************************" << std::endl;
    }
}


/// <summary>
///    ���������� ��������� ������� ��� ���������� ����������.
/// </summary>
/// <param name="arrays">
///    ������ ��������, � ������� ����� �������� ��������������� �������.
/// </param>
/// <param name="number_of_arrays">
///    ���������� �������� ��� ���������.
/// </param>
void generateRandomArrays(std::vector<std::vector<int>> &arrays, const size_t &number_of_arrays) {
    size_t amount_of_elements{};

    // �������� ������ ������� ��� �������� �������� ���������� ����������
    arrays.resize(number_of_arrays);

    for (int i = 0; i < number_of_arrays; i++) {
        // ���������� ��������� ���������� ��������� ��� �������� �������
        amount_of_elements = getRandInt(LOW_BOUND_FOR_QUANTITY, UP_BOUND_FOR_QUANTITY);

        // �������� ������ �������� ������� �������� ���������������� ���������� ���������
        arrays[i].resize(amount_of_elements);

        for (int j = 0; j < amount_of_elements; j++) {
            // ��������� ������ ���������� ���������� � ��������� ��������
            arrays[i][j] = getRandInt(LOW_BOUND_FOR_RANDOM, UP_BOUND_FOR_RANDOM);
        }
    }
}


/// <summary>
///    ��������� �������, ���������� � �������.
/// </summary>
/// <param name="arrays">
///    ������ ��������, � ������� ����������� �������.
/// </param>
void startSorting(std::vector<std::vector<int>> &arrays) {
    // ��������� ���������� ��������
    size_t number_of_arrays = arrays.size();

    // �������� � ������������� �������, ������������� ���������� ���������
    CombSort comb_sort{};

    // ������� ����, ���������� �� ���������� ��������
    for (size_t i = 0; i < number_of_arrays; i++) {
        // ���������� ��������� ��������
        comb_sort.sort(arrays[i]);
    }
}
