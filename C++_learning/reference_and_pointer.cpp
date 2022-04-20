#include <iostream>
#include <vector>

void change(std::vector<int> &test);

int main(int argc, char const *argv[])
{
	std::vector<int> test(3, 0);
	std::cout << test[0] << std::endl;
	change(test);
	std::cout << test[0] << std::endl;
	return 0;
}

void change(std::vector<int> &test){
	test[0] = 123;
}
