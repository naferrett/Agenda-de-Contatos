#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "header.h"

// Definição de códigos ANSI para cores utilizadas.
#define ANSI_WHITE   "\x1b[37m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_CYAN    "\x1b[36m"

FILE* arquivo; 

/*-------------------------------------------------OUTRAS FUNÇÕES-----------------------------------------------------------*/

void menu() {
    printf(":!:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::!:\n");
    printf(":!           :+##+++                                                                                   !:\n");   
    printf(":!        ###:     ###                                                                                 !:\n");
    printf(":!      ##m           ##        M###    .M###    ##m   ## ######    ##    ######  .M###      ####m     !:\n");                    
    printf(":!      ##             ##      ##      ##    ##  ## W  ##   ##    @#  #@    ##   ##    ##   ##         !:\n");                                           
    printf(":!      ##++           ##      ##      ##    MM  ##  W ##   ##   :#____#:   ##   ##    MM    ###_      !:\n");
    printf(":!       ###         ##        ##      ##    MM  ##   W##   ##   ###--###   ##   ##    MM   _   ##:    !:\n");           
    printf(":!         ####...mm##--        M###     ####    ##    ##   ##  @#      #@  ##     ####     :mm#M      !:\n");                                                                                                                                 
    printf(":!       ##           ###                                                                              !:\n");              
    printf(":!    ..##              ##..                                                                           !:\n");
    printf(".!-----------------------------------------------------------------------------------------------------!:\n");
    printf(".!                                                                                                     !:\n");
    printf(".!                                        1. Adicionar Contato                                         !:\n");
    printf(".!                                        2. Exibir Contatos                                           !:\n");
    printf(".!                                        3. Buscar Contato                                            !:\n");
    printf(".!                                        4. Editar Contato                                            !:\n");
    printf(".!                                        5. Excluir Contato                                           !:\n");
    printf(".!                                        6. Exibir Agenda Completa                                    !:\n");
    printf(".!                                        0. Sair                                                      !:\n");
    printf(".!                                                                                                     !:\n");
    printf(".!:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::!:\n");
    
    printf(ANSI_WHITE"\nEscolha uma opção: "ANSI_WHITE);
}

void saidadoprograma() {
    limparTela();
    printf(":!:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::!:\n");
    printf(".!                                                                                                     !:\n");
    printf(".!                                                                                                     !:\n");
    printf(".!                                                              #######################                !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              ##              #                      !:\n");
    printf(".!                                                              ##              ###                    !:\n");
    printf(".!                                                              ##       ############                  !:\n");
    printf(".!                        ..SAINDO DA AGENDA DE CONTATOS...     ##       ##############                !:\n");
    printf(".!                                                              ##       ############                  !:\n");
    printf(".!                                                              ##              ###                    !:\n");
    printf(".!                                                              ##              #                      !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              ##                   ##                !:\n");
    printf(".!                                                              #######################                !:\n");
    printf(".!                                                                                                     !:\n");
    printf(".!:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::!:\n\n");
    return;
}

void limparTela() {
    system("cls");
}

int telefoneJaCadastrado(Contato *novoContato) {
    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        FILE* arq;
        arq = fopen("contatos.txt", "w");
        printf("\nErro ao abrir o arquivo para pesquisar o telefone. Tente novamente.\n");
        fclose(arq);
        return 1;
    }

    char linha [150];
    char procurarTelefone[13];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if(fscanf(arquivo, "TELEFONE: %s\n", procurarTelefone) == 1) {
            if(strcmp(((*novoContato).numerotelefone), procurarTelefone) == 0) {
                printf(ANSI_RED"\n\n                        Já existe um contato cadastrado com esse telefone."ANSI_RED"\n\n");
                printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
                fclose(arquivo);
                return 1;
                break;
            }      
        }     
    }


    fclose(arquivo);
    return 0;
}

/*------------------------------------------------ADICIONAR CONTATO---------------------------------------------------------*/

