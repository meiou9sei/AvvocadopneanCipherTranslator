#include <stdio.h>

//Avvocadopnean Cipher Translator
//This program will translate between English and Avvocadopnean, with the standard A-Z, 0-9, and symbols . , ? ! '
//later more symbols will be included, I just gotta find my document with all the rules

/*
TODO:
create Eng to Avv translator first. try to use functions in it. test implement just letters, and numbers,
and see other stuff. try to use arrays and forloops to generate Avv rather than
a bunch of if else statements.

1) set clear goals in credits (about) part: 1) to familiarize self with arrays, loops, conditionals and in general learning by creating my first program, 2) read and write txt files
2) make a new "How to read Avvocadopnean" section
3) do MIT license
4) explain how to use software on README.md

implement function by 1) just generate the symbols correctly 2) try translating it 3) then put it into a function


*/

int startMenu(void);
void AvvToEng(void);
void EngToAvv(void);
void aboutAvv(void);
void aboutProgram(void);


int main()
{
    //change this to number of menu options desired
    int menuSelectCount = 4;

    int x;
    while (x != 0)
    {
        printf("--------------------------------------------------\n");
        printf("\nAVVOCADOPNEAN CIPHER TRANSLATOR:\n");
        printf("    1. Avvocadopnean -> English\n");
        printf("    2. English -> Avvocadopnean\n");
        printf("    3. About Avvocadopnean\n");
        printf("    4. About this program\n");
        printf("\n    0. Exit Program\n");
        printf("\nSelect mode: ");

        //TODO make menu option expandable with int variable you can change. and make exit 0.

        //checks if valid option (x = 1~5). if not, loops prompt
        int invalidOption = 1;
        while (invalidOption == 1)
        {
            scanf("%d", &x);

            if (x >= 0 && x <= menuSelectCount)
            {
                invalidOption = 0;
            } else
            {
                printf("\n%d is invalid.\nInput valid option: ", x);
            }
        }
        if (x != 0) printf("Valid option selected! Proceeding...\n");

        //proceeds to selected option - add new menu options here
            if (x == 1)
            {
                AvvToEng();
            } else if (x == 2)
            {
                EngToAvv();
            } else if (x == 3)
            {
                aboutAvv();
            } else if (x == 4)
            {
                aboutProgram();
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
void aboutAvv(void)
{
    printf("--------------------------------------------------\n");
    printf("test this is about avvocadopnean\n");
}
void aboutProgram(void)
{
    printf("--------------------------------------------------\n");
    printf("test this is about the pogram\n");
}




