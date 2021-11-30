#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

//Avvocadopnean Cipher Translator
//This program will translate between English and Avvocadopnean, with the standard A-Z, 0-9, and symbols . , ? ! '
//later more symbols from Avvocadopnean will be included

int mainMenu(void);
//menu options
void EngToAvv(void);
void AvvToEng(void);
void fileReader(void);
void aboutAvv(void);
void aboutProgram(void);
void Settings(void);
//functions for navigation
void returnHome(void);
int pageflipper(void);
//functions for input
void getString(int, char *);
int getYesNo(void);



//global variable - more avvocadopnean symbols to be added as program updated
const char AVVSYMBOLS[] = {'.', ',', '?', '!', '\''};
const char CLONESYMBOLS[] = {':', ';', '"'}; // replaced with '.', ',', '''

int main()
{
    int menuUserChoice = -1;
    //proceeds to selected option - add new menu options here
    while (menuUserChoice != 0)
    {
        //choose mode
        menuUserChoice = mainMenu();

        if (menuUserChoice == 1)
        {
            EngToAvv();
        } else if (menuUserChoice == 2)
        {
            AvvToEng();
        } else if (menuUserChoice == 3)
        {
            aboutAvv();
        } else if (menuUserChoice == 4)
        {
            aboutProgram();
        } else if (menuUserChoice == 5)
        {
            Settings();
        }
    }
    //exits program
    printf("\nThanks for using! Goodbye.\n");

    return 0;
}

//////////////////
//MENU FUNCTIONS//
//////////////////

int mainMenu(void)
{
    //change this to number of menu options desired
    int menuOptions = 5;

    // !!!!!!! if you're gonna add stuff, do a new branch and practice merging with git

    //while loop for menu
    int menuUserChoice = 1;
    while (menuUserChoice != 0)
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
        printf("    5. Settings\n");
        printf("\n");
        printf("    0. Exit Program\n");
        printf("\n");
        printf("Select mode: ");

        //checks if valid option (x = 1~menuOptions). if not, loops prompt
        int invalidOption = 1;
        while (invalidOption == 1)
        {
            scanf("%d", &menuUserChoice);

            if (menuUserChoice >= 0 && (menuUserChoice <= menuOptions) )
            {
                return menuUserChoice;
            } else
            {
                printf("\n%d is invalid.\nInput valid option: ", menuUserChoice);
            }
        }
        //exit menu and program
        if (menuUserChoice != 0)
        {
            printf("Valid option selected! Proceeding...\n");
            return 0;
        }
    }
}

