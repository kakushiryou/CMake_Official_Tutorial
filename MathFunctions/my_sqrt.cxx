#include "my_sqrt.hpp"

#include <iostream>

namespace mathfunctions {
namespace detail {

double my_sqrt(double x)
{
	if (x <= 0)
	{
		std::cout << "The input number must be greater than 0!" << '\n';
		return 0;
	}

	double result = x;

	// Do ten iterations:
	for (int i = 0; i < 10; ++i)
	{
		if (result <= 0)
		{
			result = 0.1;
		}
		double delta = x - (result * result);
		result = result + 0.5 * delta / result;
	}
	return result;
}

}
}
