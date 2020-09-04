#include<iostream>


using namespace std;

class Point{
	public:
		int x;
		int y;
		Point(int a, int b);
		Point();
};

Point::Point(){
	;
} 

Point::Point(int a, int b){
	x = a;
	y = b;
}

class Triangle{
	private:
		Point p1;
		Point p2;
		Point p3;
	public:
		Triangle(Point a , Point b , Point c);
		double area(); 
};

Triangle::Triangle(Point a , Point b , Point c){
	if(a.x != b.x && a.x != c.x){
		if(static_cast<float>(a.y - b.y) / static_cast<float>(a.x - b.x) == static_cast<float>(a.y - c.y) / static_cast<float>(a.x - c.x)){
			p1.x = 0;
			p1.y = 0;
			p2.x = 0;
			p2.y = 0;
			p3.x = 0;
			p3.y = 0;
		}
		else{
			p1.x = a.x;
			p1.y = a.y;
			p2.x = b.x;
			p2.y = b.y;
			p3.x = c.x;
			p3.y = c.y;
		}
	}
	else if(a.x == b.x){
		if(a.x == c.x){
			p1.x = 0;
			p1.y = 0;
			p2.x = 0;
			p2.y = 0;
			p3.x = 0;
			p3.y = 0;
		}
		else{
			if(a.y == b.y){
				p1.x = 0;
				p1.y = 0;
				p2.x = 0;
				p2.y = 0;
				p3.x = 0;
				p3.y = 0;
			}
			else{
				p1.x = a.x;
				p1.y = a.y;
				p2.x = b.x;
				p2.y = b.y;
				p3.x = c.x;
				p3.y = c.y;	
			}
		}
	}
	else{
		if((a.x == c.x && a.y == c.y)||(b.x == c.x && b.y == c.y)){
			p1.x = 0;
			p1.y = 0;
			p2.x = 0;
			p2.y = 0;
			p3.x = 0;
			p3.y = 0;
		}
		else{
			p1.x = a.x;
			p1.y = a.y;
			p2.x = b.x;
			p2.y = b.y;
			p3.x = c.x;
			p3.y = c.y;
		}
	}
} 

double Triangle::area(){
	double area = static_cast<double>(abs((p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x)))/2;
	if(area == 0){
		area = -1;
	}
	return area;
}

int main(){
	int input[7] = {0};
	for(int i = 0 ; i < 6 ; i++){
		cin >> input[i];
	}
	Point p1(input[0] , input[1]);
	Point p2(input[2] , input[3]);
	Point p3(input[4] , input[5]);
	Triangle t(p1 , p2 , p3);
	cout << t.area(); 
	
	return 0;
} 
