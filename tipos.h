//
//  tipos.h
//  
//
//  Created by Thierson Couto Rosa on 14/05/14.
//
//

#ifndef _tipos_h
#define _tipos_h
typedef enum{Prog, NoDeclFuncVar, DeclVar,DeclProg, DeclFunc, ListaParametrosCont, Bloco, ListaDeclVar, Tipo, ListaComando, Retorne, Leia, Escreva, Se, Senao,NovaLinha, Enquanto, Igual, Cond, Ou, E, Diferente, MenorQue, MaiorQue, MaiorIgual,Multi,  MenorIgual, Soma, Sub, Div, Resto, LValueExpr, ID, PrimExpr, Carconst, Intconst, ListExpr, Menos, Dif,lexID,lexPrograma} TespecieOperador;
//Definicao de um no da arvore abstrata.


typedef struct operador{
    TespecieOperador tipoOperador;
    int  linha;
    char* lexema; // utilizado apenas em nos da especie Num para armazenar o lexa do numero
    struct operador* filho1;
    struct operador* filho2;
    struct operador* filho3;
    struct operador* filho4;
    struct operador* filho5;
   
} Toperador;




#endif
