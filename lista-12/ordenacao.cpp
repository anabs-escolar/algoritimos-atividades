#include "ordenacao.hpp"

bool ordenado(int a[],  unsigned int t){
  for(unsigned int i=0; i+1<t; i++)
    if(a[i] > a[i+1]) return false;
  return true;
};

void selecao(int a[], unsigned int t){
    for (unsigned int i = 0; i + 1 < t; i++) {
        unsigned int min = i;
        for (unsigned int j = i + 1; j < t; j++)
            if (a[j] < a[min])
                min = j;

        if (min != i) {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
        }
    }
}

void insercao(int a[], unsigned int t){
    for (unsigned int i = 1; i < t; i++) {
        int x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
}

void merge_sort(int a[], unsigned int t){
    if (t <= 1)
        return;

    unsigned int left = t / 2;
    unsigned int right = t - left;

    merge_sort(a, left);
    merge_sort(a + left, right);

    int aux[t];
    unsigned int i = 0, j = left, k = 0;
    while (i < left && j < t) {
        if (a[i] <= a[j])
            aux[k++] = a[i++];
        else
            aux[k++] = a[j++];
    }

    while (i < left)
        aux[k++] = a[i++];
    while (j < t)
        aux[k++] = a[j++];

    for (unsigned int x = 0; x < t; x++)
        a[x] = aux[x];
};
