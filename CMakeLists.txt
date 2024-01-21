# TODO 1: Set the minimum required version of CMake to be 3.20
cmake_minimum_required(VERSION 3.20)

# TODO 2: Create a project named CMake_Official_Tutorial
project("CMake Official Tutorial")

# TODO 7: Set the project version number as 1.0 in the above project command

# TODO 6: Set the variable CMAKE_CXX_STANDARD to 11
#		  and the variable CMAKE_CXX_STANDARD_REQUIRED to True
# MSVC 中就算将 C++ 版本设置成 98 代码也能跑，就很奇怪……
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 通过以下设置，可以打印版本号了，但是不是很准确:
# 参考：https://blog.csdn.net/iceboy314159/article/details/101038217
if(MSVC)
	string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus")	# 注意字符串第一个空格，否则不起作用！
endif()


# TODO 8: Use configure_file to configure and copy TutorialConfig.h.in to
#         TutorialConfig.h

# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx
add_executable(First_Tutorial tutorial.cxx)

# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}
