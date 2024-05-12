#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int tablou[], int n){
    int ok;
    for(int i=0;i<n-1;i++){
        ok=0;
        for(int j=0;j<n-i-1;j++){
            if (tablou[j]>tablou[j+1]){
                swap(&tablou[j],&tablou[j+1]);
                ok=1;
            }
        }
        if(ok==0){
            break;
        }
    }

}
void quick_sort(int tab[], int low, int high) {
    if (low < high) {
        int pivot = tab[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (tab[j] <= pivot) {
                i++;
                swap(&tab[i], &tab[j]);
            }
        }
        swap(&tab[i + 1], &tab[high]);

        int pi = i + 1;

        quick_sort(tab, low, pi - 1);
        quick_sort(tab, pi + 1, high);
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l<r) {
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        int n1=m-l+1;
        int n2=r-m;

        int L[n1], R[n2];

        for(int i=0;i<n1;i++)
            L[i]=arr[l+i];
        for(int j=0;j<n2;j++)
            R[j]=arr[m+1+j];

        int i=0,j=0,k=l;

        while(i<n1 && j<n2) {
            if (L[i]<=R[j]) {
                arr[k]=L[i];
                i++;
            } else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }

        while(j<n2) {
            arr[k]=R[j];
            j++;
            k++;
        }
    }
}
void insertionSort(int arr[], int n) {
    int  key,j;
    for (int i=1; i<n; i++) {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void selectionSort(int arr[], int n) {
    int i,j,minIndex,temp;
    for (i=0;i<n-1;i++) {
        minIndex=i;
        for(j=i+1;j<n;j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        temp=arr[minIndex];
        arr[minIndex]=arr[i];
        arr[i]=temp;
    }
}



void print_tab(int tablou[],int size){
    for(int i=0;i<size;i++){
        printf("%d", tablou[i]);
        printf("\n");
    }
}
FILE *file;
void random_elements(int n){
    file=fopen("C:\\Users\\Matei Albu\\CLionProjects\\untitled2\\elementein.txt", "w");
    for (int i = 0;i <n;i++){
        fprintf(file,"%d", rand());
        fprintf(file," ");
    }
    fclose(file);
}
void creazatablou(int n,int tab[]){
    file=fopen("C:\\Users\\Matei Albu\\CLionProjects\\untitled2\\elementein.txt", "r");
    for (int i=0;i<n;i++){
        fscanf(file, "%d", &tab[i]);
    }
    fclose(file);
}
void afiseaza(int tab[],int n){
    for(int i=0;i<n;i++){
        printf("%d",tab[i]);
        printf("\n");
    }

}
void afiseaza_fisier(int tab[],int n){
    file=fopen("C:\\Users\\Matei Albu\\CLionProjects\\untitled2\\elementein.txt", "w");
    for(int i=0;i<n;i++){
        fprintf(file,"%d ",tab[i]);
    }
    fclose(file);
}
void sort_desc(int tab[],int n){
    int inceput=0;
    int final=n-1;
    while(inceput<final){
        swap(&tab[inceput],&tab[final]);
        inceput++;
        final--;
    }
}

int main(){
    //int nr=100000;
    //random_elements(nr);
    int n,tab[100000];
    n=sizeof (tab)/sizeof (tab[0]);
    creazatablou(n,tab);
    clock_t start=clock();
    //bubble_sort(tab,n);
    //quick_sort(tab,0,n-1);
    //mergeSort(tab,0,n-1);
    //insertionSort(tab,n);
    selectionSort(tab,n);
    clock_t end=clock();
    double total=((double)(end-start)) / CLOCKS_PER_SEC;
    printf("%f", total);
    //afiseaza_fisier(tab,n);
    return 0;
}