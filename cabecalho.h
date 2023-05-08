#ifndef cabecalho_H
#define cabecalho_H

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>

#define ENTER 13    // CÓDIGO ASCII DA TECLA ENTER
#define BACKSPACE 8 // CÓDIGO ASCII DA TECLA BACKSPACE
#define SPACE 32    // CÓDIGO ASCII DA TECLA BARRA DE ESPACO
#define TAB 9       // CÓDIGO ASCII DA TECLA BACKSPACE
#define ESC 27      // CÓDIGO ASCII DA TECLA ESC

////////////////////////////VARIAVEIS/////////////////////////////

char vlogin[20] = "adm", login[20], login2[20];
char vsenha[20] = "adm2023", senha[20], senha2[20];
int ctecla=0, menu=0, loop=0;
char ch = '\0';
int op, op4, i, px;
int produtos(FILE *arq,int id_prod);
int agendamento(FILE *arq2,int id_agenda);
extern int op2=0;

////////////////////////////FUNCOES/////////////////////////////
bool log_correto(char *user, char *password);
void Menu();
int catalogo (void);
void cadastro();
int Remover(void);

//////////////////////////TELAS DE MENU////////////////////////

void Menu()
{
system("cls");
printf("\n\t\t:::::::::::::::::::::::::::::TECHSYSTEM:::::::::::::::::::::::::::::\n\n");
printf("\n\t 1-CADASTRAR PRODUTO\t 2-CATALOGO \t 3-APAGAR REGISTROS\t 4-MENU INICIAL\n");
printf("\n\n\tdigite a opcao: ");
scanf("%d",&op2);
}

void Menu2()
{
system("cls");
printf("\n\t\t:::::::::::::::::::::::::::::TECHSYSTEM:::::::::::::::::::::::::::::\n\n");
printf("\n\t 1-MARCAR AGENDAMENTO\t 2-LISTA DE AGENDAMENTOS\t 3-REMOVER AGENDAMENTOS\t 4-MENU INICIAL\n");
printf("\n\n\tdigite a opcao: ");
scanf("%d",&op4);
}

//////////////////////////ESTRUTURAS////////////////////////

struct funcionario
{
    char cargo[50];
    char name[50];
    char doc[12];
    char telnumber[12];
    char mail[80];
} cadf;

struct cliente
{
    char name[50];
    char doc[12];
    char telnumber[12];
    char mail[80];
    char endc[50];
} cadc[300];


typedef struct
{
    int id_prod;
    int estoque;
    char nome[100];
    float valor;
} tipoproduto;

int produto(FILE *arq,int id_prod)
{
    tipoproduto tp;
    int posicao =0;
    rewind(arq);
    while(fread(&tp,sizeof(tp),1,arq)!=0)
    {
        if(tp.id_prod==produto)
            return posicao;

        else
            posicao++;
    }
    return -1;
}

//////////////////////////////// CADASTRAR PRODUTOS ////////////////////////////////

void cadastro()
{
    tipoproduto tprod;
    int voltar;
    FILE *arq;

    arq=fopen("estoque.txt","ab+");
    if(arq ==NULL)
    {
        printf("Erro!\n");
        exit(1);

    }
    do
    {
        printf("---------------------------- Cadastro de Produtos ----------------------------");
        printf("\nid do Produto: ");
        scanf("%d",&tprod.id_prod);
        fflush(stdin);

        printf("\nNome: ");
        fgets(tprod.nome,100, stdin);

        printf("\nEstoque: ");
        scanf("%d",&tprod.estoque);
        fflush(stdin);

        printf("\nPreco: R$");
        scanf("%f",&tprod.valor);
        fflush(stdin);

        fseek(arq,0,SEEK_END);
        fwrite(&tprod,sizeof(tipoproduto),1,arq);
        printf("\n\nProduto cadastrado!\n");
        getch();
        printf("\nDigite 1 para continuar ou outro valor para retornar ao menu: ");
        scanf("%d",&px);
        op2++;
    }
    while (px == 1);
    fclose(arq);
    getch();
}

///////////////////////////////////////// CATALOGO ////////////////////////////////

int catalogo (void)
{
    FILE *arq;
    arq = fopen("estoque.txt","rb+");
    if (!arq)
        return 1;
    else
    {
        tipoproduto tp;
        int i=0;
        int voltar;
        struct tipoproduto;
        voltar= fread(&tp,sizeof(tp),1,arq);
        while(voltar==1)
        {

            {
                printf("------------------------------------------------------------");
                printf("\nID Produto: %d\n",tp.id_prod);
                printf("\nNome: %s\n",tp.nome);
                printf("\nEstoque: %d\n",tp.estoque);
                printf("\nPreco: R$%.2f\n",tp.valor);
            }
            i++;
            voltar= fread(&tp,sizeof(tp),1,arq);
        }
        fclose(arq);
    }
    getch();
    return 0;
}

