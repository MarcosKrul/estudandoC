#define _QNT_MAX_ 5

typedef struct listaEstatica_t ListaEstatica;

typedef struct structInt_t {
    int value;
} Integer;


ListaEstatica* cria_le();

void libera_le(ListaEstatica* le);

void listar_le(ListaEstatica* le);

bool le_cheia(ListaEstatica* le);

bool le_vazia(ListaEstatica* le);

bool inserir_le(ListaEstatica* le, int x);

bool inserir_le_inicio(ListaEstatica* le, int x);

bool remover_le(ListaEstatica* le);

bool remover_le_inicio(ListaEstatica* le);

bool remover_le_elemento(ListaEstatica* le, int x);

bool buscar_indice_le(ListaEstatica* le, int pos, int* x);

int tamanho_le(ListaEstatica* le);

int busca_seq_le(ListaEstatica* le, int x);

int busca_bin_le(ListaEstatica* le, int x);

int comparaElementos(const void* p1, const void* p2);
