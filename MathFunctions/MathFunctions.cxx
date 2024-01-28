#include "MathFunctions.hpp"
#include <iostream>

/*
1. 	这个源文件用来生成一个数学库: my_math_func.
2. 	USE_MY_MATH 默认是没有定义的.
	当 CMakeLists.txt 中 USE_MY_MATH 为 ON 时，USE_MY_MATH 会被传进来.
*/

#ifdef USE_MY_MATH
#include "my_sqrt.hpp"
#else
#include <cmath>
#endif

namespace mathfunctions {

double sqrt(double x)
{
#ifdef USE_MY_MATH
	std::cout << "使用自己的开根号库！" << '\n';
	return detail::my_sqrt(x);
#else
	std::cout << "使用标准开根号库！" << '\n';
	return std::sqrt(x);
#endif
}

}
