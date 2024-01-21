// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

// TODO 11: Include TutorialConfig.h

int main(int argc, char* argv[])
{
	if (argc < 2) {
	// TODO 12: Create a print statement using Tutorial_VERSION_MAJOR
	//          and Tutorial_VERSION_MINOR
	std::cout << "Usage: " << argv[0] << " number" << '\n';
	return 1;
	}

	// 在 VS Code 中设置该文件的编码为 UTF-8 with BOM 可以解决中文输出乱码的问题。
	// MSVC 输出 __cplusplus 总是 199711，需要在 CMake 中额外进行配置。
	std::cout << "C++ 版本为：" << __cplusplus << '\n';
	
	

	// convert input to double
	// TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
	const double inputValue = std::stod(argv[1]);

	// calculate square root
	const double outputValue = sqrt(inputValue);
	std::cout << "The square root of " << inputValue << " is " << outputValue
			<< std::endl;
	return 0;
}