void adicionarContato() {

    limparTela();

    Contato novoContato;
    printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
    printf(ANSI_WHITE"                                    ------- NOVO CONTATO -------                                          \n\n"ANSI_WHITE);

    getchar();
    printf(ANSI_WHITE"                        Nome: "ANSI_WHITE);
    fflush(stdin); 
    fgets(novoContato.nome, 42, stdin);
    novoContato.nome[strcspn(novoContato.nome, "\n")] = '\0'; 
    
    printf(ANSI_WHITE"                        Telefone: "ANSI_WHITE);
    fflush(stdin); 
    fgets(novoContato.numerotelefone, 13, stdin);
    novoContato.numerotelefone[strcspn(novoContato.numerotelefone, "\n")] = '\0';

    if(telefoneJaCadastrado(&novoContato) == 1) {
        return;
    }
    
    printf(ANSI_WHITE"                        Aniversário (dd/mm/aaaa): "ANSI_WHITE);
    fflush(stdin);
    fgets(novoContato.aniversario, 12, stdin);
    novoContato.aniversario[strcspn(novoContato.aniversario, "\n")] = '\0';
  
    printf(ANSI_WHITE"                        Email: "ANSI_WHITE);
    fflush(stdin);
    fgets(novoContato.email, 101, stdin);
    novoContato.email[strcspn(novoContato.email, "\n")] = '\0';
 
    printf(ANSI_WHITE"                        Instagram: "ANSI_WHITE);
    fflush(stdin);
    fgets(novoContato.insta, 22, stdin);
    novoContato.insta[strcspn(novoContato.insta, "\n")] = '\0';

    printf(ANSI_WHITE"                        Twitter: "ANSI_WHITE);
    fflush(stdin);
    fgets(novoContato.twitter, 22, stdin);
    novoContato.twitter[strcspn(novoContato.twitter, "\n")] = '\0';

    adicionar_contato_no_arquivo(&novoContato);

}

void adicionar_contato_no_arquivo(Contato *novoContato) {

    arquivo = fopen("contatos.txt", "r+");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo de contatos.\n");
        printf("Contato não adicionado.");
        exit(1);
    }

    int totalDeContatos = 0; 
    fscanf(arquivo, "%d", &totalDeContatos); 
    totalDeContatos++;

    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d\n", totalDeContatos); 
    fclose(arquivo);

    arquivo = fopen("contatos.txt", "a+");

    if (arquivo == NULL) {
        printf ("\nErro ao abrir o arquivo de contatos.\n");
        return;
    }

    fprintf(arquivo, "NOME: %s\n", ((*novoContato).nome));
    fprintf(arquivo, "TELEFONE: %s\n", ((*novoContato).numerotelefone));
    fprintf(arquivo, "ANIVERSÁRIO: %s\n", ((*novoContato).aniversario));        
    fprintf(arquivo, "EMAIL: %s\n", ((*novoContato).email));            
    fprintf(arquivo, "INSTAGRAM: %s\n", ((*novoContato).insta));
    fprintf(arquivo, "TWITTER: %s\n", ((*novoContato).twitter));

    printf(ANSI_GREEN"\n\n                                 |----------------------------------|\n"ANSI_GREEN);
    printf(ANSI_GREEN"                                 | "ANSI_GREEN);
    printf(ANSI_WHITE"Contato adicionado com sucesso ✔"ANSI_WHITE);
    printf(ANSI_GREEN" |\n"ANSI_GREEN);
    printf(ANSI_GREEN"                                 |----------------------------------|\n"ANSI_GREEN);            
    printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");

    fclose(arquivo);

}

/*-------------------------------------------------EXIBIR CONTATO-----------------------------------------------------------*/

