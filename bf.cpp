#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include "bf.h"

using namespace std;

//конструктор от строки
BF:: BF(string s)
{
	uint32_t str_len = s.length();
	if (f != nullptr)
	{
		delete[]f;
		f = nullptr;
	}
	if (str_len & (str_len - 1))
	{
		cout << "Length should be equal 2^n\n";
		exit(1);
	}
	n = str_len;
	len = ((1 << int(log2(n))) + 31) >> 5;
	f = new uint32_t[len];

	for (size_t i = 0; i < len; i++)
	{
		f[i] = 0;
	}

	size_t j = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (j == 32)
		{
			j = 0;
		}
        if (s[i] == '1')
        {
		    f[(i >> 5)] |= (1 << j);
        }

		// if (s[i] == '0')
		// {
		// 	f[(i >> 5)] ^= (1 << j);
		// }
		j++;
	}
}

BF:: BF(uint8_t type, uint32_t _n = sizeof(uint32_t))
{
	if (_n & (_n - 1))
	{
		cout << "Length should be equal 2^n\n";
		exit(1);
	}

	n = _n;
	len = (((uint64_t)1 << (uint64_t)(log2(n))) + (uint64_t)31) >> 5;
    f = new uint32_t[len];

	if (type == 2)
	{
		for (size_t i = 0; i < len; i++)
		{
			f[i] = 0;
		}
        if (n <= 16)
        {
            f[0] |= (uint16_t(rand() - rand())) >> (16 - n);
        }
        else
        {
            for (uint32_t i = 0; i < len; i++)
            {
                f[i] = (rand() - rand());
				// f[i] = uint16_t(rand() - rand());
				// f[i] = f[i] << 16;
				// f[i] |= uint16_t(rand() - rand());

				// thread_local static std::mt19937 mersenne = mt();
                // if (mersenne() % 2)
                // {
                // 	f[i >> 5] |= (1 << (i % 32));
                // }
            }
        }
        
        // for (int i = 0; i < len; i++)
		// {
		// 	std::bitset<32> st(f[i]);
		// 	std::string str = st.to_string();
		// 	cout << str << endl;
		// }
	}

	if (type == 1)
	{
        // for (size_t i = 0; i < len; i++)
		// {
		// 	f[i] = 0;
		// }

        if (n < 32)
        {
			f[0] = UINT32_MAX;
			f[0] = f[0] >> (32 - n);
        }
        else
        {
            for (size_t i = 0; i < len; i++)
            {
                f[i] = UINT32_MAX;
            }
        }
        
        // for (int i = 0; i < len; i++)
		// {
		// 	std::bitset<32> st(f[i]);
		// 	std::string str = st.to_string();
		// 	cout << str << endl;
		// }
	}

	if (type == 0)
	{
		for (size_t i = 0; i < len; i++)
		{
			f[i] = 0;
		}
		
        // for (int i = 0; i < len; i++)
		// {
		// 	std::bitset<32> st(f[i]);
		// 	std::string str = st.to_string();
		// 	cout << str << endl;
		// }
	}
}

BF:: BF()
{
	n = 1;
    len = n;
	f = new uint32_t[len];
    f[0] = 0;
}

BF:: ~BF()
{
	if (f != nullptr)
	{
		delete[] f;
		f = nullptr;
	}
}

BF:: BF(const BF& other)
{
	n = other.n;
	len = other.len;
	f = new uint32_t[len];

	for (int i = 0; i < len; i++)
	{
		f[i] = other.f[i];
	}
}

BF& BF:: operator =(const BF& other)
{
	if(this != &other)  //other=other
    {
		if (f != nullptr)
		{
			delete[] f;
		}
		n = other.n;
		len = other.len;
		f = new uint32_t[len];

		for (int i = 0; i < len; i++)
		{
			f[i] = other.f[i];
		}
	}

	return *this;
}

std::ostream& operator <<(std::ostream& out, BF& other)
{
	if (other.n <= 31)
	{
		std::bitset<32> st(other.f[0]);
		std::string str = st.to_string();
		str.erase(0, 32 - other.n);
		reverse(str.begin(), str.end());
		// cout << str << endl;
		out << str;
	}
	else
	{
		for (int i = 0; i < other.len; i++)
		{
			std::bitset<32> st(other.f[i]);
			std::string str = st.to_string();
			reverse(str.begin(), str.end());
			// cout << str << endl;
			out << str;
		}
	}

	return out;
}