void EngToAvv(void)
{
    printf("\n--------------------------------------------------\n");
    printf("English -> Avvocadopnean\n");

    /*
    **************************
    ASCII char's int values:
    A~Z = 65~90
    a~z = 97~122
    ***************************
    */

    //ENG->AVV EXPLAINED (uppercase example)
    //user types HELLO
    //int values 72 69 76 76 79
    //replaces those values with -65. / and % resulting int
    //ex: 72 - 64 = 8. then divide 8 / 5 = 1, or 1st row (,), then 8 % 5 = 3, or 3rd column (?).
    //takes these from AVVSYMBOLS[] and outputs to engAvvResult[], which increments each time and gets printed
    //ingenious i know hehe >:)
    //AS FOR iAvvOutput AND avvOutput
    //created in case of printing out avvOutput txt file

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

    /////////////////////
    //TAKES USER STRING//
    /////////////////////

    const int MAXINPUT = 250;

    printf("Input expression to encrypt Eng -> Avv\n");
    printf("Up to %d characters\n", MAXINPUT);
    printf("\n");
    printf("English to encrypt: ");
    char EngAvvInput[MAXINPUT+1];
    getString(MAXINPUT, EngAvvInput);
    //printf("back in EngToAvv, your string is: %s\n", EngAvvInput);
    //RMVME remove this when capitalization added afterwards: 
    for(int i = 0; EngAvvInput[i]; i++)
    {
        EngAvvInput[i] = tolower(EngAvvInput[i]);
    }

    /////////////////////////
    //ENCIPHERS USER STRING//
    /////////////////////////

    int SymbolRow;
    int SymbolColumn;
    //records to array in case of output
    char avvOutput[MAXINPUT * 4];    
    //i'm pretty sure *4 is enough space for any cipher, but not sure. I think z being ... (4 characters)
    //is the longest possible symbol in avvocadopnean?

    int nullChecker = 1;
    int iAvvOutput = 0;
    for (int i = 0; nullChecker != '\0'; i++)
    {
        //if clone character detected, replaces it
        if (strchr(CLONESYMBOLS, EngAvvInput[i]) != NULL)
        {
            switch(EngAvvInput[i])
            {
                case ':' :
                    EngAvvInput[i] = '.';
                    break;
                case ';' :
                    EngAvvInput[i] = ',';
                    break;
                case '"' :
                    EngAvvInput[i] = '\'';
                    break;
            }
        }
        //deals with space character
        if (EngAvvInput[i] == ' ')
        {
            //printf("- "), unless previous symbol was . , ? ! (eliminate redundant space symbol)
            if ( (!(EngAvvInput[i] == '.' || EngAvvInput[i] == ',' || EngAvvInput[i] == '?' || EngAvvInput[i] == '!')) && (!(EngAvvInput[i-1] == '.' || EngAvvInput[i-1] == ',' || EngAvvInput[i-1] == '?' || EngAvvInput[i-1] == '!')) )
            {
                avvOutput[iAvvOutput] = '-';
                iAvvOutput++;
            }
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } else if (EngAvvInput[i] == '.' || EngAvvInput[i] == ',' || EngAvvInput[i] == '?' || EngAvvInput[i] == '!' || EngAvvInput[i] == '\'') //deals with punctuation markers which end sentence - don't want redundant space
        {
            avvOutput[iAvvOutput] = EngAvvInput[i];
            iAvvOutput++;
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } else if (EngAvvInput[i] == 'z') //deals with z character
        {
            //printf("... ");
            for (int i = 0; i < 3; i++)
            {
                avvOutput[iAvvOutput] = '.'; 
                iAvvOutput++;
            }
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } else if (isalpha(EngAvvInput[i]) != 0) //deals with a-y characters
        {
            SymbolRow = (EngAvvInput[i] - 97) / 5;
            SymbolColumn = ((EngAvvInput[i] - 97) % 5);
            //printf("%c%c ", AVVSYMBOLS[SymbolRow], AVVSYMBOLS[SymbolColumn]);
            avvOutput[iAvvOutput] = AVVSYMBOLS[SymbolRow];
            iAvvOutput++;
            avvOutput[iAvvOutput] = AVVSYMBOLS[SymbolColumn];
            iAvvOutput++;
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } else if (isdigit(EngAvvInput[i]) != 0) //deals with numbers - converts to decimal for now
        {
            int temp = EngAvvInput[i];
            //printf("temp is d: %d, c: %c\n", temp, temp);
            temp -= 48; //corrects from ASCII digit value to int
            if ( (temp >= 1) && (temp <= 5) )
            {
                avvOutput[iAvvOutput] = '*';
                iAvvOutput++;
                avvOutput[iAvvOutput] = AVVSYMBOLS[temp-1];
            } else
            {
                avvOutput[iAvvOutput] = '^';
                iAvvOutput++;
                if (temp == 0)
                    avvOutput[iAvvOutput] = '\'';
                else
                    avvOutput[iAvvOutput] = AVVSYMBOLS[temp-6];
            }
            iAvvOutput++;
        }
        
        else //deals with any other characters, which aren't included in Avvocadopnean
        {
            avvOutput[iAvvOutput] = EngAvvInput[i];
            iAvvOutput++;
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        }
        nullChecker = EngAvvInput[i + 1];
    }
    avvOutput[iAvvOutput] = '\0';

    //prints English and Avvocadopnean out
    printf("\n");
    printf("Comparison:\n");
    //English (needs to artificially add spaces in)
    printf("English:        ");
    for (int i = 0; i < strlen(EngAvvInput); i++)
    {
        if ((EngAvvInput[i-1] == '.' || EngAvvInput[i-1] == ',' || EngAvvInput[i-1] == '?' || EngAvvInput[i-1] == '!') && EngAvvInput[i] == ' ')
            printf(" ");
        else if (EngAvvInput[i] == ' ')
            printf("  ");
        else if (EngAvvInput[i] == '.' || EngAvvInput[i] == ',' || EngAvvInput[i] == '?' || EngAvvInput[i] == '!' || EngAvvInput[i] == '\'')
            printf("%c ", EngAvvInput[i]);
        else if (EngAvvInput[i] == 'z') //deals with z
            printf("z   ");
        else if (isalpha(EngAvvInput[i]) != 0) //deals with a-y (z excluded above) and numbers
            printf("%c  ", EngAvvInput[i]);
        else //deals with any other characters, which aren't included in Avvocadopnean
            printf("%c ", EngAvvInput[i]);
    }
    printf("\n");

    //Avvocadopnean
    printf("Avvocadopnean:  %s\n", avvOutput); 

    ///////////////
    //FILE OUTPUT//
    ///////////////

    printf("\n");
    printf("\n");
    printf("Would you like to output a text file? Y/N: ");
    int printMe = getYesNo();
    
    //file creation if doesn't exist
    if (printMe == 1)
    {
        FILE *fpointer = fopen("avvOutput.txt", "a");
        if (fpointer == NULL)
        {
            printf("Error: could not create text file\n");
            return;
        }

        //obtains time
        time_t currentTime;
        time(&currentTime);

        fprintf(fpointer, "%s", ctime(&currentTime));
        fprintf(fpointer, "%s\n", EngAvvInput);
        fprintf(fpointer, "%s\n", avvOutput);
        fprintf(fpointer, "\n");

        fclose(fpointer);
        
        printf("Output text successfully written to file avvOutput.txt\n");
        printf("avvOutput.txt is located wherever you stored this program\n");
    }
}
void AvvToEng(void)
{
    printf("\n--------------------------------------------------\n");
    printf("test this is AvvToEng\n");
}

