# AvvocadopneanCipherTranslator
Translates Avvocadopnean Cipher to English and vice versa. Personal project

Currently Avv->Eng is a bit buggy, but should work for simple messages

## How to install and use
not sure. I'll look into it later. pretty sure you can just compile the .c file and it'll work though

## TODO:
first and foremost: fix Avv->eng so it's not so buggy

0) replace aboutAvv or aboutProgram with fileReader
1) create and implement getInt function for use in menus so program doesn't crash upon entry of char
  - probably take in input a char, then convert it to int
2)  Eng->Avv translator
  - add ability to switch between lowercase/uppercase with ^
3) AvvToEng
        reverse EngToAvv, basically. Try to modify EngToAvv functions so they're reusable here.
        OR I think you can just 1) check if there's 2 (or 3 for z) symbols together 2) do x * 5 for first symbol, + x for second symbol to get ASCII int # for A-Z.
        //^lowercase I think, try implementing ^ v later
4) Settings
  - would detect if settings file exists
  - can write basic settings like whether to use binary or decimal, (also add binary)
  - whether to use default caps or lowercase when translating, etc. (also add upper/lowercase detection for Avv->Eng)
5) aboutAvv
    flesh this out more. create page flipping function so you can
    redo it following the documents you have in person
        - go to table of contents
        - go to next page
        - go to last page
            with keys probably n/ext and b/ack
6) aboutProgram
  - formalize it -_- 
x) add spoken generator
x) write in README.md instructions on how to use program

learnGit2



personal notes:
changes from original avvocadopnean rules:
- base10/binary do not need !_ and ?_ distinguishers, since they are already distinguishable
- in case of - use, like "anne-marie", should print .. ?! ?! .' -- ?? .. !? ,! .' (double --)
