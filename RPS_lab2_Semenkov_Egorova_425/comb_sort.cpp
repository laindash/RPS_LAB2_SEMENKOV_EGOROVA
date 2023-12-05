#include "comb_sort.h"
#include "input.h"


/// <summary>
/// Сортирует вектор с использованием сортировки расческой.
/// </summary>
/// <param name="array">Вектор, который нужно отсортировать.</param>
void CombSort::sort(std::vector<int> &array) {
    // Коэффициент уменьшения, в данном случае, равен 1.3, и это число выбрано эмпирически для оптимизации производительности сортировки.
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
        /// Проходим по вектору и сравниваем элементы с учетом текущего расстояния (gap).
        /// Если необходимо, меняем местами элементы, что может привести к дополнительным итерациям.
        /// Этот процесс повторяется с уменьшением расстояния до тех пор, пока массив не будет отсортирован.
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
