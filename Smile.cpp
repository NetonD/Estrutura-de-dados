#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;


class Smile{
	public:
		char matriz[10][10];
		int x,y;
		Smile(){
			for(x=0;x<10;x++){
				for(y=0;y<10;y++)
					matriz[x][y]='\0';
			}
			x=2;
			while(x==2){
				for(y=1;y<10;y++){
					if(y<3) matriz[x][y]='o';
					else if(y>5&y<8) matriz[x][y] = 'o';
				}
				x++;
			}
			x=6;
			while(x==6){
				for(y=1;y<9;y++){
					matriz[x][y] = 'x';
				}
				x++;
			}
			
		}
		void clean(){
			for(x=0;x<10;x++){
				for(y=0;y<10;y++)
					matriz[x][y]='\0';
			}
		}
		void sorrir(){
			x=5;
			while(x<6){
				for(y=1;y<9;y++){
					if(y<=5) matriz[x+y-1][y]='x';
					else if(y<9) matriz[x-y+9][y] = 'x';
				}	
				x++;
			}
			matriz[5][9]='x';
			
		}
		void update(){
			for(x=0;x<10;x++){
				cout << endl;
				for(y=0;y<10;y++){
					cout << matriz[x][y];
				}
			}
		}
};

int main(){
	Smile* can = new Smile();
//	sleep(500);
	can->clean();
	can->sorrir(); 
	can->update();
	system("PAUSE");
}
