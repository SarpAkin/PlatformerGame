#include <iostream>
#include <vector>

int a(int a)
{
    return a;
}
int main()
{
    std::vector<int> number = {1,5,1,34,18,29};
    for(int i : number)
    {
        std::cout << i << std::endl;
    }
}