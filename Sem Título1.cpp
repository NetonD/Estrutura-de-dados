#include <iostream>

using namespace std;

class Node{
	public:
		int valor;
		Node* next;
		Node* prev;
		Node(int entrada){
			valor = entrada;
			next = prev =  NULL;			
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
			
			while(aux->valor != valor_do_p && aux != NULL) aux = aux->next;
			if(aux->valor == valor_do_p) return aux;
			return NULL; 
			
		}
		
		void deletar(Node* p){
			if (p->valor < 7) {
				
				if(p == head){
					head =head->next;
					head->prev = NULL;
				}else if(p == tail){
					tail = tail->prev;
					tail->next = NULL;
				}else{
					p->prev->next = p->next;
					p->next->prev = p->prev;
				}
				
			}
		}
		
};


int main(){
	
	Lista* l = new Lista();
	return 0;
}
