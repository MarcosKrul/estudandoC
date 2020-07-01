#define TAM 5


typedef struct pilhaEstatica_t PilhaEstatica;


typedef struct {
    int value;
} Integer;


PilhaEstatica* cria_pe();

bool pe_cheia(PilhaEstatica* pe);

bool pe_vazia(PilhaEstatica* pe);

bool inserir_pe(PilhaEstatica* pe, int x);

bool remover_pe(PilhaEstatica* pe);

bool topo_pe(PilhaEstatica* pe, int* x);

int tamanho_pe(PilhaEstatica* pe);

void libera_pe(PilhaEstatica* pe);

void listar_pe(PilhaEstatica* pe);
