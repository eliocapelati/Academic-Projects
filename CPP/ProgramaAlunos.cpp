/*
	Author: Elio Capelati Jr
	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main();
int gravacao ();
int leitura ();
int query();

/*start function*/
int gravacao ()
{
    system("title grava e le arquivo");
    FILE *p;
    char nome[20],tele[10], opcao;
    
    
    p = fopen("dados.001","rt");
    
    if (p==NULL){
                 
                 printf("\n ....:Programa Dados Alunos:.....\n\n");
                 printf("\n arquivo nao existe...novo criado\n");
                 p= fopen("dados.001","wt");
                 if (p == NULL) return (-1);
                 }else{
                       printf("\t ....:Programa Dados Alunos:.....\n\n");
                       printf("\nlogado\n");
                       fclose(p);
                       p = fopen("dados.001", "at");
                       }
                while (1){
                      printf("\n<C A D A S T R O>\n\n\n\n");                      
                      printf("\nNome :");
                      scanf("%s", nome);
                      printf("\nTelefone :");
                      scanf("%s", tele); 
                
                 printf("\nconfirma gravar este registro? [s/n]:");
                 do{
                      opcao = getchar();
                      }while (tolower(opcao) != 's' && tolower(opcao) != 'n');
                      
                      if (tolower(opcao) == ' '){
                           fprintf(p, "%s %s\n", nome, tele);
                           printf("\n registro gravado");
                         }
                         
                         else{printf("\n registro nao gravado");
                              }
                              
                 printf("\ndeseja continuar gravando este registro? [s/n]:");
                   do{
                      opcao = getchar();
                      }while (tolower(opcao) != 's' && tolower(opcao) != 'n');
                      if (tolower(opcao) == 'n'){
                           printf("fim da gravacao");
                           break;}
                            
                            }                                                             
                                                                                                
                 fprintf(p,"%s %s \n",nome, tele);
                 
                                
                                                  
                 fclose(p);
                                    
                 main();
        
    

}
/*end function*/

/*start function*/
int leitura()
{
    FILE *p;
    char nome[20], tele[10];
    p = fopen("dados.001", "rt");
    if (p == NULL){
          printf("\n\n arquivo nao existe \ncriar com gravacao\n");
          return(-1);
          }
    while(!feof(p)){
          fscanf(p, "%s  %s", nome, tele);
          printf("%s %s\n", nome, tele);
          }
          fclose(p);
          system("pause>null");
          main();    
    
    
    }




/*end function*/

/*start function*/

int query()
{
    
    system("title ...:Ler Dados:...");
    FILE *p;
    char nome[20], tele[10];
    char s1[20];

    int achou =0;
    
    p = fopen("dados.001","rt");//modo read (leitura)
    
    if (p==NULL){
                 printf("\n arquivo nao existe...\n");
                 exit(0);
                 }
                
                                            
                 else{printf("\n Leitura de arquivo: Dados!\n\n\n");}
          
          
                printf("Digite  nome para Procura \n");
                scanf(" %s",s1);
                strlwr(s1);
                 
                  
                 while (!feof(p))
                 {
                   fscanf(p ,"%s %s",nome, tele);
               
               
                  if (strcmp(s1,nome)== 0)
                   {
                    strlwr(nome);
                   
                   printf("Nome:  %s  telefone:  %s\n\n\n",nome, tele);                       
                   achou =1;
                   break;
                   
                   }
                   }
                   if(achou ==0)
                   printf("\n\nArquivo nao localizado");
                 printf ("\n\nprograma completamente executado em :\n");
                 system ("date/t");
                 printf ("as: ");
                 system ("time/t");
                 


                 fclose(p);
                 printf("\n\n\nFim.....\n");
                 system("pause>null");
                 main();
        
    

}

/*end function*/

int main ()
{
    system("cls");
     system ("color 70");
     char opcao;
     printf("\n\n< P R O G R A M A      S I S T E M A     D E     C A D A S T R O >\n\n");
                       printf("\ndigite [g] para gravar, [l] para ler, e [b] para busca ou digite [s] para sair::\n");
                 do{
                      opcao = getchar();
                      }while (tolower(opcao) != 'g' && tolower(opcao) != 'l' && tolower(opcao)  != 'b' && tolower(opcao) != 's');
                      
                      if (tolower(opcao) == 'g'){
                         gravacao(); }                         
                      if (tolower(opcao) == 'l'){
                         leitura();
                                   }
                      if(tolower(opcao) == 'b'){
                         query();
                           }                     
                      if (tolower(opcao) == 's'){
                         system("exit");
                         }
     
      
     
     
     
     system("pause>null");
     }


