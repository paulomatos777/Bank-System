#include <stdio.h>

#include <stdlib.h>

#define MAX_CLIENTES 100
#define MAX_TRANSACOES 100

struct dadosClientes{
  int conta;
  char nome[15];
  char sobrenome[15];
  float saldo;
};

struct transacao{
  char tipo_transf; // + ou -
  float valor;
  int conta;
};

void atualiza_saldo(struct dadosClientes clientes[], struct transacao transacoes[], int qtd_clientes,int qtd_transacoes){
  int count;
  // Calculando saldos de acordo com transacoes realizadas
  int id_conta;
  if(qtd_clientes == 0 && qtd_transacoes == 0){
    printf("\n Primeiro carregue os clientes e as trasações");
  }else{
    for(count = 0; count < qtd_transacoes; count++){
      if(transacoes[count].tipo_transf == '+'){
        id_conta = transacoes[count].conta;
        clientes[id_conta-1].saldo += transacoes[count].valor;
      }else{
        id_conta = transacoes[count].conta;
        clientes[id_conta-1].saldo -= transacoes[count].valor;
      }
    }
    printf("\n Saldos atualizados\n\n");
  }
}
void imprime_clientes(struct dadosClientes clientes[],int qtd_clientes){
  // Imprimindo resultados
  int count;
  if(qtd_clientes == 0){
    printf("\n Primeiro carregue os clientes e as trasações");
  }else{
    for(count = 0; count < qtd_clientes; count++){
      printf("conta: %d\n",clientes[count].conta);
      printf("nome: %s %s \n",clientes[count].nome,clientes[count].sobrenome);
      printf("saldo: %.2f\n", clientes[count].saldo);
      printf("\n");
    }
  }
}
void calcula_devedores(struct dadosClientes clientes[], struct transacao transacoes[], int qtd_clientes){
  char devedores_filename[] = "DEVEDORES.txt";
  FILE *p_devedores;
  int count = 0;
  if(qtd_clientes == 0){
    printf("\n Primeiro carregue os clientes e as trasações");
  }else{
    // Gravando os devedores em um arquivo
    p_devedores = fopen(devedores_filename, "w");

    for(count = 0; count < qtd_clientes; count++){
      if( clientes[count].saldo < 0){
        fprintf(p_devedores,"%d %s %s %.2f\n", clientes[count].conta,clientes[count].nome, clientes[count].sobrenome, clientes[count].saldo);
      }
    }
    fclose(p_devedores);
  }
}
void carrega_clientes(struct dadosClientes clientes[], int *qtd_clientes){
  FILE *in;
  int count=0;
  
  in = fopen("CLIENTES.txt", "r");
  // verificando se o arquivo nao é vazio ou inexistente
	if(in == NULL){

		printf("Arquivo-fonte nao pode ser aberto\n");

	}else{

	
		while(!feof(in)){

      fscanf(in,"%d %s %s %f", &clientes[count].conta,clientes[count].nome, clientes[count].sobrenome, &clientes[count].saldo);
			//fscanf(in,"%d %s %s %f", &conta, nome, sobrenome,&saldo);

      //if(!feof(in)){ 
      printf("conta: %d\n",clientes[count].conta);
      printf("nome: %s %s \n",clientes[count].nome,clientes[count].sobrenome);
      printf("saldo: %.2f\n", clientes[count].saldo);
      printf("\n");
			//}
      count++;
	  }
  }

  *qtd_clientes = count ;
  fclose(in);
}

void carrega_transacoes(struct transacao transacoes[],int *qtd_transacoes){
  FILE *fin;
  int count;

  fin = fopen("TRANSACTIONS.txt", "r");

	

  if(fin == NULL){

		printf("Arquivo-fonte nao pode ser aberto\n");

	}else{

    count = 0;
    while(!feof(fin)){
      
			fscanf(fin,"%d %c %f", &transacoes[count].conta, &transacoes[count].tipo_transf,&transacoes[count].valor);
      printf("conta: %d\n",transacoes[count].conta);
      printf("tipo de transacao: %c \n",transacoes[count].tipo_transf);
      printf(" valor da transacao: %.2f\n", transacoes[count].valor);
      printf("\n");
      count++;
  
	  }
  }
  *qtd_transacoes = count;
  fclose(fin);
}

int main(void){
  struct dadosClientes clientes[100];
  struct transacao transacoes[100];
  int qtd_clientes = 0,
      qtd_transacoes = 0,
      count = 0;
	char escolha;
  do{
    printf("\n-----------Seja Bem-Vindo ao Banco Paulo Matos--------------\n");
    printf("1 - Carregar Clientes\n2 - Carregar Transações\n3 - Atualizar Saldos\n4 - Imprimir Clientes\n5 - Calcular e salvar Devedores\nS - Sair\n\tDigite sua escolha: ");
    scanf(" %c", &escolha);
    if(escolha=='S' || escolha=='s'){
      break;
    }
    else if(escolha == '1'){
      carrega_clientes(clientes, &qtd_clientes);
      printf("\n Quantidade de clientes  :  %d\n", qtd_clientes);
    }
    else if(escolha == '2'){
      carrega_transacoes(transacoes, &qtd_transacoes);
      printf("\n Quantidade de transacoes  :  %d\n", qtd_transacoes);
    }
    else if(escolha == '3'){
      atualiza_saldo(clientes, transacoes, qtd_clientes, qtd_transacoes);
    }
    else if(escolha == '4'){
      imprime_clientes(clientes, qtd_clientes);
    }
    else if(escolha == '5'){
      calcula_devedores(clientes, transacoes,qtd_clientes);
    }else{
      printf("\n Favor digitar alguma das opcões :\n");
    }
  }while(escolha!='S'&& escolha!='s');

  return 0;
}
