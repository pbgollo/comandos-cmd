/*
  Lista de Comandos - Um programa simples para executar uma variedade de tarefas de sistema.

  Este programa oferece uma interface de linha de comando para acessar e executar varias operacoes
  comuns do sistema, como acessar sites, verificar informacoes do sistema, pingar em um PC, entre outras.

  Como Usar:
  - Execute o programa e siga as instrucoes apresentadas no menu principal.
  - Selecione uma das opcoes disponiveis digitando o numero correspondente e pressionando Enter.
  - Dependendo da opcao selecionada, o programa pode solicitar entradas adicionais, como endereco IP ou opcoes secundarias.
  - Para sair do programa, selecione a opcao "0" no menu principal.

  Requisitos e Dependencias:
  - Este programa foi projetado inicialmente para ser executado em sistemas operacionais baseados no Windows.
  - No entanto, o codigo foi adaptado para funcionar tambem em sistemas operacionais Linux.
  - O compilador C utilizado deve suportar as bibliotecas padrao do C, como stdio.h e stdlib.h.

  Autor: Pedro Gollo
  Data de Criacao: 05/03/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16

int sistemaOperacional;
/*---------------------------------------------------------*/
// Prototipos das funcoes
void verificaSistemaOperacional();
void printaBemVindo();
void printaDivisao();
void limparBuffer();
void printaMensagem(const char *comando);
int pegaOpcaoPrincipal();
int validaOpcao(int numeroDeOpcoes);
void menuPrincipal();
void acessarSite();
void acessarPasta();
void menuDeRede();
void verIPDaMaquina();
void pingarEmUmPC();
void descobrirRotaDoIP();
void verMapeamentoDeRede();
void verEstatisticasDeRede();
void menuPoliticaDeGrupo();
void atualizarPolitica();
void verResultadoDaPolitica();
void menuInformacoes();
void verInformacoesDoSistema();
void listarDrivers();
void verListaDeProcessos();
void menuFuncionalidadesExtras();
void limparTela();
void trocarCor();
void abrirCalculadora();
void abrirBlocoDeNotas();
void menuJogos();
void gerarQuestionario();
void jogarJogoCobra();
void menuDesligarOuReiniciar();
void reiniciarComputador();
void desligarComputador();
void agendarReinicializacao();
void agendarDesligamento();
void cancelarAgendamento();
void verPrevisaoDoTempo();
/*---------------------------------------------------------*/
// Funcao principal
int main(){
    verificaSistemaOperacional();
    printaBemVindo();
    menuPrincipal();
    return 0;
}
/*---------------------------------------------------------*/
// Verifica se o usuario esta executando o programa no Windows ou Linux
void verificaSistemaOperacional(){
    #ifdef __linux__
        sistemaOperacional = 1; 
    #elif _WIN32
        sistemaOperacional = 0;
        system("title Lista de Comandos");
    #else
        printf("Sistema operacional nao reconhecido.\n");
    #endif
}
/*---------------------------------------------------------*/
// Exibe a mensagem de boas-vindas
void printaBemVindo(){
    printf("-----------------------------------------\n");
    printf("*                                       *\n");   
    printf("*            Seja Bem-vindo!            *\n");
    printf("*                                       *\n");
}
/*---------------------------------------------------------*/
// Exibe uma linha de divisao
void printaDivisao(){
    printf("-----------------------------------------\n");
}
/*---------------------------------------------------------*/
// Limpa o buffer do teclado
void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
/*---------------------------------------------------------*/
// Printa a mensagem de sucesso para os comandos
void printaMensagem(const char *comando){
    printf("\n> O comando '%s' foi executado com sucesso!\n", comando);
}
/*---------------------------------------------------------*/
// Obtem e valida opcao escolhida pelo usuario nos menus secundarios
int validaOpcao(int numeroDeOpcoes){
    int resultado;
    int opcao;
    
    if (scanf("%d", &opcao) != 1) {
        printf("> Opcao invalida!\n");
        limparBuffer();
        return -1;
    } else {
        if (opcao == 0){
            printf("> Operacao cancelada!\n");
            return -1;
        } else {
            if (opcao < 1 || opcao > numeroDeOpcoes) {
                printf("> Opcao invalida!\n");
                return -1;
            }
        }
    }
    return opcao;
}
/*---------------------------------------------------------*/
// Obtem a opcao escolhida pelo usuario no menu principal
int pegaOpcaoPrincipal(){
    int opcao;
    
    printaDivisao();
    printf("> Menu Principal:\n");
    printf("  [1] Acessar um Sistema\n");
    printf("  [2] Acessar uma Pasta na Rede\n");
    printf("  [3] Ferramentas de Rede e Conectividade\n");
    printf("  [4] Gerenciamento de Politicas de Grupo\n");
    printf("  [5] Informacoes do Sistema\n");
    printf("  [6] Funcionalidades Extras\n");
    printf("  [7] Reiniciar/Desligar o Computador\n");
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
        opcao = pegaOpcaoPrincipal();

        switch(opcao){
            case 0:
                break;
            case 1:
                acessarSite();
                break;
            case 2:
                acessarPasta();
                break;
            case 3:
                menuDeRede();
                break;
            case 4:
                menuPoliticaDeGrupo();
                break;
            case 5:
                menuInformacoes();
                break;
            case 6:
                menuFuncionalidadesExtras();
                break;
            case 7:
                menuDesligarOuReiniciar();
                break;
            case 10:
                limparTela();
                break;
            case 100:
                menuJogos();
                break;
            default:
                printf("> Opcao invalida!\n");
        }
    } while (opcao != 0);

    printf("> Programa finalizado com sucesso!\n");
    printaDivisao();
}
/*---------------------------------------------------------*/
// Acessa um site especifico usando o navegador
void acessarSite(){
    printaDivisao();

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

    printf("> Menu de Sistemas:\n");
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
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(9);

    if (opcao != -1){
        char comando[100];

        if(sistemaOperacional){
            sprintf(comando, "xdg-open %s > /dev/null 2>&1", urls[opcao - 1]);
        } else {
            sprintf(comando, "start chrome %s", urls[opcao - 1]);
        }
            
        system(comando);
        printaMensagem(comando);
    }
}
/*---------------------------------------------------------*/
// Acessa uma pasta especifica da rede
void acessarPasta(){
    printaDivisao();

    if (sistemaOperacional){
        printf("Desculpe, este comando nao e suportado neste sistema operacional.\n");
        return;
    }

    char *diretorios[] = {
        "\\\\fileserver\\suporte",
        "\\\\fileserver\\temp",
        "\\\\fileserver\\suporte\\softwares",
        "\\\\fileserver\\suporte\\rotinas",
    };

    printf("> Menu de Pastas:\n");
    printf("  [1] Suporte\n");
    printf("  [2] Temp\n");
    printf("  [3] Softwares\n");
    printf("  [4] Rotinas\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(4);

    if (opcao != -1){
        char comando[100];

        sprintf(comando, "start %s", diretorios[opcao - 1]);

        system(comando);
        printaMensagem(comando);
    }
}
/*---------------------------------------------------------*/
// Controla o menu das ferramentas de rede 
void menuDeRede(){
    printaDivisao();

    printf("> Menu de Ferramentas de Rede:\n");
    printf("  [1] Ver IP do Computador\n");
    printf("  [2] Pingar em um IP\n");
    printf("  [3] Descobrir a Rota de um IP\n");
    printf("  [4] Ver Mapeamentos de Rede\n");
    printf("  [5] Exibir Estatisticas de Rede\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(5);

    switch(opcao){
        case 1:
            verIPDaMaquina();
            break;
        case 2:
            pingarEmUmPC();
            break;
        case 3:
            descobrirRotaDoIP();
            break;
        case 4:
            verMapeamentoDeRede();
            break;
        case 5:
            verEstatisticasDeRede();
            break;
    }
}
/*---------------------------------------------------------*/
// Exibe o IP da maquina usando o comando ipconfig
void verIPDaMaquina(){
    printaDivisao();
    char comando[50];

    if(sistemaOperacional){
        strcpy(comando, "ip addr");
    } else {
        strcpy(comando, "ipconfig /all");
    }

    system(comando);
    printaMensagem(comando);
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

    char comando[100];

    if(sistemaOperacional){
        sprintf(comando, "timeout 6s ping %s", ip);
    } else {
        sprintf(comando, "ping %s", ip);
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Rastreia a rota de um IP especifico usando o comando tracert
void descobrirRotaDoIP(){
    printaDivisao();
    char ip[MAX_IP_LENGTH]; 
   
    printf("> Digite o endereco IP que deseja rastrear:\n");
    printf("> ");
    scanf("%15s", ip); 
    fflush(stdin);

    char comando[100];

    if(sistemaOperacional){
        sprintf(comando, "traceroute %s", ip);
    } else {
        sprintf(comando, "tracert %s", ip);
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Exibe os mapeamentos de rede utilizando o comando net use
void verMapeamentoDeRede(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "df -h");
    } else {
        strcpy(comando, "net use");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Exibe as estatisticas de rede utilizando o comando netstat
void verEstatisticasDeRede(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "ss -tuln");
    } else {
        strcpy(comando, "netstat -s -p IP");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Controla o menu de politicas de grupo
void menuPoliticaDeGrupo(){

    if (sistemaOperacional){
        printf("Desculpe, este comando nao e suportado neste sistema operacional.\n");
        return;
    }

    printaDivisao();

    printf("> Menu de Politicas de Grupo:\n");
    printf("  [1] Atualizar Politica de Grupo\n");
    printf("  [2] Ver Resultado da Politica de Grupo\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(2);

    switch(opcao){
        case 1:
            atualizarPolitica();
            break;
        case 2:
            verResultadoDaPolitica();
            break;
    }
}
/*---------------------------------------------------------*/
// Atualiza a politica de grupo utilizando o comando gpupdate
void atualizarPolitica(){
    printaDivisao();
    char comando[50];

    strcpy(comando, "gpupdate /force /boot");

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Exibe o resultado da politica de grupo utilizando o comando gpresult
void verResultadoDaPolitica(){
    printaDivisao();
    char comando[50];

    strcpy(comando, "gpresult /r");

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Controla o menu de informacoes sobre o sistema
void menuInformacoes(){

    printaDivisao();

    printf("> Menu de Informacoes do Sistema:\n");
    printf("  [1] Informacoes do Hardware\n");
    printf("  [2] Listar Drivers Instalados\n");
    printf("  [3] Listar Processos em Execucao\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(2);

    switch(opcao){
        case 1:
            verInformacoesDoSistema();
            break;
        case 2:
            listarDrivers();
            break;
        case 3:
            verListaDeProcessos();
            break;
    }
}
/*---------------------------------------------------------*/
// Exibe informacoes do sistema usando o comando systeminfo
void verInformacoesDoSistema(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "lshw");
    } else {
        strcpy(comando, "systeminfo");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Lista os drivers instalados usando o comando driverquery
void listarDrivers(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "lsmod");
    } else {
        strcpy(comando, "driverquery");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Lista os processos em execucao usando o comando tasklist
void verListaDeProcessos(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "ps aux");
    } else {
        strcpy(comando, "tasklist");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Controla o menu de funcionalidades extras
void menuFuncionalidadesExtras(){
    printaDivisao();

    printf("> Menu de Funcionalidades Extras:\n");
    printf("  [1] Limpar Tela\n");
    printf("  [2] Trocar Cor\n");
    printf("  [3] Ver Previsao do Tempo\n");
    printf("  [4] Abrir a Calculadora\n");
    printf("  [5] Abrir o Bloco de Notas\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(4);

    switch(opcao){
        case 1:
            limparTela();
            break;
        case 2:
            trocarCor();
            break;
        case 3:
            verPrevisaoDoTempo();
            break;
        case 4:
            abrirCalculadora();
            break;
        case 5:
            abrirBlocoDeNotas();
            break;
    }
}
/*---------------------------------------------------------*/
// Limpa a tela do console usando o comando cls
void limparTela(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "clear");
    } else {
        strcpy(comando, "cls");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Altera a cor do console usando o comando color
void trocarCor(){
    printaDivisao();

    if (sistemaOperacional){
        printf("Desculpe, este comando nao e suportado neste sistema operacional.\n");
        return;
    }

    printf("> Menu de Cores:\n");
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
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(8);

    if (opcao != -1){
        char comando[50];
        sprintf(comando, "color %d", opcao);

        system(comando);
        printaMensagem(comando);
    }
}
/*---------------------------------------------------------*/
// Exibe a previsao do tempo consultando uma API
void verPrevisaoDoTempo(){
    printaDivisao();
    char comando[50];

    strcpy(comando, "curl wttr.in/caxias?lang=pt-br^&Q^&F");

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Abre a calculadora
void abrirCalculadora(){
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "gnome-calculator 2>/dev/null");
    } else {
        strcpy(comando, "calc");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Abre o bloco de notas
void abrirBlocoDeNotas(){
    char comando[50];

    if (sistemaOperacional){
        strcpy(comando, "gedit");
    } else {
        strcpy(comando, "notepad");
    }

    system(comando);
    printaMensagem(comando);
}
/*---------------------------------------------------------*/
// Controla o menu de jogos
void menuJogos(){

    printaDivisao();

    printf("> Menu de Jogos:\n");
    printf("  [1] Quiz\n");
    printf("  [2] Snake\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(2);

    switch(opcao){
        case 1:
            gerarQuestionario();
            break;
        case 2:
            jogarJogoCobra();
            break;
    }
}
/*---------------------------------------------------------*/
// Gera um questionario sobre principais comandos de sistema
void gerarQuestionario(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        if (system("python3 --version") == 0) {
            strcpy(comando, "python3 quiz.py");
            system("clear");
            system(comando);
            system("clear");
            printaMensagem(comando);
        } else {
            printf("Python nao esta instalado.\n");
        }
    } else {
        if (system("python --version") == 0) {
            strcpy(comando, "python quiz.py");
            system("cls");
            system(comando);
            system("cls");
            printaMensagem(comando);
        } else {
            printf("Python nao esta instalado.\n");
        }
    }
}
/*---------------------------------------------------------*/
// Inicia o jogo da cobrinha
void jogarJogoCobra(){
    printaDivisao();
    char comando[50];

    if (sistemaOperacional){
        if (system("pip3 show pygame > /dev/null 2>&1") == 0) {
            strcpy(comando, "python3 snake.py");
            system("clear");
            system(comando);
            system("clear");
            printaMensagem(comando);
        } else {
            printf("Pygame nao esta instalado.\n");
        }
    } else {
        if (system("pip show pygame > NUL 2>&1") == 0) {
            strcpy(comando, "python snake.py");
            system("cls");
            system(comando);
            system("cls");
            printaMensagem(comando);
        } else {
            printf("Pygame nao esta instalado.\n");
        }
    }
}
/*---------------------------------------------------------*/
// Controla o menu de desligar/reiniciar o computador
void menuDesligarOuReiniciar(){
    printaDivisao();

    printf("> Menu Reiniciar/Desligar:\n");
    printf("  [1] Reiniciar\n");
    printf("  [2] Desligar\n");
    printf("  [3] Agendar Reinicializacao\n");
    printf("  [4] Agendar Desligamento\n");
    printf("  [5] Cancelar Agendamento\n");
    printf("  [0] Voltar\n");
    printf("\n");
    printf("> Escolha uma opcao:\n");
    printf("> ");

    int opcao = validaOpcao(5);

    switch(opcao){
        case 1:
            reiniciarComputador();
            break;
        case 2:
            desligarComputador();
            break;
        case 3:
            agendarReinicializacao();
            break;
        case 4:
            agendarDesligamento();
            break;
        case 5:
            cancelarAgendamento();
            break;
    }
}
/*---------------------------------------------------------*/
// Reinicia o computador usando o comando shutdown
void reiniciarComputador(){
    printaDivisao();
    char comando[50];

    printf("> Tem certeza que deseja reiniciar o computador? (0-Nao , 1-Sim)\n");
    printf("> ");

    int opcao = validaOpcao(1);

    if (opcao != -1){
        if (opcao == 1){
            if (sistemaOperacional){ 
                strcpy(comando, "shutdown -r -now");
            } else {
                strcpy(comando, "shutdown /r /t 0");
            }
            system(comando);
            printaMensagem(comando);
            exit(0);
        }
    }
}
/*---------------------------------------------------------*/
// Desliga o computador usando o comando shutdown
void desligarComputador(){
    printaDivisao();
    char comando[50];

    printf("> Tem certeza que deseja desligar o computador? (0-Nao , 1-Sim)\n");
    printf("> ");

    int opcao = validaOpcao(1);

    if (opcao != -1){
        if (opcao == 1){
            if (sistemaOperacional){ 
                strcpy(comando, "shutdown -h -now");
            } else {
                strcpy(comando, "shutdown /s /t 0");
            }
            system(comando);
            printaMensagem(comando);
            exit(0);
        }
    }
}
/*---------------------------------------------------------*/
// Funcao para agendar o reiniciamento do computador apos um tempo especificado
void agendarReinicializacao(){
    printaDivisao();
    float minutos;

    printf("> Informe o tempo em minutos para a reinicializacao:\n");
    printf("> ");
    
    if (scanf("%f", &minutos) != 1 || minutos <= 0) {
        printf("> Tempo invalido!\n");
        while (getchar() != '\n');
        return;
    }

    int segundos = (int)(minutos * 60); 

    char comando[50];

    if (sistemaOperacional){
        sprintf(comando, "shutdown -h +%d", (int)(minutos));
    } else {
        sprintf(comando, "shutdown /r /t %d", segundos);
    }

    system(comando);
    printaMensagem(comando);

    printf("> O computador sera reiniciado em %.1f minutos (%d segundos)!\n", minutos, segundos);
}
/*---------------------------------------------------------*/
// Funcao para agendar o desligamento do computador apos um tempo especificado
void agendarDesligamento(){
    printaDivisao();
    float minutos;

    printf("> Informe o tempo em minutos para o desligamento:\n");
    printf("> ");
    
    if (scanf("%f", &minutos) != 1 || minutos <= 0) {
        printf("> Tempo invalido!\n");
        while (getchar() != '\n');
        return;
    }

    int segundos = (int)(minutos * 60); 

    char comando[50];

    if (sistemaOperacional){
        sprintf(comando, "shutdown -h +%d", (int)(minutos));
    } else {
        sprintf(comando, "shutdown /s /t %d", segundos);
    }

    system(comando);
    printaMensagem(comando);

    printf("> O computador sera desligado em %.1f minutos (%d segundos)!\n", minutos, segundos);
}
/*---------------------------------------------------------*/
// Funcao para cancelar o agendamento de reinicializacao/desligamento
void cancelarAgendamento(){
    int retorno;
    char comando[50];

    if (sistemaOperacional){ 
        strcpy(comando, "shutdown -c");
    } else {
        strcpy(comando, "shutdown /a");
    }

    retorno = system(comando);
    printaMensagem(comando);

    if (retorno == 0){
        printf("> O agendamento de reinicializacao/desligamento foi cancelado com sucesso!\n");
    } 
}
/*---------------------------------------------------------*/
