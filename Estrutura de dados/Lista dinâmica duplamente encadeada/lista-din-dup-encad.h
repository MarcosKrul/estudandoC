
typedef struct listaDinEncadDup_t* ListaDinEncadDup;

typedef struct {
    int value;
} Integer;


ListaDinEncadDup* cria_lded();

bool lded_vazia(ListaDinEncadDup* lded);

bool inserir_lded_inicio(ListaDinEncadDup* lded, int x);

bool inserir_lded_fim(ListaDinEncadDup* lded, int x);

bool inserir_lded_pos(ListaDinEncadDup* lded, int x, int pos);

bool remover_lded_inicio(ListaDinEncadDup* lded);

bool remover_lded_fim(ListaDinEncadDup* lded);

bool remover_lded_elemento(ListaDinEncadDup* lded, int x);

bool buscar_indice_lded(ListaDinEncadDup* lded, int pos, int* x);

int tamanho_lded(ListaDinEncadDup* lded);

int buscar_lded(ListaDinEncadDup* lded, int x);

void libera_lded(ListaDinEncadDup* lded);

void listar_lded(ListaDinEncadDup* lded);