uint32_t BF::weight()
{
	uint32_t res = 0;
	for (size_t i = 0; i < len; i++)
	{
		uint32_t tmp = f[i];
		tmp = tmp - ((tmp >> 1) & 0x55555555L);
		tmp = (tmp & 0x33333333L) + ((tmp >> 2) & 0x33333333L);
		tmp = (tmp + (tmp >> 4)) & 0x0F0F0F0FL;
		tmp = tmp + (tmp >> 8);
		res += (uint8_t)(tmp + (tmp >> 16)) & 0x3F;
	}

	return res;
}

bool BF:: operator ==(const BF &other)
{
	if (n != other.n)
	{
		return false;
	}

	for (int i = 0; i < len; i++)
	{
		if (other.f[i] != f[i])
		{
			return false;
		}
	}

	return true;
}

bool BF::operator !=(const BF &other)
{
	return !(*this == other);
}

BF BF:: Mebius()
{
	BF g;
	g = *this;
	
	if (n == 2)
	{
		g.f[0] = g.f[0] ^ ((g.f[0] << 1) & 0x55555555);
		return g;
	}

	if (n == 4)
	{
		g.f[0] = g.f[0] ^ ((g.f[0] << 1) & 0x55555555);
		g.f[0] = g.f[0] ^ ((g.f[0] << 2) & 0x33333333);
		return g;
	}
	if (n == 8)
	{
		g.f[0] = g.f[0] ^ ((g.f[0] << 1) & 0xAAAAAAAA);
		g.f[0] = g.f[0] ^ ((g.f[0] << 2) & 0xCCCCCCCC);
		g.f[0] = g.f[0] ^ ((g.f[0] << 4) & 0xF0F0F0F0);
		// for (int i = 0; i < len; i++)
		// {
		// 	std::bitset<32> st(g.f[i]);
		// 	std::string str = st.to_string();
		// 	cout << str << endl;
		// }
		return g;
	}
	if (n == 16)
	{
		g.f[0] = g.f[0] ^ ((g.f[0] << 1) & 0xAAAAAAAA);
		g.f[0] = g.f[0] ^ ((g.f[0] << 2) & 0xCCCCCCCC);
		g.f[0] = g.f[0] ^ ((g.f[0] << 4) & 0xF0F0F0F0);
		g.f[0] = g.f[0] ^ ((g.f[0] << 8) & 0xFF00FF00);
		return g;
	}
	if (n >= 32)
	{
		for (size_t i = 0; i < len; i++)
		{
			g.f[i] ^= ((g.f[i] << 1) & 0xAAAAAAAA);
			g.f[i] ^= ((g.f[i] << 2) & 0xCCCCCCCC);
			g.f[i] ^= ((g.f[i] << 4) & 0xF0F0F0F0);
			g.f[i] ^= ((g.f[i] << 8) & 0xFF00FF00);
			g.f[i] ^= ((g.f[i] << 16) & 0xFFFF0000);
		}

        uint32_t per = log2(n);
        // if (per > 5)
        // {
            for (size_t i = 0; i < per; i++)
            {
                for (size_t j = 0; j < len; j++)
                {
                    for (size_t k = j * (1<<(i + 1)), l = k + (1<<i), p = 0; p < (1<<i); p++, k++, l++)
                    {
                        g.f[k] ^= g.f[l];
                    }
                }
            }
        // }
		return g;
	}

	return g;
}

// string BF:: ANF()
// {
// 	BF g;
// 	// g = *this;
// 	BF f;
// 	string str;
// 	int j = 0;
// 	for (size_t i = 0; i < n; i++)
// 	{
// 		if (j == 32)
// 		{
// 			j = 0;
// 		}
// 		g.f[j] = this->f[j] & (1<<i);
// 		for (int i = 0; i < len; i++)
// 		{
// 			std::bitset<32> st(g.f[j]);
// 			std::string str = st.to_string();
// 			cout << str << endl;
// 		}
		
// 		if (g.f[j] == true)
// 		{
// 			str[i] = char(65 + i);
// 			cout << str << endl;
// 		}
// 		j++;
// 	}
// 	return str;
// }
