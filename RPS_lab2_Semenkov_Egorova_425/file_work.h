#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <vector>
#include <fstream>


bool isDataCorrect(std::ifstream &file);

std::string checkFile();

void getArraysFromFile(std::vector<std::vector<int>> &arrays, std::string &path);

void saveToFile(std::vector<std::vector<int>> &arrays);

#endif