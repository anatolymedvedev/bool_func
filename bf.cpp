#include <string>
#include <iostream>
#include <cmath>
#include <bitset>
#include "ot.h"

using namespace std;

//конструктор от строки
BF:: BF(std::string s)
{
	uint32_t str_len = s.length();
	if (f != nullptr)
	{
		delete[]f;
		f = nullptr;
	}
	if (str_len & (str_len - 1))
	{
		std::cout << "The length can only be a power of 2\n";
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
		f[(i >> 5)] |= (1 << j);

		if (s[i] == '0')
		{
			f[(i >> 5)] ^= (1 << j);
		}
		j++;
	}

	// for (size_t i = 0; i < len; i++)
	// {
	// 	std::bitset<32> st(f[i]);
	// 	std::string str = st.to_string();
	// 	std::cout << str << " " << i << std::endl;
	// }
}

/*
* конструктор
* при type == 2 — случайный набор
* при type == 1 — константа 1
* при type == 0 — константа 0
*/
BF:: BF(uint8_t type, uint32_t _len = sizeof(uint32_t) * 8)
{
	if (_len & (_len - 1))
	{
		std::cout << "The length can only be a power of 2\n";
		exit(1);
	}

	n = _len;
	len = ((1 << int(log2(n))) + 31) >> 5;
	f = new uint32_t[len];

	if (type == 2)
	{
		for (size_t i = 0; i < len; i++)
		{
			f[i] = 0;
		}
		for (uint32_t i = 0; i < n; i++)
		{
			thread_local static std::mt19937 mersenne = mt();
			if (mersenne() % 2)
			{
				f[i >> 5] |= (1 << (i % 32));
			}
		}
	}

	if (type == 1)
	{
		for (size_t i = 0; i < len; i++)
		{
			f[i] = UINT32_MAX;
		}
	}

	if (type == 0)
	{
		for (size_t i = 0; i < len; i++)
		{
			f[i] = 0;
		}
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
	if (other.n <= 32)
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
