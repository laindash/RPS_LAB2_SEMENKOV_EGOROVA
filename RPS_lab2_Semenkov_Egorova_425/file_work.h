#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <vector>
#include <fstream>


/// <summary>
/// ������� ��� �������� ������������ ������ � �����.
/// </summary>
/// <param name="file">����, ���������� �������� ������.</param>
bool isDataCorrect(std::ifstream &file);

/// <summary>
/// ������� ��� �������� � �������� ����� � ����������� �������.
/// </summary>
std::string checkFile();

/// <summary>
/// ������� ��� ������ �������� �� �����
/// </summary>
/// <param name="array">������, ������� ����� ��������� �������.</param>
/// <param name="path">���� � ����� � ��������� �������.</param>
void getArraysFromFile(std::vector<std::vector<int>> &arrays, std::string &path);

/// <summary>
/// ������� ��� ���������� �������� � ����
/// </summary>
/// <param name="array">������, ���������� �������.</param>
void saveToFile(std::vector<std::vector<int>> &arrays);

#endif