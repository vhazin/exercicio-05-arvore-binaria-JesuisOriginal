#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define SUCCESS 1


char *build_tree(char *pre_order, char *in_order, int size);
char *sCharSwap(char *str1, int src, int dest);


int main(void)
{
    int c;
    // BinaryTrees MyBinaryTree, *MyBinaryPointer = &MyBinaryTree;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int size;
        getchar();
        scanf("%d", &size);
        
        char pre_order[size], in_order[size], *post_order;
        scanf("%s %s", pre_order, in_order);
        printf("pre=%s pos=%s\n", pre_order, in_order);
        post_order = build_tree(pre_order, in_order, size);
        printf("out\n");
        printf("%s\n", post_order);

    }
    return SUCCESS;
}

char *build_tree(char *pre_order, char *in_order, int size)
{
    char root = pre_order[0], post_order[size], *r1, *rf, *r2, *r3;
    strcpy(post_order, in_order);
    int now = 0, then = 0;
    printf("pre=%s\tpos=%s\n", pre_order, post_order);
    // post_order[size - 1] = root;
    // post_order[0] = xtreme_left;
    // if (size == 3) post_order[2] = pre_order[1];
    for (now = 0; post_order[now] != root; now++);
    then = (size-1) - now;
    printf("now=%d then=%d\n", now, then);
    printf("(size <= 3 && size > 1) = %d\n", (size <= 3 && size > 1));
    printf("(now == 0 && then == 0) = %d\n", (now == 0 && then == 0));
    printf("(now == 0 && then == 0) || (size <= 3 && size > 1) = %d\n", ((now == 0 && then == 0) || (size <= 3 && size > 1)) );
    // return ( ( now == 0 ) ? "" : build_tree( sCharSwap(pre_order, 1, now ), sCharSwap(post_order, 0, now ), size ) ) +
         
    //      ( ( then == 0 ) ? "" : build_tree( sCharSwap(pre_order, 1 + now, then ), sCharSwap(post_order, 1 + now, then ), size) ) +
         
    //         sCharSwap(pre_order,0,1) ;
    if (now == 0)
        return sCharSwap(post_order, now, size-1);
    
    if (now == (size-1))
        {
            strcpy(in_order, post_order);
            printf("%s\n", post_order);
        }
    if (then == 0) {
        r2 = strcat(sCharSwap(pre_order,0,1), "");

    }
    if ((now + 1) != size)
        r1 = strcat(( ( then == 0 ) ? "" : build_tree( sCharSwap(pre_order, 1 + now, then ), sCharSwap(post_order, 1 + now, then ), size) ),
                                                                                                                                             sCharSwap(pre_order,0,1));
    rf = strcat( build_tree( sCharSwap(pre_order, 1, now ), sCharSwap(post_order, 0, now ), size ) , 
                                                                                                     r1);
    return rf;                                                                                                                                    
    // if ((now == 0 && then == 0) || (size <= 3 && size > 1))
    //     return sCharSwap(post_order, 1, 2);
    // else if (then != 0 ) {
    //     printf("then =%d\n", then);
    //     sCharSwap(pre_order, 1, 2);
    //     sCharSwap(pre_order, 1+now, then);
    //     sCharSwap(post_order, 1+now, then);
        

    //     if (now != 0) {
    //         printf("now = %d\n", now);
    //         sCharSwap(pre_order, 1, now);
    //         sCharSwap(pre_order, 1, now);
    //         return strcat( build_tree(sCharSwap(pre_order, 1, now), sCharSwap(pre_order, 1, now), size),
    //                         pre_order);
    //     }
        

    //     return strcat(build_tree(pre_order, post_order, size), pre_order);
    // }
}

char *sCharSwap(char *str1, int src, int dest) 
{
    char temp = str1[src];
    str1[src] = str1[dest];
    str1[dest] = temp;
    return str1;
}

/*
*
 * Pré-ordem: Você deve visitar primeiro a raiz, depois a sub-árvore esquerda e por último a sub-árvore direita. 
 * Em-ordem: Você deve visitar primeiro a sub-árvore esquerda, depois a raiz e por último a sub-árvore direita. 
 * Pós-ordem: Você deve visitar primeiro a sub-árvore esquerda, depois a sub-árvore direita e por último a raiz. 
 * 
 * O conjunto de entrada consiste de um número C ≤ 2000, que dá o número de casos de teste e C linhas, 
 * uma para cada caso de teste. Cada caso de teste começa com um número 1 ≤ N ≤ 52, o número de nós nessa árvore arbitrária. 
 * Depois, há duas cadeias de caracteres S1 e S2 que descrevem o resultado do percurso da árvore em pré-ordem e em-ordem. 
 * Os nós da árvore são rotulados com caracteres diferentes no intervalo a..z e A..Z. Os valores de N, S1 e S2 são separados por um espaço em branco.
 * Saída
 * Para cada conjunto de entrada, você deve imprimir uma linha contendo o percorrimento em pós-ordem da árvore correspondente.
 */