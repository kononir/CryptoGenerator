#pragma once

#include <cmath>
#include "windows.h"

class PsevdoGenerator
{
private:
	unsigned long long xi;
	unsigned long long xi1;
	unsigned long long xi2;

public:
	PsevdoGenerator(unsigned long long, unsigned long long, unsigned long long);
	~PsevdoGenerator();

	unsigned long long generate();
};

