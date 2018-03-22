#include <iostream>

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
				for(y=2;y<10;y++){
					if(y<4) matriz[x][y]='o';
					else if(y>6&y<9) matriz[x][y] = 'o';
				}
				x++;
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
	can->sorrir(); 
	can->update();
}
