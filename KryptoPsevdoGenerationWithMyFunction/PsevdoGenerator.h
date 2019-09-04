#pragma once

#include "windows.h"

class PsevdoGenerator
{
private:
	DWORD xi;
	DWORD xi1;
	DWORD xi2;

public:
	PsevdoGenerator(DWORD, DWORD, DWORD);
	~PsevdoGenerator();

	DWORD generate();
};

