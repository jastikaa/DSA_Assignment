#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int comp = 0, swaps = 0;

void reset() { comp = swaps = 0; }

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bublesort (int arr[], int n) {
    reset();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                swaps++;
            }
        }
}

void selectionSort (int arr[], int n) {
    reset();
    for (int i=0;i<n-1;i++) {
        int min = i;
        for (int j=i+1;j<n;j++) {
            comp++;
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) {
            int t = arr[i];
             arr[i] = arr[min]; 
             arr[min] = t;
            swaps++;
        }
    }
}

void insertionSort (int arr[], int n) {
    reset();
    for (int i=1;i<n;i++) {
        int key = arr[i],j=i-1;
        while (j >= 0) {
            comp++;
            if (arr[j]>key) {
                arr[j+1] =arr[j]; 
                swaps++; j--;
            } else break;
        }
        arr[j+1] = key;
    }
}

void merge(int arr[], int l,int m,int r) {
    int n1 = m-l+1,n2=r-m;

    // Dynamic allocation instead of VLA
    int *L = (int *) malloc(n1 * sizeof(int));
    int *R = (int *) malloc(n2 * sizeof(int));
    if (!L || !R) {
        printf ("Memory allocation failed in merge function!\n");
        exit(1);
    }

    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int j=0;j<n2;j++)R[j]=arr[m+1+j];

    int i =0,j=0, k=l;
    while (i<n1&&j<n2) {
        comp++;
        if (L[i]<=R[j])arr[k++]=L[i++];
        else arr[k++] = R[j++];
        swaps++;  
    }
    while (i<n1) arr[k++]=L[i++];
    while (j<n2)arr[k++]=R[j++];

    free(L);
    free(R);
}

void mergSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l) / 2;
        mergSort(arr, l, m);
        mergSort(arr, m+1,r);
        merge(arr, l, m, r);
    }
}

void mergSortWrapper(int arr[], int n) {
    reset();
    mergSort(arr, 0, n-1);
}

int main() {
    int n, choice;
    printf("Enter N: ");
    scanf("%d", &n);
    if (n <= 0) return 1;

    srand(time(NULL));

    int *arr =(int*) malloc (n * sizeof(int));
    int *copy =(int*) malloc (n * sizeof(int));

    if (arr==NULL || copy==NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Generating %d random numbers [1-1000]...\n", n);
    for (int i =0; i<n; i++) {
        arr[i] = rand()%1000+1;
        copy[i] = arr[i];
    }

    printf("Before: "); print(copy, n);

    printf("\nChoose:\n1.Bubble 2.Selection 3.Insertion 4.Merge\nChoice: ");
    scanf("%d", &choice);

    const char* names[] =   {"Bubble", "Selection", "Insertion", "Merge"} ;
    void (*sorts[])(int[],int) =  {bublesort, selectionSort, insertionSort, mergSortWrapper};

    if (choice >= 1 && choice <= 4) {
        printf("Using %s Sort...\n", names[choice - 1]);
        sorts[choice - 1](copy, n);
    } else {
        printf("Using Bubble Sort...\n");
        bublesort(copy, n);
    }

    printf("After: "); print(copy, n);
    printf("Comparisons: %d, Swaps: %d\n", comp, swaps);

    free(arr);
    free(copy);

    return 0;
}
