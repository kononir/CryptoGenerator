#include "pch.h"
#include "PsevdoGenerator.h"

#define DENOMINATOR 34359737519


PsevdoGenerator::PsevdoGenerator(unsigned long long xi, unsigned long long xi1, unsigned long long xi2)
{
	this->xi = xi;
	this->xi1 = xi1;
	this->xi2 = xi2;
}

PsevdoGenerator::~PsevdoGenerator()
{
}

unsigned long long PsevdoGenerator::generate()
{
	unsigned long long xnext = (1995 * xi + 1998 * xi1 + 2001 * xi2) % DENOMINATOR;
	
	xi2 = xi1;
	xi1 = xi;
	xi = xnext;

	return xnext;
}
