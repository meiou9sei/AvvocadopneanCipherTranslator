#include <stdio.h>

//Avvocadopnean Cipher Translator
//This program will translate between English and Avvocadopnean, with the standard A-Z, 0-9, and symbols . , ? ! '
//later more symbols will be included, I just gotta find my document with all the rules

int startMenu(void);
void AvvToEng(void);
void EngToAvv(void);
void Credits(void);


int main()
{
    int x;
    while (x != 4)
    {
        printf("--------------------------------------------------\n");
        printf("\nAVVOCADOPNEAN CIPHER TRANSLATOR:\n");
        printf("    1. Avvocadopnean -> English\n");
        printf("    2. English -> Avvocadopnean\n");
        printf("    3. Credits\n");
        printf("    4. Exit Program\n");
        printf("\nSelect mode: ");

        //checks if valid option (x = 1~4). if not, loops prompt
        int invalidOption = 1;
        while (invalidOption == 1)
        {
            scanf("%d", &x);

            if (x >= 1 && x <= 4)
            {
                invalidOption = 0;
            } else
            {
                printf("\n%d is invalid.\nInput valid option: ", x);
            }
        }
        if (x != 4) printf("Valid option selected! Proceeding...\n");

        //proceeds to selected option
            if (x == 1)
            {
                AvvToEng();
            } else if (x == 2)
            {
                EngToAvv();
            } else if (x == 3)
            {
                Credits();
            }
    }

    //exits program
    printf("\nThanks for using! Goodbye.\n");

    return 0;
}

void AvvToEng(void)
{
    printf("--------------------------------------------------\n");
    printf("test this is AvvToEng\n");
}
void EngToAvv(void)
{
    printf("--------------------------------------------------\n");
    printf("test this is EngToAvv\n");
}
void Credits(void)
{
    printf("--------------------------------------------------\n");
    printf("test this is Credits\n");
}

