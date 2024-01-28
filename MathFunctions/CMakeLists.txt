# 添加一个叫做 my_math_func 的库，编译的时候还可以将宏参数输入进去，见下面的 target_compile_definitions。
add_library(my_math_func MathFunctions.cxx)

# 设置 USE_MY_MATH 选项默认为 on，中间为描述信息。
option(USE_MY_MATH "Use tutorial provided math implementation" ON)
message(STATUS "USE_MY_MATH 是否打开:" "${USE_MY_MATH}")

if (USE_MY_MATH)
	target_compile_definitions(my_math_func PRIVATE "USE_MY_MATH")		# 将 USE_MY_MATH 宏变量传入 my_math_func 库
	add_library(my_sqrt_static_lib STATIC my_sqrt.cxx)					# 创建 my_sqrt_static_lib 静态库
	target_link_libraries(my_math_func PRIVATE my_sqrt_static_lib)		# 将 my_sqrt_static_lib 插入到 my_math_func
endif()

