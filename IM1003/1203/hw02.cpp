#include<iostream>
#include<cmath>

using namespace std;
int max(double x[]);
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
	int shape();
	double area();
}; 


int Triangle::shape(){
	double e[3];
	e[0] = pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2);
	e[1] = pow((p3.x - p2.x),2) + pow((p3.y - p2.y),2);
	e[2] = pow((p1.x - p3.x),2) + pow((p1.y - p3.y),2);
	int m = max(e);
	double other = 0;
	for (int i = 0 ; i < 3 ; i++){
//		cout << e[i]; 
		if(i != m){
			other += e[i];
		}
	}
	if (other > e[m]){
		return 0;
	}
	else if(other == e[m]){
		return 1;
	}
	return 2;
}

double Triangle::area(){
	typedef Point Vector;
	Vector v1, v2;
	v1.x = p2.x - p1.x;
	v1.y = p2.y - p1.y;
	v2.x = p3.x - p1.x;
	v2.y = p3.y - p1.y;
	return static_cast<double>(abs((v1.x * v2.y) - (v1.y * v2.x)))/2.0;
}

int max(double x[]){
	double max = 0;
	int m = 0;
	for(int i = 0 ; i < 3 ; i++){
		if(x[i] > max){
			max = x[i];
			m = i;
		}
	}
	return m;
}

int main(){
	Triangle input;
	cin >> input.p1.x >> input.p1.y >> input.p2.x >> input.p2.y >> input.p3.x >> input.p3.y;

	cout << input.shape() << "," << input.area();
	
	
	return 0;
}
