#include "bibli.h"
#include "tp_struct.h"

// Tous les tests

void test(){
    aws* p = new_aws(15);
    display_aws(p);
    free_aws(p);
    mws* q = new_mws(5,3);
    display_mws(q);
    free_mws(q);
}

void test_hadamard(){
    mws* m1 = new_mws(3,3);
    mws* m2 = new_mws(3,3);
    m1->mat[1][2] = 6;
    m2->mat[1][2] = 3;
    mws* res = hadamard(m1,m2);
    printf(RED"|||||||||||M1|||||||||\n\n");
    display_mws(m1);
printf(RED"\n|||||||||||M2|||||||||\n\n");
    display_mws(m2);
    printf(RED"\n|||||||||||RES|||||||||\n\n");
    display_mws(res);
    printf("\n");
    free_mws(m1);
    free_mws(m2);
    free_mws(res);
}


int main(int TOTO, char* argv[]){
    printf("%d",TOTO);
    //test();
    test_hadamard();
    return 0;
}