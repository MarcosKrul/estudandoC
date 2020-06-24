
typedef struct noDescritor_t ListaEncadNo;

typedef struct {
    int value;
} Integer;


ListaEncadNo* cria_len();

bool ledn_vazia(ListaEncadNo* len);

bool inserir_len_inicio(ListaEncadNo* len, int x);

bool inserir_len_fim(ListaEncadNo* len, int x);

bool inserir_len_pos(ListaEncadNo* len, int x, int pos);

bool remover_len_inicio(ListaEncadNo* len);

bool remover_len_fim(ListaEncadNo* len);

bool remover_len_elemento(ListaEncadNo* len, int x);

bool buscar_indice_len(ListaEncadNo* len, int pos, int* x);

int tamanho_len(ListaEncadNo* len);

int buscar_len(ListaEncadNo* len, int x);

void libera_len(ListaEncadNo* len);

void listar_len(ListaEncadNo* len);
