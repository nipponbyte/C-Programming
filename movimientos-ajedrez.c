#include <stdio.h>
#include <stdbool.h>

#define COL 8
#define FIL 8
#define RES ' ' 
#define GRAF 'o' //Carácter gráfico en uso para 'pintar'.
#define IMP '*'


char fichaelegida;
char tablero[FIL+1][COL+1];
char opcion_sn;
int opcion;
int col;
int fil;
int coorfil;
int coorcol;
int mov_torre;
int mov_alfil_fil,mov_alfil_col;


int main(){

//Vaciar tablero
for(fil=1;fil<=FIL;fil++){
	for(col=1;col<=COL;col++){
		tablero[fil][col]=RES;
	}	
}	

do{
	//Cabecera del tablero
	printf("\n");
	for(col=1;col<=COL;col++){
		printf(" %i",col);
	}
	printf("\n");
	//Llonganissa
	for (fil=1;fil<=FIL;fil++){
		printf("%i",fil);
		for (col=1;col<=COL;col++){
			printf("%c ",tablero[fil][col]);
		}
		printf("%i\n",fil);
	}
	//Pie del tablero
	for(col=1;col<=COL;col++){
		printf(" %i",col);
	}
	
//---------------------------------------------------------------------------------
	
	//Menú
	printf("\n----------------------------------------\n");
	printf("\t\t  MENU\n");
	printf("----------------------------------------\n");
	printf("1- Mostrar los movimientos de una ficha\n");
	printf("2- Poner impedimento\n");
	printf("3- Borrar tablero\n");
	printf("4- Salir\n");
	printf("----------------------------------------\n");
	
	printf("Escoge una opcion del menu (1 - 4) ---> "); 
	scanf("%i",&opcion);
	
//--------------------------------------------------------------------------------	
	
	switch(opcion){
	
	//1- Mostrar los movimientos de una ficha
	
	case 1:
	
	//Borrar los anteriores movimientos (sin eliminar impedimentos)
	for(fil=1;fil<=FIL;fil++){
		for(col=1;col<=COL;col++){
			if(tablero[fil][col]!=IMP){
			tablero[fil][col]=RES;
			}
		}	
	}
	
		printf("Introduzca una ficha con la que quieras jugar\n");
		printf("(T)orre, (A)lfil, (D)ama, (R)ey o (C)aballo --> ");while(getchar()!='\n');
			scanf("%c",&fichaelegida); 
			
			
		printf("\nDime las coordenadas donde quieres colocar la ficha");
			printf("\nFila ---> ");while(getchar()!='\n');
				scanf("%i",&coorfil);
			printf("\nColumna ---> ");while(getchar()!='\n');
				scanf("%i",&coorcol);
				
	//----------------------------------------
	
		//Torre (T)
			if(fichaelegida=='t'||fichaelegida=='T'){
				tablero[coorfil][coorcol]='T';
				
				//Movimiento: Lado izquierdo
				for(mov_torre=coorcol-1;mov_torre>=1;mov_torre--){
					if(tablero[coorfil][mov_torre]!=IMP){
					tablero[coorfil][mov_torre]=GRAF;
					}
					else{
						break;
					}
				}
				//Movimiento: Lado derecho
				for(mov_torre=coorcol+1;mov_torre<=COL;mov_torre++){
					if(tablero[coorfil][mov_torre]!=IMP){
					tablero[coorfil][mov_torre]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Arriba 
				for(mov_torre=coorfil-1;mov_torre>=1;mov_torre--){
					if(tablero[mov_torre][coorcol]!=IMP){
						tablero[mov_torre][coorcol]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Abajo
				for(mov_torre=coorfil+1;mov_torre<=FIL;mov_torre++){
					if(tablero[mov_torre][coorcol]!=IMP){
						tablero[mov_torre][coorcol]=GRAF;
					}
					else{
						break;
					}
				}
			}
			
	//----------------------------------------	
	
		//Alfil (A)
			if(fichaelegida=='a'||fichaelegida=='A'){
				tablero[coorfil][coorcol]='A';
				
				//Movimiento: Superior Izquierdo
				for(mov_alfil_col=coorcol-1,mov_alfil_fil=coorfil-1;mov_alfil_fil>=1&&mov_alfil_col>=1;mov_alfil_fil--,mov_alfil_col--){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				//Movimiento: Superior Derecho
				for(mov_alfil_col=coorcol+1,mov_alfil_fil=coorfil-1;mov_alfil_fil>=1&&mov_alfil_col<=COL;mov_alfil_fil--,mov_alfil_col++){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Inferior Izquierdo
				for(mov_alfil_col=coorcol-1,mov_alfil_fil=coorfil+1;mov_alfil_fil<=FIL&&mov_alfil_col>=1;mov_alfil_fil++,mov_alfil_col--){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Inferior Derecho
				for(mov_alfil_col=coorcol+1,mov_alfil_fil=coorfil+1;mov_alfil_fil<=FIL&&mov_alfil_col<=COL;mov_alfil_fil++,mov_alfil_col++){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
			}
			
	//----------------------------------------		
			
		//Dama (D)
			if(fichaelegida=='d'||fichaelegida=='D'){
				tablero[coorfil][coorcol]='D';
				
				//Movimiento: Lado izquierdo
				for(mov_torre=coorcol-1;mov_torre>=1;mov_torre--){
					if(tablero[coorfil][mov_torre]!=IMP){
					tablero[coorfil][mov_torre]=GRAF;
					}
					else{
						break;
					}
				}
				//Movimiento: Lado derecho
				for(mov_torre=coorcol+1;mov_torre<=COL;mov_torre++){
					if(tablero[coorfil][mov_torre]!=IMP){
					tablero[coorfil][mov_torre]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Arriba 
				for(mov_torre=coorfil-1;mov_torre>=1;mov_torre--){
					if(tablero[mov_torre][coorcol]!=IMP){
						tablero[mov_torre][coorcol]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Abajo
				for(mov_torre=coorfil+1;mov_torre<=FIL;mov_torre++){
					if(tablero[mov_torre][coorcol]!=IMP){
						tablero[mov_torre][coorcol]=GRAF;
					}
					else{
						break;
					}
				}
				//Movimiento: Superior Izquierdo
				for(mov_alfil_col=coorcol-1,mov_alfil_fil=coorfil-1;mov_alfil_fil>=1&&mov_alfil_col>=1;mov_alfil_fil--,mov_alfil_col--){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				//Movimiento: Superior Derecho
				for(mov_alfil_col=coorcol+1,mov_alfil_fil=coorfil-1;mov_alfil_fil>=1&&mov_alfil_col<=COL;mov_alfil_fil--,mov_alfil_col++){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Inferior Izquierdo
				for(mov_alfil_col=coorcol-1,mov_alfil_fil=coorfil+1;mov_alfil_fil<=FIL&&mov_alfil_col>=1;mov_alfil_fil++,mov_alfil_col--){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
				
				//Movimiento: Inferior Derecho
				for(mov_alfil_col=coorcol+1,mov_alfil_fil=coorfil+1;mov_alfil_fil<=FIL&&mov_alfil_col<=COL;mov_alfil_fil++,mov_alfil_col++){
					if(tablero[mov_alfil_fil][mov_alfil_col]!=IMP){
					tablero[mov_alfil_fil][mov_alfil_col]=GRAF;
					}
					else{
						break;
					}
				}
			}
		
	//----------------------------------------		
			
		//Rey (R)
			if(fichaelegida=='r'||fichaelegida=='R'){
					tablero[coorfil][coorcol]='R';
				
				//Movimiento: Diagonal Superior Izquierdo
					if(tablero[coorfil-1][coorcol-1]!=IMP){
						tablero[coorfil-1][coorcol-1]=GRAF;
					}
				//Movimiento: Diagonal Superior Derecho
					if(tablero[coorfil-1][coorcol+1]!=IMP){
						tablero[coorfil-1][coorcol+1]=GRAF;
					}
				//Movimiento: Diagonal Inferior Izquierdo
					if(tablero[coorfil+1][coorcol-1]!=IMP){
						tablero[coorfil+1][coorcol-1]=GRAF;
					}
				//Movimiento: Diagonal Inferior Derecho
					if(tablero[coorfil+1][coorcol+1]!=IMP){
						tablero[coorfil+1][coorcol+1]=GRAF;
					}
				//Movimiento: Arriba
					if(tablero[coorfil-1][coorcol]!=IMP){
						tablero[coorfil-1][coorcol]=GRAF;
					}
				//Movimiento: Abajo
					if(tablero[coorfil+1][coorcol]!=IMP){
						tablero[coorfil+1][coorcol]=GRAF;
					}
				//Movimiento: Izquierda
					if(tablero[coorfil][coorcol-1]!=IMP){
						tablero[coorfil][coorcol-1]=GRAF;
					}
				//Movimiento: Derecha
					if(tablero[coorfil][coorcol+1]!=IMP){
						tablero[coorfil][coorcol+1]=GRAF;
					}
				}	
				
			
	//----------------------------------------		
			
		//Caballo (C)
			if(fichaelegida=='c'||fichaelegida=='C'){
					tablero[coorfil][coorcol]='C';
					
				//Movimiento: Superior Derecha (Ficha de arriba)
					if(tablero[coorfil-1][coorcol+2]!=IMP){
						tablero[coorfil-1][coorcol+2]=GRAF;
					}
					
				//Movimiento: Superior Derecha (Ficha de abajo)
					if(tablero[coorfil-2][coorcol+1]!=IMP){
						tablero[coorfil-2][coorcol+1]=GRAF;
					}
					
				//Movimiento Inferior Derecha (Ficha de arriba)
					if(tablero[coorfil+1][coorcol+2]!=IMP){
						tablero[coorfil+1][coorcol+2]=GRAF;
					}
					
				//Movimiento Inferior Derecha (Ficha de abajo)
					if(tablero[coorfil+2][coorcol+1]!=IMP){
						tablero[coorfil+2][coorcol+1]=GRAF;
					}
					
				//Movimiento: Superior Izquierda (Ficha de arriba)
					if(tablero[coorfil-1][coorcol-2]!=IMP){
						tablero[coorfil-1][coorcol-2]=GRAF;
					}
					
				//Movimiento: Superior Izquierda (Ficha de abajo)
					if(tablero[coorfil-2][coorcol-1]!=IMP){
						tablero[coorfil-2][coorcol-1]=GRAF;
					}
					
				//Movimiento Inferior Izquierda (Ficha de arriba)
					if(tablero[coorfil+1][coorcol-2]!=IMP){
						tablero[coorfil+1][coorcol-2]=GRAF;
					}
					
				//Movimiento Inferior Izquierda (Ficha de abajo)
					if(tablero[coorfil+2][coorcol-1]!=IMP){
						tablero[coorfil+2][coorcol-1]=GRAF;
					}
					
				}
	break;
	
	//2 - Poner impedimento
	
	case 2:
	
	//Borrar los anteriores movimientos (sin eliminar impedimentos)
	for(fil=1;fil<=FIL;fil++){
		for(col=1;col<=COL;col++){
			if(tablero[fil][col]!=IMP){
			tablero[fil][col]=RES;
			}
		}	
	}
	
	printf("\nDime las coordenadas donde quieres colocar un impedimento");
			printf("\nFila ---> ");while(getchar()!='\n');
				scanf("%i",&coorfil);
			printf("\nColumna ---> ");while(getchar()!='\n');
				scanf("%i",&coorcol);
			tablero[coorfil][coorcol]=IMP;
	
	
	break;
	
	//3 - Borrar tablero
	
	case 3:
	
	printf("\nDe verdad quieres eliminar el contenido del tablero? (S/n) -->"); while(getchar()!='\n');
		scanf("%c",&opcion_sn);
		if(opcion_sn=='S'||opcion_sn=='s'){
			for(fil=1;fil<=FIL;fil++){
				for(col=1;col<=COL;col++){
					tablero[fil][col]=RES;
				}	
			}	
			printf("\nEl contenido del tablero ha sido eliminado de forma satisfactoria!");
		}
	break;
	
	}

}
while(opcion!=4);
	printf("Sayounara, Baby!");
	return 0;
}

