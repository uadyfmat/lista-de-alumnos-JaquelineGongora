#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno{
	
	char *nombre; 
	int creditos;
	int semestre;
	
};

typedef struct alumno Alumno;
typedef Alumno *AlumnoPtr;

struct nodo{
	AlumnoPtr estudiante;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

AlumnoPtr crearAlumno(char*, int, int);
NodoPtr crearnodo(AlumnoPtr);
void insertarNodo_creditos(NodoPtr*, NodoPtr);
void imprimirLista(NodoPtr);

int main(){
	
	AlumnoPtr cabecera = NULL;
	
	insertarNodo_creditos(&cabecera, crearnodo(crearAlumno("Góngora Tun Jaqueline", 90, 3 )));
	imprimirLista(cabecera);
	insertarNodo_creditos(&cabecera, crearnodo(crearAlumno("González Canul Mariana Estefanía", 91, 3)));
	imprimirLista(cabecera);
	insertarNodo_creditos(&cabecera, crearnodo(crearAlumno("Kuh Esquivel Mauro Arif", 92, 3)));
	imprimirLista(cabecera);
	insertarNodo_creditos(&cabecera, crearnodo(crearAlumno("Peniche Cruz Isaías", 0, 1)));
	imprimirLista(cabecera);
	insertarNodo_creditos(&cabecera, crearnodo (crearAlumno("Rodriguez Couoh Orlando Isaias", 94, 3)));
	imprimirLista(cabecera);
	
	return 0;
}
	
AlumnoPtr crearAlumno(char *nombre, int creditos, int semestre){
	AlumnoPtr nuevoAlumno = (AlumnoPtr)malloc(sizeof( Alumno));
		
	nuevoAlumno -> nombre = strdup(nombre);
	nuevoAlumno -> creditos = creditos;
	nuevoAlumno -> semestre = semestre;
		
	return nuevoAlumno;
		
}
NodoPtr crearnodo(AlumnoPtr nuevoAlumno){
	NodoPtr nodonuevo = (NodoPtr)malloc(sizeof(Nodo));
	nodonuevo -> estudiante = nuevoAlumno;
	nodonuevo-> siguiente = NULL;
	return nodonuevo;
}
void insertarNodo_creditos (NodoPtr* cabecera, NodoPtr nodonuevo){
	NodoPtr nodo_act, nodo_ant;
	
	if(*cabecera == NULL){
		*cabecera = nodonuevo;
	}
	else{
					
		nodo_act = *cabecera, nodo_ant = NULL;
		while(nodo_act != NULL && nodonuevo -> estudiante -> creditos < nodo_act -> estudiante -> creditos){
			nodo_ant == nodo_act;
			nodo_act = nodo_act -> siguiente;
		}
	}
				
	if(nodo_act == NULL || (nodo_act != NULL && nodo_ant != NULL)){
		nodonuevo -> siguiente = nodo_ant -> siguiente;
		nodo_ant -> siguiente = nodonuevo;
	}
	else{
		nodonuevo -> siguiente = nodo_act;
		*cabecera = nodonuevo;
	}
				
}
void imprimirLista(NodoPtr cabecera){
	int i = 1;
	if(cabecera == NULL){
		printf("Lista vacia\n");
	return;
	}
	else{
		printf("\nLista:\n");	
		while(cabecera != NULL){	
			printf("%d.- %s - %d - %d\n", i, cabecera-> estudiante -> nombre, cabecera-> creditos, cabecera -> estudiante-> semestre);
			cabecera = cabecera -> siguiente;
			i++;
		}
	}
}

