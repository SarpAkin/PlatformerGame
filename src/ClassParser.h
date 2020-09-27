#ifndef ClassParser
#define ClassParser

#include <vector>
#include <array>

template<typename T>
std::array<char,sizeof(T)> ParseToStream(T pclass)
{
    std::array<char,sizeof(T)> r;
    char* ptr = (char*)&pclass;
    for(int i = 0;i < sizeof(T);i++)
    {
        r[i] = ptr[i];
    }
    return r;
}

//Class or Struct has to have a default constructor
template<typename T>
T ParseToClass(std::array<char,sizeof(T)> arr)
{
    T rClass;
    char* ptr = (char*)&rClass;
    for(int i = 0;i < sizeof(T);i++)
    {
        ptr[i] = arr[i];
    }
    return rClass;
}


#endif