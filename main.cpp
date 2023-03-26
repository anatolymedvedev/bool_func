#include <chrono>
#include <ctime>
#include <iostream>
#include "bf.h"

using namespace std;

int main()
{
    srand((unsigned int)(time(NULL)));
    //test_generation_balance
    // for (size_t i = 2; i < 32; i++)
    // {
    //    auto begin = std::chrono::high_resolution_clock::now();
    //    BF x(2, (1<<i));
    //    uint32_t w = x.weight();
    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "size_vec =" << i << "   weight/size_vec =" << (long double)(w) / (uint64_t(1) << i) << "\tTime : " << ms.count() << std::endl;
    // }

    //test_Mebius
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

    // test_Walsh_Hadamard
    // for (size_t i = 2; i < 32; i++)
    // {
    //    auto begin = std::chrono::steady_clock::now();
    //    BF x(2, (1<<i));
    //    auto end = std::chrono::steady_clock::now();
    //    auto t_gen = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    vector<int32_t> f;
    //    begin = std::chrono::steady_clock::now();
    //    f = x.Walsh_Hadamard();
    //    end = std::chrono::steady_clock::now();
    //    auto t_Walsh_Hadamard = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "Arg =" << i << "\tTime_generation =" << t_gen.count() << "\tWalsh_Hadamard =" << t_Walsh_Hadamard.count();
    //    std::cout << std::endl;
    // }

    // // string str;
    // // cin >> str;
    BF x("0110"); //0000000100000001000000010000000100000001000000010000000111111110
    std::cout << x << std::endl;
    // uint64_t w = x.weight();
    // cout << w << " - w" << endl;
    // BF g = x.Mebius();
    // cout << g << endl;
    // g.ANF();
    // cout << endl;
    // uint32_t degree = g.degree_func();
    // cout << degree << endl;

    vector<int32_t> f;
    f = x.Walsh_Hadamard();
    for (auto s : f)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
