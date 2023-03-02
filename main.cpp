#include <chrono>
#include <ctime>
#include <iostream>
#include "bf.h"

using namespace std;

int main()
{
    srand((unsigned int)(time(NULL)));
    // for (size_t i = 2; i < 31; i++)
    // {
    //    auto begin = std::chrono::high_resolution_clock::now();
    //    BF x(2, (1<<i));
    //    uint32_t w = x.weight();
    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "size_vec =" << i << "   weight/size_vec =" << (long double)(w) / (uint64_t(1) << i) << "\tTime : " << ms.count() << std::endl;
    // }

    // // string str;
    // // cin >> str;
    BF x("10101001111001111101010101111111"); 
    std::cout << x << std::endl;
    uint64_t w = x.weight();
    cout << w << " - w" << endl;

    return 0;
}
