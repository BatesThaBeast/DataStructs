/*
/*
Class:			Timer
Author:			Bjarne Stroustrup
Description:	This class is used to generate random doubles. This was taken from the C++ 4th edition book.
*/

#pragma once
#include <functional>
#include <random>
class Rand_double
{
public:
	Rand_double(double low, double high)
		:r(std::bind(std::uniform_real_distribution<>(low, high), std::default_random_engine())) {}

	double operator()() { return r(); }

private:
	std::function<double()> r;
};


