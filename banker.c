
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char const *argv[])
{
    FILE *r,*w;
    int n=3,p,i,j,k;

    printf("error after this->\n");
    r = fopen(argv[1],"r");
    fscanf(r,"%d",&p);
    printf("%d\n",p);
    int  available[n];
    for(i=0;i<n;i++)
    {
        fscanf(r,"%d",&available[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",available[i]);
    }
   printf("\n");

    int totalResources[p][9];
    for(i = 0;i<p;i++)
    {
      for(j=0;j<9;j++)
      {
        fscanf(r,"%d",&totalResources[i][j]);
      }
    }
     /*for(i = 0;i<p;i++)
    {
      for(j=0;j<9;j++)
      {
        printf("%d ",totalResources[i][j]);//To check totalResource matrix output
      }
      printf("\n");
    }*/

    
    int allocation[p][n];
    for(i = 0;i<p;i++)
    {
      for(j = 0;j<n;j++)
      {
      allocation[i][j]=totalResources[i][j];
      }
    }
    /*for(i = 0;i<p;i++)
    {
      for(j=0;j<n;j++)
      {
        printf("%d ",allocation[i][j]);//To check allocation matrix output
      }
       printf("\n");
    }*/



    int request[p][n];
    for(i = 0;i<p;i++)
    {
      for(j = n;j<(2*n);j++)
      { 
        request[i][j-3]=totalResources[i][j];
      }
    }

     /*for(i = 0;i<p;i++)
    {
      for(j=0;j<(n);j++)
      { 
        printf("%d ",request[i][j]);//To check request matrix output
      }
      printf("\n");
    }*/


    int max[p][n];
    for(i = 0;i<p;i++)
    {
      for(j =(2*n);j<9;j++)
      { 
        max[i][j-6]=totalResources[i][j];
      }
    }
    /*for(i = 0;i<p;i++)
    {
      for(j = 0;j<n;j++)
      { 
        printf("%d ",max[i][j]);//To check max matrix output
      }
      printf("\n");
    }*/

    int need[p][n];
    for(i=0;i<p;i++)
    {
     for(j=0;j<n;j++)
     {
      need[i][j]=max[i][j]-allocation[i][j];
     }
    }
    int finalAvailable[n];
    finalAvailable[0]=0,finalAvailable[1]=0,finalAvailable[2]=0;
    /*for(i = 0;i<p;i++)
    {
      for(j = 0;j<n;j++)
      { 
        printf("%d ",need[i][j]);//To check need matrix output
      }
      printf("\n");
    }*/
    for(i=0;i<p;i++)
    {
      finalAvailable[0]=finalAvailable[0]+allocation[i][0];
    }
    for(i=0;i<p;i++)
    {
      finalAvailable[1]=finalAvailable[1]+allocation[i][1];
    }
    for(i=0;i<p;i++)
    {
      finalAvailable[2]=finalAvailable[2]+allocation[i][2];
    }
    /*for(k=0;k<n;k++)
    {
      printf("%d ",finalAvailable[k]);
    }*/
    int availEnd[n];
    for(k=0;k<n;k++)
    {
      availEnd[k]=available[k]-finalAvailable[k];
    }
    for(k=0;k<n;k++)
    {
      printf("%d ",availEnd[k]);
    }
return 0;
}
