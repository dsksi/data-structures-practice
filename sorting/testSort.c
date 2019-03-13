#include <stdio.h>
#include <stdlib.h>

typedef int Item;

void bubbleSort(Item a[], int nitems);
void testBubble(void);
void selectionSort(Item a[], int nitems); 
void testSelection(void);

int main(int argc, char* argv[]) {
    testBubble();
    testSelection();
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

void testBubble() {
    int test[] = {3, 5, 2, 8, 9, 10, 15, 1};
    printf("Initial:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

    bubbleSort(test, 8);
    printf("After Bubble Sort :\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

}


void selectionSort(Item a[], int nitems) {
    Item *min = NULL;
    int x = 0;
    while(x < nitems) {
        min = &a[x];
        for(int i = x + 1; i < nitems; i++) {
            if(*min > a[i]) {
                 min = &a[i];
    	      }
        }
        Item b = a[x];
        a[x] = *min;
	  *min = b;
        x++;
    }
}

void testSelection(void) {
    int test[] = {3, 5, 2, 8, 9, 10, 15, 1};
    printf("Initial:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

    selectionSort(test, 8);
    printf("After Selection Sort :\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

}
