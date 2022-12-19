#include "relation.h"

Relation::Relation()
{
    this->isIntegrity = true;
}

Relation::~Relation() {}

std::vector<std::string> Relation::getKeys()
{
    if (this->keys.size() == 0)
        this->HowToFindKeys();
    return this->keys;
}
std::vector<std::string> Relation::getSupKeys()
{
    if (this->supKeys.size() == 0)
        this->HowToFindKeys();
    return this->supKeys;
}

void Relation::Input()
{
    std::string sTmp;
    std::cout << "Please input the attributes of the relation: ";
    std::cin >> sTmp;
    for (int i = 0; i < sTmp.length(); i++)
    {
        if (sTmp[i] >= 'a' && sTmp[i] <= 'z')
            arrAttri[sTmp[i] - 'a'] = 1;
        else
        {
            std::cout << "Invalid input!" << std::endl;
            this->isIntegrity = false;
            return;
        }
    }
    this->isIntegrity = true;

    for (int i = 0; i < 'z' - 'a' + 1; i++)
        if (arrAttri[i] == 1)
            this->attris += (char)(i + 'a');

    int n;
    std::cout << "Please input the number of functional dependencies: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string s1, s2;
        std::cout << "Please input the " << i + 1 << "th functional dependency: ";
        std::cin >> s1 >> s2;
        for (auto &it : s1)
            if (this->arrAttri[it - 'a'] == 0)
            {
                std::cout << "Invalid input! Please input again!!!" << std::endl;
                --i;
                continue;
            }
        s1 = sortStr(s1);
        for (auto &it : s2)
            if (this->arrAttri[it - 'a'] == 0)
            {
                std::cout << "Invalid input! Please input again!!!" << std::endl;
                --i;
                continue;
            }
        s2 = sortStr(s2);
        this->FDs.push_back(std::make_pair(s1, s2));
    }
}

void Relation::Output()
{
    if (!isIntegrity)
    {
        std::cout << "The relation is not integrity!" << std::endl;
        return;
    }

    std::cout << "The attributes of the relation are: " << this->attris << std::endl;
    std::cout << "The functional dependencies of the relation are:" << std::endl;
    for (auto &it : this->FDs)
    {
        std::cout << it.first << " -> " << it.second << std::endl;
    }
}

void Relation::HowToFindKeys()
{
}

void Relation::HowToFindNF()
{
}

bool Relation::CheckSupKeys(std::string)
{
    return true;
}

bool Relation::CheckSupKeys(std::vector<std::string>)
{
    return true;
}

bool Relation::CheckFDsInCoverFDs(std::string)
{
    return true;
}

bool Relation::CheckFDsInCoverFDs(std::vector<std::string>)
{
    return true;
}