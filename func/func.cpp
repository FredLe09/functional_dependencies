#include "func.h"

std::string sortStr(std::string str)
{
    int arr['z' - 'a' + 1]{};
    for (auto &it : str)
        arr[it - 'a'] = 1;

    std::string res;
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        if (arr[i] == 1)
            res += (char)(i + 'a');
    return res;
}

bool checkChrInStr(char c, std::string s)
{
    for (auto &it : s)
        if (it == c)
            return true;
    return false;
}

bool checkChrsInStr(std::string s1, std::string s2)
{
    for (auto &it : s1)
        if (!checkChrInStr(it, s2))
            return false;
    return true;
}

std::vector<std::string> subSet(std::string s)
{
    std::vector<std::string> res;
    for (int i = 0; i < (1 << s.length()); i++)
    {
        std::string tmp;
        for (int j = 0; j < s.length(); j++)
            if (i & (1 << j))
                tmp += s[j];
        res.push_back(tmp);
    }
    return res;
}

std::string findDisChr(int *arr, std::vector<std::pair<std::string, std::string>> &FDs)
{
    int aTmp['z' - 'a' + 1]{};
    for (int i = 0; i < 'z' - 'a' + 1; ++i)
        aTmp[i] = arr[i];

    for (auto &it : FDs)
    {
        auto &it1 = it.second;
        for (auto &c : it1)
            aTmp[c - 'a'] = 0;
    }

    std::string res{};
    for (int i = 0; i < 'z' - 'a' + 1; ++i)
        if (aTmp[i] == 1)
            res += char(i + 'a');

    return res;
}

std::string findBoth(std::vector<std::pair<std::string, std::string>> &FDs)
{
    int arr1['z' - 'a' + 1]{};
    int arr2['z' - 'a' + 1]{};

    for (auto &it : FDs)
    {
        for (auto &it0 : it.first)
            arr1[it0 - 'a'] = 1;

        for (auto &it1 : it.second)
            arr2[it1 - 'a'] = 1;
    }

    std::string res = "";
    for (int i = 0; i < 'z' - 'a' + 1; ++i)
        if (arr1[i] && arr2[i])
            res += char(i + 'a');
    return res;
}
