#include <iostream>
#include <string>
#include <vector>

template <typename T>
T Sum(T a, T b)
{
	return a + b;
}

template<class _Ty>
class MyArray
{
public:
	_Ty table[];

	void push_back(_Ty element);
};


int main()
{
	int sumNumber = Sum(5, 7);
	float floatingSum = Sum(3.4f, 7.7f);

	std::cout << "Zbroj intova: " << sumNumber << std::endl;
	std::cout << "Zbroj floatova: " << floatingSum << std::endl;

	std::string first = "Maja";
	std::string second = "dev";
	std::string someString = Sum(first, second);

	std::cout << "Zbroj stringova: " << someString << std::endl;

	std::vector<std::string> vectorTemplate;

	std::cin.get();
}