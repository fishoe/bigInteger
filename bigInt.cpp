#include "bigInt.h"
#include <vector>

xmath::bigInt::bigInt()
{
	unsigned int * temp = new unsigned int[1];
	*temp = 0;
	number = temp;
	chiper = 1;
	sign = true;
	bytes = sizeof(int);
}

xmath::bigInt::bigInt(const unsigned int n)
{
	unsigned int* temp = new unsigned int[1];
	*temp = n;
	number = temp;
	chiper = log10(n);
	sign = true;
	bytes = sizeof(int);
}

xmath::bigInt::~bigInt()
{
	delete[] number;
}

int xmath::bigInt::toInt()
{
	int result = *((int*)number);
	return result;
}

long long xmath::bigInt::toll()
{
	long long result = *((long long*)number);
	return result;
}

xmath::bigInt& xmath::bigInt::operator+(bigInt& op)
{
	bigInt *result = new bigInt;

	if (sign == op.sign) {//같은 부호 끼리 합
		int nInt = (bytes > op.bytes ? bytes : op.bytes) / sizeof(int);

		result->number = new unsigned int[nInt+1];
		result->bytes = (nInt + 1) * sizeof(int);
		result->sign = op.sign;

		unsigned int carry = 0;
		for (int i = 0; i < nInt; i++) {//합
			unsigned long long lval = (i * nInt) < bytes ? *((unsigned int*)number + i) : 0;
			unsigned long long rval = (i * nInt) < op.bytes ? *((unsigned int*)op.number + i) : 0;

			unsigned long long temp = lval + rval + carry;

			unsigned int* ojb = ((unsigned int*)result->number)+ i;
			*ojb = *((unsigned int*)&temp);
			carry = *((unsigned int*)&temp + 1);
		}
		if (carry != 0) { //캐리값 저장
			auto n = result->bytes / sizeof(int);
			unsigned int* t = ((unsigned int*)(result->number)) + n - 1;
			*t = carry;
		}
	}

	return *result;
}

bool xmath::bigInt::operator==(const bigInt& op) const
{
	if (chiper != op.chiper) return false;
	if (sign != op.sign) return false;

	unsigned int* l = (unsigned int *)number;
	unsigned int* r = (unsigned int*)op.number;

	int nInt = bytes / sizeof(int);

	for (int i = 0; i < nInt; i++) if (*(l + i) != *(r + i)) return false;
	return true;
}

bool xmath::bigInt::operator<(const bigInt& op) const{
	if (sign != op.sign) return sign ? false : true;
	if (chiper != op.chiper) return chiper < op.chiper ? true : false;

	unsigned int* lit = (unsigned int*)number;
	unsigned int* rit = (unsigned int*)op.number;
	int nInt = bytes / sizeof(int);
	bool result;

	for (int i = nInt - 1; i >= 0; i--) {
		if (*(lit + i) < *(rit + i)) return sign ? true : false;
		else if (*(lit + i) < *(rit + i)) return sign ? false : true;
	}

	return false;
}

bool xmath::bigInt::operator>(const bigInt& op) const {
	return op < (*this);
}