#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 52
#define MAX_TEST 2000
#define TRUE 1
#define FALSE (-1)
#define MAX_CHARS 52

typedef struct node {
    char value;
    struct node *left, *right;
} Node;

int locate(char target, int pos, int h, char *string);
void build_tree(Node *root, int pre_ord_pos, int pre_ord_h, int in_ord_pos, int in_ord_h, char *pre_order, char *in_order);
void print_post_order(Node *root);
void free_tree(Node *root);

int main(void)
{
    
    int test_cases;
    scanf("%d", &test_cases);
    Node *root[test_cases];
    for (int i =0; i < test_cases; i++) {
        int size;
        scanf("%d", &size);
        char pre_order[size], in_order[size];
        build_tree(root[i], 0, size-1, 0, size-1, pre_order, in_order);
        print_post_order(root[i]);
        printf("\n");
        free_tree(root[i]);
    }
    return EXIT_SUCCESS;
}

int locate(char target, int pos, int h, char *string)
{
    for (int i = pos; i <= h; i++) {
        if(string[i] == target) {
            return i;
        } 
    }
}

void build_tree(Node *root, int pre_ord_pos, int pre_ord_h, int in_ord_pos, int in_ord_h, char *pre_order, char *in_order)
{
    char target = pre_order[pre_ord_pos];
    int root_pos = locate(target, in_ord_pos, in_ord_h, in_order);
    root->value = target;

    int left = root_pos - in_ord_pos;
    if (in_ord_pos < root_pos) {
        Node *left_branch = malloc (sizeof (Node));
        root->left = left_branch;
        build_tree(left_branch, pre_ord_pos+1, pre_ord_pos+left, in_ord_pos, root_pos-1, pre_order, in_order);
    }
    if (root_pos < in_ord_h) {
        Node *right_branch = malloc(sizeof(Node));
        root->right = right_branch;
        build_tree(right_branch, pre_ord_pos+left+1, pre_ord_h, root_pos+1, in_ord_h, pre_order, in_order);
    }
}

void print_post_order(Node *root)
{
    if (root == NULL) return;
    print_post_order(root->left);
    print_post_order(root->right);
    printf("%c", root->value);
}

void free_tree(Node *root)
{
    if (root == NULL) return;
    free(root->left);
    free(root->right);
    free(root);
}

