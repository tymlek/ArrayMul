// ArrayMul.cpp

#include <iostream>
#include <chrono>
#include <stdexcept>
#include "ArrayMulAsm.h"
#include "ArrayMulC.h"

//-----------------------------------------------------------------------------

int main()
{
	const unsigned array_size = 100000;
	const unsigned loop_size = 10000;
	long array_of_int[array_size];
	unsigned multiplier = 5;
	auto t0 = std::chrono::steady_clock::now();
	auto t1 = std::chrono::steady_clock::now();

	try {
		// Fill an array with pseudorandom integers
		for (auto i = 0; i != array_size; ++i)
			array_of_int[i] = rand();

		// Test the Assembly language procedure
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != loop_size; ++i)
			array_mul_asm(array_of_int,multiplier,array_size);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased ASM time: "
				<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
				<<"ms.\n";

		// Test the C++ language procedure
		std::cout<<"Please wait...\n";

		t0 = std::chrono::steady_clock::now();

		for (auto i = 0; i != loop_size; ++i)
			array_mul_c(array_of_int,multiplier,array_size);

		t1 = std::chrono::steady_clock::now();

		std::cout<<"Elpased C++ time: "
				<<std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
				<<"ms.\n";
	}
	catch (std::exception& e) {
		std::cerr<<"An error has occurred:\n"<<e.what();
		return 1;
	}
	catch (...) {
		std::cerr<<"An error has occurred";
		return 2;
	}

	return 0;
}
