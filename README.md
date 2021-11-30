# AvvocadopneanCipherTranslator
Translates Avvocadopnean Cipher to English and vice versa. Personal project to test out my c skillz

currently (just for a few days) broken, will fix soon


## How to install and use
I think you can just use a C compiler (like gcc) with codeblocks or VSCode and run the main AvvocadopneanCipherTranslator.c ...? I'm new so don't know, you can probably google it. I'm pretty sure you just need the .c file, or can run AvvocadopneanCipherTranslator file itself through terminal?

I'll look into it later

## TODO:

- add settings to TODO list
  - would detect if settings file exists
  - can write basic settings like whether to use binary or decimal, 
  - whether to use default caps or lowercase when translating, etc.

**new TODO list:**
1) create and implement getInt function for use in menus so program doesn't crash upon entry of char
  - probably take in input a char, then convert it to int
  - maybe an fflush(stdin) for it after each scanf? (nah man I think you use getchar)
  - also make getYesNo, and maybe getTrueFalse (though you can prob just use getInt w/ 1 0) for settings mode
2)  Eng->Avv translator
  - add ability to switch between lowercase/uppercase with ^
  - try adding numbers
  - add '-', ':', ';', '"' recognizers
  - maybe try putting space between string text, so that it lines up with translation?
  any 
3) AvvToEng
        reverse EngToAvv, basically. Try to modify EngToAvv functions so they're reusable here.
        OR I think you can just 1) check if there's 2 (or 3 for z) symbols together 2) do x * 5 for first symbol, + x for second symbol to get ASCII int # for A-Z.
        //^lowercase I think, try implementing ^ v later
4) add 
4) aboutAvv
    flesh this out more. create page flipping function so you can
    redo it following the documents you have in person
        - go to table of contents
        - go to next page
        - go to last page
            with keys probably n/ext and b/ack
5) aboutProgram
  - formalize it -_- 
x) add spoken generator
x) write in README.md instructions on how to use program
