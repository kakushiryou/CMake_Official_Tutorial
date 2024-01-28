# 设置 CMake 最小版本号:
cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# 创建一个工程，并设置版本号:
project(CMake_Official_Tutorial VERSION 1.3)

# 设置 CXX 版本号:
set(CMAKE_CXX_STANDARD 20)				# MSVC 中就算将 C++ 版本设置成 98 代码也能跑，就很奇怪……
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 通过以下设置，可以在 MSVC 中打印版本号了，但是不是很准确:
# 参考：https://blog.csdn.net/iceboy314159/article/details/101038217
if(MSVC)
	string(APPEND CMAKE_CXX_FLAGS " /Zc:__cplusplus")	# 注意字符串第一个空格，否则不起作用！
endif()

# 传递有空格的字符串:
set(STR_TEST "Hello World from CMakeLists.txt!")		# 必须在 configure_file 的前面才起作用！

# 将 .h.in 的内容拷贝到 .h 中:
configure_file(TutorialConfig.h.in TutorialConfig.h)	# 注意头文件生成的地方！

# 把子文件夹添加进来:
add_subdirectory(MathFunctions)

add_executable(First_Tutorial tutorial.cxx)				# 生成可执行文件

# 用下述命令向可执行文件中添加链接库:
# 相当于命令行的 -lMathFunctions
target_link_libraries(First_Tutorial PUBLIC my_math_func)	# 问题：程序是怎么找到这个 my_math_func.lib 这个库文件的？


# 添加目标文件的搜索路径，相当于命令行的 -I ---
# 使用空格以防止文件名中有空格出现
target_include_directories(	First_Tutorial
							PUBLIC
							"${PROJECT_BINARY_DIR}"						# 设置可执行文件的头文件搜索路径为 ./build 
							"${PROJECT_SOURCE_DIR}/MathFunctions")		# 继续添加头文件路径，PROJECT_SOURCE_DIR 为项目第一层CMakeLists所在文件夹

message(STATUS "The PROJECT_BINARY_DIR is: ${PROJECT_BINARY_DIR}")
message(STATUS "${CMake_Official_Tutorial_VERSION_MAJOR}")				# 注意是项目的版本号而不是可执行文件的
message(STATUS "${CMake_Official_Tutorial_VERSION_MINOR}")
