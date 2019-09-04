#include "pch.h"
#include <cmath>
#include "PsevdoGenerator.h"


PsevdoGenerator::PsevdoGenerator(DWORD xi, DWORD xi1, DWORD xi2)
{
	this->xi = xi;
	this->xi1 = xi1;
	this->xi2 = xi2;
}

PsevdoGenerator::~PsevdoGenerator()
{
}

DWORD PsevdoGenerator::generate()
{
	DWORD xnext = (1995 * xi + 1998 * xi1 + 2001 * xi2) % ((DWORD) pow(2, 35) - 849);

	xi2 = xi1;
	xi1 = xi;
	xi = xnext;

	return xnext;
}
