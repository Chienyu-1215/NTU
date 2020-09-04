#include<iostream>
#include<cmath>

using namespace std;
struct Point
{
	int x;
	int y;
};

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
	double area();
}; 


double Triangle::area(){
	typedef Point Vector;
	Vector v1, v2;
	v1.x = p2.x - p1.x;
	v1.y = p2.y - p1.y;
	v2.x = p3.x - p1.x;
	v2.y = p3.y - p1.y;
	return static_cast<double>(abs((v1.x * v2.y) - (v1.y * v2.x)))/2.0;
}


int main(){
	Triangle input;
	cin >> input.p1.x >> input.p1.y >> input.p2.x >> input.p2.y >> input.p3.x >> input.p3.y;
	double area = input.area();
	cout << area;
	
	
	return 0;
}
