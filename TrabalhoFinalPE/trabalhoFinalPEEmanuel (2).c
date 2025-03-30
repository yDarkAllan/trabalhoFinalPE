#include <stdio.h>
#include <string.h>
#define MAX 200

typedef struct{
   float vtDaCompra;
   int compraCancelada;
   int bonus;
   float vDe1Bonus;
   float vDeBonificacao;
}tCompra;

typedef struct{
   char nome[100];
   char CPF[12];
   char telefone[15];
   int bonus;
   float totalEmCompras;
   tCompra ultimaCompra;
}tCliente;

typedef struct{
   int teto;
   float valor;
   float valorBonificado;
}tBonus;

/*
Objetivo: A função "opc1" realiza a configuração referente ao bônus (teto, valor de 1 bônus e valor pra receber bonificação).
Parâmetros:
    *bon: Refere-se ao endereço de memória da variavel do tipo tBonus
Retorno: Não possui retorno, todas as alterações são realizadas e salvas dentro da função
*/

void opc1 (tBonus *bon){
   int resp;

   do{
      printf("\nMENU CONFIGURA BONUS\n");
      printf("1- Alterar teto\n");
      printf("2- Alterar valor de um bonus\n");
      printf("3- Alterar valor para receber bonus\n");
      printf("0- Sair\n");
      printf("\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &resp);
      printf("\n");

      switch(resp){

         case 1: printf("\nQual o novo valor do teto? ");
                 scanf("%d", &bon->teto);
                 while(bon->teto<0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%d", &bon->teto);
                 }

                 printf("Teto alterado com sucesso!\n");
                 break;

         case 2: printf("\nQual o valor de 1 bonus? R$ ");
                 scanf("%f", &bon->valor);
                 while(bon->valor<0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &bon->valor);
                 }

                 printf("Valor de 1 bonus alterado com sucesso!\n");
                 break;

         case 3: printf("\nQual o novo valor para receber bonus? R$ ");
                 scanf("%f", &bon->valorBonificado);
                 while(bon->valorBonificado<0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &bon->valorBonificado);
                 }

                 printf("Valor para receber bonus alterado com sucesso!\n");
                 break;

         case 0: break;

         default: printf("Opcao invalida!\n");
                  break;
         }
   }while(resp!=0);
}

/*
Objetivo: A função "opc2" realiza todo o processo do cadastro de clientes (cpf, nome e telefone).
          Além disso, nessa função não é permitido cadastros além da quantidade máxima (200) e o cpf é validado.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    *quant: Refere-se ao endereço de memória da variável que controla os clientes que são cadastrados.
    bon: Refere-se à variável do tipo tBonus que guarda os dados com relação ao bônus.
Retorno: Não possui retorno, todas as alterações são realizadas e salvas dentro da função
*/

void opc2(tCliente cli[], int *quant, tBonus bon){
   tCliente c;

   if(*quant >= MAX){
      printf("Cadastro nao realizado. Conjunto cheio!\n");
      printf("\n");
      return;
   }

   char leCpf[12];
   int i;

   printf("Qual o CPF? ");
   scanf(" %12[^\n]", leCpf);
   fflush(stdin);
   while(strlen(leCpf) != 11){
      printf("Erro: CPF invalido. Digite novamente: ");
      scanf(" %12[^\n]", leCpf);
      fflush(stdin);
   }

   for(i=0; i<*quant; i++){
      if(strcmp(leCpf, cli[i].CPF) == 0){
         printf("Erro: CPF ja cadastrado.\n");
         printf("\n");
         return;
      }
   }

   strcpy(c.CPF, leCpf);
   printf("Qual o nome? ");
   scanf(" %100[^\n]", c.nome);
   fflush(stdin);
   printf("Qual o telefone? ");
   scanf(" %15[^\n]", c.telefone);
   fflush(stdin);
   c.bonus = 0;
   c.totalEmCompras = 0;
   c.ultimaCompra.compraCancelada = 1;
   c.ultimaCompra.vDe1Bonus = bon.valor;
   c.ultimaCompra.vDeBonificacao = bon.valorBonificado;
   cli[*quant] = c;
   *quant = *quant + 1;

   printf("Cliente cadastrado com sucesso!\n");
   printf("\n");
   return;
}

