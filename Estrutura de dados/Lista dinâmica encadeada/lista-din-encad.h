
typedef struct listaDinEncad_t* ListaDinEncad;

typedef struct {
    int value;
} Integer;


ListaDinEncad* cria_lde();

void libera_lde(ListaDinEncad* lde);

void listar_lde(ListaDinEncad* lde);

bool lde_vazia(ListaDinEncad* lde);

bool buscar_indice_lde(ListaDinEncad* lde, int pos, int* x);

bool inserir_lde_inicio(ListaDinEncad* lde, int x);

bool inserir_lde_fim(ListaDinEncad* lde, int x);

bool inserir_lde_pos(ListaDinEncad* lde, int x, int pos);

bool remover_lde_inicio(ListaDinEncad* lde);

bool remover_lde_fim(ListaDinEncad* lde);

bool remover_lde_elemento(ListaDinEncad* lde, int x);

int tamanho_lde(ListaDinEncad* lde);

int buscar_lde(ListaDinEncad* lde, int x);
