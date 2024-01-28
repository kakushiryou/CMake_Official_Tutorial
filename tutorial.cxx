// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.h"
#include "MathFunctions.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Usage: " << argv[0] << " number" << '\n';
		return 1;
	}

	// 在 VS Code 中设置该文件的编码为 UTF-8 with BOM 可以解决中文输出乱码的问题。
	// MSVC 输出 __cplusplus 总是 199711，需要在 CMake 中额外进行配置。
	std::cout << "C++ 版本为：" << __cplusplus << '\n';
	std::cout << "项目大版本号为：" << PROJECT_VERSION_MAJOR << '\n';
	std::cout << "项目小版本号为：" << PROJECT_VERSION_MINOR << '\n';
	std::cout << "项目中的字符串：" << PROJECT_STR << '\n';

	// 将输入转换为 double:
	// Replace atof(argv[1]) with std::stod(argv[1])
	const double inputValue = std::stod(argv[1]);

	// 计算平方差:
	const double outputValue = mathfunctions::sqrt(inputValue);
	std::cout << "The square root of " << inputValue << " is " << outputValue << '\n';
	return 0;
}