/*
Objetivo: A função "opc3" realiza as alterações no cadastro do cliente(cpf, nome e telefone). O CPF é verificado, garantindo
          que o usuário ja está cadastrado.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
Retorno: Não possui retorno, todas as alterações são realizadas e salvas dentro da função.
*/

void opc3(tCliente cli[], int quant){
   char leCpf[12];
   int i, resp, verif, ind;

   printf("Qual o CPF do cliente? ");
   scanf(" %12[^\n]", leCpf);
   fflush(stdin);

   for(i=0; i<quant; i++){
      if(strcmp(leCpf, cli[i].CPF) == 0)
         break;
   }

   if(i==quant){
      printf("Erro: CPF nao cadastrado.\n");
      printf("\n");
      return;
   }
   ind = i;

   do{
      printf("\nMENU ALTERA CLIENTE\n");
      printf("1 - Alterar CPF\n");
      printf("2 - Alterar nome\n");
      printf("3 - Alterar telefone\n");
      printf("0 - Voltar ao menu principal\n");
      printf("\nEscolha uma opcao: ");
      scanf("%d", &resp);
      printf("\n");

      switch(resp){

         case 1: printf("Qual o novo CPF? ");
                 scanf(" %12[^\n]", leCpf);
                 fflush(stdin);

                 while(strlen(leCpf) != 11){
                    printf("Erro: CPF invalido. Digite novamente: ");
                    scanf(" %12[^\n]", leCpf);
                    fflush(stdin);
                 }
                 verif = 0;

                 for(i=0; i<quant; i++){
                    if(strcmp(leCpf, cli[i].CPF) == 0){
                       printf("Erro: CPF ja cadastrado.\n");
                       verif = 0;
                       break;
                    }else{
                       verif = 1;
                    }
                 }

                 if(verif == 1){
                    strcpy(cli[ind].CPF, leCpf);
                    printf("CPF alterado com sucesso!\n");
                 }
                 printf("\n");
                 break;

         case 2: printf("Qual o novo nome? ");
                 scanf(" %100[^\n]", cli[ind].nome);
                 fflush(stdin);
                 printf("Nome alterado com sucesso!\n");
                 printf("\n");
                 break;

         case 3: printf("Qual o novo telefone? ");
                 scanf(" %100[^\n]", cli[ind].telefone);
                 fflush(stdin);
                 printf("Telefone alterado com sucesso!\n");
                 printf("\n");
                 break;

         case 0: return;

         default: printf("Opcao invalida!\n");
                  break;
      }
   }while(1);
}

/*
Objetivo: A função "opc4" realiza a efetivação das compras.
          O valor da compra é validado e é perguntado ao usuário se ele deseja usar o bonus na compra (caso tenha).
          A compra só é efetivada quando o valor do pagamento é suficiente. Após a efetivação, as alterações referentes
          aos bônus do cliente, total de compras dele e dados com relação a essa compra são salvos.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
    bon: Refere-se à variável do tipo tBonus que guarda os dados com relação ao bônus.
Retorno: Não possui retorno, todas as alterações são realizadas e salvas dentro da função.
*/

