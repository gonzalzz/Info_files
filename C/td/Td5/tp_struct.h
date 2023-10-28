// Tous les protos et déclaration de type

typedef struct array_with_size aws;

struct array_with_size{
    int* t;
    int size;
};

typedef struct matrix_with_size mws;

struct matrix_with_size{
    int** mat;
    int nbl;
    int nbc;
};

aws* new_aws(int n);
mws* new_mws(int n, int m);
void free_mws(mws* a);
void free_aws(aws* a);
void display_aws(aws* tab);
void display_mws(mws* m);
mws* hadamard(mws* m1,mws* m2);
