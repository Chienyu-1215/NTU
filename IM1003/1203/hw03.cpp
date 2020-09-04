#include<iostream>

 #include<iostream>
#include<cmath>

using namespace std;
int max(double x[]);
int isTri(double x[], int m);
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
	double e[3];//get the length of each side of the triangle
	e[0] = pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2);
	e[1] = pow((p3.x - p2.x),2) + pow((p3.y - p2.y),2);
	e[2] = pow((p1.x - p3.x),2) + pow((p1.y - p3.y),2);
	int m = max(e);
	int a = isTri(e , m);
	if( a == -1){
		return -1;
	}
	double other = 0;//get the sum of the other two edges
	for (int i = 0 ; i < 3 ; i++){
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

int isTri(double e[], int m){
	double sum = 0;
	for (int i = 0 ; i < 3 ; i++){
		if(i != m){
			sum+= sqrt(e[i]);
		}
	}
	if(sum < sqrt(e[m])){
		return -1;
	}
	return 1;
}
int max(double x[]){//find the longest edge
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
	int xMax, yMax;
	int r[7] = {0};
	cin >> r[0] >> xMax >> yMax;
	srand(r[0]);
	
	for (int i = 1 ; i < 7 ; i++){
		r[i]=rand();
	}
	input.p1.x = r[1] % (xMax + 1);
	input.p1.y = r[2] % (yMax + 1);
	input.p2.x = r[3] % (xMax + 1);
	input.p2.y = r[4] % (yMax + 1);
	input.p3.x = r[5] % (xMax + 1);
	input.p3.y = r[6] % (yMax + 1);
	
	if (input.shape()!=-1){
		cout << input.shape() << "," << input.area();
	}	
	else{
		cout << -1;
	}
	
	return 0;
}
