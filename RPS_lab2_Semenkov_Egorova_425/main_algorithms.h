#ifndef MAIN_ALGORITHMS_H
#define MAIN_ALGORITHMS_H

#include <vector>

/// <summary>
/// ¬ыводит изначальные и отсортированные массивы.
/// </summary>
/// <param name="arrays"> ¬ектор векторов, в котором хран€тс€ массивы. </param>
void showArrays(const std::vector<std::vector<int>> &arrays);

/// <summary>
/// √енерирует случайные массивы дл€ дальнейшей сортировки.
/// </summary>
/// <param name="arrays"> ¬ектор векторов, в который будут помещены сгенерированные массивы. </param>
/// <param name="number_of_arrays">  оличество массивов дл€ генерации. </param>
void generateRandomArrays(std::vector<std::vector<int>>& arrays, const size_t& number_of_arrays);

/// <summary>
/// —ортирует массивы, хран€щиес€ в векторе.
/// </summary>
/// <param name="arrays"> ¬ектор векторов, в котором сортируютс€ массивы. </param>
void startSorting(std::vector<std::vector<int>>& arrays);

#endif