# AvvocadopneanCipherTranslator
Translates Avvocadopnean Cipher to English and vice versa. Personal project to test out my c skillz

currently (just for a few days) broken, will fix soon


## How to install and use
I think you can just use a C compiler (like gcc) with codeblocks or VSCode and run the main AvvocadopneanCipherTranslator.c ...? I'm new so don't know, you can probably google it. I'm pretty sure you just need the .c file, or can run AvvocadopneanCipherTranslator file itself through terminal?

I'll look into it later

## TODO:

**new TODO list:**
1) create and implement get_int function for use in menus so program doesn't crash upon entry of char
  - probably take in input a char, then convert it to int
  - maybe an fflush(stdin) for it after each scanf? 
2) redo Eng->Avv translator
  - you broke it somehow messing with menu implementation/making it a global variable, so just recreate it from scratch
  - scratch code in laboratory ^ and just try printing it first to see if it works ^ don't add file read/write yet
  - use fgets since you're dealing with strings
  - get rid of write to file part for now - in fact, make that it's own function 
  - just focus on caps only for now, and add Z recognizability

  - default to lowercase
  - add ability to switch between lowercase/uppercase with ^
  - try adding punctuation
  - try adding numbers
  - maybe try putting space between string text, so that it lines up with translation?
3) AvvToEng
        reverse EngToAvv, basically. Try to modify EngToAvv functions so they're reusable here.
        OR I think you can just 1) check if there's 2 (or 3 for z) symbols together 2) do x * 5 for first symbol, + x for second symbol to get ASCII int # for A-Z.
        //^lowercase I think, try implementing ^ v later
4) aboutAvv
    flesh this out more. create page flipping function so you can
        - go to table of contents
        - go to next page
        - go to last page
            with keys probably n/ext and b/ack
5) aboutProgram
  - formalize it -_- 
x) add ability to read and write txt files with avvocadopnean. probably do "a" instead of "w", w/ warning message "can delete text after you take it out if you want" or something. also create said output.txt file if it doesn't exist
x) add spoken generator
x) write in README.md instructions on how to use program
