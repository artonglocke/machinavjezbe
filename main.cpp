#include <iostream>
#include <string>
#include <vector>

//Polimorfizam radi samo na heapu!

//Zadatak:
// Napraviti interface Shape koji ima metode Area i Perimeter
// Napraviti klase Triangle, Circle, Square koji implementiraju interface Shape:
// Napraviti objekte svake podklase i ispisati Area i Perimeter!

class IShape
{
public:
	virtual double getPerimiter() = 0;
	virtual double getArea() = 0;
	virtual std::string getName() = 0;
};

class Triangle : public IShape
{
public:	
	float a, b, c;

	double getPerimiter()
	{
		return a + b + c;
	}

	double getArea()
	{
		double s = getPerimiter() / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}

	std::string getName()
	{
		return "Triangle";
	}

private:

};

class Circle : public IShape
{
public:
	float radius;

	double getPerimiter()
	{
		return 2 * radius * _Pi;
	}

	double getArea()
	{
		return radius * radius * _Pi / 2;
	}

	std::string getName()
	{
		return "Circle";
	}

private:
	float _Pi = 3.14;
};

class Rectangle : public IShape
{
public:
	float a, b;

	double getPerimiter()
	{
		return 2 * a + 2 * b;
	}

	double getArea()
	{
		return a * b;
	}

	std::string getName()
	{
		return "Rectangle";
	}
};

void printShapeInfo(IShape* shape)
{
	std::cout << "Shape name: " << shape->getName() << std::endl;
	std::cout << shape->getName() << " perimiter is: " << shape->getPerimiter() << std::endl;
	std::cout << shape->getName() << " area is: " << shape->getArea() << std::endl;
	std::cout << "===================================================" << std::endl;
}

int main()
{
	Rectangle* rect = new Rectangle();
	rect->a = 5.0f;
	rect->b = 7.0f;

	Circle* circle = new Circle();
	circle->radius = 10.0f;

	Triangle* triangle = new Triangle();
	triangle->a = 5.0f;
	triangle->b = 7.0f;
	triangle->c = 9.0f;

	std::vector<IShape*> shapes;
	shapes.push_back(rect);
	shapes.push_back(circle);
	shapes.push_back(triangle);

	for (IShape* it : shapes)
	{
		printShapeInfo(it);
	}

	std::cin.get();
}