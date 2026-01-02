#ifndef FIBONACCI_H
#define FIBONACCI_H

#ifdef DLL2_EXPORTS
#define Dll2_API __declspec(dllexport)
#else
#define Dll2_API __declspec(dllimport)
#endif

#include "../SharedInterface/IFibonacci.h"
class Fibonacci : public IFibonacci
{
public:
	Fibonacci();
	~Fibonacci() override;
	void fibonacci_init(
		const unsigned long long a, const unsigned long long b) override;
	bool fibonacci_next() override;
	unsigned long long fibonacci_current() override;
	unsigned fibonacci_index() override;
private:
	unsigned long long prev_;
	unsigned long long curr_;
	unsigned index_;
};
#endif // FIBONACCI_H

extern "C" __declspec(dllexport) // This is required
Fibonacci* create_fibonacci() {
	return new Fibonacci();
}