
typedef struct listaCircular_t* ListaCircular;

typedef struct {
    int value;
} Integer;


ListaCircular* cria_lc();

bool lc_vazia(ListaCircular* lc);

bool inserir_lc_inicio(ListaCircular* lc, int x);

bool inserir_lc_fim(ListaCircular* lc, int x);

bool inserir_lc_pos(ListaCircular* lc, int x, int pos);

bool remover_lc_inicio(ListaCircular* lc);

bool remover_lc_fim(ListaCircular* lc);

bool remover_lc_elemento(ListaCircular* lc, int x);

bool busca_indice_lc(ListaCircular* lc, int pos, int* x);

int tamanho_lc(ListaCircular* lc);

int buscar_lc(ListaCircular* lc, int x);

void libera_lc(ListaCircular* lc);

void listar_lc(ListaCircular* lc);