void opc4(tCliente cli[], int quant, tBonus bon){
   int i, ind, resp1=0, resp2=0, bonificacao, somaBonus;
   float valor, pgto, converteBonus, novoValor;
   char leCpf[12];

   printf("1-Qual o CPF do cliente? ");
   scanf(" %12[^\n]", leCpf);
   fflush(stdin);

   for(i=0; i<quant; i++){
       if(strcmp(leCpf, cli[i].CPF) == 0)
          break;
   }

   if(i==quant){
      printf("Erro: CPF nao cadastrado.\n");
      printf("\n");
      return;
   }
   ind = i;

   converteBonus = cli[ind].bonus * bon.valor;
   printf("BONUS = %d.00 VALOR CORRESPONDENTE = R$ %.2f\n", cli[ind].bonus, converteBonus);

   printf("\n2-Qual o valor da compra? R$ ");
   scanf("%f", &valor);
   while(valor < 0){
      printf("Erro: valor negativo. Digite novamente: ");
      scanf("%f", &valor);
   }
   novoValor = valor;

   if(cli[ind].bonus > 0){
      printf("\n3- Deseja utilizar seu bonus? [1-sim <outro valor>-nao]: ");
      scanf("%d", &resp1);
      if(resp1 == 1){
         novoValor = valor - converteBonus;
         if(novoValor < 0)
            novoValor = 0;
         printf("BONUS ATUAL = %d.00. VALOR DA COMPRA ATUALIZADO = R$ %.2f\n", cli[ind].bonus, novoValor);
      }
   }
   printf("\n");

   do{
      printf("4-Qual o valor do pagamento do cliente? R$ ");
      scanf("%f", &pgto);
      while(pgto < 0){
         printf("Erro: valor negativo. Digite novamente: ");
         scanf("%f", &pgto);
      }
      if(pgto < novoValor){
         printf("Erro: Valor do pagamento inferior ao valor da compra. Deseja desistir da compra? [1-sim <outro valor>-nao]: ");
         scanf("%d", &resp2);
         if(resp2 == 1){
            printf("\nCOMPRA NAO EFETIVADA. Valor devolvido ao cliente: R$ %.2f\n", pgto);
            printf("\n");
            return;
         }else{
            printf("\n");
            continue;
         }
      }else{
         break;
      }
   }while(1);
   printf("TROCO = R$ %.2f\n\n", pgto - novoValor);

   cli[ind].ultimaCompra.compraCancelada = 0;
   cli[ind].ultimaCompra.vDe1Bonus = bon.valor;
   cli[ind].ultimaCompra.vtDaCompra = valor;
   cli[ind].ultimaCompra.vDeBonificacao = bon.valorBonificado;

   if(resp1 == 1){
      if(converteBonus > valor){
         bonificacao = converteBonus - valor;
         bonificacao = bonificacao / bon.valor;
         cli[ind].bonus = bonificacao;
         cli[ind].ultimaCompra.bonus = valor / bon.valor;
     }else{
         cli[ind].bonus = 0;
         cli[ind].ultimaCompra.bonus = converteBonus / bon.valor;
     }
   }else{
      if(valor >= bon.valorBonificado){
         somaBonus = valor / bon.valorBonificado;
         cli[ind].bonus = cli[ind].bonus + somaBonus;
      }
      cli[ind].ultimaCompra.bonus = 0;
   }

   cli[ind].totalEmCompras = cli[ind].totalEmCompras + valor;

   if(cli[ind].bonus > bon.teto){
      cli[ind].bonus = bon.teto;
   }

   return;
}

/*
Objetivo: A função "opc5" realiza o cancelamento de compras passadas.
          Realiza o cancelamento da última compra, de outra compra, ou exibe dados da última compra feita pelo cliente.
          Após o cancelamento da compra, as alterações com relação a bônus e valor total de compras são feitas.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
    bon: Refere-se à variável do tipo tBonus que guarda os dados com relação ao bônus.
Retorno: Não possui retorno, todas as alterações são realizadas e salvas dentro da função.
*/

