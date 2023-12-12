#ifndef MAIN_ALGORITHMS_H
#define MAIN_ALGORITHMS_H

#include <vector>

/// <summary>
/// ������� ����������� � ��������������� �������.
/// </summary>
/// <param name="arrays"> ������ ��������, � ������� �������� �������. </param>
void showArrays(const std::vector<std::vector<int>> &arrays);

/// <summary>
/// ���������� ��������� ������� ��� ���������� ����������.
/// </summary>
/// <param name="arrays"> ������ ��������, � ������� ����� �������� ��������������� �������. </param>
/// <param name="number_of_arrays"> ���������� �������� ��� ���������. </param>
void generateRandomArrays(std::vector<std::vector<int>>& arrays, const size_t& number_of_arrays);

/// <summary>
/// ��������� �������, ���������� � �������.
/// </summary>
/// <param name="arrays"> ������ ��������, � ������� ����������� �������. </param>
void startSorting(std::vector<std::vector<int>>& arrays);

#endif