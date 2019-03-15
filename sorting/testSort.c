#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Item;

void bubbleSort(Item a[], int nitems);
void testBubble(void);
void selectionSort(Item a[], int nitems); 
void testSelection(void);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void testMergeSort(void);
void mergeSortChar(char *arr[], int l, int r);
void mergeChar(char *arr[], int l, int m, int r); 
void testMergeSortChar(void);
int main(int argc, char* argv[]) { 
    testBubble();
    testSelection();
    testMergeSort();
    testMergeSortChar();
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

void mergeSort(int arr[], int l, int r) {
    if (l < r-1){
        int m = l + (r-l)/ 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m, r); 
        merge(arr, l, m, r);
    }

}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;

    int temp1[n1];
    int temp2[n2];

    //copy over contents from arr to temporary array
    for (int i = 0; i < n1; i++) {
        temp1[i] = arr[l + i];
        printf("%d ", temp1[i]);
    }
    printf("\n\n");
    for (int i = 0; i < n2; i++) {
        temp2[i] = arr[m + i];
        printf("%d ", temp2[i]);
    }
    printf("\n\n");

    //merge two temp arrays back into arr
    int t1 = 0, t2 = 0;
    int x = l;    //index for original array

    while (t1 < n1 && t2 < n2) {
        if(temp1[t1] <= temp2[t2]) {
            arr[x] = temp1[t1];
            t1++;
        } else {
            arr[x] = temp2[t2];
            t2++;
        }
        x++;
    }

    //copy over anything remaining
    while(t1 < n1) {
        arr[x] = temp1[t1];
        t1++;
        x++;
    }

    while(t2 < n2) {
        arr[x] = temp2[t2];
        t2++;
        x++;
    }
}

void testMergeSort(void) {
    int test[] = {3, 5, 2, 8, 9, 10, 15, 1};
    printf("Initial:\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

    mergeSort(test, 0, 8);
    printf("After Merge Sort :\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", test[i]);
    }
    printf("\n\n");

}

void mergeSortChar(char *arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSortChar(arr, l, m);
        mergeSortChar(arr, m + 1, r);
        mergeChar(arr, l, m, r);
    }
}

void mergeChar(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    char **tmp1 = malloc(sizeof(char *)*n1);
    char **tmp2 = malloc(sizeof(char *)*n2);

    //copy arr element into
    for(int i = 0; i < n1; i++) {
        tmp1[i] = arr[l+i];
    }

    for(int i = 0; i < n2; i++) {
        tmp2[i] = arr[m + 1 + i];
    }

    //merge two tmp back into arr
    int t1 = 0, t2 =0;
    int x = l;

    while(t1 < n1 && t2 < n2) {
        if(strcmp(tmp1[t1], tmp2[t2]) <= 0)
            arr[x++] = tmp1[t1++];
        else
            arr[x++] = tmp2[t2++];
    }

    while(t1 < n1)
        arr[x++] = tmp1[t1++];

    while(t2 < n2)
        arr[x++] = tmp2[t2++];
    free(tmp1);
    free(tmp2);
}

void testMergeSortChar(void) {
    char *test[] = {"hamsterB", "hamsterA" , "hamsterE",
                            "hamsterD", "hamsterC", "hamsterG", "hamsterF"};
    printf("Initial:\n");
    for(int i = 0; i < 7; i++) {
        printf("%s\n", test[i]);
    }
    printf("\n\n");

    mergeSortChar(test, 0, 6);
    printf("After Merge Sort Char:\n");
    for(int i = 0; i < 7; i++) {
        printf("%s\n", test[i]);
    }
    printf("\n\n");

}
