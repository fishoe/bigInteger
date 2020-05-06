#include "bigInt.h"

xstl::bigInt::bigInt()
{
	int * temp = new int[1];
	*temp = 0;
	number = temp;
	chiper = 1;
	sign = true;
	bytes = sizeof(int);
}

xstl::bigInt::~bigInt()
{
	delete[] number;
}



bool xstl::bigInt::operator==(const bigInt& op) const
{
	if (chiper != op.chiper) return false;
	if (sign != op.sign) return false;

	unsigned int* l = (unsigned int *)number;
	unsigned int* r = (unsigned int*)op.number;

	int nInt = bytes / sizeof(int);

	for (int i = 0; i < nInt; i++) if (*(l + i) != *(r + i)) return false;
	return true;
}

bool xstl::bigInt::operator<(const bigInt& op) const{
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

bool xstl::bigInt::operator>(const bigInt& op) const {
	return op < (*this);
}