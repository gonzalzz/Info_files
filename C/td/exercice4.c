#include <stdio.h>
#include <stdbool.h>

int fonct(int l[3]){
printf("heure : ");
    for (int i = 0; i<3;i++){
        scanf("%d",&l[i]);
    }
}

void print_list(int list[], int n)
{
    printf("[");
    for (int i = 0; i<n; i++)
    {
        printf("%i, ", list[i]);
    }
    printf("]\n");
}

int main(void){
    int j[3],g[3];
    int i;
    fonct(j);
    fonct(g);
    while(i<3){
        if (j[i]<g[i]){
            printf("heure 2 supérieure\n");
            i=3;
        }
        else if (j[i]>g[i]){
            printf("heure 1 supérieure\n");
            i=3;
        }
        else{
            if (i=2){
    printf("égalité");
        }
            i=i+1;
        }
        
    }
    print_list(j,3);
    print_list(g,3);
    return 0;
}