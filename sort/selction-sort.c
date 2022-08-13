#include <stdio.h>
int A[] = {20, 35, 40, 100, 3, 10, 15};
int len = 7;

void sort(char s){
    int temp = 0;
    if(s == 'u'){
            for(int i=0; i < len; i++){

                for(int j=i; j < len; j++){
                    if(A[i] > A[j]){
                        temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                    }
                }
    }
   }else if(s == 'd'){
              for(int i=0; i < len; i++){

                for(int j=i; j < len; j++){
                    if(A[i] < A[j]){
                        temp = A[j];
                        A[j] = A[i];
                        A[i] = temp;
                    }
                }
    }
   }else printf("Unknown Charcter");

}


void Print(){
    printf("arr : ");
    for(int i = 0; i < len; i++){
        printf("%d: %d\t", i, A[i]);
    }
    printf("\n");
}

int main()
{
    Print();
    sort('u');
    Print();
    sort('d');
    Print();
}
