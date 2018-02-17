#include <iostream>

using namespace std;
class Node{
	public: //DECLARA��O DE TODOS ATRIBUTOS E METODOS PULBICOS
		int valor;  //VALOR ENCAPSULADO NO 'NO'
		Node* next; //PONTEIRO QUE APONTA PARA O NO SEGUINTE
		
		//OBSERVE O POLIMORFISMO PARA DECLARAR 2 CONSTRUTORES;
		
		Node(int entrada){ //CONSTRUTOR DA CLASSE 'Node'
			valor = entrada; //INSERI NO ATRIBUTO 'valor' A 'entrada'
			next = NULL; //PARA N�O TER QUE SEMPRE DEPOIS DE CRIAR UM NO APONTAR PARA NULO JA FAZ LOGO O 'next' SER NULO AQUI
		}
		Node(){ //APENAS EXEMPLO DE COMO SERIA O POLIMORFISMO, ESSE CONSTRUTOR � INULTIL
			valor = 0;
		}
};
class Lista{
	public:
		Node* head; //O PONTEIRO QUE FICA SEMPRE NO INICIO DA LISTA
		Node* tail; //O PONTEIRO QUE FICA SEMPRE NO FINAL DA LISTA
		
		Lista(){
			head = NULL; //COMO A LISTA EST� VAZIA HEAD E TAIL APONTAM PARA 'NULL'
			tail = NULL;
		}
};

/*PARA PODER MANIPULAR A LISTA TEMOS QUE PASSAR COMO REFERENCIA UMA LISTA E UM VALOR
 NESSE CASO PARA QUANDO O METO FOR CRIAR UM 'Node' NOVO RECEBER ESSE VALOR*/  
void inserir_na_frente(Lista* l, int valor_do_no){
	Node* novo = new Node(valor_do_no); //PARA INSTACIAR UM OBJETO EU USO UM PONTEIRO QUE VAI GUARDAR A REFERENCIA DESSE OBJETO(BASICAMENTE COMO NO JAVA)

	if(!l->head){ //USANDO A REFERENCIA DA LISTA 'l' PASSADA POR REFERENCIA NOS PARAMETOS UTILIZA-SE '->' PARA ACESSAR 
				// O CAMPO DESEJADO, NESSE CASO O HEAD. ENT�O VERIFICAMOS SE O HEAD EST� VAZIO
				
		l->head = novo; //CASO A LISTA ESTEJA VAZIA ESSE SER� O PRIMEIRO ELEMENTO, ENT�O FA�O 'head' E 'tail' APONTAR PARA ELE
		l->tail = novo; 
	}else{
		novo->next = l->head; //CASO MINHA LISTA N�O ESTEJA VAZIA FA�O O 'next' DO NOVO ELEMENTO APONTAR PARA O HEAD
		l->head = novo;        //E DEPOIS FA�O O 'head' APONTAR PARA ELE FAZENDO DELE O PRIMEIRO ELEMENTO
	}
}

//MESMO ESQUEMA PARA INSERIR ULTIMO
void inserir_atras(Lista* l,int valor_do_no){
	Node* novo = new Node(valor_do_no);
	if(!l->head){ //VERIFICA SE EST� VAZIA
		l->head = novo; //SE TIVER FAZ 'head' e 'tail' APONTAR PRA ELE
		l->tail = novo;
	}else{
		l->tail->next = novo; //AQUI PODE SER MEIO CONFUSO; 'l' � UMA LISTA, NESSA LISTA(QUE � UM PONTEIRO PARA OBJETO) EU TENHO 2 ATRIBUTOS 'head' e 'tail'
		l->tail = novo;		  //MAS ELES S�O PONTEIROS PARA O TIPO 'Node' PORQUE TEM QUE APONTAR PARA OS ELEMENTOS DO INICIO E DO FINAL DA LISTA
							  //ENT�O PARA ACESSAR O CAMPO DE 'valor' OU O CAMPO 'next' TEM QUE USAR DUAS '->' A PRIMEIRA DA LISTA PARA ACESSAR SEU 'tail'
							  //E A SEGUNDO DO TAIL PARA ACESSAR O SEU 'next', E DAI VAMOS FAZER O 'next' DO ULTIMO ELEMENTO APONTO PARA O NOVO
	}	
}

