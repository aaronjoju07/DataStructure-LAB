#include <stdio.h>

int main(){
    float income;
    printf("Enter your income: ");
    scanf("%f",&income);
    if(income<=150000){
        printf("Income tax is zero");
    }else if(income>= 150001 && income <= 300000){
        float tax = (income-150000)*10/(100);
        printf("Income tax is: %f",tax);

    }else if(income>= 300001 && income <= 500000){
        float tax = (income-150000)*20/(100);
        printf("Income tax is: %f",tax);

    }else{
        float tax = (income-150000)*30/(100);
        printf("Income tax is: %f",tax);
    }
    return 0;
}

