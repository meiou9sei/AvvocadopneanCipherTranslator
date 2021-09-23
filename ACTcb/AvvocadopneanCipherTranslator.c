#include <stdio.h>

//Avvocadopnean Cipher Translator
//This program will translate between English and Avvocadopnean, with the standard A-Z, 0-9, and symbols . , ? ! '
//later more symbols from Avvocadopnean will be included

/*
TODO:
    1) MENU
        make menu option expandable with int variable you can change. and make exit 0.
    2) EngToAvv
        add lowercase
        try adding punctuation.
        try adding numbers.
        maybe try putting space between string text, so that it lines up with translation?
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
    x) write in README.md instructions on how to use program

*/

int mainMenu(void);
void EngToAvv(void);
void AvvToEng(void);
void aboutAvv(void);
void aboutProgram(void);
void laboratory(void);
void returnHome(void);

//if you can, try to make constant: char avvSymbols[] = {'.', ',', '?', '!', '\''};


int main()
{
    //change this to number of menu options desired
    int menuSelectCount = 5;

    int menuUserSelect;
    while (menuUserSelect != 0)
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
            scanf("%d", &menuUserSelect);

            if (menuUserSelect >= 0 && menuUserSelect <= menuSelectCount)
            {
                invalidOption = 0;
            } else
            {
                printf("\n%d is invalid.\nInput valid option: ", menuUserSelect);
            }
        }
        if (menuUserSelect != 0) printf("Valid option selected! Proceeding...\n");

        //proceeds to selected option - add new menu options here
            if (menuUserSelect == 1)
            {
                EngToAvv();
            } else if (menuUserSelect == 2)
            {
                AvvToEng();
            } else if (menuUserSelect == 3)
            {
                aboutAvv();
            } else if (menuUserSelect == 4)
            {
                aboutProgram();
            } else if (menuUserSelect == 5)
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

    //generates avvocadopnean symbol table
    //REMOVE THIS if you can get constant char array working
    char avvSymbols[] = {'.', ',', '?', '!', '\''};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c%c ", avvSymbols[i], avvSymbols[j]);
        }
        printf("\n");

    }
    printf("...");
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
    printf("ABOUT THIS PROGRAM\n");
    printf("\n");
    printf("The AVVOCADOPNEAN CIPHER TRANSLATOR program was written by Cameron Avvampato (me) in C.\n");
    printf("This program was intends to:\n");
    printf("    1. Translate Avvocadopnean and English to eachother\n");
    printf("    2. Read and Write .txt files with English/Avvocadopnean\n");
    printf("and:\n");
    printf("    A. Be my first real program\n");
    printf("        that's heckin' cool yo\n");
    printf("    B. Solidify my understanding of arrays and loops\n");
    printf("        by generating the cipher using ASCII codes and loops\n");

    returnHome();
}
void laboratory(void)
{
    printf("\n--------------------------------------------------\n");
    printf("currently testing Eng -> Avv translator\n");

    char avvSymbols[] = {'.', ',', '?', '!', '\''};

    /***************************
    ASCII char's int values:
    A~Z = 65~90
    a~z = 97~122
    ****************************/

    //takes user string
    char EngAvvInput[101];
    printf("Input expression to encrypt Eng -> Avv\n");
    printf("\n");
    printf("Up to 100 characters, only A-Z, a-z, numbers,\n");
    printf("and punctuation and symbols . , ? ! '\n");
    printf("\n");
    printf("English to encrypt: ");
    getchar(); //clears stream
    scanf("%100[^\n]s", EngAvvInput); //black magic I don't understand

    printf("\n");
    printf("%s\n", EngAvvInput);

    printf("\n");
    //converts string to cipher
    int SymbolRow;
    int SymbolColumn;
    //must declare int to any number EXCEPT 0, or it skips for loop.
    //I don't know why this works, but maybe nullChecker != '\0' thinks 0 == '\0'
    int nullChecker = 1;
    for (int i = 0; nullChecker != '\0'; i++)
    {
        if (EngAvvInput[i] == 32)
        {
            printf("- ");
        } else
        {
            //explanation how this works written under "ENG->AVV EXPLAINED"
            SymbolRow = (EngAvvInput[i] - 65) / 5;
            SymbolColumn = ((EngAvvInput[i] - 65) % 5);
            printf("%c%c ", avvSymbols[SymbolRow], avvSymbols[SymbolColumn]);
        }
        nullChecker = EngAvvInput[i + 1];
    }
    printf("\n");

    //ENG->AVV EXPLAINED
    //user types HELLO
    //int values 72 69 76 76 79
    //replaces those values with -64. / and % resulting int
    //ex: 72 - 64 = 8. then divide 8 / 5 = 1, or 1st row (,), then 8 % 5 = 3, or 3rd column (?).
    //takes these from avvSymbols[] and outputs to engAvvResult[], which increments each time and gets printed
    //ingenious i know hehe >:)

    /*
    ASCII Codes for A~Z
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

    returnHome();
}

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


