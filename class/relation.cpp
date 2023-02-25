#include "relation.h"

Relation::Relation()
{
    this->isIntegrity = true;
}


Relation::~Relation() {}


std::vector<std::string> Relation::getKeys()
{
    if (this->keys.size() == 0)
        this->process();
    return this->keys;
}


std::vector<std::string> Relation::getSupKeys()
{
    if (this->keys.size() == 0)
        this->process();
    
    std::vector<std::string> supKeys;
    // TODO: find super keys
    return supKeys;
}


void Relation::input()
{
    std::string sTmp;
    std::cout << "Please input the attributes of the relation (ABC...): ";
    std::cin >> sTmp;
    for (int i = 0; i < sTmp.length(); i++)
    {
        if (sTmp[i] >= 'A' && sTmp[i] <= 'Z')
            this->arrAttris[sTmp[i] - 'A'] = 1;
        else
        {
            std::cout << "Invalid input!" << std::endl;
            this->isIntegrity = false;
            return;
        }
    }
    this->isIntegrity = true;

    for (int i = 0; i < 'Z' - 'A' + 1; i++)
        if (this->arrAttris[i] == 1)
            this->attris += (char)(i + 'A');

    int n;
    std::cout << "Please input the number of functional dependencies: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        std::string s1, s2;
        std::cout << "Please input the " << i + 1 << "th functional dependency: ";
        std::cin >> s1 >> s2;
        for (auto &it : s1)
            if (this->arrAttris[it - 'A'] == 0)
            {
                std::cout << "Invalid input! Please input again!!!" << std::endl;
                --i;
                continue;
            }
        s1 = sortStr(s1);
        for (auto &it : s2)
            if (this->arrAttris[it - 'A'] == 0)
            {
                std::cout << "Invalid input! Please input again!!!" << std::endl;
                --i;
                continue;
            }
        s2 = sortStr(s2);
        this->FDs.push_back(std::make_pair(s1, s2));
    }
}


void Relation::output()
{
    if (!isIntegrity)
    {
        std::cout << "The relation is not integrity!" << std::endl;
        return;
    }

    std::cout << "The attributes of the relation are: " << this->attris << std::endl;
    std::cout << "The functional dependencies of the relation are:" << std::endl;
    for (auto &it : this->FDs)
        std::cout << "    \"" << it.first << "\" -> \"" << it.second << "\"" << std::endl;
    std::cout << std::endl;
}


void Relation::process()
{
    std::string N = findDisChr(this->arrAttris, this->FDs);
    std::string coverOfN = this->findCoverAttris(N);
    if (coverOfN == this->attris)
    {
        std::cout << "    The cover of \"" << N << "\" are \"" << coverOfN << "\" that\"s also exactly all attributes of relation." << std::endl;
        this->keys = std::vector<std::string>{N};
        return;
    }

    std::string TG = findBoth(this->FDs);
    std::vector<std::string> CTG = subSet(TG);
    bool *arrTG = new bool[CTG.size()]{};           // 0: not cover, 1: cover
    for (int i = 0; i < CTG.size(); ++i)
    {
        if (arrTG[i])
            continue;

        std::string setAttr = sortStr(CTG[i] + N);
        std::string coverOfSetAttr = this->findCoverAttris(setAttr);
        if (coverOfSetAttr == this->attris)
        {
            this->keys.push_back(setAttr);
            for (int j = i + 1; j < CTG.size(); ++j)
                if (!arrTG[j] && checkChrsInStr(CTG[i], CTG[j]))
                {
                    arrTG[j] = true;
                }
        }
    }
    delete[] arrTG;
}


