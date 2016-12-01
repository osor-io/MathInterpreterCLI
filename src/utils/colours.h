#ifndef BDC_COLOURS_H
#define BDC_COLOURS_H

//Comfortable implementation for showing colours in Unix's terminals found at: http://stackoverflow.com/questions/3585846/color-text-in-terminal-applications-in-unix

//May not work in every single terminal so you can define "DONT_USE_COLOURS" in order to turn off all the colours.


#ifdef DONT_USE_COLOURS

#define RED
#define GRN
#define YEL
#define BLU
#define MAG
#define CYN
#define WHT
#define RESET

#else

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#endif

#endif //BDC_COLOURS_H
