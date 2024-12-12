#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Executed with ./main 100000 100 1000

int n, range, r1, r2, useCounts;
int size;
int *numbersArray;

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == -1 || arr[mid] > x) {
            high = mid - 1;
        }

        else if (arr[mid] < x) {
            low = mid + 1;
        }

        else {
            return mid;
        }
    }
    return low;
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


void test() {

}

int find(int v) {

}

int add(int v) {
    int index = binarySearch(numbersArray, 0, size - 1, v);
    printf("\nIndex: %d\n", index);
    int negativeIndex = -1;
    // find the next -1
    for (int i = index; i < size; i++) {
        if (numbersArray[i] == -1) {
            negativeIndex = i;
            break;  // Stop once the next -1 is found
        }
    }
    
    printf("\nNegative Index Value: %d\n", numbersArray[negativeIndex - 1]);
    for (int j = negativeIndex - 1; j >= index; j--) { 
        numbersArray[j+1] = numbersArray[j];
    }

    numbersArray[index] = v;


    //return index;
}

int delete(int v) {

}

int pred(int v) {

}

int succ(int v) {

}

int min(int v) {

}

int max(int v) {

}

void drive() {
    if (useCounts == 0) {
        size = (int)(1.1 * n);
        
        int newIndex;
        numbersArray = (int*)malloc(size * sizeof(int));
        if (numbersArray == NULL) {
            printf("\nExit!\n");
            exit(1);
        }

        for (int i = 0; i < size; i++) {
            numbersArray[i] = rand() % (range + r1);
        }



        qsort(numbersArray, size, sizeof(int), cmp);

        for (int i = 0; i < size; i+=10) {
            numbersArray[i] = -1;
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", numbersArray[i]);
        }
        printf("\nEND\n");
        add(200);
        for (int i = 0; i < size; i++) {
            printf("%d ", numbersArray[i]);
        }
        add(300);
        for (int i = 0; i < size; i++) {
            printf("%d ", numbersArray[i]);
        }
        
        add(400);
        for (int i = 0; i < size; i++) {
            printf("%d ", numbersArray[i]);
        }
        //free(numbersArray);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    n = 50;
    r1 = atoi(argv[2]);
    r2 = atoi(argv[3]);
    range = r2 - r1 + 1;
    if (range < n) {
        printf("Here!");
        useCounts = 1;
        printf("useCounts = %d\n", useCounts);
        drive();
    } else {
        useCounts = 0;
        drive();
    }

    // Remove the duplicate call to drive()
    if (n < 0) {
        n = abs(n);
        test();
    }
}