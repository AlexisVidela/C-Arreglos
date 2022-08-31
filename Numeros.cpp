#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 200


typedef struct{
	 int a[SIZE];
	 int cant;
}Arreglo;

void Poner(Arreglo *dato){
	int ii;
	//comienza
	ii=1;
	while(ii<7){
		printf("Ingrese un Numero :");
		scanf("%d",&dato->a[ii]);
		ii=ii+1;
	}
	dato->cant=ii-1;
	printf("Cantidad de elemntos en lista: %d \n",dato->cant);
}

void depurar(Arreglo dato,Arreglo *dato2){
	int ii,jj,kk;
	int Dif;
	 
	 //inciar
	 ii=1;
	 kk=2;
	 Dif=0;
	 dato2->a[ii] =dato.a[ii];
	 while(ii<=dato.cant){
	 	printf("-------ciclo %d -------\n,",ii);
	 	jj=1;
	 	while(jj<kk){
	 		printf("compara %d con ",dato.a[ii]);
	 		printf(" %d \n",dato2->a[jj]);
	 		
	 		
	 		if (dato.a[ii]==dato2->a[jj]){
	 			printf("son iguales \n");
	 			Dif=0;
	 			jj=kk;
			 }else{
			 	printf("son distintos \n");
			 	Dif=1;
			 }
	 		jj++;
		 } 

	if (Dif==1){
 		dato2->a[kk]=dato.a[ii];
 		printf("dato guardo %d ",dato.a[ii]);
 		printf("en lista depurada seccion: %d \n",kk);
 		kk=kk+1;
			}
	ii++;
	}
 	dato2->cant=kk-1;
}

void cant_rep(Arreglo dato,Arreglo dato2){
	//lexico local
	int ii,jj;
	int cantP;
	//incio
	jj=1;
	while(jj<=dato2.cant){
		cantP=0;
		ii=1;
		//printf("----entra-----\n");
		while(ii<=dato.cant){
			printf("----< Comparando >-----\n");
			//if(strcmp (dato2.a[jj].director,dato.a[ii].director)==0){
			//printf("compara %d ",dato2.a[jj]);
			//printf("con %d \n",dato.a[ii]);
			if(dato2.a[jj]==dato.a[ii]){
			//	printf("suma  :");
				cantP++;
			//	printf("%d  \n",cantP);
			}else{
			//	printf("no suma \n");
			}
			ii++;
		}
		printf("el numero %d ",dato2.a[jj]);
		printf("se repite %d  \n",cantP);
		jj++;
	}
}



void Mostrar(Arreglo dato2){
	int ii;
	//iniciar
	ii=1;
	while(ii<=dato2.cant){
		printf("Dato en lista : %d \n",dato2.a[ii]);
		ii=ii+1;
	}
	
}




int GuardadoAB (Arreglo dato2){
	//lexico local
	FILE *Arch_B;
	int ii;
	
	//inicio
	Arch_B = fopen("Numeros.txt","wb");//("Peliculas.dat","wb");
	if (Arch_B == NULL){
		return 0; 
	}
	
	ii=1;
	while(ii<=dato2.cant){
		printf("------escribiendo archivo------\n");
		fwrite(&dato2.a[ii],sizeof(Arreglo),1,Arch_B);
		printf("Dato guardado: %d \n",dato2.a[ii]);
		ii++;
	}
	fflush(Arch_B);
	fclose(Arch_B);
	return 1;
}

int verAB (Arreglo dato2){
	//lexico local
	FILE *Arch_B;
	int ii;
	//inicio
	Arch_B = fopen("Numeros.txt","rb");//("Peliculas.dat","rb");
	if (Arch_B == NULL){
		return 0; 
	}
	//printf("valor de %d \n",dato2.cant);
	for(ii=1;ii<=dato2.cant;ii++){
		printf("------leyendo archivo------\n");
		fread(&dato2.a[ii],sizeof(Arreglo),1,Arch_B);
		printf("Dato leido : %d  \n",dato2.a[ii]);
	}
	fclose(Arch_B);
	return 1;
}

Arreglo array1;
Arreglo array2;
int Menu;



int main()
{
	
	printf("____________________\n");
	printf("|                  |\n");
	printf("|                  |\n");
	printf("|                  |\n");
	printf("|                  |\n");
	printf("|__________________|\n");
	printf("-------------------opciones-------------------------\n");
	printf("---------------------------------------------------\n");
	printf("\n");
	printf("		[1]-Llenar lista\n");
	printf("		[2]-Depurar lista\n");
	printf("		[3]-Mostrar lista\n");
	printf("		[4]-Mostrar lista Depurada\n");
	printf("		[5]-Elementos repetidos\n");
	printf("		[6]-Guarda en Archivo Txt\n");
	printf("		[7]-Ver datos de Archivo txt\n");
	printf("		[0]-Salir\n");
	scanf("%i",&Menu);

while (Menu>0){	
if	(Menu==1){  Poner(&array1);}
if	(Menu==2){depurar(array1,&array2);}
if	(Menu==3) {Mostrar(array1);}
if	(Menu==4) {Mostrar(array2);}
if	(Menu==5) {cant_rep(array1,array2);}
if	(Menu==6) {GuardadoAB (array2);}
if	(Menu==7) {verAB(array2);}
if	(Menu==0){ return 0;}
printf("\n Eliga la siguiente Option :\n");
scanf("%i",&Menu);
}
return 0;
}
