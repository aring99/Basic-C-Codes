#include <stdio.h>
#include <stdlib.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];           // Array declaration.
    float fnum1 = 0.0;
    int sign_index=-1;
    char errorState=0;

    printf("Enter arithmetic operation:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);
    if (errorState==0)
    {
        printf("%.2f \n", fnum1);
    }
    else if (errorState==1)
    {
        printf("Error has been occurred due to inappropriate input!\n");
    }
    else if (errorState==2)
    {
        printf("Cannot divided into 0.\n");
    }

    return 0;
}

float myAtof(char* string, char* error)  // Function to convert string into float.
{
    float result= 0.00;
    int index = 0;
    int dot_checker = 0;
    int dot_zero_checker = 1;
    int zero_counter = 10;
    int error_checker = 0;
    int sign_finder = 0;
    int sign_catcher = 0;
    char string2[SIZE];
    char errorState=0;
    while( string[index]!= '\0' &&sign_catcher == 0)
    {
        if((string[index]== '+') || (string[index]== '/')||(string[index]== '*')||(string[index]== '-'))
        {
            sign_finder = index;
            sign_catcher =1;
            continue;
        }
        if((string[index] != '0' )&&(string[index] != '1')&&(string[index] != '2')&&(string[index] != '3')&&(string[index] != '4')&&(string[index] != '5')&&(string[index] != '6')&&(string[index] != '7') && (string[index] != '8')&&(string[index] != '9')&& (string[index] != '.')
                &&(string[index] != '+') && (string[index] != '-')&& (string[index] != '*')&& (string[index] != '/') )
        {
            *error = 1;
            error_checker = 1;
            string[index] = '\0';
        }
        if( (string[index] == ' '))
        {

            index = index+1;
            continue;
        }

        if((dot_checker == 0)&& sign_catcher == 0)
        {
            if((string[index] == '0'))
            {
                result = (result * 10);
                index++;
            }
            else if((string[index] == '1'))
            {
                result = (result * 10) + 1.00;
                index++;
            }
            else if((string[index] == '2'))
            {
                result = (result * 10) + 2.00;
                index++;
            }
            else if((string[index] == '3'))
            {
                result = (result * 10) + 3.00;
                index++;
            }
            else if((string[index] == '4'))
            {
                result = (result * 10) + 4.00;
                index++;
            }
            else if((string[index] == '5'))
            {
                result = (result * 10) + 5.00;
                index++;
            }
            else if((string[index] == '6'))
            {
                result = (result * 10) + 6.00;
                index++;
            }
            else if((string[index] == '7'))
            {
                result = (result * 10) + 7.00;
                index++;
            }
            else if((string[index] == '8'))
            {
                result = (result * 10) + 8.00;
                index++;
            }
            else if((string[index] == '9'))
            {
                result = (result * 10) + 9.00;
                index++;
            }
            else if((string[index] == '.'))
            {
                dot_checker = 1;
                index++;
            }
        }
        else if(dot_checker == 1 && sign_catcher == 0)
        {
            if((string[index] == '0'))
            {
                dot_zero_checker++;
                index++;
            }
            else if((string[index] == '1'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 1.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '2'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + (2.00/( zero_counter ));
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '3'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 3.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '4'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 4.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '5'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 5.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '6'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 6.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '7'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 7.00/( zero_counter );
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '8'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 8.00/( zero_counter );
                dot_zero_checker = 1;
                zero_counter = zero_counter*10;
                index++;
            }
            else if((string[index] == '9'))
            {
                while(dot_zero_checker>1)
                {
                    zero_counter = zero_counter * 10;
                    dot_zero_checker--;
                }
                result = (result) + 9.00/( zero_counter );
                dot_zero_checker = 1;
                zero_counter = zero_counter*10;
                index++;
            }
        }
    }
    if ((dot_checker == 0)&& error_checker == 0 && sign_catcher == 0)
        return result;
    else if(dot_checker == 1 && error_checker == 0 && sign_catcher == 0)
        return result;
    else if (error_checker == 0 && sign_catcher == 1)
    {
        if(string[sign_finder] == '-')
        {
            int k = 0;
            for(int i = sign_finder + 1; string[i] != '\0'; i++ )
            {
                string2[k] = string[i];
                if((string2[k] != '0' )&&(string2[k] != '1')&&(string2[k] != '2')&&(string2[k] != '3')&&(string2[k] != '4')&&(string2[k] != '5')&&(string2[k] != '6')&&(string2[k] != '7') && (string2[k] != '8')&&(string2[k] != '9')&& (string2[k] != '.')
                        &&(string2[k] != '+') && (string2[k] != '-')&& (string2[k] != '*')&& (string2[k] != '/')  )
                    *error = 1;
                k++;
            }
            float result2 = myAtof(string2,&errorState);
            if(*error == 0)
            {
                printf("%.2f ", result);
                printf("- ");
                printf("%.2f ", result2);
                printf("= ");
                return result - result2;
            }
        }
        else if(string[sign_finder] == '+')
        {
            int k = 0;
            for(int i = sign_finder + 1; string[i] != '\0'; i++ )
            {
                string2[k] = string[i];
                if((string2[k] != '0' )&&(string2[k] != '1')&&(string2[k] != '2')&&(string2[k] != '3')&&(string2[k] != '4')&&(string2[k] != '5')&&(string2[k] != '6')&&(string2[k] != '7') && (string2[k] != '8')&&(string2[k] != '9')&& (string2[k] != '.')
                        &&(string2[k] != '+') && (string2[k] != '-')&& (string2[k] != '*')&& (string2[k] != '/')  )
                    *error = 1;
                k++;
            }
            float result2 = myAtof(string2,&errorState);
            if(*error == 0)
            {
                printf("%.2f ", result);
                printf("+ ");
                printf("%.2f ", result2);
                printf("= ");
                return result + result2;
            }
        }
        else if(string[sign_finder] == '*')
        {
            int k = 0;
            for(int i = sign_finder + 1; string[i] != '\0'; i++ )
            {
                string2[k] = string[i];
                if((string2[k] != '0' )&&(string2[k] != '1')&&(string2[k] != '2')&&(string2[k] != '3')&&(string2[k] != '4')&&(string2[k] != '5')&&(string2[k] != '6')&&(string2[k] != '7') && (string2[k] != '8')&&(string2[k] != '9')&& (string2[k] != '.')
                        &&(string2[k] != '+') && (string2[k] != '-')&& (string2[k] != '*')&& (string2[k] != '/')  )
                    *error = 1;
                k++;
            }
            float result2 = myAtof(string2,&errorState);
            if(*error == 0)
            {
                printf("%.2f ", result);
                printf("* ");
                printf("%.2f ", result2);
                printf("= ");
                return result * result2;
            }
        }
        else if(string[sign_finder] == '/')
        {
            int k = 0;
            for(int i = sign_finder + 1; string[i] != '\0'; i++ )
            {
                string2[k] = string[i];
                if((string2[k] != '0' )&&(string2[k] != '1')&&(string2[k] != '2')&&(string2[k] != '3')&&(string2[k] != '4')&&(string2[k] != '5')&&(string2[k] != '6')&&(string2[k] != '7') && (string2[k] != '8')&&(string2[k] != '9')&& (string2[k] != '.')
                        &&(string2[k] != '+') && (string2[k] != '-')&& (string2[k] != '*')&& (string2[k] != '/')  )
                    *error = 1;
                k++;
            }
            float result2 = myAtof(string2,&errorState);
            if(result2 == 0)
            {
                *error = 2;
            }
            if(*error == 0)
            {
                printf("%.2f ", result);
                printf("/ ");
                printf("%.2f ", result2);
                printf("= ");
                return result / result2;
            }
        }
    }

}
