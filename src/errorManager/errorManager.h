#ifndef BDC_ERRORMANAGER_H
#define BDC_ERRORMANAGER_H

typedef enum {
    ERR_UNEXPECTED_EOF,
    ERR_BAD_OPERATOR,
    ERR_FILE_ERROR,
    ERR_BAD_BINARY,
    ERR_LEXEME_TOO_LARGE,
    ERR_BAD_SCI_NO,
    ERR_JUMP_LINE_IN_LITERAL,
    ERR_SCAPE_CHAR,
    ERR_CANT_PARSE_FUNCTION,
    ERR_BISON
} errorType;


void manageNonFatalError(int code, char *message);

void manageNonFatalErrorWithLine(int code, char *message, int line, int position);

void manageFatalError(int code, char *message);

void manageFatalErrorWithLine(int code, char *message, int line, int position);


#endif //BDC_ERRORMANAGER_H
