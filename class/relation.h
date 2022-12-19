#pragma once
#include <iostream>
#include <vector>
#include <../func/func.h>

class Relation
{
private:
    bool isIntegrity;
    std::string attris;
    int arrAttri['z' - 'a' + 1]{};
    std::vector<std::pair<std::string, std::string>> FDs;
    std::vector<std::string> keys;
    std::vector<std::string> supKeys;
    int normalForm;
    std::vector<std::pair<std::string, std::string>> coverAttris;
    std::vector<std::pair<std::string, std::string>> coverFDs;

public:
    Relation();
    ~Relation();

    void Input();
    void Output();
    void HowToFindKeys();
    void HowToFindNF();
    bool CheckSupKeys(std::string);
    bool CheckSupKeys(std::vector<std::string>);
    bool CheckFDsInCoverFDs(std::string);
    bool CheckFDsInCoverFDs(std::vector<std::string>);
};
