/*
Universidade Federal do Maranhão 
Bacharelado Interdisciplinar em Ciência e Tecnologia 
Disciplina: Laboratório de Programação 
Professor:Luiz Henrique Rodrigues 
Discentes:Kauan Garcia Pereira Martins - 2021026595,Dorivan Cunha de Morais - 2021039388, Walter César de Abreu Ferreira - 2021023430
Terceira Avaliação
*/

#include <stdio.h>   //Biblioteca padrão
#include <stdlib.h>  // Alocação de memoria e processamento
#include <stdbool.h> // Incluindo a biblioteca para usar o tipo de dados bool (True e False)
#include <time.h>    // Biblioteca relacionada ao tempo

// Constante com valor de 100
#define Numero_maximo_de_produtos 100

// Estrutura chamada Produto que contem informações de três variaveis
struct Produto
{
    char nome[20];
    int quantidade;
    char validade[10];
};

// Array de estrutura e declaração da variavel Numero_de_Produtos que começa com 0
struct Produto Produtos[Numero_maximo_de_produtos];
int Numero_de_Produtos = 0;

// Função para validar a data fornecida pelo usuario com base na data atual
// É usado o dado booleano (True e False)
bool ValidarData(int dd, int mm, int yy)
{
    // Obter a data atual
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);

    // Comparar a data de validade com a data atual
    if (yy > tm_info.tm_year + 1900 ||
        (yy == tm_info.tm_year + 1900 && mm > tm_info.tm_mon + 1) ||
        (yy == tm_info.tm_year + 1900 && mm == tm_info.tm_mon + 1 && dd >= tm_info.tm_mday))
    {

        // Validar o restante da data
        if (yy >= 2023 && yy <= 100000000)
        {
            if (mm >= 1 && mm <= 12)
            {
                if ((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                {
                    return true;
                }
                else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                {
                    return true;
                }
                else if ((dd >= 1 && dd <= 28) && (mm == 2))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// Função para cadastra produto
void Cadastrar_Produto()
{
    // Condição para verificar se a quantidade de produtos esta no máximo
    if (Numero_de_Produtos == Numero_maximo_de_produtos)
    {
        printf("Numero maximo de produtos atingido.\n");
        return;
    }

    // Estrutura
    struct Produto Novo_Produto;
    printf("Digite o nome do produto: ");
    scanf("%s", Novo_Produto.nome);

    printf("Quantidade: ");
    scanf("%d", &Novo_Produto.quantidade);

    // Solicitar a validade pelo usuario e verificar se a data é validar se não repeti
    // operador ! (nao)
    int dd, mm, yy;
    do
    {
        printf("Digite a Validade nesse formato (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &dd, &mm, &yy);
    } while (!ValidarData(dd, mm, yy));

    sprintf(Novo_Produto.validade, "%02d/%02d/%04d", dd, mm, yy);
    Produtos[Numero_de_Produtos++] = Novo_Produto;

    printf("\n\n");
    printf("Produto registrado.\n\n");
}

// Fun��o para consultar produto
void Produtos_Cadastrados()
{

    // Verifi��o se n�o h� nenhum produto cadastrado
    if (Numero_de_Produtos == 0)
    {
        printf("Produtos cadastrados:\n\n");
        return;
    }

    // Trecho informativo do estoque de produtos
    printf("Registro de Produtos:\n");

    // Condi��o informativa de estoque de produtos
    for (int i = 0; i < Numero_de_Produtos; i++)
    {
        printf("Produto #%d\n", i + 1);
        printf("nome: %s\n", Produtos[i].nome);
        printf("quantidade: %d\n", Produtos[i].quantidade);
        printf("validade: %s\n\n", Produtos[i].validade);
    }
}

// Fun��o para alterar produto
void Alterar_Produto()
{

    // Verifi��o se n�o h� nenhum produto cadastrado
    if (Numero_de_Produtos == 0)
    {
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    // Vari�vel para armazenar o n�mero do produto digitado
    int Lista_de_Produtos;

    // Intera��o com o usu�rio para informar o n�mero do produto a ser alterado
    printf("Digite o numero do produto a ser alterado (1-%d): ", Numero_de_Produtos);
    scanf("%d", &Lista_de_Produtos);

    // Condi��o para analisar se o n�mero digitado condiz com o n�mero de produtos geral
    if (Lista_de_Produtos < 1 || Lista_de_Produtos > Numero_de_Produtos)
    {
        printf("Produto da lista invalido.\n");
        return;
    }

    // Utiliza��o de ponterio para indicar a altera��o de dados de um produto
    struct Produto *Produto = &Produtos[Lista_de_Produtos - 1];

    // Intera��o com o usu�rio para alterar a quantidade
    printf("Digite a nova quantidade: ");
    scanf("%d", &Produto->quantidade);

    // Intera��o com o usu�rio para alterar a validade
    printf("Digite a nova validade: ");
    scanf("%s", Produto->validade);

    // Mensagem de altera��o do produto
    printf("Produto alterado.\n\n");
}

// Fun��o para excluir produto
void Excluir_Produto()
{

    // Verifi��o se n�o h� nenhum produto cadastrado
    if (Numero_de_Produtos == 0)
    {
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    // Vari�vel para armazenar o n�mero do produto digitado
    int Lista_de_Produtos;

    // Intera��o com o usu�rio para informar o n�mero do produto a ser excluido
    printf("Digite o numero do produto a ser excluido (1-%d): ", Numero_de_Produtos);
    scanf("%d", &Lista_de_Produtos);

    // Condi��o para analisar se o n�mero digitado condiz com o n�mero de produtos geral
    if (Lista_de_Produtos < 1 || Lista_de_Produtos > Numero_de_Produtos)
    {
        printf("Produto da lista invalido.\n");
        return;
    }

    // Condi��o para exclus�o do produto ecolhido da lista de produtos
    for (int i = Lista_de_Produtos - 1; i < Numero_de_Produtos - 1; i++)
    {
        Produtos[i] = Produtos[i + 1];
    }

    // Decr�scimo no n�mero de produtos
    Numero_de_Produtos--;

    // Mensagem de exclus�o do produto
    printf("Produto excluido.\n\n");
}

// Escopo de intera��o com o usu�rio
int main()
{
    // Vari�vel do menu de intera��o dos produtos
    int MENU;

    // Estrutura de repeti��o do menu de intera��o dos produtos
    while (1)
    {
        printf("  ----------------------------------------- \n");
        printf("| >>>> SISTEMA DE CONTROLE DE PRODUTOS <<<<|\n");
        printf("  -----------------------------------------\n\n");
        printf("|  1. Cadastrar produto                    |\n");
        printf("|  2. Produtos cadastrados                 |\n");
        printf("|  3. Alterar dados de um produto          |\n");
        printf("|  4. Excluir produto                      |\n");
        printf("|  5. Sair do sistema                      |\n");
        printf("  -----------------------------------------\n\n");
        printf("COLOQUE O NUMERO DA OPCAO ESCOLHIDA: ");

        // Entrada do n�mero da intera��o com o menu
        scanf("%d", &MENU);

        // Direcinamento da intera��o com o menu
        switch (MENU)
        {
        case 1:
            Cadastrar_Produto();
            break;
        case 2:
            Produtos_Cadastrados();
            break;
        case 3:
            Alterar_Produto();
            break;
        case 4:
            Excluir_Produto();
            break;
        case 5:
            printf("Sistema finalizado\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Numero invalido\n\n");
            break;
        }
    }
    return 0;
}
