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

    // test_cor
    // for (size_t i = 2; i < 32; i++)
	// {
	// 	auto begin = std::chrono::steady_clock::now();
	// 	BF x(1, 1 << i);
	// 	auto end = std::chrono::steady_clock::now();
	// 	auto t_gen = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	// 	uint32_t r = 0;
	// 	begin = std::chrono::steady_clock::now();
	// 	r = x.cor();
	// 	end = std::chrono::steady_clock::now();
	// 	auto t_cor = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	// 	std::cout << "Arg =" << i << "\tTime_gen =" << t_gen.count() << "\tTime_cor =" << t_cor.count() << "\tCor =" << r;
	// 	std::cout << std::endl;
	// }

    // test_auto_cor
    // for (size_t i = 2; i < 32; i++)
    // {
    //    auto begin = std::chrono::steady_clock::now();
    //    BF x(1, (1<<i));
    //    auto end = std::chrono::steady_clock::now();
    //    auto t_gen = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    vector<int32_t> f;
    //    begin = std::chrono::steady_clock::now();
    //    f = x.auto_cor();
    //    end = std::chrono::steady_clock::now();
    //    auto t_auto_cor = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "Arg =" << i << "\tTime_generation =" << t_gen.count() << "\tauto_cor =" << t_auto_cor.count();
    //    std::cout << std::endl;
    // }

    BF x("01101001"); //10010110  11010001 00011010
    cout << x << endl;
    // uint64_t w = x.weight();
    // cout << w << " - w" << endl;
    BF g = x.Mebius();
    cout << "Mebius: " << g << endl;
    g.ANF();
    cout << endl;
    uint32_t degree = g.degree_func();
    cout << "degree = " << degree << endl;

    vector<int32_t> f;
    f = x.Walsh_Hadamard();
    cout << "Walsh_Hadamard: " << endl; 
    for (auto s : f)
    {
        cout << s << " ";
    }
    cout << endl;

    uint32_t cor = x.cor();
    cout << "cor = " << cor << endl;

    cout << x.nf_nap() << endl;
    cout << endl;

    vector<int32_t> AC;
    AC = x.auto_cor();
    cout << "Auto_cor : " << endl; 
    for (auto s : AC)
    {
        cout << s << " ";
    }
    cout << endl;

    uint32_t PC = x.PC();
    cout << "PC = " << PC << endl;

    cout << "CN_f = " << x.Cn_f() << endl;
    cout << endl;

    return 0;
}
