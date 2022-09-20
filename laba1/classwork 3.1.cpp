#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
class Point
{
public:
	unsigned long long const x, y;
	Point(unsigned long long x, unsigned long long y) : x(x), y(y) {}
	Point minx(Point const& rha) const
	{
		return Point(rha.x < x ? rha.x : x, y);
	}
	Point miny(Point const& rha) const
	{
		return Point(rha.y < y ? rha.y : x, y);
	}
	Point maxx(Point const& rha) const
	{
		return Point(rha.x > x ? rha.x : x, y);
	}
	Point maxy(Point const& rha) const
	{
		return Point(rha.y > y ? rha.y : x, y);
	}
	void print() const
	{
		std::cout << x  << " " << y << std::endl;
	}

};
class Rectangle
{
public:
	unsigned long long x, y;
	Rectangle(unsigned long long const x, unsigned long long const y) : x(x), y(y) {}
	Rectangle(Point const& p) : x(p.x), y(p.y) {}
	Rectangle& operator +(Rectangle const& rha) const
	{
		Rectangle sum = Rectangle(std::max(rha.x, this->x), std::max(rha.y, this->y));
		return sum;
	}
	Rectangle& operator *(Rectangle const& rha) const
	{
		Rectangle sum = Rectangle(std::min(rha.x, this->x), std::min(rha.y, this->y));
		return sum;
	}
	void print()
	{
		std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
	}

};
int main()
{
	std::string expression;
	std::string exprcln;
	std::getline(std::cin, expression);
	int sum = 0;
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] != ' ')
		{
			sum++;
		}
	}
	for (int i = 0; i < expression.length(); i++)
	{
		if (expression[i] != ' ')
		{
			exprcln += expression[i];
		}
	}
	int counter = 0;
	int rigcount = 0;
	int a1 = 0;
	int a2 = 0;
	if (sum > 0)
	{

		Rectangle sr = Rectangle((int)exprcln[1], (int)exprcln[3]);
		int flag = 0;
		for (int i = 0; i < exprcln.length(); i++)
		{
			if (exprcln[i] == '*')
			{	
				while (exprcln[i - counter - 2] != ',')
				{
					a2 += ((int)exprcln[i - counter - 2] - (int)'0') * pow(10,rigcount);
					exprcln[i - counter - 2] = ' ';
					counter++;
					rigcount++;
				}
				 exprcln[i - counter - 2] = ' ';
				 counter++;
				 rigcount = 0;
				while (exprcln[i - counter - 2] != '(')
				{
					a1 += ((int)exprcln[i - counter - 2] - (int)'0') * pow(10, rigcount);
					exprcln[i - counter - 2] = ' ';
					counter++;
					rigcount++;
				}
				exprcln[i - counter - 2] = ' ';
				sr = Rectangle(a1, a2);
				counter = 0;
				rigcount = 0;
				exprcln[i - 1] = ' ';
				exprcln[i] = ' ';
				exprcln[i + 1] = ' ';
				a1 = 0;
				a2 = 0;
				while (exprcln[i + counter + 2] != ',')
				{
					a1 += ((int)exprcln[i + counter + 2] - (int)'0') * pow(10, rigcount);
					exprcln[i + counter + 2] = ' ';
					counter++;
					rigcount++;
				}
				exprcln[i + counter + 2] = ' ';
				counter++;
				rigcount = 0;
				while (exprcln[i + counter + 2] != ')')
				{
					a2 += ((int)exprcln[i + counter + 2] - (int)'0') * pow(10, rigcount);
					exprcln[i + counter + 2] = ' ';
					rigcount++;
					counter++;
				}
				rigcount = 0;
				sr = sr*Rectangle(a1, a2);
				a1 = sr.x; a2 = sr.y;
				while (a2 != 0)
				{
					exprcln[i + counter + 1] = (char)(a2 % 10 + '0');
					a2 = a2 / 10;
					counter--;
				}
				exprcln[i + counter + 1] = ',';
				counter--;
				while (a1 != 0)
				{
					exprcln[i + counter + 1] = (char)(a1 % 10 + '0');
					a1 = a1 / 10;
					counter--;
				}
				exprcln[i + counter + 1] = '(';
				
			}
			


		}
		sum = 0;
		expression = exprcln;
		exprcln = "";
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] != ' ')
			{
				sum++;
			}
		}
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] != ' ')
			{
				exprcln += expression[i];
			}
		}
		sr = Rectangle((int)exprcln[1] - (int)'0', (int)exprcln[3] - (int)'0');
		for (int i = 0; i < exprcln.length(); i++)
		{
			if (exprcln[i] == '+')
			{
				counter = 0;
				rigcount = 0;
				while (exprcln[i + counter + 2] != ',')
				{
					a1 += ((int)exprcln[i + counter + 2] - (int)'0') * pow(10, rigcount);
					counter++;
					rigcount++;
				}
				counter++;
				rigcount = 0;
				while (exprcln[i + counter + 2] != ')')
				{
					a2 += ((int)exprcln[i + counter + 2] - (int)'0') * pow(10, rigcount);
					rigcount++;
					counter++;
				}
				rigcount = 0;
				sr =sr + Rectangle(a1, a2);
			}
		}
		sr.print();
	}
	Point a = Point(5, 6);
	Rectangle b = Rectangle(a);
	Point a11 = Point(11, 4);
	Rectangle b1 = Rectangle(a11);
	Rectangle ex = Rectangle(0 ,0);
	ex = b * b1;
	return 0;
}