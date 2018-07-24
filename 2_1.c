#include<stdio.h>
#include<time.h>
#include<math.h>
//printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC)

/*
int main()
{
    for(int a = 100; a <= 999; a++){
        if(a == (int)pow((a/100),3) + (int)pow(((a%100)/10),3) + (int)pow((a%10),3))
            printf("%d\n",a);
    }
    printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
*/

int main()
{
    for(int a = 1 ; a <= 9 ; a++)
        for(int b = 0 ; b <= 9 ; b++)
            for(int c = 0 ; c <= 9 ; c++){
                if(a*100+b*10+c == a*a*a+b*b*b+c*c*c)
                    printf("%d\n",a*100+b*10+c);
            }
    printf("Time used = %.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;   
}