%{
/* Secao prologo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern char * yytext;
extern char * yylex();
extern int numLinha;
extern FILE* yyin;
extern int erroOrigem;
void yyerror( char const *s);




typedef struct noArvorePilha
{
  struct dir *esq;
  struct dir *dir;
  char tipo[40];
  char id[40];
  int  escopo;
  int  pos;
  	
}noArvorePilha;

typedef struct pilha
{
    struct arvore   * pontArvore;
    struct pilha    * proximo;
}pilha;




void pesquisaPreOrdemPilha(noArvorePilha *raiz);
void inserirNoArvorePilha(noArvorePilha **raiz,char identificador[],char tipo[]);
void listar (pilha *top);
void inserir (pilha **top, char lexema[], char tipo[]);
Toperador* CriaOperador(TespecieOperador tipoOperador,  int linha, Toperador* filho1, Toperador* filho2, Toperador* filho3, Toperador* filho4, Toperador* filho5, char* lexema);

void percorreArvore(Toperador* raiz);
void obtemEspecieNoEnumLin(Toperador* no, char* nomeOperador);

pilha * topo = NULL;
Toperador* raiz;
char nomeOperador[200];
char a[34] =  {'l','e','x','P','r','o','g','r','a','m','a'};
char b[34] =  {'T','i','p','o'};
char c[34] =  {'l','e','x','I','D'};
char d[34] =  { 'D','e','c','l','V','a','r'};
char declFuncvar[34] =  {'N','o','D','e','c','l','F','u','n','c','V','a','r'};
char tipo[10];
char lex[80];	
int tok;
char inteiro[4] = {'i','n','t'};
char charr[5] = {'c','a','r'};
int escopo = 0;



%}
/* Secao de definicoes para o Bison 
 define os simbolos usados na gramatica e tipos dos valores
 semanticos associados a cada simbolo (terminal e não terminal)*/

%union{
    int nlinha;
    Toperador* Tpont;
    char * lexemaId;
}


%token id programa intconst carconst in car retorne leia escreva novalinha enquanto execute cadeiaCaracteres entao ou se senao igual diferente menorigual maiorigual e
       
%start Programa

%type<Tpont> DeclFuncVar DeclProg DeclVar DeclFunc ListaParametros ListaParametrosCont  Bloco ListaDeclVar Tipo ListaComando Comando Expr AssignExpr CondExpr OrExpr AndExpr EqExpr 		     DesigExpr AddExpr  MulExpr UnExpr LValueExpr PrimExpr ListExpr id intconst cadeiaCaracteres novalinha 

/* Pode haver mais de uma secao prologo e mais de uma secao de definicoes do Bison. 
   Estas secoes podem aparecer intercaladas entre si. Ver Secao 3.1.1 */

%%  /* Secao de regras - producoes da gramatica - Veja as normas de formação de produçoes na secao 3.3 do manual */



Programa    		:DeclFuncVar DeclProg		 			{raiz=CriaOperador(Prog ,numLinha,$1,$2,NULL,NULL,NULL, NULL);}
       			;

DeclFuncVar 		:Tipo id DeclVar';'DeclFuncVar 				{Toperador * aux1 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										 $$=CriaOperador(NoDeclFuncVar, numLinha, $1,aux1,$3,$5,NULL,NULL);}	
			|Tipo id '['intconst']' DeclVar';'DeclFuncVar		{$$=CriaOperador(NoDeclFuncVar, numLinha, $1,NULL,NULL,$6,$8, NULL);}
			|Tipo id DeclFunc DeclFuncVar				{Toperador * aux2 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										 $$=CriaOperador(NoDeclFuncVar, numLinha, $1,aux2,$3,$4,NULL, NULL);}
			| 							{$$=NULL;} 
			;

DeclProg    		: programa Bloco   					{Toperador * aux5 = CriaOperador(lexPrograma, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										  $$=CriaOperador(DeclProg, numLinha,aux5 ,$2,NULL,NULL,NULL, NULL);}	             		
       			;

DeclVar   		:',' id DeclVar 					{Toperador * aux = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										 $$=CriaOperador(DeclVar ,numLinha,$3,aux,NULL,NULL,NULL, NULL);} ///editar aqui
			|',' id '['intconst']' DeclVar				{$$=CriaOperador(DeclVar ,numLinha,$6,NULL,NULL,NULL,NULL, NULL);}        
			|       						{$$=NULL;}
			;

DeclFunc		:'('ListaParametros')' Bloco				{$$=CriaOperador(DeclFunc ,numLinha,$2,$4,NULL,NULL,NULL, NULL);}
			;	

ListaParametros 	:							{$$=NULL;} 
			|ListaParametrosCont					{$$=$1;}	
			;

ListaParametrosCont 	:Tipo id					  	{Toperador * aux7 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										 $$=CriaOperador(ListaParametrosCont ,numLinha,$1,aux7,NULL,NULL,NULL, NULL);}
			|Tipo id '['']'						{Toperador * aux8 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										$$=CriaOperador(ListaParametrosCont ,numLinha,$1,aux8,NULL,NULL,NULL, NULL);}
			|Tipo id','ListaParametrosCont				{Toperador * aux9 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										$$=CriaOperador(ListaParametrosCont,numLinha,$1,aux9,$4,NULL,NULL, NULL);}		
			|Tipo id'['']'','ListaParametrosCont			{Toperador * aux10 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										$$=CriaOperador(ListaParametrosCont ,numLinha,$1,aux10,$6,NULL,NULL, NULL);}	
			;


Bloco 			:'{' ListaDeclVar ListaComando '}'                      {$$=CriaOperador(Bloco,numLinha,$2,$3,NULL,NULL,NULL, NULL);}  
			|'{' ListaDeclVar '}'                                   {$$=$2;}      
			;

ListaDeclVar		: 							{$$=NULL;}
			|Tipo id DeclVar';' ListaDeclVar                        {Toperador * aux = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, $2);
										 $$=CriaOperador(ListaDeclVar ,numLinha,$1,aux,$3,$5,NULL, NULL);} //editar aqui
			|Tipo id '['intconst']' DeclVar';' ListaDeclVar		{$$=CriaOperador(ListaDeclVar ,numLinha,$1,NULL,NULL,$6,$8, NULL);}
			;

Tipo 			:in							{$$=CriaOperador(Tipo, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}		
			|car							{$$=CriaOperador(Tipo, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);} 
			;

ListaComando		:Comando                                                {$$=$1;}
			|Comando ListaComando					{$$=CriaOperador(ListaComando,numLinha,$1,$2,NULL,NULL,NULL, NULL);}
			;

Comando			:';'							{$$=NULL;}		
			|Expr';'					        {$$=$1;}	
			|retorne Expr';'					{$$=CriaOperador(Retorne,numLinha,$2,NULL,NULL,NULL,NULL, NULL);}
			|leia LValueExpr';'					{$$=CriaOperador(Leia,numLinha,$2,NULL,NULL,NULL,NULL, NULL);}		
			|escreva Expr';'					{$$=CriaOperador(Escreva,numLinha,$2,NULL,NULL,NULL,NULL, NULL);}	
			|escreva cadeiaCaracteres ';'			 	{$$=CriaOperador(Escreva,numLinha,NULL,NULL,NULL,NULL,NULL, yytext);}		
			|novalinha';'		            			{$$=CriaOperador(NovaLinha,numLinha,NULL,NULL,NULL,NULL,NULL, yytext);}					
			|se '('Expr ')' entao Comando                           {$$=CriaOperador(Se,numLinha,$3,$6,NULL,NULL,NULL, NULL);}		   
			|se '('Expr ')' entao Comando senao Comando		{$$=CriaOperador(Se,numLinha,$3,$6,NULL,NULL,NULL, NULL);
										$$=CriaOperador(Senao,numLinha,$8,NULL,NULL,NULL,NULL, NULL);}
			|enquanto '('Expr')' execute Comando			{$$=CriaOperador(Enquanto,numLinha,$3,$6,NULL,NULL,NULL, NULL);}
			|Bloco							{$$=NULL;}
			;

Expr			:AssignExpr					 	{$$=$1;}
			;


AssignExpr		:CondExpr						{$$=$1;}
			|LValueExpr'='AssignExpr				{$$=CriaOperador(Igual,numLinha,$1,$3,NULL,NULL,NULL, NULL);}	
			;

CondExpr		:OrExpr							{$$=$1;}
			|OrExpr '?' Expr ':' CondExpr				{$$=CriaOperador(Cond,numLinha,$1,$3,$5,NULL,NULL, NULL);}		    
			;

OrExpr			:OrExpr ou AndExpr					{$$=CriaOperador(Ou,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|AndExpr						{$$=$1;}
			;

AndExpr			:AndExpr 'e' EqExpr					{$$=CriaOperador(E,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|EqExpr							{$$=$1;}
			;

EqExpr			:EqExpr igual DesigExpr					{$$=CriaOperador(Igual,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|EqExpr diferente DesigExpr				{$$=CriaOperador(Diferente,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|DesigExpr						{$$=$1;}
			;

DesigExpr		:DesigExpr '<' AddExpr					{$$=CriaOperador(MenorQue,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|DesigExpr '>' AddExpr					{$$=CriaOperador(MaiorQue,numLinha,$1,$3,NULL,NULL,NULL, NULL);}	
			|DesigExpr maiorigual AddExpr				{$$=CriaOperador(MaiorIgual,numLinha,$1,$3,NULL,NULL,NULL, NULL);}	
			|DesigExpr menorigual AddExpr				{$$=CriaOperador(MenorIgual,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|AddExpr						{$$=$1;}
			;

AddExpr			:AddExpr '+' MulExpr					{$$=CriaOperador(Soma,numLinha,$1,$3,NULL,NULL,NULL, NULL);}					
			|AddExpr '-' MulExpr					{$$=CriaOperador(Sub,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|MulExpr						{$$=$1;}	
			;

MulExpr			:MulExpr '*' UnExpr					{$$=CriaOperador(Multi,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|MulExpr '/' UnExpr					{$$=CriaOperador(Div,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|MulExpr '%' UnExpr					{$$=CriaOperador(Resto,numLinha,$1,$3,NULL,NULL,NULL, NULL);}
			|UnExpr							{$$=$1;}
			;

UnExpr			:'-'PrimExpr						{$$=CriaOperador(Menos,numLinha,$2,NULL,NULL,NULL,NULL, NULL);}
			|'!' PrimExpr						{$$=CriaOperador(Dif,numLinha,$2,NULL,NULL,NULL,NULL, NULL);}	
			|PrimExpr						{$$=$1;}
			;

LValueExpr		:id '[' Expr ']'        				{$$=CriaOperador(LValueExpr,numLinha,$1,$3,NULL,NULL,NULL, NULL);}	
			|id                           			        {$$=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}                   
			;

PrimExpr		:id '(' ListExpr ')'					{$$=CriaOperador(PrimExpr,numLinha,NULL,$3,NULL,NULL,NULL, yytext);}
			|id '('')'						{$$=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
			|id '[' Expr ']'					{$$=CriaOperador(PrimExpr,numLinha,NULL,$3,NULL,NULL,NULL, yytext);}
			|id							{$$=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
			|carconst                       			{$$=CriaOperador(Carconst, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}  
			|intconst						{$$=CriaOperador(Intconst, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}                    
			|'(' Expr ')'						{$$=$2;}
			;

ListExpr		:AssignExpr						{$$=$1;}
			|ListExpr','AssignExpr					{$$=CriaOperador(ListExpr, numLinha , $1 , $3,NULL,NULL,NULL,  yytext);}  	
			;		





%% /* Secao Epilogo*/	



int main(int argc, char** argv){
   if(argc!=2)
        yyerror("Uso correto: ./simpleLang nome_arq_entrada");
   yyin=fopen(argv[1], "r");
   if(!yyin)
        yyerror("arquivo não pode ser aberto\n");
  
    yyparse();
    printf("\n---- Árvore abstrata ---- \n");
    percorreArvore(raiz);
    printf("\n---- Tabela de simbolos ---- \n");	
    pesquisaPreOrdemPilha(topo);
    printf("\n");
}

void yyerror( char const *s) {
    if(erroOrigem==0) /*Erro lexico*/
    {
        printf("%s na linha %d - token: %s\n", s, numLinha, yytext);
    }
    else
    {
        printf("Erro sintatico proximo a %s \n", yytext);
        printf(" - linha: %d \n", numLinha);
        erroOrigem=1;
    }
    exit(1);
}

void percorreArvore(Toperador * raiz){
    if(raiz){
        obtemEspecieNoEnumLin(raiz, nomeOperador);
	
        if (strcmp(nomeOperador,a) == 0){
	      inserir(&topo, NULL,NULL);
        }

	if (strcmp(nomeOperador,declFuncvar) == 0){
	      inserir(&topo, NULL,NULL);
        }  

	if (strcmp(nomeOperador,b) == 0){
	    strcpy (tipo,raiz->lexema);   	
        }

        if (strcmp(nomeOperador,c) == 0){
	    inserir(&topo,raiz->lexema,tipo);
        } 
	
	printf("nome do operador: %s  \n", nomeOperador);                                        
        
	percorreArvore(raiz->filho1);
        percorreArvore(raiz->filho2);
	percorreArvore(raiz->filho3);
        percorreArvore(raiz->filho4);
	percorreArvore(raiz->filho5);
    }
  
}

///Inserção na pilha de árvores
void inserir (pilha **top, char lexema[], char tipo[])
{
   
     if(lexema == NULL ){
	     pilha * novo;
	     noArvorePilha *raiz = NULL;
	     novo = (pilha *) malloc (sizeof(pilha));
             
	     if(novo == NULL){
		printf("Não tenho memória");
		exit(1);
	     }else {
		
	       if(*top == NULL){
		 novo->proximo = NULL;
	       }else{
		 novo->proximo = *top;
	       }
	       *top = novo;
	     }
	(*top)->pontArvore = raiz;	
        
	
     }
     if(lexema != NULL)
     inserirNoArvorePilha(&(*top)->pontArvore, lexema, tipo);
        
}


///Inserção de um nó de uma árvore da pilha
void inserirNoArvorePilha(noArvorePilha **raiz,char identificador[],char tipo[])
{

  if (identificador != NULL && tipo != NULL){
	  if(*raiz == NULL)
	    {
		noArvorePilha *aux = (noArvorePilha *) malloc (sizeof(noArvorePilha));
                if(tipo != NULL && identificador != NULL){		
			strcpy (aux->tipo, tipo);
			strcpy (aux->id, identificador);
		}
		aux->dir = aux->esq = NULL;
		*raiz = aux;
		//printf("Elemento %s do tipo %s foi inserido com sucesso! \n", identificador, tipo);
		return;
	    }
	    if (identificador > (*raiz)-> id){
		inserirNoArvorePilha(&(*raiz)->dir,identificador, tipo);
		return;
	    }
	    if (identificador < (*raiz)-> id){
		inserirNoArvorePilha(&(*raiz)->esq, identificador , tipo);
		return;
	    }

            
	    printf("Elemento %s ja existe na arvore. \n", identificador);
  }
}

Toperador* CriaOperador(TespecieOperador tipoOperador,  int linha, Toperador* filho1, Toperador* filho2, Toperador* filho3, Toperador* filho4, Toperador* filho5, char* lexema){
    
    Toperador* aux = (Toperador*) malloc(sizeof(Toperador));
    if (aux){
        aux->tipoOperador=tipoOperador;
        aux->linha=linha;
        aux->filho1=filho1;
        aux->filho2=filho2;
	aux->filho3=filho3;
	aux->filho4=filho4;
	aux->filho5=filho5;
	
        if(lexema){ 
	    aux->lexema= (char*)malloc(strlen(lexema)+1);
            strcpy(aux->lexema, lexema);
        }
        return(aux);
    }
    return(NULL);
}

void obtemEspecieNoEnumLin(Toperador* no, char* nomeOperador){
    switch(no->tipoOperador){
		
		case lexPrograma:
		     sprintf(nomeOperador,"lexPrograma");
		     break;
		case lexID:
		     sprintf(nomeOperador,"lexID");
		     break;		
		case Prog:
		     sprintf(nomeOperador,"Prog - Lin: %d", no->linha);
		     break;
		case DeclProg:
		     sprintf(nomeOperador,"DeclProg - Lin: %d", no->linha);
 		     break;	
		case NoDeclFuncVar:
		     sprintf(nomeOperador,"NoDeclFuncVar");
		     break;
		case DeclVar:
		     sprintf(nomeOperador,"DeclVar");
		     break;
		case DeclFunc:
		     sprintf(nomeOperador,"DeclFunc - Lin: %d", no->linha);
		     break;
		case ListaParametrosCont:
		     sprintf(nomeOperador,"ListaParametrosCont - Lin: %d", no->linha);
		     break;
		case Bloco:
		     sprintf(nomeOperador,"Bloco");
		     break;
		case ListaDeclVar:
		     sprintf(nomeOperador,"ListaDeclVar");
		     break;
		case Enquanto:
		     sprintf(nomeOperador,"Enquanto - Lin: %d", no->linha);
		     break;
		case Tipo:
		     sprintf(nomeOperador,"Tipo");
		     break;
		case ListaComando:
		     sprintf(nomeOperador,"ListaComando - Lin: %d", no->linha);
		     break;
		case Retorne:
		     sprintf(nomeOperador,"Retorne - Lin: %d", no->linha);
		     break;
		case Leia:
		     sprintf(nomeOperador,"Leia - Lin: %d", no->linha);
		     break;
		case Se:
		     sprintf(nomeOperador,"Se");
		     break;
		case Senao:
		     sprintf(nomeOperador,"Senao - Lin: %d", no->linha);
		     break;
		case Cond:
		     sprintf(nomeOperador,"Cond - Lin: %d", no->linha);
		     break;
		case Ou:
		     sprintf(nomeOperador,"Ou - Lin: %d", no->linha);
		     break;
		case  E:
		     sprintf(nomeOperador,"E - Lin: %d", no->linha);
		     break;
		case Igual:
		     sprintf(nomeOperador,"Igual - Lin: %d", no->linha);
		     break;
		case Diferente:
		     sprintf(nomeOperador,"Diferente - Lin: %d", no->linha);
		     break;
		case MenorQue:
		     sprintf(nomeOperador,"MenorQue - Lin: %d", no->linha);
		     break;
		case MaiorIgual:
		     sprintf(nomeOperador,"MaiorIgual - Lin: %d", no->linha);
		     break;
		case MenorIgual:
		     sprintf(nomeOperador,"MenorIgual - Lin: %d", no->linha);
		     break;
		case Soma:
		     sprintf(nomeOperador,"Soma - Lin: %d", no->linha);
		     break;
		case Sub:
		     sprintf(nomeOperador,"Sub - Lin: %d", no->linha);
		     break;
		case Div:
		     sprintf(nomeOperador,"Div - Lin: %d", no->linha);
		     break;
		case Resto:
		     sprintf(nomeOperador,"Resto - Lin: %d", no->linha);
		     break;
		case LValueExpr:
		     sprintf(nomeOperador,"LValueExpr - Lin: %d", no->linha);
		     break;
		case ID:
		     sprintf(nomeOperador,"ID");
		     break;
		case PrimExpr:
		     sprintf(nomeOperador,"PrimExpr - Lin: %d", no->linha);
		     break;
		case Carconst:
		     sprintf(nomeOperador,"Carconst - Lin: %d", no->linha);
		     break;
		case Intconst:
		     sprintf(nomeOperador,"Intconst - Lin: %d", no->linha);
		     break;
		case ListExpr:
		     sprintf(nomeOperador,"ListExpr - Lin: %d", no->linha);
		     break;

    }
}



///Listar conteúdo da pilha!
void listar (pilha *top)
{
    pilha * aux ;
    if(top == NULL)
        printf("pilha vazia!\n");
    else{
        aux = top;
        while(aux!= NULL){
            pesquisaPreOrdemPilha(aux->pontArvore);
            aux = aux -> proximo;	
        }
    }


}


void pesquisaPreOrdemPilha(noArvorePilha *raiz)
{
    if(raiz == NULL){
         printf("\n");
         return;
    }
    else{
	if(strcmp(raiz->tipo,inteiro) == 0 || strcmp(raiz->tipo,charr) == 0)	
	   printf("%s %s\n",raiz->id,raiz->tipo);	
	else if((strlen(raiz->tipo) > 0))
	  printf("Erro semântico \n");             

  
           pesquisaPreOrdemPilha(raiz->esq);
	   pesquisaPreOrdemPilha(raiz->dir);				
          
   }
}
