#pragma once
#ifndef IFIBONACCI_H
#define IFIBONACCI_H

class IFibonacci
{
public:
	virtual ~IFibonacci();
	virtual void fibonacci_init(
		const unsigned long long a, const unsigned long long b) = 0;
	virtual bool fibonacci_next() = 0;
	virtual unsigned long long fibonacci_current() = 0;
	virtual unsigned fibonacci_index() = 0;
};
IFibonacci::~IFibonacci() = default;

#endif