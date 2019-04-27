#include <iostream>
#include <string>
#include <vector>

struct Vector3
{
	float x, y, z;
};

class Entity
{
public:
	Vector3 position;

protected:
	std::string name;
};

class Player : public Entity
{
public:

	Vector3 getPositiong()
	{
		return position;
	}

	std::string getName()
	{
		return name;
	}
};

class Enemy : public Entity
{
public:

};

int main()
{
	
	Entity entity = Entity();
	Vector3 vector = Vector3();
	Player player = Player();
	Enemy enemy = Enemy();
	player.position;
	enemy.position;
	

	std::cout << player.getName() << std::endl;
	std::cin.get();
}