void exibirContatos() {

    limparTela();

    arquivo = fopen("contatos.txt", "r+");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo de contatos.\n");
        return;
    }

    int qntdContatos = 0;
    fscanf(arquivo, "%d", &qntdContatos);

    char *linhaNome;
    linhaNome = (char*)malloc(52*sizeof(char));

    if (linhaNome == NULL) {
        printf("Memória não alocada.\n");
        return;
    }

    printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n"ANSI_WHITE);
    printf(ANSI_WHITE"                                      ------- CONTATOS -------                                           \n\n"ANSI_WHITE);

    if (qntdContatos == 0){
        printf(ANSI_WHITE"                        Não há "ANSI_WHITE ANSI_YELLOW"nenhum"ANSI_YELLOW ANSI_WHITE" contato salvo.\n\n"ANSI_WHITE);
    }
    else if (qntdContatos == 1) {
        printf(ANSI_WHITE"                        Existe apenas "ANSI_WHITE ANSI_YELLOW"1"ANSI_YELLOW ANSI_WHITE" contato salvo.\n\n"ANSI_WHITE);
    }
    else {
        printf(ANSI_WHITE"                        Existem "ANSI_WHITE ANSI_YELLOW"%d"ANSI_YELLOW ANSI_WHITE" contatos salvos.\n\n"ANSI_WHITE, qntdContatos);
    }
    
    while(fgets(linhaNome, 52, arquivo) != NULL) {
        if(strstr(linhaNome, "NOME:") != NULL) {
            printf("                        %s", linhaNome);
        }
    }

    printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
    getchar();
    
    free(linhaNome);
    fclose(arquivo);
    
}

/*-------------------------------------------------BUSCAR CONTATO-----------------------------------------------------------*/

void buscarContato() {

    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char simNao[10];

    char *contatoBuscado = (char*)malloc(42*sizeof(char));

    if (contatoBuscado == NULL) {
        printf("Memória não alocada.\n");
        return;
    }

    do {

        limparTela();

        int contatoEncontrado = 0;
        printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n"ANSI_WHITE);
        printf(ANSI_WHITE"                                   ------- BUSCAR CONTATO -------                                        \n\n"ANSI_WHITE);
        printf(ANSI_WHITE"                             🔍︎ Digite o contato para busca:"ANSI_WHITE);
        scanf("%s", contatoBuscado);
        
        int qtndContatos;
        char procurarNome[42];
        char procurarTelefone[13];
        char procurarAniversario[12];
        char procurarEmail[101];
        char procurarInsta[22];
        char procurarTT[22];

        fscanf(arquivo, "%d\n", &qtndContatos);
        while (fscanf(arquivo, "NOME: %s\n", procurarNome) == 1) {
            fscanf(arquivo, "TELEFONE: %s\n", procurarTelefone);
            fscanf(arquivo, "ANIVERSÁRIO: %s\n", procurarAniversario);
            fscanf(arquivo, "EMAIL: %s\n", procurarEmail);
            fscanf(arquivo, "INSTAGRAM: %s\n", procurarInsta);
            fscanf(arquivo, "TWITTER: %s\n", procurarTT);

            if (strcmp(contatoBuscado, procurarNome) == 0) {
                printf(ANSI_CYAN"\n                                   = ----------CONTATO----------"ANSI_CYAN"\n");
                printf(ANSI_CYAN"                                   + NOME:"ANSI_CYAN " %s\n", procurarNome);
                printf(ANSI_CYAN"                                   + TELEFONE:"ANSI_CYAN " %s\n", procurarTelefone);
                printf(ANSI_CYAN"                                   + ANIVERSÁRIO:"ANSI_CYAN " %s\n", procurarAniversario);
                printf(ANSI_CYAN"                                   + EMAIL:"ANSI_CYAN " %s\n", procurarEmail);
                printf(ANSI_CYAN"                                   + INSTAGRAM:"ANSI_CYAN " %s\n", procurarInsta);
                printf(ANSI_CYAN"                                   + TWITTER:"ANSI_CYAN " %s\n", procurarTT);
                printf(ANSI_CYAN"                                   = ----------------------------"ANSI_CYAN"\n\n");
                printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
                contatoEncontrado = 1;
                break;
            }
        }

        if (contatoEncontrado == 0) {
            printf(ANSI_RED"\n                          Esse contato não existe ou não foi encontrado."ANSI_RED"\n\n");
            printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
        }

        printf("\n                       Deseja realizar outra busca? Digite 'SIM' ou 'NÃO': ");
        scanf("%s", simNao);
        fseek(arquivo, 0, SEEK_SET); 

    } while (strcmp(simNao, "SIM") == 0);

    free(contatoBuscado);
    fclose(arquivo);
    limparTela();
    getchar();
}

