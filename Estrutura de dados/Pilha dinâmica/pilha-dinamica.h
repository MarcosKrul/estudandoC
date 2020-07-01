
typedef struct pilhaDinamica_t* PilhaDinamica;


typedef struct {
    int value;
} Integer;


PilhaDinamica* cria_pd();

bool pd_vazia(PilhaDinamica* pd);

bool inserir_pd(PilhaDinamica* pd, int x);

bool topo_pd(PilhaDinamica* pd, int* x);

bool remover_pd(PilhaDinamica* pd);

int tamanho_pd(PilhaDinamica* pd);

void libera_pd(PilhaDinamica* pd);

void listar_pd(PilhaDinamica* pd);