void opc5(tCliente cli[], int quant, tBonus bon){
   int i, resp1, resp2, resp3, resp4, ind, bonusDecrementa, verifBonus, imprimeBonus;
   float valorCompra;
   char leCpf[12];

   do{
      printf("Qual o CPF do cliente? ");
      scanf(" %12[^\n]", leCpf);
      fflush(stdin);
      for(i=0; i<quant; i++){
         if(strcmp(leCpf, cli[i].CPF) == 0){
            break;
         }
      }

      if(i==quant){
         printf("Erro: CPF nao cadastrado. Deseja informar outro CPF [1-sim, <outro valor>-nao]: ");
         scanf("%d", &resp1);
         if(resp1 == 1){
            continue;
         }else{
            printf("\n");
            return;
         }
      }else{
         ind = i;
         break;
      }
   }while(1);

   do{
      printf("\nMENU CANCELA COMPRA\n");
      printf("1 - Ultima compra\n");
      printf("2 - Outra compra\n");
      printf("3 - Exibir dados da ultima compra\n");
      printf("0 - Sair\n");
      printf("\nEscolha uma opcao: ");
      scanf("%d", &resp2);

      switch(resp2){

         case 1: if (cli[ind].ultimaCompra.compraCancelada == 1){
                    printf("ERRO: Ultima compra ja cancelada!\n");
                    break;
                 }else{
                    printf("Valor total da compra: R$ %.2f\n", cli[ind].ultimaCompra.vtDaCompra);
                    printf("Quantidade de bonus utilizado na compra: %d\n", cli[ind].ultimaCompra.bonus);
                    printf("Valor de 1 bonus no periodo desta compra: R$ %.2f\n", cli[ind].ultimaCompra.vDe1Bonus);
                    printf("Valor para receber bonus no periodo desta compra: R$ %.2f\n", cli[ind].ultimaCompra.vDeBonificacao);
                    printf("\nTem certeza que deseja cancelar a ultima compra? [1-sim <outro valor>-nao] ");
                    scanf("%d", &resp3);

                    if(resp3 != 1){
                       printf("COMPRA NAO CANCELADA!\n");
                       break;
                    }else{
                       printf("COMPRA CANCELADA!\n");

                       cli[ind].ultimaCompra.compraCancelada = 1;
                       cli[ind].totalEmCompras = cli[ind].totalEmCompras - cli[ind].ultimaCompra.vtDaCompra;

                       if(cli[ind].ultimaCompra.bonus == 0){
                          if(cli[ind].ultimaCompra.vtDaCompra >= cli[ind].ultimaCompra.vDeBonificacao){
                             bonusDecrementa = cli[ind].ultimaCompra.vtDaCompra / cli[ind].ultimaCompra.vDeBonificacao;
                             cli[ind].bonus = cli[ind].bonus - bonusDecrementa;
                          }
                       }else{
                          cli[ind].bonus += cli[ind].ultimaCompra.bonus;
                       }

                       if(cli[ind].bonus < 0){
                          cli[ind].bonus = 0;
                       }

                       if(cli[ind].totalEmCompras < 0){
                          cli[ind].totalEmCompras = 0;
                       }

                       break;
                    }
                 }

         case 2: printf("Qual o valor da compra a ser cancelada? ");
                 scanf("%f", &valorCompra);
                 while(valorCompra < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &valorCompra);
                 }

                 verifBonus = 0;
                 if(valorCompra >= bon.valorBonificado){
                    verifBonus = valorCompra / bon.valorBonificado;
                    verifBonus = verifBonus * 2;
                 }

                 printf("BONUS A SER DESCONTADO = %d. Tem certeza que deseja cancelar a compra? [1-sim <outro valor>-nao] ", verifBonus);
                 scanf("%d", &resp4);

                 if(resp4 != 1){
                    printf("COMPRA NAO CANCELADA!\n");
                    break;
                 }else{
                    printf("COMPRA CANCELADA!\n");
                    cli[ind].bonus = cli[ind].bonus - verifBonus;
                    cli[ind].totalEmCompras = cli[ind].totalEmCompras - valorCompra;
                 }

                 if(cli[ind].bonus < 0){
                    cli[ind].bonus = 0;
                 }

                 if(cli[ind].totalEmCompras < 0){
                    cli[ind].totalEmCompras = 0;
                 }

                 break;

         case 3: if(cli[ind].ultimaCompra.bonus == 0){
                    imprimeBonus = cli[ind].ultimaCompra.vtDaCompra / cli[ind].ultimaCompra.vDeBonificacao;
                 }else{
                    imprimeBonus = 0;
                 }
                 printf("NOME DO CLIENTE: %s\n", cli[ind].nome);
                 printf("CPF DO CLIENTE: %s\n", cli[ind].CPF);
                 printf("VALOR DA COMPRA: R$ %.2f\n", cli[ind].ultimaCompra.vtDaCompra);
                 printf("PONTOS ADQUIRIDOS COM A COMPRA: %d\n", imprimeBonus);
                 printf("VALOR DE UM BONUS NA EPOCA DA COMPRA: R$ %.2f\n", cli[ind].ultimaCompra.vDe1Bonus);
                 break;

         case 0: break;

         default: printf("Opcao invalida!\n");
                  break;
      }
   }while(resp2!=0);
   return;
}

