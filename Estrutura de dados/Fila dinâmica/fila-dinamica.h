
typedef struct noDescritor_t FilaDinamica;


typedef struct {
    int value;
} Integer;


FilaDinamica* cria_fd();

bool fd_vazia(FilaDinamica* fd);

bool inserir_fd(FilaDinamica* fd, int x);

bool remover_fd(FilaDinamica* fd);

bool primeiro_fd(FilaDinamica* fd, int* x);

int tamanho_fd(FilaDinamica* fd);

void listar_fd(FilaDinamica* fd);

void libera_fd(FilaDinamica* fd);
