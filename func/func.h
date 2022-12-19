#pragma once
#include <iostream>
#include <vector>

std::string sortStr(std::string);
bool checkChrInStr(char, std::string);
bool checkChrsInStr(std::string, std::string);
std::vector<std::string> subSet(std::string);
std::string findDisChr(int *, std::vector<std::pair<std::string, std::string>> &);
std::string findBoth(std::vector<std::pair<std::string, std::string>> &);