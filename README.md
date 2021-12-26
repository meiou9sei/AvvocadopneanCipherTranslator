# AvvocadopneanCipherTranslator
Translates Avvocadopnean Cipher to English and vice versa. Personal project of Cameron Avvampato. Written in C. Enciphers English to Avvocadopnean and vice versa.

Current bugs:
* Avv->Eng is a bit buggy, but should work for simple messages. punctuation/spacing may be buggy, and numbers do not work
* filereader requires confirmation on output every line for now

## How to install and use
On windows, you can compile AvvocadopneanCipherTranslator.c in ACTcb folder, or download the AvvocadopneanCipherTranslator.exe file (located within same folder) and run that for windows. 

On mac and linux, you can just compile it I'm pretty sure with gcc -o AvvocadopneanCipherTranslator.c ACT, then run ./ACT 

## TODO:
first and foremost: fix Avv->eng so it's not so buggy

1)  Eng->Avv translator
  - add ability to switch between lowercase/uppercase with ^
  - spacing on numbers is broken
2) AvvToEng
  fix it. also implement numbers
3) Settings
  - would detect if settings file exists
  - can write basic settings like whether to use binary or decimal, (also add binary)
  - whether to use default caps or lowercase when translating, etc. (also add upper/lowercase detection for Avv->Eng)
4) aboutAvv
    flesh this out more. create page flipping function so you can
    redo it following the documents you have in person
        - go to table of contents
        - go to next page
        - go to last page
            with keys probably n/ext and b/ack

x) add spoken Avvocadopnean generator

x) write in README.md instructions on how to use program

x) restructure input to be dynamic string sizes with malloc?

personal notes:
changes from/for original avvocadopnean rules:
- base10/binary do not need !_ and ?_ distinguishers, since they are already distinguishable
- in case of - use, like "anne-marie", should print .. ?! ?! .' -- ?? .. !? ,! .' (double --)