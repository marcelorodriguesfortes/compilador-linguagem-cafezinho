
%{
// Secao do Flex de definicao de vriaveis da linguagem C, e inclusap  de arquivos de cabecalho
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
#include "simpleLang.h"
char msg[500];
extern void yyerror( char const   *s); 
int numLinha=1;
int erroOrigem=1;
%}



DIGIT [0-9]
id [_a-zA-Z][_a-zA-Z0-9]*
%x comentario
int [0-9]
intconst  [0-9]*
carconst  '[a-z]*'
cadeiaCaracteres ["][^\"^/\n]*["] 

%%




"/*"		    BEGIN(comentario);

<comentario>[^*\n]*  /*se esta em uma start condition correspondente a comentario, consome   qualquer caractere que nao seja * ou \n */

<comentario>"*"+[^/\n]  

<comentario><<EOF>> {   strcpy(msg, "Erro: comentario nao termina"); 
			yyerror(msg);
                  }
<comentario>\n numLinha++;  
  
<comentario>"*"+"/"    BEGIN(INITIAL); 
     
"["			{yylval.nlinha= numLinha; return '[';}
			
"="			{yylval.nlinha= numLinha; return '=';}
  
"]"			{yylval.nlinha= numLinha; return ']'; }	

"("			{yylval.nlinha= numLinha; return '(';}
			
")"			{yylval.nlinha= numLinha; return ')';}
 				
">="			{yylval.nlinha= numLinha; return maiorigual;}

"<="	                {yylval.nlinha= numLinha; return menorigual;}

"+"			{yylval.nlinha= numLinha; return '+';}

"-" 			{yylval.nlinha= numLinha; return '-';}

"!"			{yylval.nlinha= numLinha; return '!';}

"!="			{yylval.nlinha= numLinha; return diferente;}

"programa"	        {yylval.lexemaId = (char *) malloc(strlen((yytext)+1));				      
			 strcpy(yylval.lexemaId,yytext);
			 yylval.nlinha= numLinha; return programa;}

"leia" 			{yylval.nlinha= numLinha; return leia;}

"escreva"		{yylval.nlinha= numLinha; return escreva;}

"retorne"		{yylval.nlinha= numLinha; return retorne;}

"novalinha"		{yylval.nlinha= numLinha; return novalinha;}

"se"			{yylval.nlinha= numLinha; return se;}

"ou"			{yylval.nlinha= numLinha; return ou;}			

"e"			{yylval.nlinha= numLinha; return e;}

"enquanto"		{yylval.nlinha= numLinha; return enquanto;}			

"senao"			{yylval.nlinha= numLinha; return senao;}

"entao"			{yylval.nlinha= numLinha; return entao;}

"execute"		{yylval.nlinha= numLinha; return execute;}	

"," 			{yylval.nlinha= numLinha; return ',';}

"?"			{yylval.nlinha= numLinha; return '?';}

"=="			{yylval.nlinha= numLinha; return igual;}

">"			{yylval.nlinha= numLinha; return '>';}

"<"			{yylval.nlinha= numLinha; return '<';}

"*" 			{yylval.nlinha= numLinha; return '*';}

"/"			{yylval.nlinha= numLinha; return '/';}
			
";"			{yylval.nlinha= numLinha; return ';';}

\n 			{yylval.nlinha= numLinha; numLinha++;}

[ \t]+ 	 		 

"%"             	{yylval.nlinha= numLinha; return '%';}

"car"  			{yylval.nlinha= numLinha; return car;}

"int" 			{yylval.nlinha= numLinha; return in;}

{carconst}		{yylval.nlinha= numLinha; return carconst;}

{intconst}   		{yylval.nlinha= numLinha; return intconst;}  

{cadeiaCaracteres}      {yylval.nlinha= numLinha; return cadeiaCaracteres;}	

"{"			{yylval.nlinha= numLinha; return '{';}

"}" 			{yylval.nlinha= numLinha; return '}';}
			
{id}                    {yylval.nlinha = numLinha; 
			 yylval.lexemaId = (char *) malloc(strlen((yytext)+1));				      
			 strcpy(yylval.lexemaId,yytext);
			return id;}

.			{ 
				
				printf("Caractere invalido: %s\n", yytext);
				
			}

<<EOF>> 		return(EOF);


%%

int yywrap(){return 1;}
