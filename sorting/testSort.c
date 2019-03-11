#include <stdio.h>
#include <stdlib.h>

typedef int Item;

void bubbleSort(Item a[], int nitems);

int main(int argc, char* argv[]) {
    int test[] = {3, 5, 2, 8, 9, 10, 15, 1};
    printf("Initial:");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

    bubbleSort(test, 8);
    printf("After bubble:");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

    return 0;
}

void bubbleSort(Item a[], int nitems) {
    int x = 0;
    while (x < nitems) {    
        for(Item i = 0; i < nitems-x-1; i++) {
            if (a[i] > a[i+1]) {
                Item b = a[i];
                a[i] = a[i+1];
                a[i+1] = b;
            }
        }
        x++;
    }
}
