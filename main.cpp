#include <iostream>
#include <limits>
#include "bigInt.h"
using namespace std;

int main()
{	
	xmath::bigInt a(UINT_MAX);
	xmath::bigInt b(1);
	
	auto c = a + b;

	auto e = UINT_MAX;
	unsigned long long d = c.toll();
	return 0;
}