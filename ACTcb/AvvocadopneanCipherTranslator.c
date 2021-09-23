#include <stdio.h>

//Avvocadopnean Cipher Translator
//This program will translate between English and Avvocadopnean, with the standard A-Z, 0-9, and symbols . , ? ! '
//later more symbols will be included, I just gotta find my document with all the rules

/*
TODO:
    1) MENU
        make menu option expandable with int variable you can change. and make exit 0.
    2) EngToAvv
        create this before Avv->Eng. do it in the lab isolated with just generating the letter characters using nested loops and arrays.
        then try creating the translation.
        then try adding punctuation.
        then try adding numbers.
    3) AvvToEng
        reverse EngToAvv, basically. Try to modify EngToAvv functions so they're reusable here.
    4) aboutAvv
        flesh this out more. create page flipping function so you can
            - go to table of contents
            - go to next page
            - go to last page
                with keys probably n/ext and b/ack
    x) add ability to read and write txt files with avvocadopnean
    x) add spoken generator
//remove this comment later



1) set clear goals in credits (about) part: 1) to familiarize self with arrays, loops, conditionals and in general learning by creating my first program, 2) read and write txt files
2) make a new "How to read Avvocadopnean" section
3) explain how to use software on README.md
4) add a "spoken" outputter

implement function by 1) just generate the symbols correctly 2) try translating it 3) then put it into a function


*/

int mainMenu(void);
void EngToAvv(void);
void AvvToEng(void);
void aboutAvv(void);
void aboutProgram(void);
void laboratory(void);
void returnHome(void);


int main()
{
    //change this to number of menu options desired
    int menuSelectCount = 5;

    int x;
    while (x != 0)
    {
        printf("\n--------------------------------------------------\n");
        printf("\n");
        printf("AVVOCADOPNEAN CIPHER TRANSLATOR\n");
        printf("Created by Cameron Avvampato, 2021\n");
        printf("\n");
        printf("    1. English -> Avvocadopnean\n");
        printf("    2. Avvocadopnean -> English\n");
        printf("    3. About Avvocadopnean\n");
        printf("    4. About this program\n");
        printf("    5. Laboratory\n");
        printf("\n");
        printf("    0. Exit Program\n");
        printf("\n");
        printf("Select mode: ");

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
                EngToAvv();
            } else if (x == 2)
            {
                AvvToEng();
            } else if (x == 3)
            {
                aboutAvv();
            } else if (x == 4)
            {
                aboutProgram();
            } else if (x == 5)
            {
                laboratory();
            }
    }

    //exits program
    printf("\nThanks for using! Goodbye.\n");

    return 0;
}

void EngToAvv(void)
{
    printf("\n--------------------------------------------------\n");
    printf("test this is EngToAvv\n");
}
void AvvToEng(void)
{
    printf("\n--------------------------------------------------\n");
    printf("test this is AvvToEng\n");
}

//explains how Avvocadopnean works
void aboutAvv(void)
{
    //page 0
    printf("\n--------------------------------------------------\n");
    printf("\nABOUT AVVOCADOPNEAN\n");
    printf("\n");
    printf("Table of contents\n");
    printf("    1. History\n");
    printf("    2. Basic Avvocadopnean\n");
    printf("    3. Punctuation in Avvocadopnean\n");
    printf("    4. Numbers in Avvocadopnean\n");
    printf("    5. Other forms of Avvocadopnean\n");
    printf("\n");
    printf("    0. Return to Main Menu\n");


    //page 1
    printf("\n--------------------------------------------------\n");
    printf("\nHISTORY\n");
    printf("\n");
    printf("Avvocadopnean is a simple cipher I created while in highschool.\n");
    printf("It coincidentally resembles the Tap Code cipher, and honestly\n");
    printf("that's probably a better developed cipher than what I came up with.\n");
    printf("Avvocadopnean uses the symbols found on the bottom row of the iOS keyboard's\n");
    printf("special characters keyboard, and thus can be rapidly typed on an iPhone with practice.\n");
    printf("\n");
    printf("Over time, cursive, caligraphy, morse, and spoken forms of Avvocadopnean were developed.\n");
    printf("There is very little use for this cipher as basically only I speak it lmao\n");

    //page 2
    printf("\n--------------------------------------------------\n");
    printf("USING AVVOCADOPNEAN\n");
    printf("\n");
    printf("To use standard script Avvocadopnean, lay out the symbols .,?!' to a 5x5 grid like so:\n");
    printf("\n");
    printf("           .   ,   ?   !   '  \n");
    printf("         +-------------------+\n");
    printf("       . | A | B | C | D | E |\n");
    printf("         +-------------------+\n");
    printf("       , | F | G | H | I | J |\n");
    printf("         +-------------------+\n");
    printf("       ? | K | L | M | N | O |\n");
    printf("         +-------------------+\n");
    printf("       ! | P | Q | R | S | T |\n");
    printf("         +-------------------+\n");
    printf("       ' | U | V | W | X | Y |\n");
    printf("         +-------------------+\n");
    printf("        Z is represented as ...\n");
    printf("\n");
    printf("\n");
    printf("To encrypt a letter, first use the horizontal row then the vertical column.\n");
    printf("Words are separated by a -\n");
    printf("\n");
    printf("For example:\n");
    printf("\n");
    printf("    ,? .' ?, ?, ?' - '? ?' !? ?, .!\n");
    printf("    h  e  l  l  o    w  o  r  l  d\n");
    printf("\n");

    returnHome();
}

