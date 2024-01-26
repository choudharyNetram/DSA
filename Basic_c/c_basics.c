# include<stdio.h>
int main() {
    /*float number1 = 2.0 ;
    int number2 = 3;
    int number3 = 6;
    printf("%f", (number1+number2+number3)/3);
    char a ;
    scanf("%c", &a);
    printf("%d", a%1==0 );
    printf("enter number");
    int salary ;
    scanf("%d", &salary);
    printf("salary is %d\n", salary);
    if (salary >= 100){
        printf("nice salary\n");
    }
    else { 
        printf("not good salary\n");
    }
 
    int age ;
    scanf("%d", &age);
    if(age >= 18) {
    printf("you are an adult");
    }
    else {
    printf("you are not an adult");
    }*/
    char caste ;
    scanf("%c", &caste);
    switch (caste) {
        case 'n': printf("ghosliya");
                break ;
        case 'k': printf("chopra");
                break;
        default : printf("no caste")  ;      
    } 
 /*
    char day ;
    scanf("%c", &day);
    switch (day) {
        case 'm' : printf("monday \n");
                break;

        case 't' : printf("tuesday \n");
                break;
        case 'w' : printf("wednesday \n");
                break;
        case 'T' : printf("thursday \n");
                break;
        case 'f' : printf("friday \n");
                break;
        case 's' : printf("saturday \n");
                break;
        case 'S' : printf("sunday \n");
                break;

    }*/
    return 0;

}