/*
Objetivo: A função "opc6" realiza a consulta do total de bônus de um cliente.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
    bon: Refere-se à variável do tipo tBonus que guarda os dados com relação ao bônus.
Retorno: Não possui retorno, a função apenas imprime as informações.
*/

void opc6(tCliente cli[], int quant, tBonus bon){
   int i, ind;
   char leCpf[12];

   printf("1-Qual o CPF do cliente? ");
   scanf(" %12[^\n]", leCpf);
   fflush(stdin);

   for(i=0; i<quant; i++){
      if(strcmp(leCpf, cli[i].CPF) == 0)
         break;
   }
   if(i==quant){
      printf("Erro: CPF nao cadastrado.\n");
      printf("\n");
      return;
   }
   ind = i;

   printf("\nBONUS = %d. VALOR CORRESPONDENTE = R$ %.2f.\n", cli[ind].bonus, cli[ind].bonus * bon.valor);
   printf("\n");
   return;
}

/*
Objetivo: A função "opc7" lista por meio de um relatório, os dados de todos os clientes já cadastrados.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
Retorno: Não possui retorno, a função apenas imprime as informações.
*/

void opc7(tCliente cli[], int quant){
   int i;

   printf("RELATORIO DADOS DOS CLIENTES\n");
   printf("\n");

   for(i=0; i<quant; i++){
      printf("Nome: %s\n", cli[i].nome);
      printf("CPF: %s\n", cli[i].CPF);
      printf("Telefone: %s\n", cli[i].telefone);
      printf("Bonus: %d\n", cli[i].bonus);
      printf("Total em compras: R$ %.2f\n", cli[i].totalEmCompras);
      printf("------------------------------------------------------------\n");
   }

   printf("\n");
   return;
}

/*
Objetivo: A função "opc8" lista por meio de um relatório, os bônus de todos os clientes já cadastrados.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
    bon: Refere-se à variável do tipo tBonus que guarda os dados com relação ao bônus.
Retorno: Não possui retorno, a função apenas imprime as informações.
*/

void opc8(tCliente cli[], int quant, tBonus bon){
   int i;

   printf("RELATORIO BONUS DOS CLIENTES\n");
   printf("\n");

   for(i=0; i<quant; i++){
      printf("Nome: %s\n", cli[i].nome);
      printf("CPF: %s\n", cli[i].CPF);
      printf("Bonus: %d\n", cli[i].bonus);
      printf("Valor do Bonus: R$ %.2f\n", cli[i].bonus * bon.valor);
      printf("------------------------------------------------------------\n");
   }

   printf("\n");
   return;
}

/*
Objetivo: A função "opc9" lista por meio de um relatório, o valor total em compras dos clientes.
          Nessa função, é possível consultar o total em compras inferior a um valor, superior a um valor,
          igual a um valor, ou dentro de uma determinada faixa.
Parâmetros:
    cli: Refere-se ao vetor do tipo tCliente que armazena as informacoes de cada cliente cadastrado.
    quant: Refere-se à variável que controla os clientes ja cadastrados.
Retorno: Não possui retorno, a função apenas imprime as informações.
*/