//basically the credits for the program
void aboutProgram(void)
{
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("ABOUT THIS PROGRAM");
    printf("\n");
    printf("The AVVOCADOPNEAN CIPHER TRANSLATOR program was written by Cameron Avvampato (me) in C.\n");
    printf("This program was intends to:\n");
    printf("    1. Translate Avvocadopnean and English to eachother\n");
    printf("    2. Read and Write .txt files with English/Avvocadopnean\n");
    printf("and:\n");
    printf("    A. Be my first real program");
    printf("        that's heckin' cool yo\n");
    printf("    B. Solidify my understanding of arrays and loops");
    printf("        by generating the cipher using ASCII codes and loops");

    returnHome();
}
void laboratory(void)
{
    printf("\n--------------------------------------------------\n");
    printf("test this is where i test stuff\n");

    char avvSymbols[] = {'.', ',', '?', '!', '\''};
    //char avvSet[26][3];
    //thoughts - it would assign the symbol pairs to an array as strings, then the translator would interpret the ASCII of userString to

    //generates avvocadopnean symbol table
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c%c ", avvSymbols[i], avvSymbols[j]);
            //avvSet[i] =
        }
        printf("\n");

    }
    printf("...");

    printf("\n");

    /*
    printf("           .   ,   ?   !   '  \n");
    printf("         +-------------------+\n");
    printf("       . |65 |66 |67 |68 |69 |\n");
    printf("         +-------------------+\n");
    printf("       , |70 |71 |72 |73 |74 |\n");
    printf("         +-------------------+\n");
    printf("       ? |75 |76 |77 |78 |79 |\n");
    printf("         +-------------------+\n");
    printf("       ! |80 |81 |82 |83 |84 |\n");
    printf("         +-------------------+\n");
    printf("       ' |85 |86 |87 |88 |89 |\n");
    printf("         +-------------------+\n");
    printf("       90 is represented as ...\n");
    */

    //test with only 1 word strings
    char testEngAvvInput[100];
    printf("Input word to encrypt Eng -> Avv: ");
    scanf("%s", testEngAvvInput);

    printf("\n");
    printf("%s\n", testEngAvvInput);

    int testSymbolRow;
    int testSymbolColumn;
    int x;
    for(int i = 0; x != '\0'; i++)
    {
        if (testEngAvvInput[i] == 32)
        {
            printf(" ");
        } else
        {
            testSymbolRow = (testEngAvvInput[i] - 65) / 5;
            testSymbolColumn = ((testEngAvvInput[i] - 65) % 5);
            printf("%c%c ", avvSymbols[testSymbolRow], avvSymbols[testSymbolColumn]);

        }
        x = testEngAvvInput[i + 1];
    }



    //user types HELLO
    //sees int values 72 69 76 76 79
    //replaces those values with -64. / and %
    //ex: 72 - 64 = 8. then divide 8 / 5 = 1, or 1th row, then 8 % 5 = 3, or 3rd column. , ?
    //takes these from avvSymbols[] and outputs to engAvvResult[], which increments each time and gets printed


    //takes usertext input and displays it
    /*
    char userText[101];
    getchar();
    printf("Type a line of text here (up to 100 characters): ");
    fgets(userText, sizeof(userText), stdin); // reads string
    printf("Test: ");
    puts(userText);
    */

    /***************************
    ASCII char's int values:
    A~Z = 65~90
    a~z = 97~122
    ****************************/

    returnHome();

}\

//test functions - idk if i'm keeping these

//function keeps user on page until 0 is entered - prevents auto-exiting of mode before I create something probably more sophisticated
//don't delete this when you're done with it, just comment it out
void returnHome(void)
{
    printf("\nEnter 0 to return to main menu: ");
    int loopTrapper = 1;
    while (loopTrapper == 1)
    {
        int userReturn;
        scanf(" %d", &userReturn);

        if (userReturn == 0)
        {
            loopTrapper = 0;
            printf("Exiting to main menu...\n");
        } else
        {
            printf("\nInvalid input. Enter 0 to return to main menu: ");
        }
    }
}


