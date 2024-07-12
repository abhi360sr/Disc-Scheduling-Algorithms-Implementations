#include <stdio.h>

int main()
{
    int i,n,seek_count=0,x,initial,rq[100];
    printf("Enter number of prcess  ");
    scanf("%d",&n);
    printf("Enter initial head position");
    scanf("%d",&initial);
    for(i=0;i<n;i++){
        printf("Enter request %d    ",i+1);
        scanf("%d",&rq[i]);
    }

    for(i=0;i<n;i++)
    {
        x=abs(initial-rq[i]);
        if(x<0)
        {
            x=rq[i]-initial;
        }
        seek_count+=x;
        initial=rq[i];
    }

    printf("Total seek COUnt = %d",seek_count);
}