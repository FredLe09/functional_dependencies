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

    int normalForm;
    std::vector<std::pair<std::string, std::string>> coverAttris;
    std::vector<std::pair<std::string, std::string>> coverFDs;

public:
    Relation();
    ~Relation();

    std::vector<std::string> getKeys();
    std::vector<std::string> getSupKeys();

    void input();
    void output();
    void process();
    void howToFindKeys();
    void howToFindNF();
    std::string findCoverAttris(std::string);
    bool checkKey(std::string);
    std::vector<bool> checkKeys(std::vector<std::string>);
    bool checkSupKey(std::string);
    std::vector<bool> checkSupKeys(std::vector<std::string>);
    bool checkFDInCoverFDs(std::string, std::string);
    std::vector<bool> checkFDsInCoverFDs(std::vector<std::pair<std::string, std::string>>);
};
