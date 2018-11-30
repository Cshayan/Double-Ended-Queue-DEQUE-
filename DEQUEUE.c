#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int left=-1;
int right=-1;
void insertRight(int val)
{
    if((left==0&&right==MAX-1)||(left==right+1))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if(left==-1)
    {
        left=right=0;
        queue[right]=val;
    }
    else if(right==MAX-1)
    {
        right=0;
        queue[right]=val;
    }
    else
    {
        queue[++right]=val;
    }
}
void insertLeft(int val)
{
    if((left==0&&right==MAX-1)||(left==right+1))
    {
        printf("\nQueue Overflow\n");
        return;
    }
    if(left==-1)
    {
        left=right=0;
        queue[left]=val;
    }
    else if(left==0)
    {
        left=MAX-1;
        queue[left]=val;
    }
    else
    {
        queue[--left]=val;
    }
}
int deleteLeft()
{
    if(left==-1)
    {
        printf("\nQueue Underflow");
        return -1;
    }
    int val=queue[left];
    if(left==right)
    {
        left=right==-1;
    }
    else if(left==MAX-1)
    {
        left=0;
    }
    else
    {
        left++;
    }
    return val;
}
int deleteRight()
{
    if(left==-1)
    {
        printf("\nQueue Underflow\n");
        return -1;
    }
    int val=queue[right];
    if(left==right)
    {
        left=right=-1;
    }
    else if(right==0)
    {
        right=MAX-1;
    }
    else
    {
        right--;
    }
    return val;
}
int main()
{
    int val,ch;
    while(1)
    {
        printf("\n1.InsertRight");
        printf("\n2.InsertLeft");
        printf("\n3.DeleteRight");
        printf("\n4.DeleteLeft");
        printf("\n5.Exit");
        printf("\nEnter your choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the value to insert:- ");
            scanf("%d",&val);
            insertRight(val);
            break;
        case 2:
            printf("\nEnter the value to insert:- ");
            scanf("%d",&val);
            insertRight(val);
            break;

        case 3:
            val=deleteLeft();
            if(val!=-1)
            {
                printf("The deleted value is:- %d\n",val);
            }
            break;
        case 4:
            val=deleteRight();
            if(val!=-1)
            {
                printf("The deleted value is:- %d\n",val);
            }
            break;
        case 5:
            exit(0);

        }
    }
}

