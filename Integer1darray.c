// Write a C program using functions and pointers for the following
#include <stdio.h>

void main()
{
   int sw;
   printf("Select 1. Read and display n numbers\n2. Read and display odd positioned elements\n3. Display the even numbers from the set of integers\n4. Display maximum number from the set of integers Calculate the sum and average of n numbers\n 5. Calculate the sum and average of n numbers \n Enter you choice :");
   scanf("%d", &sw);
   switch (sw)
   {
   case 1:
      RDnumbers();
      break;
   case 2:
      RDoddNumbers();
      break;
   case 3:
      RDevenNumbers();
      break;
   case 4:
      RDmaxNumbers();
      break;
   case 5:
      RDSumNumbers();
      break;
   default:
      printf("Invalid Choice!!!!!");
      break;
   }
}
// 1. Read and display n numbers
void RDnumbers()
{
   int arr[10], count, i;
   printf("Enter the limit of the number :");
   scanf("%d", &count);
   printf("Enter the number\n");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("\n");
   printf("The numbers are : ");
   for (i = 0; i < count; i++)
   {
      printf("%d ", arr[i]);
   }
}
// 2. Read and display odd positioned elements
RDoddNumbers()
{
   int arr[10], count, i;
   printf("Enter the limit of the number :");
   scanf("%d", &count);
   printf("Enter the number\n");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("\n");
   printf("The odd positioned numbers are : ");
   for (i = 0; i < count; i++)
   {
      if (i%2!=0)
      {
         printf("%d ", arr[i]);
      } 
   }
}
// 3. Display the even numbers from the set of integers
RDevenNumbers()
{
   int arr[10], count, i;
   printf("Enter the limit of the number :");
   scanf("%d", &count);
   printf("Enter the number\n");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("\n");
   printf("The even numbers are : ");
   for (i = 0; i < count; i++)
   {
      if (arr[i]%2==0)
      {
         printf("%d ", arr[i]);
      } 
   }
}
// 4. Display maximum number from the set of integers
RDmaxNumbers()
{
   int arr[10], count, i,max=0;
   printf("Enter the limit of the number :");
   scanf("%d", &count);
   printf("Enter the number\n");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("\n");
   printf("The max number is : ");

   for (i = 0; i < count; i++)
   {
      if (arr[i]>max)
      {
         max=arr[i];
      }     
   }
    printf("%d",max);
}
// 5. Calculate the sum and average of n numbers
RDSumNumbers()
{
   int arr[10], count, i,sum=0;
   printf("Enter the limit of the number :");
   scanf("%d", &count);
   printf("Enter the number\n");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &arr[i]);
   }
   printf("\n");
   printf("The sum of numbers is : ");

   for (i = 0; i < count; i++)
   {
      sum=sum + arr[i];
   }
   printf("%d",sum);
}