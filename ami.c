#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
typedef struct data{
	int dia,mes,ano;
}dt;
typedef struct amigo{
	int id_a;
	char ema[50];
	struct amigo *prox;
}amg;
typedef struct grup_a{
	int id_g;
	amg *ga;
	struct grup_a *prox;
}gra;
typedef struct destino{
	int id_d;
	char local[50],prov[50];
	struct destino *prox;
}dest;
typedef struct desloca{
	int id_dc;
	dest *desc;
	struct desloca *prox;	
}desloca;
typedef struct viagem{
	int id_v;
	desloca *deslo;
	gra *gru_a;
	dt ida,volta;
	struct viagem *prox;
}vgm;
/*Validações de cadastro*/
    int valida_d(dest *p,char*locl){
    	dest *d=p->prox;
    do
	{
    if(strcmpi(d->local,locl)==0)
	{
		return 0;
	}
	

	}while(d!=p->prox);
    		return 1;	
    }
	int valida_a(amg *k,char *vf)
	{
		amg *d=k->prox;
	do
	{
		if(strcmpi(d->ema,vf)==0)
		{
			return 0;
		}
		d=d->prox;   
     }while(d!=k->prox);
		return 1;
			
		}
	/*Cadastros Destino e Amigos*/
	dest *insert_d(dest *d,char *prv,char*loca){
	dest *tmp=(dest*)malloc(sizeof(dest));
	strcpy(tmp->prov,prv);
	strcpy(tmp->local,loca);
	if(d==NULL)
	{
		tmp->prox=tmp;
		puts("Cadastrado com Sucesso !");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
		return tmp;
	}else{
		if(valida_d(d,loca)==0)
		{
			puts("Cadastro Inválido!");
			 printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
			return d;
		}else{
		tmp->prox=d->prox;
		d->prox=tmp;
		puts("Cadastrado com Sucesso !");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
		return tmp;
		}
		
	}		
	}
amg *insert_a(amg *a,char *emai){
	
	amg *tmp=(amg*)malloc(sizeof(amg));
	strcpy(tmp->ema,emai);

if(a==NULL)
{ 
	tmp->prox=tmp;
	puts("Cadastrado com Sucesso !");
		printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
	return tmp;
	
}else{	
	if(valida_a(a,emai)==0)
  {
  	puts("Cadastro Inválido !\n Amigo já existente");
  	 printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
  	return a;
  }else
  {
	   tmp->prox=a->prox;
	  
	   a->prox=tmp;
	   puts("Cadastrado com sucesso");
	  printf("\n PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.\n");
	   return tmp;	
 }
  
}
 

}
dest *procura_d(dest *k,char *p,char *l){
		dest *aux;
		aux=k->prox;
		do{
			
			if((strcmpi(aux->prov,p)==0)&&(strcmpi(aux->local,l)==0))
				return aux;
			aux=aux->prox;
		}while(aux!=k->prox);
		return NULL;
	}

desloca *cria_d(desloca*p,char *provnc,char *locald,dest*ld){
	desloca *novo=(desloca*)malloc(sizeof(desloca));
	novo->desc=procura_d(ld,provnc,locald);
	if(novo->desc==NULL){
		return p;
	}else{
		if(p==NULL){
			novo->id_dc=1;
			novo->prox=novo;
			return novo;
		}else{
			novo->prox=p->prox;
			novo->id_dc=p->id_dc+1;
			p->prox=novo;
			return novo;
		}	
	}
	
	
}
void mostrar_de(desloca *k){
		desloca *aux;
		dest *auxd;
		aux=k->prox;
		auxd = aux->desc->prox;
		do{
			do{
				
				printf("%s/%s->",auxd->prov,auxd->local);
			    auxd=auxd->prox;
			}while(auxd!=aux->desc->prox);
			
		}while(aux!=k->prox);
	}
vgm *cr_via(vgm *a,dt data_id,dt data_vt){
	vgm *novo=(vgm*)malloc(sizeof(vgm));
	novo->gru_a=NULL;
	novo->deslo=NULL;
    novo->ida=data_id;
    novo->volta=data_vt;
    
    if(a==NULL){
    	novo->id_v=1;
    	novo->prox=novo;
    	return novo;
    }else{
    	novo->prox=a->prox;
    	novo->id_v=a->id_v+1;
    	a->prox=novo;
    	return novo;
    }
	
}
/*Funções de controle*/
void mostrar_a(amg *k){
		amg *aux;
		aux=k->prox;
		do{
			
			printf("Email: %s\n\n\n",aux->ema);
			aux=aux->prox;
		}while(aux!=k->prox);
	}
void mostrar_d(dest *k){
		dest *aux;
		aux=k->prox;
		do{
			
			printf("Provincia:%s\nLocalidade:%s\n\n",aux->prov,aux->local);
			aux=aux->prox;
		}while(aux!=k->prox);
	}

			


