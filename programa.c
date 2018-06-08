#include "ami.c"

//FILE *f =fopen("arq.txt","ab");
main(){
	char opcao;
	amg *primeiro=NULL;
	dest *pd=NULL;
	char emmm[50],loca[50],pro[50];
	desloca *dr=NULL;
	/*Loop infinito do menu enquanto for diferente 's'*/
	while(opcao !='s')
	{
		
	  printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     AMIGOS E VIAGENS");printf("\t\t\t      |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t       %c----------%c\t\t\t\t\n    ",201,187);
      printf("\t       |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <A>  Inserir Amigo                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <B>  Inserir Destino              |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <C>  Criar Viagem                 |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <D>  Cancelar Viagem              |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <E>  Desistir Viagem              |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <F>  Listar Viagem durante um ano |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <G>  Listar Viagem num intervalo  |\n"); 
      printf("   |-----------------------------------|\n");
      printf("   | <S>  Sair                         |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");
      fflush(stdin);
      opcao=getch();
     //setlocale(LC_ALL,"");
     switch(opcao)
     {
     	
     	case 'A':   
        case 'a':
        	fflush(stdin);
              system("cls");
              
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n\n\n",200,188);
              printf("Digite o email \n");
              gets(emmm);
              
              primeiro=insert_a(primeiro,emmm);
              mostrar_a(primeiro);
              getch();
			
		break;
		case 'B': 
        case 'b':
        	  fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n\n\n",200,188);
        	  printf("Digite a Provincia\n");
              gets(pro);
              printf("Digite a Localidade\n");
              gets(loca);
              pd=insert_d(pd,pro,loca);
              mostrar_d(pd);
              getch();
		break;
		case 'C':   
        case 'c':
        	fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n\n\n",200,188);
              printf("Digite a Provincia\n");
              gets(pro);
              printf("Digite a Localidade\n");
              gets(loca);
              dr=cria_d(dr,pro,loca,pd);
              mostrar_de(dr);
        	getch();
			
		break;
		case 'D':   
        case 'd':
        	
			
		break;
		case 'E':   
        case 'e':
        	
			
		break;
		case 'F':   
        case 'f':
        	
			
		break;
		case 'G':   
        case 'g':
        	
			
		break;
		case 'S':   
        case 's':
        
			opcao='s';	
			
		break;
		default:
			system("cls");
        break;
     	
     	
     	
     }
	}
	
	
}
