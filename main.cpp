#include <iostream>
#include <string>
#include <vector>
//Zadatak:
// Napraviti klasu osobe, sadrzava ime, prezime, adresu, oib
// Konstruktor treba inicijalizariti sve membere osim oiba
// Posebna metoda za setanje oiba, provjeriti jel valjan oib ili postojeci, te na temelju toga
// namjestiti oib
// Napraviti program koji omogucuje izradu novih osoba i ima mogucnost printanja svih unesenih
// osoba

class Person
{
public:
	Person(std::string givenName, std::string givenLastName, std::string givenAddress)
	{
		_name = givenName;
		_lastName = givenLastName;
		_address = givenAddress;
	}
	
	bool trySetSSN(std::string ssn)
	{
		if (_socialSecurityNumber != "")
		{
			std::cout << "Social Security Number is already set!" << std::endl;
			std::cout << "Persons SSN cannot be changed!" << std::endl;
			return true;
		}

		if (ssn.size() != 11)
		{
			std::cout << "Social Security Number is invalid! Wrong number of characters!" << std::endl;
			return false;
		}

		for (size_t i = 0; i < ssn.size(); i++)
		{
			char current = ssn[i];
			if (current < 48 || current > 57)
			{
				std::cout << "Social Security Number is invalid!" << std::endl;
				std::cout << "Character at index " << i << " is invalid!" << std::endl;
				return false;
			}
		}
		_socialSecurityNumber = ssn;
		return true;
	}

	void print()
	{
		std::cout << "Name: " << _name << " " << _lastName << std::endl;
		std::cout << "Address: " << _address << std::endl;
		std::cout << "Social Security Number: " << _socialSecurityNumber << std::endl;
	}

private:
	std::string _name, _lastName, _address, _socialSecurityNumber;
};

void displayPersons(std::vector<Person> persons)
{
	for (size_t i = 0; i < persons.size(); i++)
	{
		persons[i].print();
	}
}

void inputNewData(std::string message, std::string& data)
{
	std::cout << message << std::endl;
	std::cin >> data;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
}

void createPerson(std::vector<Person>& persons)
{
	std::string name, lastName, address;
	inputNewData("Enter new persons name: ", name);
	inputNewData("Enter new persons last name: ", lastName);
	inputNewData("Enter new persons address: ", address);

	Person person = Person(name, lastName, address);

	while (true)
	{
		std::string ssn;
		inputNewData("Enter new social security number: ", ssn);
		if (person.trySetSSN(ssn))
		{
			persons.push_back(person);
			return;
		}
	}

	
}



int main()
{
	std::vector<Person> persons;

	bool valid = true;
	while (valid)
	{
		std::cout << "What do you want to do: " << std::endl;
		std::cout << "1 - Add new person" << std::endl;
		std::cout << "2 - Exit" << std::endl;

		int choice;
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(10000, '\n');

		switch (choice)
		{
		case 1:
			createPerson(persons);
			break;
		case 2:
			valid = false;
			break;
		default:
			break;
		}
	}

	displayPersons(persons);
	

	std::cin.get();
}