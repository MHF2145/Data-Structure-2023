#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mhs
{
    char nrp[10];
    char nama[30];
    int nilai;
    struct mhs *left;
    struct mhs *right;
} mhs;

mhs *input()
{
    mhs *a = (mhs *)malloc(sizeof(mhs));
    printf("nrp   : ");
    scanf("%10s", a->nrp);
    printf("nama  : ");
    scanf("%29s", a->nama);
    printf("nilai : ");
    scanf("%d", &a->nilai);
    a->nrp[9] = '\0';  // Menyimpan null-terminator pada indeks ke-9 (batas maksimal karakter NRP)
    a->nama[29] = '\0'; // Menyimpan null-terminator pada indeks ke-29 (batas maksimal karakter nama)
    a->left = NULL;
    a->right = NULL;
    getchar();  // Menghapus karakter newline yang mungkin tersisa di buffer setelah membaca nilai
    return a;
}

void output(mhs *a)
{
    printf("nrp   = %s\n", a->nrp);
    printf("nama  = %s\n", a->nama);
    printf("nilai = %d\n", a->nilai);
}

void printPreorder(mhs *a)
{
    if (a == NULL)
        return;
    printf("nrp   = %s\n", a->nrp);
    printf("nama  = %s\n", a->nama);
    printf("nilai = %d\n", a->nilai);
    printPreorder(a->left);
    printPreorder(a->right);
}

void deleteTree(mhs *a)
{
    if (a == NULL)
        return;

    deleteTree(a->left);
    deleteTree(a->right);

    free(a);
}

int main()
{
    mhs *root = NULL;
    int choice;
    char cont;

    do
    {
        printf("\nMenu:\n");
        printf("1. Input data\n");
        printf("2. Show data\n");
        printf("3. Delete data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                root = input();
            }
            else
            {
                mhs *temp = input();
                mhs *current = root;
                while (1)
                {
                    if (temp->nilai < current->nilai)
                    {
                        if (current->left == NULL)
                        {
                            current->left = temp;
                            break;
                        }
                        current = current->left;
                    }
                    else
                    {
                        if (current->right == NULL)
                        {
                            current->right = temp;
                            break;
                        }
                        current = current->right;
                    }
                }
            }
            break;

        case 2:
            if (root == NULL)
            {
                printf("No data to show.\n");
            }
            else
            {
                printf("Data:\n");
                printPreorder(root);
            }
            break;

        case 3:
            if (root == NULL)
            {
                printf("No data to delete.\n");
            }
            else
            {
                deleteTree(root);
                root = NULL;
                printf("Data deleted successfully.\n");
            }
            break;

        case 4:
            printf("Exiting program.\n");
            deleteTree(root);
            break;

        default:
            printf("Invalid choice.\n");
        }

        do
        {
            printf("so.... Continue? (y/n): ");
            scanf(" %c", &cont);
        } while (cont != 'y' && cont != 'n');

    } while (cont == 'y');

    return 0;
}
