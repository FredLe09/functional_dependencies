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