//COMO S� VAI PERCORRER A LISTA S� PRECISA PASSAR ELA NO PARAMENTRO
void exibir_elementos(Lista* l){
	Node* auxiliar = l->head; //O PONTEIRO AUXILIAR PARA PERCORRER A LISTA SEM TIRAR O 'head' DO LUGAR
	cout << "Lista: " << endl;
	while(auxiliar){
		cout << auxiliar->valor << endl; //PRINTA O VALOR DO ELEMENTO
		auxiliar = auxiliar->next; //FAZ O AUXILIAR 'PULAR' PARA O PROXIMO ELEMENTO
	}
	cout << "Fim." << endl;
}

//MESMO ESQUEMA PADR�O, S� QUE AGORA O VALOR VAI SER O ELEMENTO QUE A GENTE QUER
bool buscar_elemento(Lista* l,int procurado){
	if(!l->head){ //VERIFICO SE A LISTA TA VAZIA PRA N�O DA PAU NO PROGRAMA
		cout << "Lista vazia." << endl;
		return false;
	}
	Node* auxiliar = l->head;
	while(auxiliar || (auxiliar->valor != procurado) ) auxiliar = auxiliar->next; //LA�O PARA PERCORRER A LISTA TODA, ELE S� PARA EM DUAS CONDI��ES:
	//																			  //CHEGAR NO FIM DA FILA OU O VALOR SER IGUAL. ISSO DIMINUI AS ITERA��ES DE IF DENTRO DO WHILE
	if(auxiliar->valor == procurado){ //VERIFICA SE O MOTIVO DA SAIDO DO LAA�O WHILE FOI A IGUALDADE ENTRE OS VALORES SE SIM PRINTA E RETORNA TRUE
		cout << "Elemento encontrado." << endl;
		return true;
	}else{ //CASO ELE N�O SEJA O VALOR PROCURADO RETORNA FALSE
		cout << "Elemento n�o encontrado." << endl;
		return false;
	}
}

//COMO VAI EXCLUIR APENAS O PRIMEIRO N�O PRECISA DO VALOR APENAS DA LISTA
void excluir_primeiro(Lista* l){
	if(!l->head){
		cout << "Lista vazia." << endl; // SE A LISTA TA VAZIA N�O TEM O QUE EXCLUIR
		return;
	}else{ //CASO A LISTA TENHA MAIS QUE UM ELEMENTO TEM QUE FAZER O 'head' APONTAR PRO SEU 'next' EXLCUINDO O ELEMENTO DA LISTA
		l->head = l->head->next;
	}	
}

//MESMA COISA DA EXCLUS�O DO PRIMEIRO ELEMENTO, MAS AGORA TEM QUE PERCORRER A LISTA PRA ACHAR O TAIL
void excluir_ultimo(Lista* l){
	if(!l->head){
		cout << "Lista vazia." << endl; //LISTA VAZIA N�O EXLCUI ELEMENTO
		return; //PARA SAIR DO METODO
	}
	Node* auxiliar = l->head; //PONTEIRO PARA PERCORRER A LISTA
	if(!l->head->next){ //SE A LISTA TIVER SO UM ELEMENTO, 'tail' e 'head' APONTAM PARA NULO
		l->head = NULL;
		l->tail = NULL;
		cout << "Lista limpa, elemento excluido." << endl;
	}else{
		while(auxiliar->next != l->tail) auxiliar = auxiliar->next; //PERCORRE A LISTA ATE CHEGAR NO ELEMENTO ANTERIOR A 'tail'
		l->tail = auxiliar; //FAZ TAIL APONTAR PARA O ELEMENTO DE TR�S
		l->tail->next = NULL; //FAZENDO O NEXT DE 'tail' SER NULL EXCLUI O ULTIMO ELEMENTO
		cout << "Elemento excluido." << endl;
	}
}
//AGORA TEM QUE PASSAR O VALOR PARA PUDER BUSCAR QUAIS ELEMENTOS SERAO EXCLUIDOS
void excluir_aparicao(Lista* l, int procurado){
	if(!l->head){
		cout << "Lista vazia." << endl; //LISTA VAZIA...
		return;
	}

	if(!l->head->next && l->head->valor == procurado){
		l->head =NULL;
		l->tail =NULL;
		cout << "Lista limpa, elemento excluido." << endl;
		return;
	}else{
		cout << "Unico elemento n�o � o procurado"; << endl;
		return
	}
}
int main(){
	
}
