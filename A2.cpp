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
		
		Node* buscar(int valor_do_p){
			Node* aux = head;
			
			if(head == NULL) return NULL;
			
			while(aux->valor != valor_do_p && aux != tail) aux = aux->next;
			if(aux->valor == valor_do_p) return aux;
			return NULL; 
			
		}
		
		void deletar(Node* p){
			if (p->valor < 7) {
				
				if(p == head){
					head = head->next;
					tail->next = head;
				}else if(p == tail){
					Node* aux = head;
					
					while(aux->next != tail) aux = aux->next;
					tail = aux;
					tail->next = head;
				}else{
					Node* aux = head;
					
					while(aux->next != p) aux = aux->next;
					aux->next = aux->next->next;
					
				}
				
			}
		}
		
};


int main(){
	
	Lista* l = new Lista();
	return 0;
}
