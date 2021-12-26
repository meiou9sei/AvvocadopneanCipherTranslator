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
void Settings(void);
//cipher functions
void engtoavvCipher(int, char *);
void avvtoengCipher(int, char *);
//functions for navigation
void returnHome(void);
int pageflipper(void);
//functions for input
void getString(int, char *);
int getYesNo(void);
int getDigit(void);
//file output
void fileOutput(char *, char *, char *);



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
            fileReader();
        } else if (menuUserChoice == 4)
        {
            aboutAvv();
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
        printf("    3. File Reader\n");
        printf("    4. About this Program/Avvocadopnean\n");
        printf("    5. Settings\n");
        printf("\n");
        printf("    0. Exit Program\n");
        printf("\n");
        printf("Select mode: ");

        //checks if valid option (x = 1~menuOptions). if not, loops prompt
        int invalidOption = 1;
        while (invalidOption == 1)
        {

            menuUserChoice = getDigit();

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

//enciphers English to Avvocadopnean
void EngToAvv(void)
{
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("English -> Avvocadopnean\n");
    printf("\n");

    /////////////////////
    //TAKES USER STRING//
    /////////////////////

    const int MAXINPUT = 250;

    printf("Input expression to encipher Eng -> Avv\n");
    printf("Up to %d characters\n", MAXINPUT);
    printf("\n");
    printf("English to encipher: ");
    char EngAvvInput[MAXINPUT+1];
    getString(MAXINPUT, EngAvvInput);

    //encipher string
    engtoavvCipher(MAXINPUT, EngAvvInput);

    returnHome();
}

//deciphers Avvocadopnean to English
void AvvToEng(void)
{
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("Avvocadopnean -> English\n");
    printf("\n");

    printf("WARNING: This mode is buggy. Some texts will not decipher properly\n");
    printf("\n");

    /////////////////////
    //TAKES USER STRING//
    /////////////////////

    const int MAXINPUT = 1000;

    printf("Input expression to decipher Avv -> Eng\n");
    printf("Up to %d characters\n", MAXINPUT);
    printf("\n");
    printf("Avvocadopnean to decipher: ");
    char AvvEngInput[MAXINPUT+1];
    getString(MAXINPUT, AvvEngInput);
    //printf("back in AvvToEng, your string is: %s\n", AvvEngInput);

    //deciphers Avv to Eng
    avvtoengCipher(MAXINPUT, AvvEngInput);

    returnHome();
}

void fileReader(void)
{
    printf("\n--------------------------------------------------\n");
    printf("\n");
    printf("FILE READER\n");
    printf("\n");
    printf("Have a .txt file to read?\n");
    printf("\n");
    printf("    1) English file\n");
    printf("    2) Avvocadopnean file\n");
    printf("\n");
    printf("    0) exit to menu\n");
    printf("\n");

    ////////////////////
    //takes type to do//
    ////////////////////

    printf("Enter option: ");
    int fileType = 0;
    int nah = 0;
    while (nah == 0)
    {
        nah = 1;
        char menuOp[3];
        getString(2, menuOp);
        //printf("string %s\n", menuOp);
        if (menuOp[0] == '1')
            fileType = 1;
        else if (menuOp[0] == '2')
            fileType = 2;
        else if (menuOp[0] == '0')
            fileType = 0;
        else
        {
            printf("Error. Enter valid menu option 0-2.\n");
            nah = 0;
        }
    }
    printf("\n");

    //////////////
    //reads file//
    //////////////
    int inputLength = 500;
    int maxlines = 100;
    printf("Reads up to %d characters per line, %d lines\n", inputLength, maxlines);
    printf("Enter name of file (with .txt) (file should be in same folder as program): ");
    char fileName[100];
    getString(99, fileName);

    FILE * fPointer;
    fPointer = fopen(fileName, "r");
    if (fPointer == NULL)
    {
        printf("ERROR: file not found\n");
        printf("Don't forget to add \".txt\" at the end of your filename\n");
        returnHome();
        return;
    }

    char storesLines[maxlines][inputLength];
    int lineCounter = 0;
    int line = 0;

    while (!feof(fPointer))
    {
        fgets(storesLines[line], inputLength, fPointer);
        lineCounter++;
        line++;
    }
    //printf("lineCounter is %d\n", lineCounter);

    fclose(fPointer);

    /////////////////////////////////////////////////
    //sends off to appropriate function for message//
    /////////////////////////////////////////////////
    if (fileType == 1)
    {
        for (int line = 0; line < lineCounter; line++)
        {
            engtoavvCipher(inputLength, storesLines[line]);
        }
    }
    else if (fileType == 2)
    {
        for (int line = 0; line < lineCounter; line++)
        {
            avvtoengCipher(inputLength, storesLines[line]);
        }
    }


    returnHome();
}

//explains how Avvocadopnean works
void aboutAvv(void)
{
    //page 0
    printf("\n--------------------------------------------------\n");
    printf("\n");
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
    printf("To encipher a letter, first use the horizontal row then the vertical column.\n");
    printf("Words are separated by a -\n");
    printf("\n");
    printf("For example:\n");
    printf("\n");
    printf("    ,? .' ?, ?, ?' - '? ?' !? ?, .!\n");
    printf("    h  e  l  l  o    w  o  r  l  d\n");
    printf("\n");

    printf("\n--------------------------------------------------\n");
    printf("ABOUT THIS PROGRAM\n");
    printf("\n");
    printf("The AVVOCADOPNEAN CIPHER TRANSLATOR program was written by Cameron Avvampato (me) in C.\n");
    printf("This program intends to:\n");
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
////////////////////
//CIPHER FUNCTIONS//
////////////////////
void engtoavvCipher(int MAXINPUT, char *EngAvvInput)
{
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
        //printf("enter doom :)\n");
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
            //deals with space character - printf("- "), unless previous symbol was . , ? ! (eliminate redundant space symbol)
            if ( (!(EngAvvInput[i] == '.' || EngAvvInput[i] == ',' || EngAvvInput[i] == '?' || EngAvvInput[i] == '!')) && (!(EngAvvInput[i-1] == '.' || EngAvvInput[i-1] == ',' || EngAvvInput[i-1] == '?' || EngAvvInput[i-1] == '!')) )
            {
                avvOutput[iAvvOutput] = '-';
                iAvvOutput++;
            }
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } //deals with punctuation markers which end sentence - don't want redundant space
        else if (EngAvvInput[i] == '.' || EngAvvInput[i] == ',' || EngAvvInput[i] == '?' || EngAvvInput[i] == '!' || EngAvvInput[i] == '\'')
        {
            avvOutput[iAvvOutput] = EngAvvInput[i];
            iAvvOutput++;
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        } else if (EngAvvInput[i] == '-')
        {
            avvOutput[iAvvOutput] = EngAvvInput[i];
            iAvvOutput++;
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
        } else //deals with any other characters, which aren't included in Avvocadopnean
        {
            avvOutput[iAvvOutput] = EngAvvInput[i];
            iAvvOutput++;
            avvOutput[iAvvOutput] = ' ';
            iAvvOutput++;
        }
        nullChecker = EngAvvInput[i + 1];
        //printf("nullChecker is %c\n", nullChecker);
    }
    avvOutput[iAvvOutput] = '\0';

    ////////////////////////////////////////
    //prints English and Avvocadopnean out//
    ////////////////////////////////////////
    printf("\n");
    printf("Pre-cipher text: %s", EngAvvInput);

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
        else if (EngAvvInput[i] == '-')
            printf("%c%c ", EngAvvInput[i]);
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
    //create avvoutput as a string
    char fileName[15]; //prevents strcat crashing in fileReader?
    strcpy(fileName, "engToAvv");
    if (getYesNo() == 1)
        fileOutput(fileName, EngAvvInput, avvOutput);

}

void avvtoengCipher(int MAXINPUT, char *AvvEngInput)
{
    //AVV->ENG EXPLAINED (uppercase example)
    //user types ,? .' ?, ?, ?'
    //take ,?
    //1) confirms is 2 letters (followed by space) and not a number (would start with ^ or *) nor hyphen (--)
    //2) index of , in AVVSYMBOLS[] is 1, ? is 2.
    //       multiply first by 5, then add second, then add ASCII 65 for A
    //       (1 * 5) + 2 + 65 = 72, or ASCII value for H
    //3) any groupings of 1 characters are left alone
    //       any groupings of 3 characters are deemed uppercase/lowercase (starts with ^ or *) or z (...)

    /////////////////////////
    //DECIPHERS USER STRING//
    /////////////////////////

    int SymbolRow;
    int SymbolColumn;
    //records to array in case of output
    char engOutput[MAXINPUT/2 +1];
    //Eng is at least half the size of Avv if only punctuations are typed in, probably much shorter
    int nullChecker = 1;
    int iEngOutput = 0;

    //printf("test message - you reached me\n");

    int i = 0; //tracks which element of AvvEngInput on

    int testWhile = 0;
    while (nullChecker != '\0') //not a for loop like Eng->Avv, because in E->A each char expands from 1 to multiple, but in A->E a group of 1~4 chars group into 1
    {
        //printf("entered while loop number %d\n", testWhile);
        testWhile++;

        int letterCase = 0;
        //first if/else deal with z
        if (AvvEngInput[i] == '-') //lmao you had this as ' ' and were confused why you kept getting spaces in engOutput
        {
            //printf("entered '-' zone\n");
            engOutput[iEngOutput] = ' ';
            iEngOutput++;
            i++;
        } else if (AvvEngInput[i] == ' ')
        {
            //printf("entered ' ' zone\n");
            i++;
        }  else if ( ( (AvvEngInput[i] == '.') && (AvvEngInput[i+1] == '.') && (AvvEngInput[i+2] == '.') ) || ( (AvvEngInput[i] == '*') && (AvvEngInput[i+1] == '.') && (AvvEngInput[i+2] == '.') && (AvvEngInput[i+3] == '.') ) ) //lowercase z
        {
            engOutput[iEngOutput] = 'z';
            iEngOutput++;
            i += 3;
        }
        else if ((AvvEngInput[i] == '^') && (AvvEngInput[i+1] == '.') && (AvvEngInput[i+2] == '.') && (AvvEngInput[i+3] == '.')) //uppercase Z
        {
            engOutput[iEngOutput] = 'Z';
            iEngOutput++;
            i += 4;
        }

        //then move onto the rest of characters
        //a-y, or number if start w/ ^ * OR IF 3 letter (upper/lowercase specifier), uses parts of 2 letter function
        else if ( ((AvvEngInput[i+1] != ' ') && ( (AvvEngInput[i+2] == ' ') || (AvvEngInput[i+2] == '\0') ) ) || ((AvvEngInput[i+1] != ' ') && (AvvEngInput[i+2] != ' ') && ( (AvvEngInput[i+3] == ' ') || (AvvEngInput[i+3] == '\0') ) ) )
        {
            if ((AvvEngInput[i+1] != ' ') && (AvvEngInput[i+2] != ' ') && (AvvEngInput[i+2] != '\0') && (AvvEngInput[i+3] == ' ')) //3 letter case specifier realm
            {
                if (AvvEngInput[i] == '^')
                    letterCase = 65;
                else if (AvvEngInput[i] == '*')
                    letterCase = 97;

                i++;
            } else
            {
                letterCase = 97;
            }
            //code to decipher 2 letter here
            //printf("code to decipher 2 letters here\n");
            //finds row
            for (int j = 0; j < 5; j++)
            {
                /*
                printf("entered j loop\n");
                printf("j is %d\n", j);
                printf("AvvEngInput[i] is: %c, AVVSYMBOLS[j] is: %c\n", AvvEngInput[i], AVVSYMBOLS[j]);
                */
                if (AvvEngInput[i] == AVVSYMBOLS[j])
                {
                    //printf("two are equal\n");
                    SymbolRow = j;
                    //printf("SymbolRow is %d, j is %d\n", SymbolRow, j);
                }
            }
            //printf("SymbolRow is %d\n\n\n", SymbolRow);
            //SymbolRow = strchr(AVVSYMBOLS, AvvEngInput[i]); <- this doesn't work, strchr returns a pointer to the char in AVVSYMBOLS, not an int for what element it was
            i++;
            //finds column
            for (int k = 0; k < 5; k++)
            {
                /*
                printf("entered k loop\n");
                printf("k is %d\n", k);
                printf("AvvEngInput[i] is: %c, AVVSYMBOLS[k] is: %c\n", AvvEngInput[i], AVVSYMBOLS[k]);
                */
                if (AvvEngInput[i] == AVVSYMBOLS[k])
                {
                    //printf("two are equal\n");
                    SymbolColumn = k;
                    //printf("SymbolColumn is %d, k is %d\n", SymbolColumn, k);
                }
            }
            //printf("SymbolColumn is %d\n\n\n", SymbolColumn);
            //SymbolColumn = strchr(AVVSYMBOLS, AvvEngInput[i]); <- this doesn't work, strchr returns a pointer to the char in AVVSYMBOLS, not an int for what element it was
            i++;

            //printf("letterCase is %d\n", letterCase);
            //printf("2 letter digit is: %d\n", ((SymbolRow * 5) + SymbolColumn + letterCase));

            //adds up numbers and stores character
            engOutput[iEngOutput] = ((SymbolRow * 5) + SymbolColumn + letterCase);
            //printf("2 letter output is: %c\n", engOutput[iEngOutput]);
            iEngOutput++;
        }
        //if not avvocadopnean, comes here
        //also special symbol/punctuation are translated as is
        else
        {
            engOutput[iEngOutput] = AvvEngInput[i];
            iEngOutput++;
            i++;
        }
        nullChecker = AvvEngInput[i];
        //printf("nullChecker is %c\n", nullChecker);
    }
    engOutput[iEngOutput] = '\0';

    ////////////////////////////////////////
    //prints English and Avvocadopnean out//
    ////////////////////////////////////////

    //printf("tests: %s !!! %s\n", AvvEngInput, engOutput);

    printf("\n");
    printf("Comparison:\n");
    //Avvocadopnean
    printf("Avvocadopnean:  %s\n", AvvEngInput);

    //bellow chunk copied from Eng->Avv
    //English (needs to artificially add spaces in)
    printf("English:        ");
    for (int i = 0; i < strlen(engOutput); i++)
    {
        if ((engOutput[i-1] == '.' || engOutput[i-1] == ',' || engOutput[i-1] == '?' || engOutput[i-1] == '!') && engOutput[i] == ' ')
            printf(" ");
        else if (engOutput[i] == ' ')
            printf("  ");
        else if (engOutput[i] == '.' || engOutput[i] == ',' || engOutput[i] == '?' || engOutput[i] == '!' || engOutput[i] == '\'')
            printf("%c ", engOutput[i]);
        else if (engOutput[i] == '-')
            printf("%c%c ", engOutput[i]);
        else if (engOutput[i] == 'z') //deals with z
            printf("z   ");
        else if (isalpha(engOutput[i]) != 0) //deals with a-y (z excluded above) and numbers
            printf("%c  ", engOutput[i]);
        else //deals with any other characters, which aren't included in Avvocadopnean
            printf("%c ", engOutput[i]);
    }
    printf("\n");


    //English
    printf("\n");
    printf("Output: %s", engOutput);

    ///////////////
    //FILE OUTPUT//
    ///////////////

    printf("\n");
    printf("\n");
    printf("Would you like to output a text file? Y/N: ");
    //create avvoutput as a string
    char fileName[15]; //prevents strcat crashing in fileReader?
    strcpy(fileName, "AvvToEng");
    if (getYesNo() == 1)
        fileOutput(fileName, AvvEngInput, engOutput);


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
    int userReturn;
    while (loopTrapper == 1)
    {
        userReturn = getDigit();

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

int getDigit(void) //http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
{
    int a;
    int rc;
    while ((rc = scanf("%d", &a)) == 0)  // Neither success (1) nor EOF
    {
        // clear what is left, the * means only match and discard:
        scanf("%*[^\n]");
        // input was not a number, ask again:
        printf("Invalid. Enter a number: ");
    }
    if (rc == EOF)
    {
        printf("End of file reached. No numbers read.\n");
    }
    else
    {
        //testmsg printf("You entered %d.\n", a);
    }
    return a;
}


///////////////
//FILE OUTPUT//
///////////////
void fileOutput(char * fileName, char * originalText, char * cipherText)
{
    //printf("reached fileOutput line 1\n");
    strcat(fileName, ".txt");   //apparently this strcat causes "stack smashing" (buffer overflow, I think) if fileName in wherever this is called doesn't have enough slots for ".txt\0"

    //file creation if doesn't exist
    FILE *fpointer = fopen(fileName, "a");
    if (fpointer == NULL)
    {
        printf("Error: could not create text file\n");
        return;
    }

    //obtains time
    time_t currentTime;
    time(&currentTime);

    fprintf(fpointer, "%s", ctime(&currentTime));
    fprintf(fpointer, "%s\n", originalText);
    fprintf(fpointer, "%s\n", cipherText);
    fprintf(fpointer, "\n");

    fclose(fpointer);

    printf("Output text successfully written to file %s\n", fileName);
    printf("%s is located in the same folder/directory where this program is stored\n", fileName);
}
