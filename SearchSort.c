#include <stdio.h>
#include <stdbool.h>

void enterNum(int choice, int arr[],int arrClone[]);
void displayNum(int choice, int arr[]);
void bubbleSort(int choice, int arr[], int arrClone[]);
void selectionSort(int choice, int arr[], int arrClone[]);
void linearSearch(int choice, int arr[]);
void binarySearch(int choice, int arr[]);

int main()
{
    int choice;
    int arr[10];
    int arrClone[10];

    do
    {
        printf("\n\n=== Menu ===\n");
        printf("1. Enter numbers\n"
                "2. Display Numbers\n"
                "3. Bubble sort\n"
                "4. Selection Sort\n"
                "5. Linear Search\n"
                "6. Binary Search\n"
                "7. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enterNum(choice, arr, arrClone);
                break;
            case 2:
                displayNum(choice, arr);
                break;
            case 3:
                bubbleSort(choice, arr, arrClone);
                break;
            case 4:
                selectionSort(choice, arr, arrClone);
                break;
            case 5:
                linearSearch(choice, arr);
                break;
            case 6:
                binarySearch(choice, arr);
                break;
            case 7:
                printf("Exiting program....");
            default:
                return 0;
                break;
        }

    }while(choice != 7);
    return 0;
};

void enterNum(int choice, int arr[], int arrClone[])
{
    for(int i = 0; i < 10; i++)
    {
        printf("Enter [%d]: ", i);
        scanf("%d", &arr[i]);
        arrClone[i] = arr[i];
    }
}

void displayNum (int choice, int arr[])
{
    printf("List: {");
    for(int i = 0; i < 10; i++)
    {
        printf(" %d,", arr[i]);
    }
    printf("}");
}

void bubbleSort(int choice, int arr[], int arrClone[])
{
    int i, j, temp, n = 10;
    bool swapped;

    printf("List: {");
    for(int i = 0; i < 10; i++)
        {
            printf(" %d,", arrClone[i]);
        }
    printf("}");
    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                    
                    swapped = true;
                }
        }
    }
    printf("\nSorted array(Bubble): ");

    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}");
}

void selectionSort(int choice, int arr[], int arrClone[])
{

    int n =10;
    int min;
    int temp;

    
    printf("List: {");
    for(int i = 0; i < 10; i++)
        {
            printf(" %d,", arrClone[i]);
        }
    printf("}");
    for (int i = 0; i < n - 1; i++) {

        min = i;

        for (int j = i + 1; j < n; j++) {

            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("\nSorted array(Selection): ");

    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}");
}

void linearSearch(int choice, int arr[])
{
    int n = 10;
    int search;
    int found = 0;

    printf("\nEnter Number to search: ");
    scanf("%d", &search);

    for (int i = 0; i < n; i++) {

        if (arr[i] == search) {
            printf("Found at index %d", i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Not found");
    }
}

void binarySearch(int choice, int arr[])
{
    int n = 10;
    int search;
    int left = 0;
    int right = n - 1;
    int found = 0;

    printf("\nEnter Number to search: ");
    scanf("%d", &search);

    while (left <= right) {

        int mid = (left + right) / 2;

        if (arr[mid] == search) {
            printf("Found at index %d", mid);
            found = 1;
            break;
        }
        else if (search < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (found == 0) {
        printf("Not found");
    }

}