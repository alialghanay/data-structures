#include <stdio.h>
int A[] = {12, 40, 3, 2, 15};
int len = 5;

void sort(char s){
    int temp = 0;
    if(s == 'u'){
            for(int i=0; i < len-1; i++){

                for(int j=0; j < len-1-i; j++){
                    if(A[j] > A[j+1]){
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
                    }
                }
    }
   }else if(s == 'd'){
              for(int i=0; i < len-1; i++){

                for(int j=0; j < len-1-i; j++){
                    if(A[j] < A[j+1]){
                        temp = A[j];
                        A[j] = A[j+1];
                        A[j+1] = temp;
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
}
