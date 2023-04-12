#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"

int ceknik(KTP isi_){
    int l = 1, r = size, mid;
    while(l <= r){
        mid = l + (r-l)/2;
        if(isi[mid].NIK == isi_.NIK){
            return 1;
        } else if(isi[mid].NIK > isi_.NIK)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}
