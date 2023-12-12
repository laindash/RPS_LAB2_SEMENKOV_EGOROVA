#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <vector>
#include <fstream>


/// <summary>
/// Функция для проверки корректности данных в файле.
/// </summary>
/// <param name="file">Файл, содержащий исходные данные.</param>
bool isDataCorrect(std::ifstream &file);

/// <summary>
/// Функция для проверки и открытия файла с корректными данными.
/// </summary>
std::string checkFile();

/// <summary>
/// Функция для чтения массивов из файла
/// </summary>
/// <param name="array">Вектор, который будет содержать массивы.</param>
/// <param name="path">Путь к файлу с исходными данными.</param>
void getArraysFromFile(std::vector<std::vector<int>> &arrays, std::string &path);

/// <summary>
/// Функция для сохранения массивов в файл
/// </summary>
/// <param name="array">Вектор, содержащий массивы.</param>
void saveToFile(std::vector<std::vector<int>> &arrays);

#endif