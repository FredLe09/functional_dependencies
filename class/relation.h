#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include "../func/func.h"

class Relation
{
private:
    bool isIntegrity;
    std::string attris;
    int arrAttris['z' - 'a' + 1]{};
    std::vector<std::pair<std::string, std::string>> FDs;
    std::vector<std::string> keys;
    std::vector<std::string> supKeys;
    int normalForm;
    std::vector<std::pair<std::string, std::string>> coverAttris;
    std::vector<std::pair<std::string, std::string>> coverFDs;

public:
    Relation();
    ~Relation();

    std::vector<std::string> getKeys();
    std::vector<std::string> getSupKeys();

    void Input();
    void Output();
    void HowToFindKeys();
    void HowToFindNF();
    std::string findCoverAttris(std::string);
    bool CheckSupKeys(std::string);
    std::vector<bool> CheckSupKeys(std::vector<std::string>);
    bool CheckFDsInCoverFDs(std::string);
    std::vector<bool> CheckFDsInCoverFDs(std::vector<std::string>);
};
