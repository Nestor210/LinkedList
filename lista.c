#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *nxt; 
}typeNodo,*nodo;

typedef struct linkedlist{
    nodo head;
}linkedlist,*list;

nodo createNode( int data ){
	
	nodo nuevo = (nodo) malloc(sizeof(typeNodo));
	nuevo -> value = data;
	nuevo -> nxt = NULL;
	
	return nuevo;
}

list createList(){
	
	list lista = (list) malloc(sizeof(linkedlist));
	lista -> head = NULL;
	
	return lista; 
	
}

bool empty( list lista ){
	
	if( lista -> head == NULL){
		return true;
	}
	return false;
}

int size(list lista){
	int counter = 0;
	nodo aux = lista -> head;
	while(aux != NULL){
		counter ++;
		aux = aux -> nxt;
	}
	return counter;
}

void insertFront(int data, list lista){
	
	nodo nuevoNodo = createNode( data );
	nuevoNodo -> nxt = lista -> head;
	lista -> head = nuevoNodo;
	
}

void insertLast(int data, list lista){
	
	nodo nuevoNodo = createNode( data );
	nodo aux = lista -> head;
	while( aux -> nxt != NULL ){
		aux = aux -> nxt;
	}
	aux -> nxt = nuevoNodo;
}

void insert(int data, int position, list lista){
	
	if( position <= size(lista) ){
		
		nodo nuevoNodo = createNode(data);
		nodo aux = lista -> head;
		for(int i = 2; i < position; i++){
			aux = aux -> nxt;
		}
		nuevoNodo -> nxt = aux -> nxt;
		aux -> nxt = nuevoNodo;
	}
	
}

int findElement(int data, list lista){
	
	if( !empty(lista) ){
		nodo aux = lista -> head;
		int position = 1;
		while( aux -> value != data && aux -> nxt != NULL){
			aux = aux -> nxt;
			position++;
		}
		return position;
	}
	return NULL;
}

int deleteFront(list lista){
	
	if( !empty(lista) ){
		
		int data = lista -> head -> value;
		nodo aux = lista -> head;
		aux = aux -> nxt;
		free(lista -> head);
		lista -> head = aux;
		return data;
	}
	return 0;
}

int deleteLast(list lista){
	
	if( !empty(lista) ){
		
		nodo aux = lista -> head;
		//el siguiente del siguiente debe ser el nulo 
		while(aux -> nxt -> nxt != NULL){
			aux = aux -> nxt;
		}
		//ontenemos el valor del siguiente 
		int data = aux -> nxt -> value;
		//guardamos en una variable el nodo a eliminar
		nodo eliminado = aux -> nxt;
		//que el nodo actual apunte a null
		aux -> nxt = NULL;
		//liberamos el espacio de memoria del nodo eliminado
		free(eliminado);
		return data;
	}
	return 0;
}

int eliminar(int position, list lista){
	if( !empty(lista) && position <= size(lista)){
		nodo aux = lista -> head;
		for(int i = 2; i < position; i++){
			aux = aux -> nxt;
		}
		int data = aux -> nxt -> value;
		nodo eliminado = aux -> nxt;
		aux -> nxt = aux -> nxt -> nxt;
		free(eliminado);
		return data;
	}
}

void insertDespuesde( int val,int data, list lista ){
	
	nodo nuevoNodo = createNode(data);
	nodo aux = lista -> head;
	while( aux -> nxt != NULL ){
		if( aux -> value == val ){
			nuevoNodo -> nxt = aux -> nxt;
			aux -> nxt = nuevoNodo;
			break;
		}
		aux = aux -> nxt;
	}
}

void insertAntesde( int val,int data, list lista ){
	
	nodo nuevoNodo = createNode(data);
	nodo aux = lista -> head;
	while( aux -> nxt -> nxt != NULL ){
		if( aux -> nxt -> value == val ){
			nuevoNodo -> nxt = aux -> nxt;
			aux -> nxt = nuevoNodo;
			break;
		}
		aux = aux -> nxt;
	}
}

void showList( list lista ){
	
	nodo aux = lista -> head;
	while( aux  != NULL ){
		printf("%i" ,aux -> value);
		printf(" ");
		aux = aux -> nxt;
	}
}

int first(list lista){
	
	nodo aux = lista -> head;
	return aux -> value;
	
}

int last(list lista){
	
	nodo aux = lista -> head;
	while( aux -> nxt != NULL ){
		aux = aux -> nxt;
	}
	return aux -> value;
}

int main()
{
	list prueba = createList();
	
	printf("-------------------------------\n");
	if( empty(prueba) ){
		printf("nice la funcion empty si funciona\n");
	}
	printf("-------------------------------\n");
	
	printf("\n");
	
	printf("-------------------------------\n");
	insertFront(4,prueba);
	printf("la lista solo tiene un elemento\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	insertFront(2,prueba);
	printf("Agregamos un valor al inico (insertFront)\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	insertLast(3,prueba);
	printf("Agregamos un valor al final (insertLast)\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	insert(5,2,prueba);
	printf("Agregamos el 5 en la posicion 2\n");
	showList(prueba);
	printf("\n");
	insert(9,4,prueba);
	printf("Agregamos el 9 en la posicion 4\n");
	showList(prueba);
	printf("\n");
	insert(7,3,prueba);
	printf("Agregamos el 7 en la posicion 3\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	
	printf("-------------------------------\n");
	printf("%i",deleteFront(prueba));
	printf(" es el valor que ha sido eliminado (deleteFront)\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf("%i",deleteLast(prueba));
	printf(" es el valor que ha sido eliminado (deleteLast)\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf("%i",eliminar(3,prueba));
	printf(" eliminamos el valor en la posicion 3\n");
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf( "%i", size(prueba) ); printf(" = tamaño de la lista (size)\n");
	printf( "%i", first(prueba) ); printf(" = primer elemento de la lista (first)\n");
	printf( "%i", last(prueba) ); printf(" = ultimo elemento de la lista (last)\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf( "encontrar la posicion en la que se encuentra 7 \n" );
	printf("%i", findElement(7,prueba) );
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf( "insertar 8 despues de 7 \n" );
	insertDespuesde( 7,8,prueba );
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");
	
	printf("-------------------------------\n");
	printf( "insertar 2 antes de 8 \n" );
	insertAntesde( 8,2,prueba );
	showList(prueba);
	printf("\n");
	printf("-------------------------------\n");
	printf("\n");

    return 0;
}
