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
	Alumno estudiante;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

Nodoptr crearnodo(AlumnoPtr)

AlumnoPtr crearAlumno(char*, int*, int*);
void imprimirLista(AlumnoPtr actualPtr);
void insertarAlumnoFinal(AlumnoPtr*, AlumnoPtr);
void insertarAlumnoOrdenado(AlumnoPtr*, AlumnoPtr);
int compararAlumnos(AlumnoPtr, AlumnoPtr);

int main(){
	
	AlumnoPtr cabecera = NULL;
	
	// insertarAlumnoOrdenado(&cabecera, crearAlumno("Rodriguez", "Couoh", "Orlando Isaias"));
	// imprimirLista(cabecera);}
	
	insertarAlumnoOrdenado(&cabecera, crearAlumno("Góngora Tun Jaqueline", "90", "3" ));
	imprimirLista(cabecera);
	insertarAlumnoOrdenado(&cabecera, crearAlumno("González Canul Mariana Estefanía", "91", "3"));
	imprimirLista(cabecera);
	insertarAlumnoOrdenado(&cabecera, crearAlumno("Kuh Esquivel Mauro Arif", "92", "3"));
	imprimirLista(cabecera);
	insertarAlumnoOrdenado(&cabecera, crearAlumno("Peniche Cruz Isaías", "0", "1"));
	imprimirLista(cabecera);
	insertarAlumnoOrdenado(&cabecera, crearAlumno("Rodriguez Couoh Orlando Isaias", "94", "3"));
	imprimirLista(cabecera);
	
	return 0;
}
	
	AlumnoPtr crearAlumno(char *nombre, int *creditos, int *semestre){
		
		AlumnoPtr nuevoAlumno = (Alumno*)malloc(sizeof( Alumno));
		
		nuevoAlumno -> nombre = strdup(nombre);
		nuevoAlumno -> creditos = strdup(creditos);
		nuevoAlumno -> semestre = strdup(semestre);
		
		nuevoAlumno -> enlace = NULL;
		
		return nuevoAlumno;
		
	}
		
		void imprimirLista(AlumnoPtr actualPtr){
			
			int i = 1;
			if(actualPtr == NULL){
				//Verificamos si la lista estÃ¡ vacÃ­a
				printf("La lista esta vacia\n");
				return;
				
			}
			else{
				
				printf("\nLista de alumnos\n");
				
				while(actualPtr != NULL){
					
					printf("%d.- %s %s %s\n", i , actualPtr -> nombre, actualPtr -> creditos, actualPtr -> semestre);
					actualPtr = actualPtr -> enlace;
					i++;
				}
			}
		}
			
			void insertarAlumnoFinal(AlumnoPtr *cabecera, AlumnoPtr nuevo){
				
				//Insertando el primer nodo
				if(*cabecera == NULL){
					
					*cabecera = nuevo;
				}else{
					//Insertando siempre al final
					AlumnoPtr actual = *cabecera;
					
					while (actual -> enlace != NULL)
					{
						actual = actual -> enlace;
					}
					
					actual -> enlace = nuevo;
					
				}
			}
				
				void insertarAlumnoOrdenado(AlumnoPtr *cabecera, AlumnoPtr nuevo){
					
					if(*cabecera == NULL){
						
						*cabecera = nuevo;
					}else{
						
						AlumnoPtr actual = *cabecera, anterior = NULL;
						
						while (actual -> enlace != NULL && compararAlumnos(nuevo, actual) > 0)
						{
							anterior = actual;
							actual = actual -> enlace;
						}
						
						if (actual == NULL || (actual!= NULL && anterior != NULL)){ //Inserta al final o enmedio
							nuevo -> enlace = anterior -> enlace;
							anterior -> enlace = nuevo;
							
						}else{ // insertando al principio
							nuevo -> enlace = actual;
							*cabecera = nuevo;	
						} 
						
						
					}
				}
					
					int compararAlumnos(AlumnoPtr nuevo, AlumnoPtr actual){
						
						int diferencia1 = strcmp(nuevo -> creditos, actual -> creditos);
						
						if(diferencia1 != 0){
							return diferencia1;
						}
						
						int diferencia2 = strcmp(nuevo -> semestre, actual -> semestre);
						
						if(diferencia2 != 0){
							return diferencia2;
						}
						
						int diferencia3 = strcmp(nuevo -> nombre, actual -> nombre);
						
						if(diferencia3 != 0){
							return diferencia3;
						}
						
						return 0;
						
					}
						
						

