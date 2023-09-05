//search.h
int search(char key[], Student list[], int n)
{
    // search for key in list[0] to list[n-1]
    // if found, return the location; if not found, return -1
    for (int h = 0; h < n; h++)
        if (strcmp(key, list[h].name) == 0)
            return h;
    return -1;
} // end search