# Lista de Comandos: Windows CMD

![GitHub repo size](https://img.shields.io/github/repo-size/pbgollo/comandos-cmd?style=for-the-badge)
![GitHub language count](https://img.shields.io/github/languages/count/pbgollo/comandos-cmd?style=for-the-badge)
![GitHub forks](https://img.shields.io/github/forks/pbgollo/comandos-cmd?style=for-the-badge)

<img src="print.png" alt="Exemplo imagem">

> Este programa oferece uma interface de linha de comando para acessar e executar várias operações comuns do sistema, como acessar sites, verificar informações do sistema, pingar em um PC, entre outras.

## 🔧 Tecnologias Utilizadas

No projeto, a principal tecnologia adotada foi a linguagem de programação C. O código utiliza a função system() para executar comandos do sistema operacional.

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

## 💻 Pré-requisitos

Antes de começar, verifique se você atende aos seguintes requisitos:

- Você tem uma máquina que suporta a execução de programas em C
- Você tem um compilador C instalado (por exemplo, GCC)
- O sistema operacional é Windows

## 🚀 Executando o Projeto

Para compilar e executar o aplicativo, siga estas etapas:

- Abra um terminal e navegue até o diretório onde o arquivo C está localizado
- Compile o código usando o compilador C (por exemplo, `gcc -o comandos .\seu_programa.c`)
- Execute o programa resultante (por exemplo, `.\comcomandos.exe`)

## ☕ Entendendo o Código

O sistema é composto por várias funções que oferecem diferentes funcionalidades:

- A função acessarSite() permite ao usuário acessar sites específicos, como intranet, e-mails, chamados, entre outros.
- A função verIPDaMaquina() exibe o endereço IP da máquina.
- A função verInformacoesDoSistema() mostra informações detalhadas sobre o sistema, como hardware e software.
- A função verListaDeProcessos() lista os processos em execução no sistema.
- A função pingarEmUmPC() permite ao usuário pingar um endereço IP específico.
- A função limparTela() limpa a tela do terminal.
- A função trocarCor() permite ao usuário alterar a cor do terminal.
- As funções reiniciarComputador() e desligarComputador() oferecem a opção de reiniciar ou desligar o computador, respectivamente.
- A função verPrevisaoDoTempo() exibe a previsão do tempo para uma determinada localização.
- Cada função é chamada de acordo com a escolha do usuário no menu principal, que é implementado na função menuPrincipal().

O código é estruturado de forma a utilizar condicionais e loops para controlar o fluxo do programa e interagir com o usuário.

## 🤝 Colaboradores

Agradecemos às seguintes pessoas que contribuíram para este projeto:

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/pbgollo" title="Perfil do Pedro Gollo no GitHub">
        <img src="https://avatars.githubusercontent.com/u/130512644" width="100px;" alt="Foto do Pedro Gollo no GitHub"/><br>
        <sub>
          <b>Pedro Gollo</b>
        </sub>
      </a>
    </td>
  </tr>
</table>
