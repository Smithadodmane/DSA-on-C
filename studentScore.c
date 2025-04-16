#include <stdio.h>
#include <stdlib.h>

int N,size,i,j,k,temp;
struct student{
char name[30];
int reg_no;
int marks[3];
float avg;
};

void read(struct student *);
void disp(struct student *);
void avg(struct student *);

void main()
{
struct student *st;
printf("Enter the size:");
scanf("%d",&size);
st=(struct student*)malloc(size*sizeof(struct student));
int choice;
for(;;)
{
    printf("enter the choice:\n1.read\n2.display\n3.avg\n4exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:read(st);
               break;
        case 2:disp(st);
              break;
        case 3:avg(st);
              break;
        case 4:printf("thank yoiu!!!");
               exit(0);
        default:printf("invalid choice");
               free(st);
               st=NULL;
    }
}
}

void read(struct student*st)
{
    printf("enter the number of students:");
    scanf("%d",&N);
    if(N>size)
    {
        printf("insufficient space\nreallocating the memory");
        st=(struct student*)realloc(st,(N-size)*sizeof(struct student));
        
    }
        for(i=0;i<N;i++){
        printf("enter the name and regno. of the student%d",i+1);
        scanf("%s%d",(st+i)->name,&(st+i)->reg_no);
        
            printf("enter the marks scored 3 tests");
            for(j=0;j<3;j++){
                scanf("%d",&(st+i)->marks[j]);
            }
        }
    
}


void disp(struct student*st)
{   if(N==0){
    printf("empty");
}
    printf("\nreg_no.\tname\ttest1\ttest2\ttest3\t\n");
    for(i=0;i<N;i++){
        printf("%d\t%s\t",(st+i)->reg_no,(st+i)->name);
         for(j=0;j<3;j++){
                printf("%d\t",(st+i)->marks[j]);}
                printf("\n");
    }
}

void avg(struct student*st){
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            for(k=0;k<3-j-1;k++){
                if((st+i)->marks[k]>(st+i)->marks[k+1])
                {
                    temp=(st+i)->marks[k];
                    (st+i)->marks[k]=(st+i)->marks[k+1];
                    (st+i)->marks[k+1]=temp;
                }
            }
        }
    }
    int sum[N];
    for(i=0;i<N;i++){
        sum[i]=(st+i)->marks[1]+(st+i)->marks[2];
        (st+i)->avg=(float)sum[i]/2;                
            }
             printf("\nreg_no.\tname\ttest1\ttest2\ttest3\tavg\t\n");
    for(i=0;i<N;i++){
        printf("%d\t%s\t",(st+i)->reg_no,(st+i)->name);
         for(j=0;j<3;j++){
                printf("%d\t",(st+i)->marks[j]);
                }
                printf("%.2f\t",(st+i)->avg);
                printf("\n");
    }
}
        

