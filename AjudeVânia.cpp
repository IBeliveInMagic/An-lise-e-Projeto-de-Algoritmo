#include<bits/stdc++.h>

using namespace std;

/* Definir variaveis globais */

/* Arrays que armazenam o peso de cada livro e o grau de interesse em cada livro, respectivamente*/
int weight[1100],value[1100];

/* Variáveis que armazenam o peso máximo que a mochila suporta e a quantidade de livros, respectivamente*/
int pesomax , qtd;

/* Matriz dp responsável por armazenar valores e serve para evitar recalcular soluções já encontradas*/
long long dp[1100][1009];

/* Função que vai organizando os elementos da matriz dp de forma recursiva*/
long long funcao(int i, int pesoatual){
	if(i==qtd || pesoatual <= 0){  /* Caso base da recursão*/
		return 0;
	}

	if(dp[i][pesoatual]>=0){	/* Caso já tenha um valor armazenado nessa parte da matriz 
								ele continuará com esse resultado */
		return dp[i][pesoatual];

	}

	/* Caso não esteja preenchida essa posição na matriz ele continua com o código: */

	long long naocoloca = funcao(i+1,pesoatual); /* chamada recursiva */

	/* Nessa parte do código caso a mochila ainda não tenha ultrapassado se peso máximo: */
	if(pesoatual-weight[i] >= 0){

		long long coloca = funcao(i+1,pesoatual-weight[i]) + value[i]; /* chamada recursiva que 
																	   soma o grau de interesse*/

		/* Nessa parte do código é onde se faz a escolha do valor máximo até essa parte do problema.
		Assim vai amazenando somente os valores máximos economizando cálculos desnecessários. */
		return dp[i][pesoatual] = max(coloca,naocoloca); /* decisão se coloca ou não coloca o livro na mochila*/

	}

	/* Nessa parte do código caso a mochila ainda tenha ultrapassado se peso máximo: */
	return dp[i][pesoatual] = naocoloca;
}


int main(){

	int i; 				/* contador */
	int Case = 0;		/* Variável que armazena o número de casos */
	int peso,grau;		/* Variáveis que armazenam o peso de cada livro 
						e o grau de interesse no livro respectivamente */

	while(1){

		Case++;

	    cin >> qtd >> pesomax;		/* Recebe os valores relacionados a quantidade de 
									livros e o peso máximo que a mochila suporta*/
	    
	    if(qtd == 0 && pesomax == 0) break;		/* Critério de parada do loop */
           
		/* Enquanto houver livro :*/
        for(i = 0; i < qtd; i++){

            cin >> peso >> grau;		/* Recebe os valores relacionados ao peso e grau de interesse de cada livro*/
            weight[i] = peso;			/* Preenche o array weight com os pesos*/
            value[i] = grau;			/* Preenche o array value com cada valor de grau de interesse*/

        }
        
        memset(dp,-1,sizeof(dp)); /* funcao que preenche todos os elementos da matriz dp com -1*/
            
        long long resposta = funcao(0,pesomax); /* variável que recebe o valor máximo de grau de interesse dos livros
												que conseguiram serem colocados dentro da mochila sem ultrapassar seu
												limite máximo */
            
        cout << "Caso " << Case << ": " << resposta << endl;    /* imprime os valores */

	}

	return 0;
}