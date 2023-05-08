#include "cabecalho.h"

int main()
{
    system("color 1F");
    system("title TECHSYSTEM");

    memset(login, '\0', sizeof(login));
    memset(senha, '\0', sizeof(senha));
    printf("\n\t\t:::::::::::::::::::::::::::::TECHSYSTEM:::::::::::::::::::::::::::::\n\n");
    printf("\n\t\tUsuario: ");
    scanf("%s", login);
    getchar();
    fflush(stdin);
    printf("\n\t\tSenha: ");

    while (ctecla < 15)
    {
        ch = getch();

        switch (ch)
        {
        case BACKSPACE:
            if (ctecla > 0)
            {
                fflush(stdin);
                putch(BACKSPACE);
                ch = '\0';
                senha[ctecla] = ch;
                ctecla--;
                putch(SPACE);
                putch(BACKSPACE);
            }
            break;
        case TAB:
            putch(TAB);
            ctecla = 15;
            break;
        case ENTER:
            putch(ENTER);
            ctecla = 15;
            break;
        default:
            senha[ctecla] = ch;
            putch('*');
            ctecla++;
            break;
        }
    }
    if (strcmp(vlogin, login) == 0 && strcmp(vsenha, senha) == 0)
    {
        while (loop == 0)
        {
            system("cls");
            printf("\n\t\t:::::::::::::::::::::::::::::TECHSYSTEM:::::::::::::::::::::::::::::\n\n");
            printf("\n\t1-EXIBIR CLIENTES\t 2-CADASTRAR CLIENTES\t 3-PRODUTOS\t 4-AGENDAR\t 5-FUNCIONARIOS\t 6-ENCERRAR");
            printf("\n\n\tDigite a opcao: ");
            scanf("%d", &menu);
            getchar();

            switch (menu)
            {
            //////////////////////////EXIBIR CLIENTES////////////////////
            case 1:
                system("cls");
                for (i = 1; i <= op; i++)
                {
                    system("cls");
                    ("\n\t\t:::::::::::::::::::::::::::::LISTA CLIENTES:::::::::::::::::::::::::::::\n\n");
                    printf("\n Nome: %s\n", cadc[i].name);
                    printf("\n CPF: %s\n", cadc[i].doc);
                    printf("\n Telefone: %s\n", cadc[i].telnumber);
                    printf("\n E-mail: %s\n", cadc[i].mail);
                    printf("\n Endereco: %s\n", cadc[i].endc);
                    FILE *clientes_pt;
                    clientes_pt = fopen("cadastro_clientes.txt", "a");
                    fprintf(clientes_pt, "\nNome: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\nEndereco: %s\n", cadc[i].name, cadc[i].doc,
                    cadc[i].telnumber, cadc[i].mail, cadc[i].endc);
                    fclose(clientes_pt);
                    system("pause");
                }
                break;

            case 2:
                system("cls");
                ("\n\t\t:::::::::::::::::::::::::::::CADASTRO CLIENTES:::::::::::::::::::::::::::::\n\n");
                printf("\n\n Quantos cadastros voce deseja realizar?");
                scanf("%d", &op);
                FILE *clientes_pt;
                clientes_pt = fopen("cadastro_clientes.txt", "ab");
                if (clientes_pt == NULL)
                {
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                }
                for (i = 1; i <= op; i++)
                {
                    system("cls");
                    ("\n\t\t:::::::::::::::::::::::::::::CADASTRO CLIENTES:::::::::::::::::::::::::::::\n\n");
                    printf("\n Nome: ");
                    fflush(stdin);
                    scanf("%[^\n]s", cadc[i].name);
                    printf("\n CPF: ");
                    fflush(stdin);
                    scanf("%[^\n]s", cadc[i].doc);
                    printf("\n Telefone: ");
                    fflush(stdin);
                    scanf("%[^\n]s", cadc[i].telnumber);
                    printf("\n E-mail: ");
                    fflush(stdin);
                    scanf("%[^\n]s", cadc[i].mail);
                    printf("\n Endereco: ");
                    fflush(stdin);
                    scanf("%[^\n]s", cadc[i].endc);
                    printf("\n\n\t\t");
                    printf("\n Cliente cadastrado\n\n");
                    fprintf(clientes_pt, "\nNome: %s \nCPF: %s \nTelefone: %s \nE-mail: %s \nEndereco: %s\n", cadc[i].name, cadc[i].doc, cadc[i].telnumber, cadc[i].mail, cadc[i].endc);
                    system("pause");
                    system("cls");
                }
                fclose(clientes_pt);
                break;

            case 3:
                ;
                FILE *arq;
                int op;
                arq = fopen("estoque.txt", "rb+");
                if (arq == NULL)
                {
                    arq = fopen("estoque.txt", "wb+");
                }
                if (arq != NULL)
                {
                    int fim = 0;
                    do
                    {
                        Menu();
                        switch (op2)
                        {
                        case 1:
                            system("cls");
                            cadastro(arq);
                            break;
                        case 2:
                            system("cls");
                            catalogo();
                            break;
                        case 3:
                            system("cls");
                            apagar();
                            break;
                        case 4:
                            fim = 1;
                            break;
                        default:
                            printf("Opcao Invalida\n");
                        }
                    }
                    while (!(fim));
                }
                break;

            case 4:
                ;
                FILE *arq2;
                int opcao;
                arq2 = fopen("agendamentos.txt", "rb+");
                if (arq2 == NULL)
                {
                    arq2 = fopen("agendamentos.txt", "wb+");
                }
                if (arq2 != NULL)
                {
                    int fim = 0;
                    do
                    {
                        Menu2();
                        switch (op4)
                        {
                        case 1:
                            system("cls");
                            cadastrar_agendamento(arq2);
                            break;
                        case 2:
                            system("cls");
                            listar_agendamentos();
                            break;
                        case 3:
                            system("cls");
                            remover_agendamentos();
                            break;
                        case 4:
                            fim = 1;
                            break;
                        default:
                            printf("Opcao Invalida\n");
                        }
                    }
                    while (!(fim));
                }
                break;

            case 5:
                system("cls");
                ("\n\t\t:::::::::::::::::::::::::::::DADOS DO FUNCIONARIO:::::::::::::::::::::::::::::\n\n");
                printf("Nome: ");
                gets(cadf.name);
                printf("Cargo: ");
                gets(cadf.cargo);
                printf("CPF: ");
                gets(cadf.doc);
                printf("E-mail: ");
                gets(cadf.mail);
                printf("Telefone: ");
                gets(cadf.telnumber);

                FILE *logusuarios_ptr;
                logusuarios_ptr = fopen("cadastro-usuarios.txt", "a");
                printf("Login de acesso:\n ");
                scanf("%s", login2);
                fflush(stdin);
                printf("Senha de acesso: \n ");
                scanf("%s", senha2);
                fflush(stdin);
                fprintf(logusuarios_ptr, "\n%s|%s", login2, senha2);
                fclose(logusuarios_ptr);
                printf("usuario cadastrado");

                FILE *funcionarios_ptr;
                funcionarios_ptr = fopen("cadastro-funcionarios.txt", "a");
                fprintf(funcionarios_ptr,"\nfuncionario 1- \n nome: %s \n cargo:%s \n Cpf %s \n email: %s \n telefone %s",cadf.name, cadf.cargo, cadf.doc, cadf.mail, cadf.telnumber);
                fclose(funcionarios_ptr);
                getch();
                break;

            case 6:
                system("cls");
                printf("Sessao encerrada");
                loop = 1;
                break;



            default:
                printf("Opcao invalida");
                getch();
                break;
            }
        }
    }

    else

    {
        bool correto = log_correto(login2, senha2);

        if (correto == true)
        {
            while (loop == 0)
            {
                system("cls");
                printf("\n\t\t:::::::::::::::::::::::::::::TECHSYSTEM:::::::::::::::::::::::::::::\n\n");
                printf("\n\t1-EXIBIR CLIENTES\t 2-CADASTRAR CLIENTES\t 3-PRODUTOS\t 4-AGENDAR 5-ENCERRAR");
                printf("\n\n\tdigite a opcao: ");
                scanf("%d", &menu);
                getchar();

                switch (menu)
                {
                case 1:
                    system("cls");
                    for (i = 1; i <= op; i++)
                    {
                        system("cls");
                        printf("\n\n\t\t\t CLIENTES %d\n", i);
                        printf("\n Nome: %s\n", cadc[i].name);
                        printf("\n CPF: %s\n", cadc[i].doc);
                        printf("\n Telefone: %s\n", cadc[i].telnumber);
                        printf("\n E-mail: %s\n", cadc[i].mail);
                        printf("\n Endereco: %s\n", cadc[i].endc);
                        system("pause");
                    }
                    break;

                case 2:
                    system("cls");
                    printf("\n\nQuantidade de cadastros a ser realizado: ");
                    scanf("%d", &op);
                    for (i = 1; i <= op; i++)
                    {
                        system("cls");
                        printf("\n\n\t\t\t CADASTRO %d\n", i);
                        printf("\n Nome: ");
                        fflush(stdin);
                        scanf("%[^\n]s", cadc[i].name);
                        printf("\n CPF: ");
                        fflush(stdin);
                        scanf("%[^\n]s", cadc[i].doc);
                        printf("\n Telefone: ");
                        fflush(stdin);
                        scanf("%[^\n]s", cadc[i].telnumber);
                        printf("\n E-mail: ");
                        fflush(stdin);
                        scanf("%[^\n]s", cadc[i].mail);
                        printf("\n Endereco: ");
                        fflush(stdin);
                        scanf("%[^\n]s", cadc[i].endc);
                        printf("\n\n\t\t");
                        printf("\n Cadastro realizado\n\n");
                        system("pause");
                        system("cls");
                    }
                    break;

                case 3:
                    ;
                    FILE *arq;
                    int op;
                    arq = fopen("estoque.txt", "rb+");
                    if (arq == NULL)
                    {
                        arq = fopen("estoque.txt", "wb+");
                    }
                    if (arq != NULL)
                    {
                        int fim = 0;
                        do
                        {
                            Menu();
                            switch (op2)
                            {
                            case 1:
                                system("cls");
                                cadastro(arq);
                                break;
                            case 2:
                                system("cls");
                                catalogo();
                                break;
                            case 3:
                                system("cls");
                                apagar();
                                break;
                            case 4:
                                fim = 1;
                                break;
                            default:
                                printf("Opcao Invalida\n");
                            }
                        }
                        while (!(fim));
                    }
                    break;
                case 4:
                    ;
                    FILE *arq2;
                    int opcao;
                    arq2 = fopen("agendamentos.txt", "ab");
                    if (arq2 == NULL)
                    {
                        arq2 = fopen("agendamentos.txt", "ab");
                    }
                    if (arq2 != NULL)
                    {
                        int fim = 0;
                        do
                        {
                            Menu2();
                            switch (op4)
                            {
                            case 1:
                                system("cls");
                                cadastrar_agendamento(arq2);
                                break;
                            case 2:
                                system("cls");
                                listar_agendamentos();
                                break;
                            case 3:
                                system("cls");
                                remover_agendamentos();
                                break;
                            case 4:
                                fim = 1;
                                break;
                            default:
                                printf("Opcao Invalida\n");
                            }
                        }
                        while (!(fim));
                    }
                    break;

                case 5:
                    system("cls");
                    printf("sessao encerrada\n");
                    loop = 1;
                    break;
                default:
                    printf("Opcao invalida\n");
                    getch();
                    break;
                }
            }
        }

        if (correto == false)
        {
            printf("USUARIO OU SENHA INVALIDO\n");
            return 0;
        }
    }
}
