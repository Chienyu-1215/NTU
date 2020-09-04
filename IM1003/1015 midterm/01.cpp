#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	int shape=0;
	if((abs(x1-x2)!=0&&abs(x1-x2)==abs(x3-x4))||(abs(x1-x4)!=0&&abs(x1-x4)==abs(x2-x3))||(abs(x1-x3)!=0&&abs(x1-x3)==abs(x2-x4))){
		if(abs(y1-y2)!=0&&(abs(y1-y2)==abs(y3-y4))||(abs(y1-y4)!=0&&abs(y1-y4)==abs(y2-y3))||(abs(y1-y3)!=0&&abs(y1-y3)==abs(y2-y4))){
			shape=2;
		}
	}
	if(abs(x1-x2)!=0&&abs(x1-x2)==abs(x3-x4)){
		if(abs(y1-y2)==abs(y3-y4)||abs(y1-y4)==abs(y2-y3)||abs(y1-y3)==abs(y2-y4)){
			if(abs(x1-x2)==abs(y1-y2)||abs(x1-x2)==abs(y1-y3)||abs(x1-x2)==abs(y1-y4)){
				shape=1;
			}
		}
	}
	if(abs(x1-x3)!=0&&abs(x1-x3)==abs(x2-x4)){
		if(abs(y1-y2)==abs(y3-y4)||abs(y1-y4)==abs(y2-y3)||abs(y1-y3)==abs(y2-y4)){
			if(abs(x1-x3)==abs(y1-y2)||abs(x1-x3)==abs(y1-y3)||abs(x1-x3)==abs(y1-y4)){
				shape=1;
			}
		}
	}
	if(abs(x1-x4)!=0&&abs(x1-x4)==abs(x3-x2)){
		if(abs(y1-y2)==abs(y3-y4)||abs(y1-y4)==abs(y2-y3)||abs(y1-y3)==abs(y2-y4)){
			if(abs(x1-x4)==abs(y1-y2)||abs(x1-x4)==abs(y1-y3)||abs(x1-x4)==abs(y1-y4)){
				shape=1;
			}
		}
	}
	cout<<shape;
	return 0;
}
