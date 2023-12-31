//
// Created by Julio Neto on 11/12/23.
//

#include "menu.h"
#include <stdio.h>
#include <string.h>
#include "../produto/produto.h"
#include "../utils/utils.h"

void execucaoMenu();//Função de executar o menu

void menuExibir();//Função de Exibir

void menuInserir();//Função de Inserir

void menuRemover();//Função de Remover

void menuProcurar();//Função de Procurar

void menuTamanho();//Função que verifica o tamanho do vetor e quantas posições estão ocupadas


int opcao;
Estoque estoque;
Produto produto;

// Menu pricipal com as opcoes disponiveis
void menu() {
    // Inicializa o estoque
    inicializarEstoque(&estoque);

    // Recupera os produtos do arquivo dados.txt
    recuperarProdutos(&estoque);

    // Executa o menu
    execucaoMenu();

    while (opcao != 0) {
        switch (opcao) {
            case 1:
                // Exibe o estoque
                printf("\nLISTAR\n\n");
                menuExibir();
                break;
            case 2:
                // Insere um produto
                printf("\nINSERIR\n\n");
                menuInserir();
                break;
            case 3:
                // Remove um produto
                printf("\nREMOVER\n\n");
                menuRemover();
                break;
            case 4:
                // Procura um produto
                printf("\nPROCURAR\n\n");
                menuProcurar();
                break;
            case 5:
                // Verifica o tamanho do estoque
                printf("\nTAMANHO\n\n");
                menuTamanho();
                break;
            default:
                printf("\n\033[1;31m[ ERRO ]: OPÇÃO INVÁLIDA!\033[0m\n\n");
        }
        execucaoMenu();
    }
    printf("Encerrando o programa...\n");
}

// Listagem das principais opções
void listagemDeOpcoes() {
    printf("1 - Listar produtos\n");
    printf("2 - Inserir produto\n");
    printf("3 - Remover produto\n");
    printf("4 - Procurar produto\n");
    printf("5 - Tamanho do estoque\n");
    printf("0 - SAIR\n\n");
}

// Escolha da opção
void escolherOpcao() {
    printf("Digite uma das opções acima: ");
    scanf("%d", &opcao);
}

// Execução do menu
void execucaoMenu() {
    listagemDeOpcoes();
    escolherOpcao();
}

// Exibição do estoque
void menuExibir() {
    exibirEstoque(&estoque);
}

// Inserção de um produto
void menuInserir() {

    printf("Insira o código: ");
    scanf("%d", &produto.codigo);
    limparBufferEntrada();//Removendo o Buffer
    printf("Insira o descricao: ");
    fgets(produto.descricao, 50, stdin);
    produto.descricao[strcspn(produto.descricao, "\n")] = '\0'; // Remove a quebra de linha
    printf("Insira o categoria: ");
    fgets(produto.categoria, 15, stdin);
    produto.categoria[strcspn(produto.categoria, "\n")] = '\0'; // Remove a quebra de linha
    printf("Insira a quantidade: ");
    scanf("%d", &produto.quantidade);
    limparBufferEntrada(); //Removendo o Buffer
    printf("Insira o preço: ");
    scanf("%lf", &produto.preco);
    limparBufferEntrada();
    // Adiciona o produto ao estoque
    adicionarProduto(&estoque, produto.codigo, produto.descricao, produto.categoria, produto.preco, produto.quantidade,
                     'a');
}

// Remoção de um produto
void menuRemover() {
    int codigo;
    printf("Digite o código do produto que deseja remover: ");
    scanf("%d", &codigo);
    removerProduto(&estoque, codigo);
}

// Busca de um produto
void menuProcurar() {
    int codigo;
    printf("Digite o código do produto que deseja buscar: ");
    scanf("%d", &codigo);
    buscarProduto(&estoque, codigo);
}

// Tamanho do estoque e capacidade total
void menuTamanho() {
    printf("Tamanho atual: %d\nCapacidade Total: %d\n\n", tamanhoEstoque(&estoque),
           capacidadeEstoque(&estoque));
}