/*-------------------------------------------------EDITAR CONTATO-----------------------------------------------------------*/

void mudarInfo(char *nomeContato, char *tipo, char *novaInfo) {
    
    arquivo = fopen("contatos.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int quantidade_contatos;
    fscanf(arquivo, "%d\n", &quantidade_contatos);

    FILE* arquivo2;
    arquivo2 = fopen("dois.txt", "w"); 

    if (arquivo2 == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo2, "%d\n", quantidade_contatos); 
    char linha[150];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        if (strstr(linha, nomeContato) != NULL) {
            
            if(strcmp(tipo, "NOME") == 0) {
                fprintf(arquivo2, "NOME: %s\n", novaInfo);
            } 

            else {
                fprintf(arquivo2, "NOME: %s\n", nomeContato); 
                while (fgets(linha, sizeof(linha), arquivo) != NULL)  { 

                    if (strstr(linha, tipo) != NULL) {

                        fprintf(arquivo2, "%s: %s\n", tipo, novaInfo); 
                        break; 
                    }
                    else {
                        fprintf (arquivo2, "%s", linha);
                    }
                }
            }
        } 
        
        else {
            fprintf(arquivo2, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(arquivo2);

    remove("contatos.txt"); 
    rename("dois.txt", "contatos.txt"); 
  
}

void editarContato() {

    char simNao[10];

    do {
        limparTela();
        arquivo = fopen("contatos.txt", "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        char contatoParaEditar[42]; 
        printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
        printf(ANSI_WHITE"                                   ------- EDITAR CONTATO -------                                        \n\n"ANSI_WHITE);
        printf(ANSI_WHITE"                       🖉  Digite o nome do contato que deseja editar:"ANSI_WHITE);
        scanf("%s", contatoParaEditar);

        int quantidade_contatos;
        char procurarNome[42];
        char procurarTelefone[13];
        char procurarAniversario[13];
        char procurarEmail[101];
        char procurarInsta[22];
        char procurarTT[22];

        int contatoEncontrado = 0;

        fscanf(arquivo, "%d\n", &quantidade_contatos); 
        while (fscanf(arquivo, "NOME: %s\n", procurarNome) == 1) { 
            fscanf(arquivo, "TELEFONE: %s\n", procurarTelefone);
            fscanf(arquivo, "ANIVERSÁRIO: %s\n", procurarAniversario);
            fscanf(arquivo, "EMAIL: %s\n", procurarEmail);
            fscanf(arquivo, "INSTAGRAM: %s\n", procurarInsta);
            fscanf(arquivo, "TWITTER: %s\n", procurarTT);

            if (strcmp(contatoParaEditar, procurarNome) == 0) {
                printf(ANSI_CYAN"\n                                   = ----------CONTATO----------"ANSI_CYAN"\n");
                printf(ANSI_CYAN"                                   + NOME:"ANSI_CYAN " %s\n", procurarNome);
                printf(ANSI_CYAN"                                   + TELEFONE:"ANSI_CYAN " %s\n", procurarTelefone);
                printf(ANSI_CYAN"                                   + ANIVERSÁRIO:"ANSI_CYAN " %s\n", procurarAniversario);
                printf(ANSI_CYAN"                                   + EMAIL:"ANSI_CYAN " %s\n", procurarEmail);
                printf(ANSI_CYAN"                                   + INSTAGRAM:"ANSI_CYAN " %s\n", procurarInsta);
                printf(ANSI_CYAN"                                   + TWITTER:"ANSI_CYAN " %s\n", procurarTT);
                printf(ANSI_CYAN"                                   = ----------------------------"ANSI_CYAN"\n\n");
                contatoEncontrado = 1;
                break; 
            }
        }
        
        fclose(arquivo); 


        if(contatoEncontrado == 0) { 
            printf(ANSI_RED"\n                          Esse contato não existe ou não foi encontrado."ANSI_RED);
            printf(ANSI_WHITE"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
        }

        else {
            int opcao;

            printf(ANSI_WHITE"                                   Selecione que você deseja mudar desse contato?\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   1. Mudar Nome\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   2. Mudar Telefone\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   3. Mudar Aniversario\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   4. Mudar Email\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   5. Mudar Instagram\n"ANSI_WHITE);
            printf(ANSI_WHITE"                                   6. Mudar Twitter\n"ANSI_WHITE);
            printf(ANSI_WHITE"\n                                   Digite a opção desejada: "ANSI_WHITE);
            scanf("%d", &opcao);

            char mudanca[101]; 
            switch (opcao) {
                case 1:
                    printf(ANSI_WHITE"                                   Digite o novo NOME do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "NOME", mudanca); 
                    break;

                case 2:
                    printf(ANSI_WHITE"                                   Digite o novo TELEFONE do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "TELEFONE", mudanca);
                    break;

                case 3:
                    printf(ANSI_WHITE"                                   Digite o novo ANIVERSÁRIO do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "ANIVERSÁRIO", mudanca);
                    break;

                case 4:
                    printf(ANSI_WHITE"                                   Digite o novo EMAIL do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "EMAIL", mudanca);
                    break;

                case 5:
                    printf(ANSI_WHITE"                                   Digite o novo INSTAGRAM do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "INSTAGRAM", mudanca);
                    break;

                case 6:
                    printf(ANSI_WHITE"                                   Digite o novo TWITTER do contato: "ANSI_WHITE);
                    scanf("%s", mudanca);
                    mudarInfo(contatoParaEditar, "TWITTER", mudanca);
                    break;

                default:
                    printf(ANSI_RED"                                   A opção digitada não existe. Tente novamente\n"ANSI_RED);
                    printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
                    getchar();
                    return;
            }

            printf(ANSI_GREEN"\n\n                                 |----------------------------------|\n"ANSI_GREEN);
            printf(ANSI_GREEN"                                 | "ANSI_GREEN);
            printf(ANSI_WHITE"Contato modificado com sucesso ✔"ANSI_WHITE);
            printf(ANSI_GREEN" |\n"ANSI_GREEN);
            printf(ANSI_GREEN"                                 |----------------------------------|\n"ANSI_GREEN); 
            printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
        }

        printf("\n                       Deseja editar outro contato? Digite 'SIM' ou 'NÃO': ");
        scanf("%s", simNao);

    } while(strcmp(simNao, "SIM") == 0);


    limparTela();
    getchar();
}

/*-------------------------------------------------EXCLUIR CONTATO----------------------------------------------------------*/

void excluirContato() {

    char simNao[10];
        
    do {
        arquivo = fopen("contatos.txt", "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        FILE* arquivo2;
        arquivo2 = fopen("dois.txt", "w"); 

        if (arquivo2 == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return;
        }

        limparTela();
        char contatoParaExcluir[42];
        printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n"ANSI_WHITE);
        printf(ANSI_WHITE"                                   ------- EXCLUIR CONTATO -------                                       \n\n"ANSI_WHITE);
        printf(ANSI_WHITE"                       ⓧ  Digite o nome do contato que deseja excluir: "ANSI_WHITE);
        scanf("%s", contatoParaExcluir);

        int quantidade_contatos = 0;
        int quantidade_excluidos = 0;
        char procurarNome[42];
        char procurarTelefone[13];
        char procurarAniversario[12];
        char procurarEmail[101];
        char procurarInsta[22];
        char procurarTT[22]; 

        int contatoEncontrado = 0;
    
        
        fscanf(arquivo, "%d\n", &quantidade_contatos); 
        fprintf(arquivo2, "%d\n", quantidade_contatos);

        while (fscanf(arquivo, "NOME: %s\n", procurarNome) == 1) {
            fscanf(arquivo, "TELEFONE: %s\n", procurarTelefone);
            fscanf(arquivo, "ANIVERSÁRIO: %s\n", procurarAniversario);
            fscanf(arquivo, "EMAIL: %s\n", procurarEmail);
            fscanf(arquivo, "INSTAGRAM: %s\n", procurarInsta);
            fscanf(arquivo, "TWITTER: %s\n", procurarTT);   

            if (strcmp(contatoParaExcluir, procurarNome) == 0) { 
                contatoEncontrado = 1;
                printf(ANSI_WHITE"\n                         Esse é o contato que você quer excluir?:\n"ANSI_WHITE);
                printf(ANSI_CYAN"\n                                   = ----------CONTATO----------"ANSI_CYAN"\n");
                printf(ANSI_CYAN"                                   + NOME:"ANSI_CYAN " %s\n", procurarNome);
                printf(ANSI_CYAN"                                   + TELEFONE:"ANSI_CYAN " %s\n", procurarTelefone);
                printf(ANSI_CYAN"                                   + ANIVERSÁRIO:"ANSI_CYAN " %s\n", procurarAniversario);
                printf(ANSI_CYAN"                                   + EMAIL:"ANSI_CYAN " %s\n", procurarEmail);
                printf(ANSI_CYAN"                                   + INSTAGRAM:"ANSI_CYAN " %s\n", procurarInsta);
                printf(ANSI_CYAN"                                   + TWITTER:"ANSI_CYAN " %s\n", procurarTT);
                printf(ANSI_CYAN"                                   = ----------------------------"ANSI_CYAN"\n\n");
                printf(ANSI_WHITE"\n                         Digite \"SIM\" para caso afirmativo e \"NÃO\" para caso negativo: "ANSI_WHITE);
                scanf("%s", simNao);

                    if(strcmp(simNao, "SIM") == 0) {
                        quantidade_excluidos++;
                        limparTela();
                        printf(ANSI_GREEN"\n                                 |----------------------------------|\n"ANSI_GREEN);
                        printf(ANSI_GREEN"                                 |  "ANSI_GREEN);
                        printf(ANSI_WHITE"Contato"ANSI_WHITE ANSI_RED" excluido"ANSI_RED ANSI_WHITE" com sucesso ✔"ANSI_WHITE);
                        printf(ANSI_GREEN"  |\n"ANSI_GREEN);
                        printf(ANSI_GREEN"                                 |----------------------------------|\n"ANSI_GREEN); 
                        printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
                    }
                    
                    else {
                        quantidade_excluidos = quantidade_excluidos;
                        limparTela();
                        printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"ANSI_WHITE);
                        printf(ANSI_YELLOW"\n                                   |--------------------------------|\n"ANSI_YELLOW);
                        printf(ANSI_YELLOW"\n                                   |  ");
                        printf(ANSI_WHITE"O contato não foi excluído ✘"ANSI_WHITE);
                        printf(ANSI_YELLOW"  |\n"ANSI_YELLOW);
                        printf(ANSI_YELLOW"\n                                   |--------------------------------|\n"ANSI_YELLOW);
                        printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"ANSI_WHITE);
                        fprintf(arquivo2, "NOME: %s\n", procurarNome);
                        fprintf(arquivo2, "TELEFONE: %s\n", procurarTelefone);
                        fprintf(arquivo2, "ANIVERSÁRIO: %s\n", procurarAniversario);
                        fprintf(arquivo2, "EMAIL: %s\n", procurarEmail);
                        fprintf(arquivo2, "INSTAGRAM: %s\n", procurarInsta);
                        fprintf(arquivo2, "TWITTER: %s\n", procurarTT);
                    }
            } 

            else {
                fprintf(arquivo2, "NOME: %s\n", procurarNome);
                fprintf(arquivo2, "TELEFONE: %s\n", procurarTelefone);
                fprintf(arquivo2, "ANIVERSÁRIO: %s\n", procurarAniversario);
                fprintf(arquivo2, "EMAIL: %s\n", procurarEmail);
                fprintf(arquivo2, "INSTAGRAM: %s\n", procurarInsta);
                fprintf(arquivo2, "TWITTER: %s\n", procurarTT);
            }

        }

        quantidade_contatos = quantidade_contatos - quantidade_excluidos;
        fseek(arquivo2, 0, SEEK_SET);
        fprintf(arquivo2, "%d", quantidade_contatos);

        fclose(arquivo);
        fclose(arquivo2);

        remove("contatos.txt");
        rename("dois.txt", "contatos.txt");


        if (contatoEncontrado == 0) {
            printf(ANSI_RED"\n                          Esse contato não existe ou não foi encontrado."ANSI_RED);
            printf(ANSI_WHITE"\n\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n");
         }

        printf("\n                       Deseja excluir outro contato? Digite 'SIM' ou 'NÃO': ");
        scanf("%s", simNao);

    } while (strcmp(simNao, "SIM") == 0);

    limparTela();
    getchar();
    
}

/*---------------------------------------------EXIBIR AGENDA COMPLETA-------------------------------------------------------*/

int lerLinhas(FILE *arq) {
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo de contatos.\n");
        return 1;
    }

    char *linha = (char*)malloc(150*sizeof(char));

    if (fgets(linha, 150, arq) != NULL) {
        printf(ANSI_WHITE"                        %s"ANSI_WHITE, linha);
        free(linha);
        return(lerLinhas(arq));

    } else {
        return 1;
    }
    free(linha);

}

void exibirAgendaCompleta(char *nomeArquivo) {
    limparTela();
    int quantidade_contatos = 0;

    printf(ANSI_WHITE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n"ANSI_WHITE);
    printf(ANSI_WHITE"                            ------------- AGENDA COMPLETA ------------                                   \n\n"ANSI_WHITE);
    printf(ANSI_WHITE"                        Total de contatos salvos: "ANSI_WHITE);

    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo de contatos.\n");
        return;
    }

    fscanf(arquivo, "%d\n", &quantidade_contatos);
    printf(ANSI_YELLOW"%d"ANSI_YELLOW "\n\n", quantidade_contatos);

    lerLinhas(arquivo);

    printf(ANSI_WHITE"\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"ANSI_WHITE"\n\n");
    getchar();

    fclose(arquivo);
}

/*-----------------------------------------------------MAIN-----------------------------------------------------------------*/

int main() {

    setlocale(LC_ALL, "pt-BR");

    int opcao;

    do {

        limparTela();
        menu();
        scanf(" %d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;

            case 2:
                exibirContatos();     
                break;

            case 3:
                buscarContato();
                break;

            case 4:
                editarContato();
                break;

            case 5:
                excluirContato();
                break; 

            case 6:
                exibirAgendaCompleta("contatos.txt");
                break;

            case 0:
                saidadoprograma();
                break;

            default:
                limparTela();
                printf ("✘ Opção Inválida. Tente novamente.\n");
                getchar();
                break;
        }

        printf("\nPressione Enter para continuar...");
        getchar();
        
        limparTela();
       

    } while (opcao != 0);

    return 0;   
}
