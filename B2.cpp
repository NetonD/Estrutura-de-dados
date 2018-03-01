#include <iostream>

using namespace std;

class Node{
	public:
		int valor;
		Node* next;
		Node(int entrada){
			valor = entrada;
			next = NULL;			
		}	
};

class Lista{
	public:
		Node *head;
		Node *tail;
		
		Lista(){
			head = tail = NULL;
		}							
}


int main(){
	
	Lista* l = new Lista();
	return 0;
}
