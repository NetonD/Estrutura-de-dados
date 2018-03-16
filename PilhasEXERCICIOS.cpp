#include <iostream>

using namespace std;

class Node{
	public:
		string nome;
		Node* next;
		Node(string _nome){
			nome = _nome;
			next = NULL;
		}
};

class Stack{
	private:
		Node* topStack;
		int n_elem;
	
	public:
		
		Stack(){
			topStack = NULL;
			n_elem   = 0;
		}
		
		bool isEmpty(){
			return topStack = NULL;
		}
		
		void deflate(){
			topStack = NULL;
		}
		
		void push(string _nome){
			if(n_elem < 50){
				Node* novo = new Node(_nome);
				novo->next = topStack;
				topStack = novo;
				n_elem++;
			}else{
				cout << "Pilha cheia" << endl;
			}
		}
		
		void pop(){
			topStack = topStack->next;
			n_elem--;
			if(n_elem <= 25){
				cout << "Item com limite baixo. Favor solicitar compra!" << endl;
			}
		}
		
		void verify(){
			if(!topStack || n_elem < 25) cout << "Efetuar compra urgente! Estoque baixo ou vazio" << endl;
		}
		
		void mult_pop(int deal){
			while(deal!=0){
				pop();
				n_elem--;
				deal --;
			}
			if(n_elem < 25 || !topStack){
				cout << "Ratificando que seu estoque esta baixo ou vazio." << endl;
			}
		}
};



int main(){
	int x=0;
	Stack* pil = new Stack();
	while (x <60){
		pil->push("carro");
		x++;
	}
	pil->mult_pop(30);
}
