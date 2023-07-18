#include <chrono>

#include "inpaint.h"

int main(int argc, char const *argv[])
{
	auto start = std::chrono::system_clock::now();
	if (argc != 3) {
		std::cout << "请输入图片路径！！！" << std::endl;
		return -1;
	}

	if (MyIpaint(argv[1], atoi(argv[2])) < 0)
		return -1;

	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Time to inpaint a image using radiu(" << argv[2] << ") spend "
                  << duration.count()  << " ms\n";
	return 0;
}