void Relation::howToFindKeys()
{
    if (!isIntegrity)
    {
        std::cout << "The relation is not integrity!" << std::endl;
        return;
    }

    std::cout << "+ Step 1: Find N" << std::endl;
    std::string N = findDisChr(this->arrAttris, this->FDs);
    std::cout << "    N = \"" << N << "\"" << std::endl;
    std::string coverOfN = this->findCoverAttris(N);
    if (coverOfN == this->attris)
    {
        std::cout << "    The cover of \"" << N << "\" are \"" << coverOfN << "\" that\"s also exactly all attributes of relation." << std::endl;
        this->keys = std::vector<std::string>{N};
        return;
    }
    std::cout << "    The cover of \"" << N << "\" are \"" << coverOfN << "\" != \"" << this->attris << "\"" << std::endl
              << std::endl;

    std::cout << "+ Step 2: Find TG: " << std::endl;
    std::string TG = findBoth(this->FDs);
    std::cout << "    TG = \"" << TG << "\"" << std::endl;
    std::vector<std::string> CTG = subSet(TG);
    std::cout << "    CTG = {";
    for (auto &it : CTG)
        std::cout << "\"" << it << "\",";
    std::cout << "\b}" << std::endl
              << std::endl;
    bool *arrTG = new bool[CTG.size()]{};

    std::cout << "+ Step 3: Make table like this..." << std::endl;
    for (int i = 0; i < CTG.size(); ++i)
    {
        if (arrTG[i])
            continue;

        std::string setAttr = sortStr(CTG[i] + N);
        std::string coverOfSetAttr = this->findCoverAttris(setAttr);
        std::cout << std::right << std::setw(10) << "\"" + N + "\"";
        std::cout << std::right << std::setw(10) << "\"" + CTG[i] + "\"";
        std::cout << std::right << std::setw(20) << "\"" + setAttr + "\"";
        std::cout << std::right << std::setw(20) << "\"" + coverOfSetAttr + "\"";

        if (coverOfSetAttr == this->attris)
        {
            std::cout << std::right << std::setw(8) << "Yes";
            this->keys.push_back(setAttr);
            std::queue<std::string> que;
            std::cout << " | ";
            for (int j = i + 1; j < CTG.size(); ++j)
                if (!arrTG[j] && checkChrsInStr(CTG[i], CTG[j]))
                {
                    que.push(CTG[j]);
                    arrTG[j] = true;
                }

            if (!que.empty())
            {
                std::cout << "Remove ";
                while (!que.empty())
                {
                    std::cout << "\"" << que.front() << "\",";
                    que.pop();
                }
                std::cout << "\b ";
            }
        }
        else
            std::cout << std::right << std::setw(8) << "No"
                      << " | ";
        std::cout
            << std::endl;
    }
    delete[] arrTG;
}

void Relation::howToFindNF()
{
}

std::string Relation::findCoverAttris(std::string attris)
{
    std::string res = attris;
    bool chks[this->FDs.size()]{};
    bool isContinue;
    do
    {
        isContinue = false;
        for (int i = 0; i < this->FDs.size(); ++i)
            if (!chks[i] && checkChrsInStr(this->FDs[i].first, res))
            {
                isContinue = true;
                res = sortStr(res + this->FDs[i].second);
                chks[i] = 1;
            }
    } while (isContinue);

    return res;
}

bool Relation::checkKey(std::string attr)
{
    for (auto &it : this->keys)
        if (attr == it)
            return true;
    return false;
}

std::vector<bool> Relation::checkKeys(std::vector<std::string> attrs)
{
    std::vector<bool> res;
    for (auto &it : attrs)
        res.push_back(this->checkKey(it));
    return res;
}

bool Relation::checkSupKey(std::string attr)
{
    std::string coverOfAttr = this->findCoverAttris(attr);
    return coverOfAttr == this->attris;
}

std::vector<bool> Relation::checkSupKeys(std::vector<std::string> attrs)
{
    std::vector<bool> res;
    for (auto &it : attrs)
        res.push_back(this->checkSupKey(it));
    return res;
}

bool Relation::checkFDInCoverFDs(std::string first_FD, std::string second_FD)
{
    std::string coverOfFirst_FD = this->findCoverAttris(first_FD);
    return checkChrsInStr(second_FD, coverOfFirst_FD);
}

std::vector<bool> Relation::checkFDsInCoverFDs(std::vector<std::pair<std::string, std::string>> FDs)
{
    std::vector<bool> res;
    for (auto &it : FDs)
        res.push_back(this->checkFDInCoverFDs(it.first, it.second));
    return res;
}