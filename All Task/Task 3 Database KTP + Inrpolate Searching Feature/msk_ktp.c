#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fungsi.h"


void msk_ktp(KTP isi_)
{
	if(size == 0)
    {
		isi[++size] = isi_;
		return;
	}
    int l = 1, r = size, mid, idx = size+1, i;
    while(l <= r)
    {
        mid = l + (r-l)/2;
        if(isi[mid].NIK > isi_.NIK)
        {
            idx = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    size++;
    for(i = size; i > idx; i--)
    {
        isi[i] = isi[i-1];
	}
    isi[idx] = isi_;
}
