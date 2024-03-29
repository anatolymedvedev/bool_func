#include <string>
#include<cstring>
#include <algorithm> 
#include <random>
#include <iostream>
#include <cmath>
#include <bitset>
#include <chrono>

using namespace std;

static std::mt19937& mt() 
{
    // initialize once per thread
    thread_local static std::mt19937 mt(static_cast<uint32_t>(time(nullptr)));
    return mt;
}

class BF
{
	uint32_t  n = 0;         //количество битов 
	uint32_t  len = 0; 
	uint32_t* f = nullptr;	
public:
    BF();
    BF(std::string s);
    BF(uint8_t type, uint32_t _n);
    ~BF();
    BF(const BF& other);
    BF& operator =(const BF& other);
    friend std::ostream& operator <<(std::ostream& out, BF& other);
    uint32_t weight();
    bool operator ==(const BF &other);
    bool operator !=(const BF &other);
    BF Mebius();
    // bool bit_value(uint32_t , uint32_t );
    void print_monom(uint32_t );
    void ANF();
    uint32_t degree_func();
    vector<int32_t> Walsh_Hadamard();
    uint32_t cor();
    string nf_nap();
    vector<int32_t> auto_cor();
    uint32_t PC();
    uint32_t Cn_f();
};
