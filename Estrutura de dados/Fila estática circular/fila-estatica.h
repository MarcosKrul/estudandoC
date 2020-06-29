
#define TAM 5


typedef struct filaEstatica_t FilaEstatica;


typedef struct {
    int value;
} Integer;


FilaEstatica* cria_fe();

bool fe_vazia(FilaEstatica* fe);

bool fe_cheia(FilaEstatica* fe);

bool inserir_fe(FilaEstatica* fe, int x);

bool remover_fe(FilaEstatica* fe);

int tamanho_fe(FilaEstatica* fe);

bool primeiro_fe(FilaEstatica* fe, int* x);

void libera_fe(FilaEstatica* fe);

void listar_fe(FilaEstatica* fe);

// Para testes / monitoramento
void no_descritor(FilaEstatica* fe);
