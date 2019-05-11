#include <iostream>
#include <string>
#include <vector>

//Polimorfizam radi samo na heapu!

//Zadatak:
// Napraviti interface Shape koji ima metode Area i Size
// Napraviti klase Triangle, Circle, Square koji implementiraju interface Shape:
// Napraviti objekte svake podklase i ispisati Area i Size!

class Human
{
public:
	int hands;
	int feet;
	int eyes;

	virtual void PrintType()
	{
		std::cout << "I am a human being!" << std::endl;
	}

	virtual int getNumberOfHands() = 0;

private:

};

class Male : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a male human being!" << std::endl;
	}

	int getNumberOfHands()
	{
		return hands;
	}
};

class Female : public Human
{
public:
	void PrintType()
	{
		std::cout << "I am a female human being!" << std::endl;
	}

	int getNumberOfHands()
	{
		return hands;
	}
};

int main()
{
	Male* maleObject = new Male();
	maleObject->hands = 2;
	maleObject->feet = 2;
	maleObject->eyes = 2;

	maleObject->PrintType();

	Female* femaleObject = new Female();
	femaleObject->PrintType();

	Human* humanObject = new Female();

	std::vector<Human*> humans;
	humans.push_back(maleObject);
	humans.push_back(femaleObject);
	//humans.push_back(humanObject);

	std::cout << "======================================" << std::endl;

	for (size_t i = 0; i < humans.size(); i++)
	{
		humans[i]->PrintType();
		std::cout << humans[i]->getNumberOfHands() << std::endl;
	}
	std::cin.get();
	
	delete femaleObject;
	delete maleObject;
}