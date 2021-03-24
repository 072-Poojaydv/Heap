#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag;
typedef struct family{
    char name[40];
    int age;
} Family;
void swap(Family *a,Family *b)
{
	Family tmp=*a;
	*a=*b;
	*b=tmp;
}
void heap_back(Family *arr,int root,int high)
{
	int l=2*root+1,r=2*root+2;
	int max=root;
	if(l<=high && !((arr[max].age<arr[l].age)^flag)){
		max=l;
	}
	if(r<=high && !((arr[max].age<arr[r].age)^flag)){
		max=r;
	}
	if(max!=root){
		swap(&arr[max],&arr[root]);
		heap_back(arr,max,high);
	}
}
void add(Family *arr,int *len){
    Family data;
    printf("Enter the name and age(age should be positive number only):");
    scanf("%s%d",data.name,&data.age);
    arr[++(*len)]=data;
    if(*len==-1){
        return;
    }
    int child =*len;
    while(child>0 && !((arr[(child-1)/2].age<arr[child].age)^flag)){
        swap(&arr[(child-1)/2],&arr[child]);
        child=(child-1)/2;
    }
}

Family delete(Family *arr,int *high){
    if(*high>=0){
        Family data=arr[0];
        swap(&arr[0],&arr[(*high)--]);
			heap_back(arr,0,*high);
        return data;
    }
    printf("Ooops!!Heap is empty\n");
    Family m;
    strcpy(m.name,"\0");
    m.age=-1;
    return m;
}
int main(){
    char option[4];
    printf("Type min for min heap and max for max heap::");
    scanf("%s",option);
    if(strcmp(option,"min")==0){
        flag=0;
    }else if(strcmp(option,"max")==0){
        flag=1;
    }else{
        printf("oops!! You have typed something else !!\n");
        exit(0);
    }
    Family arr[50];
    int choice,high=-1;
    printf("1. ADD\n");
    printf("2. DELETE\n");
    do{
        printf("Select what operation you want to perform::");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                    add(arr,&high);
                    break;
            case 2:
                    if(high>=0){
                        Family t=delete(arr,&high);
                        printf("%s(age: %d) removed successfully!!\n",t.name,t.age);
                    }
                    else{
                        printf("Sorry!! Heap is already empty\n");
                    }
                    break;
            default:exit(0);
        }
    }while(choice==1 || choice==2);
    return 0;
}