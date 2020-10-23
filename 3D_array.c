//passing 2D array to a function

#include <stdio.h>
void passbyelement(int arr,int *sum)
{
    *sum = *sum + arr;
}

void passbyaddress(int *ptr,int *sum)
{
    *sum = *sum + *ptr ;
}

void passbyplaneaddress(int plane ,int row,int col,int (*arr)[row][col],int *sum) //void passbyaddress(int n , int arr[][row][col] , int *sum)
{
    for(int i=0 ; i<plane ; i++)
    {
        for(int j=0 ; j<row ; j++)
        {
            for(int k=0 ; k<col ; k++)
            {
                *sum = *sum + *(*(*(arr+i)+j)+k); //*sum = *sum + arr[i][j][k]
            }
        }
    }

/*    int *ptr = **arr;
    for(int i=0 ; i<8 ; i++)
    {
        *sum = *sum + *ptr ;
        ptr++;
    }
*/
}

void passbywholearray(int plane ,int row , int col , int (*arr)[plane][row][col] , int *sum)  // arr[][plane][row][col] = > (*arr)[plane][row][col]
{
    for(int i=0 ; i<plane ; i++)
    {
        for(int j=0 ; j<row ; j++)
        {
            for(int k=0 ; k<col ; k++)
            {
                printf("%d  ",*(*(*(*(arr)+i)+j)+k));   //arr[0][i][j][k]
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0 ; i<plane ; i++)
    {
        for(int j=0 ; j<row ; j++)
        {
            for(int k=0 ; k<col ; k++)
            {
                *sum = *sum + *(*(*(*(arr)+i)+j)+k);   //arr[0][i][j][k]
            }
        }
    }
/*
    int *ptr= ***arr;
    for(int i=0 ; i<8 ; i++)
    {
        *sum = *sum + *ptr;
        ptr++;
    }
*/
}

void main()
{
    int sum=0;
    int arr[2][2][2]={1,2,3,4,5,6,7,8};
    //passing elements one by one
    for(int i=0 ; i<2 ; i++)//this loop is for plane
    {
        for(int j=0 ; j<2 ; j++)//this loop is for row
        {
            for(int k=0 ; k<2 ; k++)//this loop is for column 
            {
                passbyelement(arr[i][j][k],&sum);
            }
        }
    }
    printf("sum of all elements is %d\n",sum);

    sum=0;
    //passing address of elements one by one
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            for(int k=0 ; k<2 ; k++)
            {
                passbyaddress(&arr[i][j][k],&sum);
            }
        }
    } 
    printf("sum of all elements is %d\n",sum);

    sum=0;
    //passing base address of an elements 
    passbyplaneaddress(2,2,2,arr,&sum);
    printf("sum of all elements is %d\n",sum);    

    sum=0;
    //passing address of whole array
    passbywholearray(2,2,2,&arr,&sum);
    printf("sum of all elements is %d\n",sum);

}
    