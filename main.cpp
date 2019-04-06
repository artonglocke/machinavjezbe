#include <iostream>
#include <string>

int main()
{
	int number = 5;
	int& tracker = number;
	int* ptr = &number;
	std::string* stringptr;
	std::string someWord = "Nesto";
	stringptr = &someWord;
	int** doubleptr = &ptr;

	number = 9;
	std::cout << "Hello world" << std::endl;
	std::cout << "number: " << number << std::endl;
	std::cout << "number: " << tracker << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "stringptr: " << stringptr << std::endl;
	
	std::cout << "derefference stringptr: " << *stringptr << std::endl;
	*stringptr = "nesto drugo";

	std::cout << "derefference stringptr take 2: " << *stringptr << std::endl;
	std::cout << "doubleptr ptr address: " << *doubleptr << std::endl;
	std::cout << "doubleptr ptr address: " << **doubleptr << std::endl;


	std::cin.get();
}