//////////////////////////////////////REMOVER PRODUTOS ////////////////////////////////

int apagar(void)
{
    int op3;
    printf("Apagar todos os registros?");
    printf("\n1-SIM  \n2-NAO:\n");
    scanf("%d",&op3);
    if (op3 == 1)
    {
        FILE * arq;
        arq = fopen("estoque.txt","wb+");
        printf("Registros removidos!");
        fclose(arq);
    }
    getch();
}

/////////////////////////////////AGENDAMENTOS////////////////////////////////

typedef struct
{
    char id_agenda[20];
    char id_cliente[30];
    char endereco[30];
    char id_produto[10];
    char data[20];
    char turno[20];
} agend;


int agendar(FILE *arq2,int id_agenda)
{
    agend ag;
    int posicao =0;
    rewind(arq2);
    while(fread(&ag,sizeof(ag),1,arq2)!=0)
    {
        if(ag.id_agenda==agendar)
            return posicao;

        else
            posicao++;
    }
    return -1;
}
/////////////////////////////////CADASTRAR////////////////////////////////
void cadastrar_agendamento()
{
    agend ag;
    int voltar;
    FILE *arq;

    arq=fopen("cadastrar_agendamento.txt","ab+");
    if(arq ==NULL)
    {
        printf("Erro!\n");
        exit(1);

    }
    do
    {
        printf("::::::::::::::::::::::::::::::: AGENDAMENTO :::::::::::::::::::::::::::::::");
        fflush(stdin);
        printf("\nCliente: ");
        fflush(stdin);
        fgets(ag.id_cliente,100, stdin);

        printf("\nLocal da instalacao: ");
        fflush(stdin);
        fgets(ag.endereco,100, stdin);

        printf("\nData de instalacao: ");
        fflush(stdin);
        fgets(ag.data,100, stdin);

        printf("\nTurno: ");
        fflush(stdin);
        fgets(ag.turno ,100, stdin);

        printf("\nID-Produto: ");
        fflush(stdin);
        fgets(ag.id_produto,100, stdin);



        fseek(arq,0,SEEK_END);
        fwrite(&ag,sizeof(agend),1,arq);
        printf("\n\nagendamento realizado!\n");
        getch();
        printf("\nDigite 1 para continuar ou outro valor para retornar ao menu: ");
        scanf("%d",&px);
        op4++;
    }
    while (px == 1);
    fclose(arq);
    getch();
}

/////////////////////////////////LISTAR AGENDAMENTO////////////////////////////////

int listar_agendamentos (void)
{
    FILE *arq2;
    arq2 = fopen("cadastrar_agendamento.txt", "rb+");
    if (!arq2)
        return 1;
    else
    {
        agend ag;
        int i=0;
        int voltar;
        struct agend;
        voltar= fread(&ag,sizeof(ag),1,arq2);
        while(voltar==1)
        {

            {
                printf("------------------------------------------------------------");
                printf("\nID-Agendamento: %s\n",ag.id_agenda);
                printf("\nData de instalacao: %s\n",ag.data);
                printf("\nCliente: %s\n",ag.id_cliente);
                printf("\nID-Produto: %s\n",ag.id_produto);
            }
            i++;
            voltar= fread(&ag,sizeof(ag),1,arq2);
        }
        fclose(arq2);
    }
    getch();
    return 0;
}
/////////////////////////////////Deletar agendamentos///////////////////////////////////////////////////

void remover_agendamentos()
{
    int opcao;
    printf("Tem certeza que deseja remover todos os agendamentos?\n");
    printf("1 - SIM\n");
    printf("2 - NAO\n");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        FILE *arq2 = fopen("cadastrar_agendamento.txt", "wb");
        fclose(arq2);
        printf("Todos os agendamentos foram removidos.\n");
    }
    else
    {
        printf("Operacao cancelada.\n");
    }
    getch();
}

/////////////////////////////////LOGIN DE USUARIOS////////////////////////////////

bool log_correto(char *user, char *password)
{
    FILE *logusuarios_ptr;
    logusuarios_ptr = fopen("cadastro-usuarios.txt", "r");

    if (!logusuarios_ptr)
    {
        printf("error: não foi possível abrir o arquivo de usuários.");
        return 2;
    }

    char current_line[256];

    while (fgets(current_line, sizeof(current_line), logusuarios_ptr))
    {
        char *current_user = strtok(current_line, "|");
        char *current_password = strtok(NULL, "|");
        // remove o \n da senha
        current_password[strcspn(current_password, "\n")] = '\0';

        if (strcmp(user, current_user) == 0 && strcmp(password, current_password) == 0)
        {
            fclose(logusuarios_ptr);
            return true;
        }
    }
        fclose(logusuarios_ptr);
        return false;
    }
#endif
