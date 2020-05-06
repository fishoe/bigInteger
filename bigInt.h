#ifndef BIGINT_H
#define BIGINT_H

#include <limits>
#include <string>
#include <cmath>
using namespace std;

namespace xmath {
	const int MAX_CHIPER = UINT_MAX;

	class bigInt
	{
	public:
		bigInt();
		~bigInt();
		
		unsigned int getChipers() { return chiper; }
		//toString
		string toStr();
		//acc
		bigInt& operator+(bigInt &op);
		//min
		bigInt& operator-(bigInt &op);
		//product
		bigInt& operator*(bigInt &op);
		//div
		bigInt& operator/(bigInt &op);
		//comp
		bool operator==(const bigInt &op) const;
		bool operator<(const bigInt &op) const;
		bool operator>(const bigInt &op) const;

	private:
		bool sign; //true : pos, false : neg
		void* number;
		unsigned int chiper;
		unsigned int bytes;
	};
}

#endif