void opc9(tCliente cli[], int quant){
   int i, resp;
   float valor, aux, faixaInicial, faixaFinal;

   do{
      printf("\nRELATORIO DE COMPRAS\n");
      printf("1- Total de compras inferior a um valor\n");
      printf("2- Total de compras superior a um valor\n");
      printf("3- Total de compras igual a um valor\n");
      printf("4- Total de compras em uma faixa\n");
      printf("0- Sair\n");
      printf("\nEscolha uma opcao: ");
      scanf("%d", &resp);

      switch(resp){

         case 1: printf("\nQual o valor? ");
                 scanf("%f", &valor);
                 while(valor < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &valor);
                 }

                 printf("\nRELATORIO DE COMPRAS\n");
                 printf("\n");

                 for(i=0; i<quant; i++){
                    if(cli[i].totalEmCompras < valor){
                       printf("Nome: %s\n", cli[i].nome);
                       printf("CPF: %s\n", cli[i].CPF);
                       printf("Total em compras: R$  %.2f\n", cli[i].totalEmCompras);
                       printf("------------------------------------------------------------\n");
                    }
                 }
                 break;

         case 2: printf("\nQual o valor? ");
                 scanf("%f", &valor);
                 while(valor < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &valor);
                 }

                 printf("\nRELATORIO DE COMPRAS\n");
                 printf("\n");

                 for(i=0; i<quant; i++){
                    if(cli[i].totalEmCompras > valor){
                       printf("Nome: %s\n", cli[i].nome);
                       printf("CPF: %s\n", cli[i].CPF);
                       printf("Total em compras: R$  %.2f\n", cli[i].totalEmCompras);
                       printf("------------------------------------------------------------\n");
                    }
                 }
                 break;

         case 3: printf("\nQual o valor? ");
                 scanf("%f", &valor);
                 while(valor < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &valor);
                 }

                 printf("\nRELATORIO DE COMPRAS\n");
                 printf("\n");

                 for(i=0; i<quant; i++){
                    if(cli[i].totalEmCompras == valor){
                       printf("Nome: %s\n", cli[i].nome);
                       printf("CPF: %s\n", cli[i].CPF);
                       printf("Total em compras: R$  %.2f\n", cli[i].totalEmCompras);
                       printf("------------------------------------------------------------\n");
                    }
                 }
                 break;

         case 4: printf("Qual o valor inicial? ");
                 scanf("%f", &faixaInicial);
                 while(faixaInicial < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &faixaInicial);
                 }
                 printf("Qual o valor final? ");
                 scanf("%f", &faixaFinal);
                 while(faixaFinal < 0){
                    printf("Erro: valor negativo. Digite novamente: ");
                    scanf("%f", &faixaFinal);
                 }

                 if(faixaFinal < faixaInicial){
                    aux = faixaInicial;
                    faixaInicial = faixaFinal;
                    faixaFinal = aux;
                 }

                 printf("\nRELATORIO DE COMPRAS\n");
                 for(i=0; i<quant; i++){
                    if(cli[i].totalEmCompras >= faixaInicial && cli[i].totalEmCompras <= faixaFinal){
                       printf("Nome: %s\n", cli[i].nome);
                       printf("CPF: %s\n", cli[i].CPF);
                       printf("Total em compras: R$  %.2f\n", cli[i].totalEmCompras);
                       printf("------------------------------------------------------------\n");
                    }
                 }
                 break;

         case 0: break;

         default: printf("Opcao invalida!\n");
                  break;
      }
   }while(resp!=0);

   printf("\n");
   return;
}

int main(){
   int resp, quant = 0;
   tBonus bon;
   bon.teto = 1000; bon.valor = 0.50; bon.valorBonificado = 100;
   tCliente cli[MAX];

   do{
      printf("MENU PRINCIPAL\n");
      printf("01 - Configurar bonus\n");
      printf("02 - Cadastrar cliente\n");
      printf("03 - Alterar cadastro do cliente\n");
      printf("04 - Efetivar compra\n");
      printf("05 - Cancelar compra\n");
      printf("06 - Consultar bonus\n");
      printf("07 - Listar dados de todos os clientes\n");
      printf("08 - Listar bonus de todos os clientes \n");
      printf("09 - Listar clientes pelo valor total de compras\n");
      printf("00 - Sair\n");
      printf("\n");
      printf("Escolha uma opcao: ");
      scanf("%d", &resp);
      printf("\n");

      switch(resp){

         case 1:   opc1(&bon);
                   break;

         case 2:   opc2(cli, &quant, bon);
                   break;

         case 3:   opc3(cli, quant);
                   break;

         case 4:   opc4(cli, quant, bon);
                   break;

         case 5:   opc5(cli, quant, bon);
                   break;

         case 6:   opc6(cli, quant, bon);
                   break;

         case 7:   opc7(cli, quant);
                   break;

         case 8:   opc8(cli, quant, bon);
                   break;

         case 9:   opc9(cli, quant);
                   break;

         case 0:   printf("Encerrando sistema!\n");
                   break;

         default:  printf("Opcao invalida!\n\n");
                   break;
      }
   }while(resp!=0);
return 0;
}
