#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

void letterGrade(int grade, int* a, int* b, int* c, int* d, int* f){
    if(grade >= 90){
        printf("A");
        (*a)++;
    } else if(grade >= 80){
        printf("B");
        (*b)++;
    } else if(grade >= 70){
        printf("C");
        (*c)++;
    } else if(grade >= 60){
        printf("D");
        (*d)++;
    } else{
        printf("F");
        (*f)++;
    }
}

int main(){
    int grade[MAX_SIZE];
    int count=0 , a=0 , b=0 , c=0 , d=0 , f=0;
    FILE *fptr;
    fptr = fopen("grades.txt","w");
    if(fptr == NULL){
        printf("Error!\n");
        exit(1);
    }
    for(int i=0; i<MAX_SIZE; i++){
        printf("Enter grade %d: ",i+1);
        scanf("%d",&grade[i]);
        fprintf(fptr,"%d\n",grade[i]);
    }
    fclose(fptr);
    
    fptr = fopen("grades.txt","r");
    if(fptr == NULL){
        printf("Error!\n");
        exit(1);
    }
    
    while(fscanf(fptr,"%d",&grade[count]) && count < MAX_SIZE){
        letterGrade(grade[count], &a, &b, &c, &d, &f);
        printf("\n");
        count++;
    }
    fclose(fptr);
    
    printf("A: %d\n", a);
    printf("B: %d\n", b);
    printf("C: %d\n", c);
    printf("D: %d\n", d);
    printf("F: %d\n", f);

    system("pause");
    return 0;
}
