#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
short v[6][6]={0},ok=1,i,j,k,x,whatever,max=1,areloc=1;
void afim(int f)
{
    int kk=nr(f);
    if (f==0)
    {
        int aux=max;
        while (aux)
        {
            printf(" ");
            aux--;
        }

    }
    else{


    if (kk==2 && max==3)
        printf (" %d",f);
       if (max==3 && kk==1)
         printf (" %d ",f);
    if (max<=kk)
        printf ("%d",f);

     if (max==2 && kk==1)
          printf (" %d",f);

    if(max==4 && kk==1)
                printf ("   %d",f);
     if(max==4 && kk==2)
        printf (" %d ",f);
         if(max==4 && kk==3)
               printf (" %d",f);
          }
         if (j!=4)
           printf (" ");



}




int nr(int n)
{
    if (n==0)
        return 0;
    else
        return 1+nr(n/10);
}
void mS ()
{

    for (i=1;i<4 && ok;i++)
    {
        for (j=1;j<=4 && ok;j++)
        {
            whatever=0;
            for (k=1;k<4 && whatever<3;k++)
            {

                if (v[j][k]==0)
                   {
                       for (x=k;x<=4;x++)
                         v[j][x]=v[j][x+1];
                         k--;
                         whatever++;

                   }
            }

            if (v[j][i]==v[j][i+1])
             {
                 v[j][i]*=2;
                 if (v[j][i]==2048)
                    ok=0;

                 for (k=i+1;k<=4;k++)
                    v[j][k]=v[j][k+1];
                    x=1;


             }

        }
    }
}
void mD()
{
     for (i=4;i>1 && ok;i--)
    {
        for (j=4;j>=1 && ok;j--)
        {
            whatever=0;
            for (k=4;k>1 && whatever<3;k--)
            {

                if (v[j][k]==0)
                   {
                       for (x=k;x>=1;x--)
                         v[j][x]=v[j][x-1];
                         k++;
                         whatever++;

                   }
            }

            if (v[j][i]==v[j][i-1])
             {
                 v[j][i]*=2;
                 if (v[j][i]==2048)
                    ok=0;

                 for (k=i-1;k>=1;k--)
                    v[j][k]=v[j][k-1];
                    x=1;


             }

        }
    }
}
void r()
{
    srand(time(NULL));
    int n,m,v42;
    n=rand()%4+1;
    m=rand()%4+1;
    v42=(rand()%2)*2+2;
    if (v42==4)
        v42=(rand()%2)*2+2;
    while (v[m][n]!=0)
    {
        n=rand()%4+1;
        m=rand()%4+1;
    }
    v[m][n]=v42;

}
void afi()
{
     for (i=1;i<=max*4+4;i++)
        printf("*");
     printf("\n");
    for (i=1;i<=4;i++)
    {

        for (j=1;j<=4;j++)
           afim(v[i][j]);


        printf ("|");
        printf("\n");

    }
     for (i=1;i<=max*4+4;i++)
        printf("*");
        printf("\n");
    printf("\n");
}
void mU()
{

    for (i=1;i<=4 && ok;i++)
    {
        for (j=1;j<4 && ok;j++)
        {
            whatever=0;
            for (k=1;k<4 && whatever<3;k++)
            {

                if (v[k][i]==0)
                   {
                       for (x=k;x<=4;x++)
                         v[x][i]=v[x+1][i];
                         k--;
                         whatever++;

                   }
            }

            if (v[j][i]==v[j+1][i])
             {
                 v[j][i]*=2;
                 if (v[j][i]==2048)
                    ok=0;

                 for (k=j+1;k<=4;k++)
                    v[k][i]=v[k+1][i];
                    x=1;

             }

        }
    }
}
void mJos()
{

  for (i=1;i<=4 && ok;i++)
    {
        for (j=4;j>1 && ok;j--)
        {
            whatever=0;
            for (k=4;k>=1 && whatever<3;k--)
            {

                if (v[k][i]==0)
                   {
                       for (x=k;x>=1;x--)
                         v[x][i]=v[x-1][i];
                         k--;
                         whatever++;

                   }
            }

            if (v[j][i]==v[j-1][i])
             {
                 v[j][i]*=2;
                 if (v[j][i]==2048)
                    ok=0;

                 for (k=j-1;k>=1;k--)
                    v[k][i]=v[k-1][i];





             }

        }
    }

}

int look()
{
    for (i=1;i<=4;i++)
      for (j=1;j<=4;j++)
         {
               if (v[i][j]==0)
                 areloc=1;
               if (nr(v[i][j])>max)
                    max=nr(v[i][j]);
         }



}
int lost()
{
    for (i=1;i<=4;i++)
        for (j=1;j<=4;j++)
             if (v[i][j]==v[i-1][j] || v[i][j]==v[i][j+1] || v[i][j]==v[i+1][j] || v[i][j]==v[i][j-1])
               return 1;
    return 0;
}
int main()
{

    printf ("Use W A S D to move \n");
    char n;
    r();
    afi();
    while (ok)
    {

        n=getch();
        switch (n)
        {
        case 'w':
            mU();break;
        case 'a':
            mS();
            break;
        case 'd':
            mD();
            break;
        case 's':
            mJos();
            ;
            break;
        }


        if (!ok)
          {  printf ("WP you won");
            break;
          }
        areloc=0;
         look();
         if (areloc)
            r();

system("cls");
        afi();
         if (lost()==0)
         {
                printf ("You lost");

                break;
         }

    }
}



































