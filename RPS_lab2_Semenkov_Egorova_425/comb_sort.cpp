#include "comb_sort.h"
#include "input.h"


/// <summary>
/// ��������� ������ � �������������� ���������� ���������.
/// </summary>
/// <param name="array">������, ������� ����� �������������.</param>
void CombSort::sort(std::vector<int> &array) {
    // ����������� ����������, � ������ ������, ����� 1.3, � ��� ����� ������� ����������� ��� ����������� ������������������ ����������.
    const double shrink_factor = 1.3; 
    size_t gap = array.size();
    bool is_sorted = false;

    while (!is_sorted || gap != 1) {
        if (gap > 1) {
            gap = static_cast<size_t>(gap / shrink_factor);
        }
        else {
            gap = 1;
        }

        is_sorted = true;

        /// <remarks>
        /// �������� �� ������� � ���������� �������� � ������ �������� ���������� (gap).
        /// ���� ����������, ������ ������� ��������, ��� ����� �������� � �������������� ���������.
        /// ���� ������� ����������� � ����������� ���������� �� ��� ���, ���� ������ �� ����� ������������.
        /// </remarks>
        for (size_t i = gap; i < array.size(); i++) {
            if (array[i - gap] > array[i]) {
                int tmp = array[i];
                array[i] = array[i - gap];
                array[i - gap] = tmp;

                is_sorted = false;
            }
        }
    }
}
