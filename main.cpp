#include <chrono>
#include <ctime>
#include <iostream>
#include "bf.h"

using namespace std;

int main()
{
    srand((unsigned int)(time(NULL)));
    // for (size_t i = 2; i < 32; i++)
    // {
    //    auto begin = std::chrono::high_resolution_clock::now();
    //    BF x(2, (1<<i));
    //    uint32_t w = x.weight();
    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "size_vec =" << i << "   weight/size_vec =" << (long double)(w) / (uint64_t(1) << i) << "\tTime : " << ms.count() << std::endl;
    // }

    // for (size_t i = 2; i < 32; i++)
    // {
    //    auto begin = std::chrono::steady_clock::now();
    //    BF x(2, (1<<i));
    //    auto end = std::chrono::steady_clock::now();
    //    auto t_gen = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    BF y;
    //    BF z;
    //    begin = std::chrono::steady_clock::now();
    //    y = x.Mebius();
    //    end = std::chrono::steady_clock::now();
    //    auto t_mebius = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    z = y.Mebius();
       
    //    std::cout << "Arg =" << i << "\tTime_generation =" << t_gen.count() << "\tTime_mebius =" << t_mebius.count() << "\tEqual after 2 mebius? =" << ((x == z) ? "true" : "No");
    //    std::cout << std::endl;
    // }

    // // string str;
    // // cin >> str;
    // BF x("0001000100011110000100010001111000010001000111101110111011100001"); //0001000100011110000100010001111000010001000111101110111011100001
    // std::cout << x << std::endl;
    // uint64_t w = x.weight();
    // cout << w << " - w" << endl;
    // BF g = x.Mebius();
    // cout << g << endl;
    // string str = g.ANF();
    // cout << str << endl;

    int kek = log2(64); 
    cout << kek << endl;

    return 0;
}
