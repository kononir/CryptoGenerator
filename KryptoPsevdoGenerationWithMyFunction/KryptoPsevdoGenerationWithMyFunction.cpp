// KryptoPsevdoGenerationWithMyFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "windows.h"
#include "PsevdoGenerator.h"
#include <iostream>

#define BUFOUTSIZE 50000
#define X_SEED_1 156
#define X_SEED_2 1901
#define X_SEED_3 78345

int main()
{
	FILE * out;
	DWORD dwRand;
	DWORD * hMem = 0;
	try {
		fopen_s(&out, "rand_out.bin", "wb");
		if (out == NULL) return -1;
		hMem = (DWORD *) ::VirtualAlloc(0, BUFOUTSIZE * 4, MEM_COMMIT, PAGE_READWRITE);
		if (hMem) {
			PsevdoGenerator generator = PsevdoGenerator(X_SEED_1, X_SEED_2, X_SEED_3);
			for (int i = 0; i < BUFOUTSIZE; i++) {
				dwRand = generator.generate();
				memcpy(hMem + i, &dwRand, 4);
			}

			fwrite(hMem, 4, BUFOUTSIZE, out);
			::VirtualFree(hMem, 0, MEM_RELEASE);
		}
	}
	catch (...) {
		printf("\r\n\error create file");
	}
	fclose(out);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