void fileReader(void)
{
    printf("\n--------------------------------------------------\n");
    printf("Have a .txt file to read? Translate it here!\n");
    printf("\n");
    //have 1 Eng->Avv, 2 Avv->Eng, and 0 (exit) as options
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
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c%c ", AVVSYMBOLS[i], AVVSYMBOLS[j]);
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
    printf("\n");
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

void Settings(void)
{
    printf("\n--------------------------------------------------\n");
    printf("beep boop\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d character is %c\n", i, AVVSYMBOLS[i]);
    }


    returnHome();
}

//////////////////////
//NON-MENU FUNCTIONS//
//////////////////////

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

//for about modes, returns page user wishes to view
int pageFlipper(void)
{
    return 0;
}

//sanitizes input
void getString(int inputLength, char * inputString)
{
    //gets string - modeled from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
    char tmpStore[inputLength+1];
    getchar();
    if (fgets(tmpStore, inputLength, stdin))
    {
        tmpStore[strcspn(tmpStore, "\n")] = 0;
        //printf("test message: %s\n", tmpStore);
        strcpy(inputString, tmpStore);
    } else
    {
        printf("error getting string\n");
    }
}

int getYesNo(void)
{
    //gets string - modeled from http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
    char tmpStore[4];
    int error = 0;
    while (error == 0)
    {
        //getchar();
        
        if (fgets(tmpStore, 4, stdin))
        {
            tmpStore[strcspn(tmpStore, "\n")] = 0;
            //printf("test message1: %s\n", tmpStore);

            //convert to lowercase
            for (int i = 0; i < 4; i++)
            {
                tmpStore[i] = tolower(tmpStore[i]);
            }
            //printf("test message2: %s\n", tmpStore);

            if (strcmp(tmpStore, "yes") == 0 || strcmp(tmpStore, "y") == 0)
                return 1;
            else if (strcmp (tmpStore, "no") == 0 || strcmp(tmpStore, "n") == 0)
                return 0;
        } else
        {
            printf("Error getting yes/no input\n");
            error = 1;
        }
        printf("Invalid Input: Input Yes or No (Y/N): ");
    }
}

