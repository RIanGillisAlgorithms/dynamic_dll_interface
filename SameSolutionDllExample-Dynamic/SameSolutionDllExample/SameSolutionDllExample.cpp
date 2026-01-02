#include <iostream>
#include "dlfcn.hpp"
#include "../SharedInterface/IFibonacci.h"


typedef IFibonacci* (*CREATOR_FUNCTION)();

void DoFibonacci(std::string dllToLoad)
{
	// Load the DLL that contains the Fibonacci class implementation.
	void* dll_handle = dlopen(dllToLoad.c_str(), RTLD_LAZY);
	if (!dll_handle) {
		std::cerr << "Cannot load DLL: " << dlerror() << std::endl;
		return;
	}
	// Get the factory function to create Fibonacci instances.
	CREATOR_FUNCTION create_fibonacci =
		(CREATOR_FUNCTION)dlsym(dll_handle, "create_fibonacci");

	if (!create_fibonacci) 
	{
		std::cerr << "Cannot load symbol create_fibonacci: "
			<< dlerror() << std::endl;
		dlclose(dll_handle);
		return;
	}

	// Create an instance of the Fibonacci class.
	IFibonacci* fibonacci = create_fibonacci();
	if (!fibonacci) 
	{
		std::cerr << "Failed to create Fibonacci instance." << std::endl;
		dlclose(dll_handle);
		return;
	}

	// Initialize a Fibonacci relation sequence.
	// start with 2,3 to handle the multiplicative fib in Dll2
	fibonacci->fibonacci_init(2, 3);

	// Write out the sequence values until overflow.
	do 
	{
		std::cout << fibonacci->fibonacci_index() << ": "
			<< fibonacci->fibonacci_current() << std::endl;
	} while (fibonacci->fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci->fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;

	// Clean up.
	delete fibonacci;
	dlclose(dll_handle);
}

int main()
{
	DoFibonacci("Dll1.dll");
	std::cout << "-----------------------" << std::endl;
	DoFibonacci("Dll2.dll");
	return 0;
}