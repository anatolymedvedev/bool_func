#include <chrono>
#include <ctime>
#include "ot.h"

using namespace std;

int main()
{
    // srand((unsigned int)(time(NULL)));
    
    // for (size_t i = 1; i < 31; i++)
    // {
    //    auto begin = std::chrono::high_resolution_clock::now();
    //    BF x(2, 1<<i);
    //    uint64_t w = x.weight();
    //    auto end = std::chrono::high_resolution_clock::now();
    //    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    //    std::cout << "vec_size =" << i << "   weight/vec_size =" << (long double)(w) / (uint64_t(1) << i) << "\tTime : " << ms.count() << std::endl;
    // }

    // string str;
    // cin >> str;
    BF x("1100010110100111"); //1001101100111101101011101110110000011011001001011010111011101100
    std::cout << x << std::endl;
    uint64_t w = x.weight();
    cout << w << " - w" << endl;
    return 0;
}
