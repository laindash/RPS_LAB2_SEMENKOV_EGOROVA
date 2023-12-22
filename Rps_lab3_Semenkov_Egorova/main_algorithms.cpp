#include "input.h"
#include "comb_sort.h"


void generateRandomArrays(std::vector<std::vector<int>> &arrays, const size_t &number_of_arrays) {
    size_t amount_of_elements{};
    std::vector<std::vector<int>> new_arrays{};

    // Изменяем размер вектора для массивов согласно указанному количеству
    new_arrays.resize(number_of_arrays);

    for (int i = 0; i < number_of_arrays; i++) {
        // Генерируем случайное количество элементов для текущего массива
        amount_of_elements = getRandInt(LOW_BOUND_FOR_QUANTITY, UP_BOUND_FOR_QUANTITY);

        // Изменяем размер текущего массива согласно сгенерированному количеству элементов
        new_arrays[i].resize(amount_of_elements);

        for (int j = 0; j < amount_of_elements; j++) {
            // Заполняем массив случайными значениями в указанных пределах
            new_arrays[i][j] = getRandInt(LOW_BOUND_FOR_RANDOM, UP_BOUND_FOR_RANDOM);
        }
        // Добавляем новый массив к старым
        arrays.push_back(new_arrays[i]);
    }
}


void startSorting(std::vector<std::vector<int>> &arrays) {
    // Вычисляем количество массивов
    size_t number_of_arrays = arrays.size();

    // Создание и инициализация объекта, производящего сортировку расчёской
    CombSort comb_sort{};

    // Внешний цикл, отвечающий за количество массивов
    for (size_t i = 0; i < number_of_arrays; i++) {
        // Сортировка отдельных массивов
        comb_sort.sort(arrays[i]);
    }
}
