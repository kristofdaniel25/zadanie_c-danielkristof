#include <stdio.h>
 
void cyklicky_posun_rychlo(int *p,int l,int s)
{ 
    int i,j,temp;
    for(i=0; i<s; i++)
    {
        temp=p[l-1];
        for(j=l-1; j>0; j--)
        {
           p[j]=p[j-1];
		}
 
         p[j]=temp;
    }
    
       
 }
 
void print(int *p,int n)
{ 
   
    int i;
    for(i=0; i<n; i++)
    {
       printf("%d ",p[i]);
    }
    
       
 }
 
  
int main()
{
	srand(time(0)); 
    int pole[100000],i,n,k;
    
    printf("Zadaj velkost pola:\n");
    scanf("%d", &n);
    
    for(i=0; i<n; i++)
    {
        pole[i] = rand()%50;
    }
    printf("Povodne pole:\n");
	print(pole,n);
    printf("\nZadaj s, pocet pozicii o ktore sa pole posunie:\n");
    
	scanf("%d", &k);
     
    cyklicky_posun_rychlo(pole,n,k);
    printf("Pole po posunuti:\n");
 
    print(pole,n);
    
 	return 0;
}
