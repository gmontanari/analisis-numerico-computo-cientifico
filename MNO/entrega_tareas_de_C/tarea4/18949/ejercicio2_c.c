/*
 * ejercicio2.c
 *
 *  Created on: Mar 2, 2017
 *      Author: Javier Quiroz
 */
#include <stdio.h>
#include <string.h>

#define MAXLINEA 1000 /*máximo tamaño de una línea*/


/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/
int obtenlinea(void);
void copia(void);



/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n'; i++)
        linea[i] = c;
    if(c == '\n'){
        linea[i] = c;
        i++;
    }
    linea[i]='\0'; //este caracter es necesario para almacenar strings
    return i;
}



/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia_con_i(void){
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(linea_max[i] != '\0' ){
        linea_max[i] = linea[i] ;
        i++;
    }
    linea_max[i] = '\0'; //asegura que la cadena tenga un terminador
}



/*
*
*   c) Modifica la función copia para que no use break pero todavía debe de usar el índice i.
*
+
*
*/





int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia_con_i();
        }
    if( max  > 0)
        printf("%s", linea_max);
return 0;
}


