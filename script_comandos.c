/*
  Lista de Comandos - Um programa simples para executar uma variedade de tarefas de sistema.

  Este programa oferece uma interface de linha de comando para acessar e executar varias operacoes
  comuns do sistema, como acessar sites, verificar informacoes do sistema, pingar em um PC, entre outras.

  Como Usar:
  - Execute o programa e siga as instrucies apresentadas no menu principal.
  - Selecione uma das opcoes disponiveis digitando o numero correspondente e pressionando Enter.
  - Dependendo da opcao selecionada, o programa pode solicitar entradas adicionais, como endereco IP ou URL.
  - Para sair do programa, selecione a opcao "0" no menu principal.

  Requisitos e Dependencias:
  - Este programa foi projetado para ser executado em sistemas operacionais baseados no Windows.
  - O compilador C utilizado deve suportar as bibliotecas padrao do C, como stdio.h e stdlib.h.

  Autor: Pedro Gollo
  Data de Criacao: 05/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
int primeiro = 1;
/*---------------------------------------------------------*/
// Prototipos das funcoes
void printaBemVindo();
void printaDivisao();
void limparBuffer();
int pegaOpcao();
void menuPrincipal();
void acessarSite();
void verIPDaMaquina();
void verInformacoesDoSistema();
void verListaDeProcessos();
void pingarEmUmPC();
void limparTela();
void trocarCor();
void reiniciarComputador();
void desligarComputador();
void verPrevisaoDoTempo();
/*---------------------------------------------------------*/
// Funcao principal
int main() {
    system("title Lista de Comandos");
    printaBemVindo();
    menuPrincipal();
    return 0;
}
/*---------------------------------------------------------------*/
// Exibe a mensagem de boas-vindas
void printaBemVindo(){
    printf("--------------------------------------\n");
    printf("*                                    *\n");   
    printf("*          Seja Bem-vindo!           *\n");
    printf("*                                    *\n");
}
/*---------------------------------------------------------*/
// Exibe uma linha de divisao
void printaDivisao(){
    printf("--------------------------------------\n");
}
/*---------------------------------------------------------*/
// Limpa o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/*---------------------------------------------------------*/
// Obtem a opcao escolhida pelo usuario
int pegaOpcao(){
    int opcao;
    
    primeiro = 0;
    
    printaDivisao();
    printf("> Menu de Comandos:\n");
    printf("  [1] Acessar um Sistema\n");
    printf("  [2] Ver IP do Computador\n");
    printf("  [3] Pingar em um PC\n");
    printf("  [4] Ver Informacoes do Hardware\n");
    printf("  [5] Listar Processos em Execucao\n");
    printf("  [6] Limpar Tela\n");
    printf("  [7] Trocar Cor\n");
    printf("  [8] Reiniciar Computador\n");
    printf("  [9] Desligar Computador\n");
    printf("  [0] Sair\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");
    
    if (scanf("%d", &opcao) != 1) {
        limparBuffer();
        return -1;
    }

    return opcao;
}
/*---------------------------------------------------------*/
// Controla o menu principal executando as opcoes escolhidas pelo usuario
void menuPrincipal(){
    int opcao;
    
    do {
        opcao = pegaOpcao();

        switch(opcao){
            case 0:
                break;
            case 1:
                acessarSite();
                break;
            case 2:
                verIPDaMaquina();
                break;
            case 3:
                pingarEmUmPC();
                break;
            case 4:
                verInformacoesDoSistema();
                break;
            case 5:
                verListaDeProcessos();
                break;
            case 6:
                limparTela();
                break;
            case 7:
                trocarCor();
                break;
            case 8:
                reiniciarComputador();
                break;
            case 9:
                desligarComputador();
                break;
            case 10:
                verPrevisaoDoTempo();
                break;
            default:
                printf("> Opcao invalida!\n");
        }
    } while (opcao != 0);

    printf("> Programa finalizado com sucesso!\n");
    printaDivisao();
}
/*---------------------------------------------------------*/
// Exibe o IP da maquina usando o comando ipconfig
void verIPDaMaquina(){
    printaDivisao();
    system("ipconfig");
}
/*---------------------------------------------------------*/
// Exibe informacoes do sistema usando o comando systeminfo
void verInformacoesDoSistema(){
    printaDivisao();
    system("systeminfo");
}
/*---------------------------------------------------------*/
// Lista os processos em execucao usando o comando tasklist
void verListaDeProcessos(){
    printaDivisao();
    system("tasklist");
}
/*---------------------------------------------------------*/
// Pinga um PC especifico usando o comando ping
void pingarEmUmPC(){
    printaDivisao();
    char ip[MAX_IP_LENGTH]; 
   
    printf("> Digite o endereco IP que deseja pingar:\n");
    printf("> ");
    scanf("%15s", ip); 
    fflush(stdin);

    char comando[MAX_IP_LENGTH + 6];
    sprintf(comando, "ping %s", ip);

    system(comando);
}
/*---------------------------------------------------------*/
// Limpa a tela do console usando o comando cls
void limparTela(){
    printaDivisao();
    system("cls");
    printf("> Tela limpa!\n");
}
/*---------------------------------------------------------*/
// Altera a cor do console usando o comando color
void trocarCor() {
    int cor;
    printaDivisao();

    printf("> Escolha uma cor:\n");
    printf("  [1] Azul\n");
    printf("  [2] Verde\n");
    printf("  [3] Azul Claro\n");
    printf("  [4] Vermelho\n");
    printf("  [5] Roxo\n");
    printf("  [6] Amarelo\n");
    printf("  [7] Branco\n");
    printf("  [8] Cinza\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> ");

    if (scanf("%d", &cor) != 1) {
        printf("> Opcao invalida!\n");
        limparBuffer();
        return;
    } else {
        if (cor == 0){
            printf("> Operacao cancelada!\n");
            return;
        } else {
            if (cor < 1 || cor > 8) {
                printf("> Opcao invalida!\n");
                return;
            }
        }
    }

    char comando[20];
    sprintf(comando, "color %d", cor);

    system(comando);
    printf("> Cor alterada com sucesso!\n");
}
/*---------------------------------------------------------*/
// Reinicia o computador usando o comando shutdown
void reiniciarComputador(){
    printaDivisao();
    int resposta;

    printf("> Tem certeza que deseja reiniciar o computador? (0-Nao , 1-Sim)\n");
    printf("> ");

    if (scanf("%d", &resposta) != 1) {
        printf("> Operacao cancelada!\n");
        limparBuffer();
        return;
    }

    if (resposta == 1){
        system("shutdown /r /t 0");
    } else {
        printf("> Operacao cancelada!\n");
        return;
    }
}
/*---------------------------------------------------------*/
// Desliga o computador usando o comando shutdown
void desligarComputador(){
    printaDivisao();
    int resposta;

    printf("> Tem certeza que deseja desligar o computador? (0-Nao , 1-Sim)\n");
    printf("> ");

    if (scanf("%d", &resposta) != 1) {
        printf("> Operacao cancelada!\n");
        limparBuffer();
        return;
    }

    if (resposta == 1){
        system("shutdown /s /t 0");
    } else {
        printf("> Operacao cancelada!\n");
        return;
    }
}
/*---------------------------------------------------------*/
// Acessa um site especifico usando o navegador Chrome
void acessarSite() {
    int site;
    printaDivisao();

    printf("> Escolha um Sistema:\n");
    printf("  [1] Intranet\n");
    printf("  [2] E-mail (Zimbra)\n");
    printf("  [3] Chamados (GLPI)\n");
    printf("  [4] Impressoras (CUPS)\n");
    printf("  [5] Inventario (OCS)\n");
    printf("  [6] Ramais\n");
    printf("  [7] Zimbra Admin\n");
    printf("  [8] Site da Camara\n");
    printf("  [9] Processadora de Video\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> ");

    if (scanf("%d", &site) != 1) {
        printf("> Opcao invalida!\n");
        limparBuffer();
        return;
    } else {
        if (site == 0){
            printf("> Operacao cancelada!\n");
            return;
        } else {
            if (site < 1 || site > 9) {
                printf("> Opcao invalida!\n");
                return;
            }
        }
    }

    char *urls[] = {
        "http://intranet.cmcxs.gov.br/",
        "https://zimbra.camaracaxias.rs.gov.br/",
        "https://glpi.camaracaxias.rs.gov.br/",
        "http://172.28.0.93:631/printers",
        "https://ocs.camaracaxias.rs.gov.br/",
        "http://ramais.cmcxs.gov.br/",
        "https://zimbra.camaracaxias.rs.gov.br:7071/zimbraAdmin/",
        "https://www.camaracaxias.rs.gov.br/",
        "https://telao.cmcxs.gov.br/"
    };

    char command[100];
    sprintf(command, "start chrome %s", urls[site - 1]);

    system(command); 
    printf("> Sistema acessado com sucesso!\n");
}
/*---------------------------------------------------------*/
// Exibe a previsao do tempo consultando uma API
void verPrevisaoDoTempo(){
    printaDivisao();
    system("curl wttr.in/caxias");
}
/*---------------------------------------------------------*/