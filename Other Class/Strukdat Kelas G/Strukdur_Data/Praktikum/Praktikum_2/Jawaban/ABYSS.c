#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ll long long

struct BST
{
    ll data;
    int kekuatan;
    struct BST *left;
    struct BST *right;
};

typedef struct BST node;

int data_monster[100][100] = {0}, pwr_monster[100][100] = {0}, z = 0, kapan_mati = 0;

node *createNode(ll n, int p)
{
    node *newnode;
    newnode = malloc(sizeof(node));
    newnode->data = n;
    newnode->kekuatan = p;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node *insert(node *root, ll n, int p, int a)
{
    if (root == NULL)
    {
        if (a > z)
        {
            z = a;
        }
        // printf("di kedalaman: %d [%d]\n", z, a);
        root = createNode(n, p);
    }
    else if (n <= root->data)
    {
        a++;
        root->left = insert(root->left, n, p, a);
    }
    else
    {
        a++;
        root->right = insert(root->right, n, p, a);
    }
    return root;
}

void inorder(node *root, int lvl)
{
    lvl++;
    if (root == NULL)
        return;
    inorder(root->left, lvl);
    // printf("%d [%d] (%d)\n", root->data, lvl, root->kekuatan);
    for (int i = 0; i < 100; i++)
    {
        if (data_monster[lvl][i] == 0)
        {
            data_monster[lvl][i] = root->data;
            pwr_monster[lvl][i] = root->kekuatan;
            printf("%d [%d] (%d) {%d}\n", data_monster[lvl][i], pwr_monster[lvl][i], lvl, i);
            break;
        }
        else
        {
            continue;
        }
    }
    inorder(root->right, lvl);
}

bool tarung(int a)
{
    int b, c = a, d;
    for (int i = z; i >= 0; i--)
    {
        b = 0;
        for (int j = 0; j < 100; j++)
        {
            b += pwr_monster[i][j];
        }
        if (c % 2 == 0)
        {
            d = b * 90 / 100;
            // printf("%d [%d] (%d)\n", b, c, d);
        }
        else
        {
            d = b * 80 / 100;
            // printf("%d [%d] (%d)\n", b, c, d);
        }
        c = c - d;
        if (c < 0)
        {
            // printf("hasil saat mati: %d\n", c);
            kapan_mati = (z + 1) - i;
            return false;
        }
    }
    return true;
}

int main()
{
    node *root = NULL;
    char nama_traveller[50], power_traveller[50], nama_dungeon[50];
    int jumlah_monster, kekuatan_traveller, kekuatan_monster;
    ll data;
    scanf("%s %d %s %d %s", nama_traveller, &jumlah_monster, power_traveller, &kekuatan_traveller, nama_dungeon);
    while (jumlah_monster--)
    {
        scanf("%lld %d", &data, &kekuatan_monster);
        root = insert(root, data, kekuatan_monster, 0);
    }
    inorder(root, -1);
    printf("*****************************************************************************\n");
    printf("The Abyss Game Dungeon %s\n\n", nama_dungeon);
    printf("Traveller : %s\n", nama_traveller);
    printf("Superpower : %s - %d\n", power_traveller, kekuatan_traveller);
    printf("----------------------------------------------------------------------------\n");
    char huruf_monster;
    int dungeon_ke = 1, monster_ke;
    for (int i = z; i > 0; i--)
    {
        huruf_monster = 'A';
        monster_ke = 1;
        printf("Stage %d:\n", dungeon_ke);
        for (int k = 0; k < 100; k++)
        {
            if (data_monster[i][k] != 0)
            {
                printf("Monster %c%d_%d_%d: %d\n", huruf_monster, data_monster[i][k], dungeon_ke, monster_ke, pwr_monster[i][k]);
                monster_ke++;
                huruf_monster++;
            }
        }
        dungeon_ke++;
        printf("\n");
    }

    printf("Final Stage:\n");
    printf("Dark Overlord %s_%d: %d\n\n", nama_dungeon, data_monster[0][0], pwr_monster[0][0]);
    printf("Result:\n");
    if (!tarung(kekuatan_traveller))
    {
        if (kapan_mati == z)
        {
            printf("%s kalah  dan  mati  di  Dungeon %s pada Final Stage\n", nama_traveller, nama_dungeon);
        }
        else
        {
            printf("%s kalah  dan  mati  di  Dungeon %s pada Stage %d\n", nama_traveller, nama_dungeon, kapan_mati);
        }
    }
    else
    {
        printf("%s menang melawan Dark Overlord dan memenangkan game di Dungeon %s\n", nama_traveller, nama_dungeon);
    }
    printf("*****************************************************************************");
    return 0;
}