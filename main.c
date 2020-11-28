#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>


typedef struct nodo{
    int numero ;
    struct nodo *sgte ;
}nodo ;
 typedef nodo *lista ;
 lista Agenda = NULL ;

void agregarD(lista *lista_donde_almacenara_los_datos, int dato_que_almacenara){
    lista aux,nuevo;
    nuevo =(lista) malloc(sizeof(nodo)) ;
    nuevo->numero = dato_que_almacenara;
    nuevo->sgte = NULL;

    aux = *lista_donde_almacenara_los_datos;
    if(aux == NULL)
        *lista_donde_almacenara_los_datos = nuevo;
    else{
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
}
void Mostrar(lista lista_donde_estan_almacenados_los_datos){
    lista p;
    p=lista_donde_estan_almacenados_los_datos;
    while(p != NULL){
        printf("Valor : %d \n",p->numero);
        p = p->sgte;
    }
}
 void agregarI(lista *lista_donde_almacenara_los_datos, int dato_que_almacenara){
    lista aux,nuevo; //lista nueva es un auxiliar que se llena y despues se coloca en la lista principal mediante los sgte(sgte)
    nuevo =(lista) malloc(sizeof(nodo)) ;
    nuevo->numero = dato_que_almacenara;
    nuevo->sgte = NULL;

    aux = *lista_donde_almacenara_los_datos;
    if(aux == NULL)
        *lista_donde_almacenara_los_datos = nuevo;
    else{
        nuevo->sgte = *lista_donde_almacenara_los_datos ;
        *lista_donde_almacenara_los_datos = nuevo ;
    }
}
void Eliminar_primero(lista *lista_donde_esta_almacenado_los_datos){
    lista aux;
    aux = *lista_donde_esta_almacenado_los_datos;
    if(aux!=NULL){
        *lista_donde_esta_almacenado_los_datos = aux->sgte;
        free(aux);
    }
}
int ContarNodos(lista lista_donde_estan_almacenados_los_datos){
    int contador = 0 ;
    lista aux ;
    aux = lista_donde_estan_almacenados_los_datos ;
    while(aux != NULL){
        contador++ ;
        aux = aux->sgte ;
    }
    return contador ;
}
bool Buscar(lista *lista_donde_esta_almacenado , int elemento_buscado){
    bool a = false ;
    lista aux ;
    aux = *lista_donde_esta_almacenado ;
    while(aux != NULL){
        if (aux->numero == elemento_buscado){
            a = true ;
            break ;
        }
        aux=aux ->sgte ;
    }
    return a ;
}
void Eliminar_Nodo_Cualquiera(lista *lista_donde_estan_almacenados_los_datos , int dato_a_eliminar){
    lista aux,aux2 ;
    aux = *lista_donde_estan_almacenados_los_datos ;
    aux2 = *lista_donde_estan_almacenados_los_datos ;
    if(aux->numero == dato_a_eliminar){
        *lista_donde_estan_almacenados_los_datos = aux->sgte ;
        free(aux) ;
    }
    else{
        while((aux->sgte)->numero != dato_a_eliminar){
            aux = aux->sgte ;
        }
        aux2 = aux->sgte ;
        aux->sgte = ((aux->sgte)->sgte) ;
        free(aux2) ;

    }
}
void Eliminar_ultimo(lista *lista_donde_esta_almacenado_los_datos){
    lista aux ;
    aux = *lista_donde_esta_almacenado_los_datos ;
    if(aux->sgte != NULL){
        while((aux->sgte)->sgte != NULL){
            aux = aux->sgte ;
        }
        free(aux->sgte) ;
        aux->sgte =NULL ;
    }
    else
       *lista_donde_esta_almacenado_los_datos = NULL ;
}

int main(){
    // Agregar por la derecha o al final
    printf("Agregar datos por la derecha:\n ");
    agregarD(&Agenda, 5);
    agregarD(&Agenda, 6);
    agregarD(&Agenda, 7);
    agregarD(&Agenda, 8);
    Mostrar(Agenda);

    // Agregar por la izquierda o al comienzo
    printf("\n\nAgregar datos por la izquierda:\n");
    agregarI(&Agenda, 4);
    agregarI(&Agenda, 3);
    agregarI(&Agenda, 2);
    agregarI(&Agenda, 1);
    Mostrar(Agenda);

    // Contar datos en la lista
    printf("\n\nLa lista contiene %i datos", ContarNodos(Agenda));

    // Eliminar primer dato de la lista
    Eliminar_primero(&Agenda);
    printf("\n\n");
    Mostrar(Agenda);

    // Eliminar último dato de la lista
    Eliminar_ultimo(&Agenda);
    printf("\n\n");
    Mostrar(Agenda);

    // Eliminar cualquier dato de la lista
    Eliminar_Nodo_Cualquiera(&Agenda, 5);
    printf("\n\n");
    Mostrar(Agenda);

    // Buscar un dato en la lista
    printf("\n\n%s", Buscar(&Agenda, 5) ? "El dato se encuentra en la lista" : "El dato no se encuentra en la lista");


    return 0;
}