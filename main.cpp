#include<iostream>
#include<math.h>

using namespace std;

const float PI = 3.141592653f;
const int SIZE = 9;
const int SUB_SIZE = 3;

class Shape
{
public:
	virtual float area() = 0;
	virtual void show() = 0;
};

class Triangle : public Shape
{
private:
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
public:
	Triangle(float x1, float y1, float x2, float y2, float x3, float y3) 
	{
		this->x1 = x1;
		this->x2 = x2;
		this->x3 = x3;
		this->y1 = y1;
		this->y2 = y2;
		this->y3 = y3;
	};

	float area()
	{
		float a, b, c, p;
		a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
		c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
		p = (a + b + c) / 2;
		return sqrt(p * (p - a)*(p - b)*(p - c));
	}

	void show()
	{
		cout << "Triangle:" << x1 << "," << y1 << ";"
			<< x2 << ',' << y2 << ';'
			<< x3 << ',' << y3 << " area:"<<area()<<endl;
	}
};

class Rectangle : public Shape
{
private:
	float x;
	float y;
	float w;
	float h;
public:
	Rectangle(float x, float y, float w, float h) 
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	};

	float area()
	{
		return abs(x - w) * abs(y - h);
	}

	void show()
	{
		cout << "Rectangle:" << x << "," << y << ","
			<< w << ',' << h << " area:"<<area()<<endl;
	}
};

class Circle : public Shape
{
private:
	float x;
	float y;
	float r;
public:
	Circle(float x, float y, float r) 
	{
		this->x = x;
		this->y = y;
		this->r = r;
	};

	float area() 
	{
		return PI * r * r;
	};

	void show()
	{
		cout << "circle:" << x << "," << y << ","<<r
			<<" area:"<< area()<<endl;
	}
};

void show_title_input()
{
	cout<<"Please input:" << "t:triangle    "
		<< "c:circle    " << "r:rectangle    "
		<< "others to quit" << endl;
}

void show_title_output()
{
	cout << "Please input:" << "t:show triangle    "
		<< "c:show circle    " << "r:show rectangle    "
		<<"a:all show"<< "others to quit" << endl;
}

void eatline(char ch)
{
	while (ch = getchar() != '\n') 
		continue;
}

void main()
{
	Shape *p_shape[SIZE] = { NULL };

	int pos_tri = 0;
	int pos_cri = 3;
	int pos_rec = 6;
	int index_tri = 0;
	int index_cri = pos_cri;
	int index_rec = pos_rec;
	int index = 0;
	float a, b, c, d, e, f;
	char ch;

	show_title_input();

	while (((ch = getchar()) == 't')
		|| (ch == 'c') || (ch == 'r'))
	{
		if ((index_rec == SIZE) && (index_tri == pos_cri)
			&&(index_cri >= pos_rec))
		{
			cout << "memory full" << endl;
			break;
		}

		switch (ch)
		{
		case 't':
			if (index_tri >= pos_cri)
			{
				cout << "triangle memory full" << endl;
				break;
			}
			cout << "please input x1,y1,x2,y2,x3,y3" << endl;
			cin >> a >> b >> c >> d >> e >> f;
			p_shape[index_tri++] = new Triangle(a, b, c, d, e, f);
			break;
		case 'c':
			if (index_cri >= pos_rec)
			{
				cout << "circle memory full" << endl;
				break;
			}
			cout << "please input x,y,r" << endl;
			cin >> a >> b >> c;
			p_shape[index_cri++] = new Circle(a, b, c);
			break;
		case 'r':
			if (index_rec >= SIZE)
			{
				cout << "rectangle memory full" << endl;
				break;
			}
			cout << "please input x,y,w,h" << endl;
			cin >> a >> b >> c >> d;
			p_shape[index_rec++] = new Rectangle(a, b, c, d);
			break;
		}

		show_title_input();
		eatline(ch);
	}
	eatline(ch);
	show_title_output();

	while (((ch = getchar()) == 't')
		|| (ch == 'c') || (ch == 'r') || (ch == 'a'))
	{
		switch (ch)
		{
		case 't':
			for (int i = pos_tri; i < pos_cri; i++)
			{
				if (p_shape[i] == NULL)
				{
					break;
				}
				p_shape[i]->show();
			}
				
			break;
		case 'c':
			for (int i = pos_cri; i < pos_rec; i++)
			{
				if (p_shape[i] == NULL)
				{
					break;
				}
				p_shape[i]->show();
			}

			break;
		case 'r':
			for (int i = pos_rec; i < SIZE; i++)
			{
				if (p_shape[i] == NULL)
				{
					break;
				}
				p_shape[i]->show();
			}

			break;
		case 'a':
			for (int i = pos_tri; i < SIZE; i++)
			{
				if ((p_shape[i] == NULL) && (i < pos_cri))
				{
					i = pos_cri;
				}
				else if ((p_shape[i] == NULL) && (i < pos_rec))
				{
					i = pos_rec;
				}
				else if (p_shape[i] == NULL)
				{
					break;
				}
				p_shape[i]->show();
			}

			break;
		}

		show_title_input();
		eatline(ch);
	}
}
