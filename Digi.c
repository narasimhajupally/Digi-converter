#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
void DE(unsigned long int n, int a);
unsigned long int TD(char b[], int a);
int main()
{
    printf("\n                 ***WELCOME TO DIGITS CONVERTER***\n");
    printf("\n                                                       ->by Jupalli");
    int n1, n2;
    unsigned long int n, a;
    char b[50];
    while (n1 != -1)
    {
        printf("\n\n\n -->choose your input type(-1 to end) \n");
        printf("\n    1)DECIMAL  2)BINARY  3)OCTAL  4)HEXADECIMAL\n");
        scanf("%d", &n1);
        if (n1 >= 1 && n1 <= 4)
        {
            printf("\n -->enter the value : \n");
            if (n1 == 1)
                scanf("%ld", &n);
            if (n1 == 2 || n1 == 3 || n1 == 4)
            {
                scanf("%s", b);
            }
            switch (n1)
            {
            case 1:
                printf("\n -->to be converted into \n");
                printf("\n    1)BINARY  2)OCTAL 3)HEXADECIMAL \n");
                scanf("%d", &n2);
                if (n2 == 1)
                {
                    printf("\n                >>> the BINARY equivalent is : ");
                    DE(n, 2);
                }
                if (n2 == 2)
                {
                    printf("\n                >>> the OCTAL equivalent is : ");
                    DE(n, 8);
                }
                if (n2 == 3)
                {
                    printf("\n                >>> the HEXADECIMAL equivalent is : ");
                    DE(n, 16);
                }
                break;
            case 2:
                printf("\n -->to be converted into ");
                printf("\n    1)DECIMAL  2)OCTAL  3)HEXADECIMAL \n");
                scanf("%d", &n2);
                if (n2 == 1)
                {
                    a = TD(b, 2);
                    printf("\n                >>> the DECIMAL equivalent is : %ld", a);
                }
                if (n2 == 2)
                {
                    printf("\n                >>> the OCTAL equivalent is : ");
                    a = TD(b, 2);
                    DE(a, 8);
                }
                if (n2 == 3)
                {
                    printf("\n                >>> the HEXADECIMAL equivalent is : ");
                    a = TD(b, 2);
                    DE(a, 16);
                }
                break;
            case 3:
                printf("\n -->to be converted into ");
                printf("\n    1)DECIMAL  2)BINARY  3)HEXADECIMAL \n");
                scanf("%d", &n2);
                if (n2 == 1)
                {
                    printf("\n                >>> the DECIMAL equivalent is : %ld", TD(b, 8));
                }
                if (n2 == 2)
                {
                    printf("\n                >>> the BINARY equivalent is : ");
                    a = TD(b, 8);
                    DE(a, 2);
                }
                if (n2 == 3)
                {
                    printf("\n                >>> the HEXADECIMAL equivalent is : ");
                    a = TD(b, 8);
                    DE(a, 16);
                }
                break;
            case 4:
                printf("\n -->to be converted into ");
                printf("\n    1)DECIMAL  2)BINARY  3)OCTAL \n");
                scanf("%d", &n2);
                if (n2 == 1)
                {
                    printf("\n                >>> the DECIMAL equivalent is : %ld", TD(b, 16));
                }
                if (n2 == 2)
                {
                    printf("\n                >>> the BINARY equivalent is : ");
                    a = TD(b, 16);
                    DE(a, 2);
                }
                if (n2 == 3)
                {
                    printf("\n                >>> the OCTAL equivalent is : ");
                    a = TD(b, 16);
                    DE(a, 8);
                }
                break;
            }
        }
        else if (n1 != -1)
            printf("\n :-invalid choice\n");
    }
    printf("\n    **********************************\n");
    printf("    |  Your Are Welcome ,Good Luck %c |\n", 1);
    printf("    **********************************\n\n");
    printf("\n");
    return 0;
}

void DE(unsigned long int n, int a)
{
    int i = 0, j, rem;
    char arr[200];
    while (n > 0)
    {
        rem = n % a;
        n = n / a;
        if (rem > 9 && rem < 16)
            arr[i++] = rem - 10 + 'A';
        else
            arr[i++] = rem + '0';
    }
    for (j = i - 1; j >= 0; j--)
        printf("%c", arr[j]);
}

unsigned long int TD(char b[], int a)
{
    int i = 0, j;
    unsigned long int r = 0;
    while (1)
    {
        if (b[i] == '\0')
            break;
        else
            i++;
    }
    for (j = i - 1; j >= 0; j--)
    {
        if (b[j] >= 48 && b[j] <= 57)
            r = r + (b[j] - 48) * pow(a, i - 1 - j);
        else
            r = r + (b[j] - 55) * pow(a, i - 1 - j);
    }
    return r;
}
