// Struct:
typedef struct Contatos { 
    char nome[42];
    char numerotelefone[13]; 
    char aniversario[12]; 
    char email[101];
    char insta[22];
    char twitter[22];
} Contato; 

// Definição das funções que serão utilizadas
void limparTela( );
void menu( );
void saidadoprograma( );
int telefoneJaCadastrado(Contato *novoContato);
void adicionarContato( );
void adicionar_contato_no_arquivo(Contato *novoContato);
void exibirContatos( );
void buscarContato( );
void editarContato( );
void mudarInfo(char* nomeContato, char* tipo, char* novaInfo);
void excluirContato( );
void exibirAgendaCompleta(char *nomeArquivo);
int lerLinhas(FILE *arq);
