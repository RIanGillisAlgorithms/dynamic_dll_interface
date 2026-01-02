#include "pch.h"
#include "Fibonacci.h"
#include <iostream>


Fibonacci::Fibonacci()
	: prev_(0), curr_(0), index_(0)
{
}
Fibonacci::~Fibonacci() = default;
void Fibonacci::fibonacci_init(
	const unsigned long long a, const unsigned long long b)
{
	std::cout<< "(Dll1)Fibonacci::fibonacci_init called with a="
		<< a << ", b=" << b << std::endl;
	prev_ = a;
	curr_ = b;
	index_ = 0;
}
bool Fibonacci::fibonacci_next()
{
	std::cout << "(Dll1)Fibonacci::fibonacci_next called." << std::endl;
	unsigned long long next = prev_ * curr_;
	// Check for overflow.
	if (next < curr_)
	{
		return false;
	}
	prev_ = curr_;
	curr_ = next;
	++index_;
	return true;
}
unsigned long long Fibonacci::fibonacci_current()
{
	return curr_;
}
unsigned Fibonacci::fibonacci_index()
{
	return index_;
}

