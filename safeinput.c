#include "safeinput.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int readInt() {
    return readIntWithCallback(NULL);
}

int readIntWithCallback(Callback errorCallback) {
    return readIntWithCallbackAndExitChar(errorCallback, '\0');
}

int readIntWithCallbackAndExitChar(Callback errorCallback, char exitChar) {
    int value;
    char input[100];

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == exitChar || input[0] == toupper(exitChar)) {
            return -1;
        }
        
        if (sscanf(input, "%d", &value) == 1 && strchr(input, '\n')) {
            return value;
        }

        if (errorCallback) {
            errorCallback();
        }
    }

    return -1;
}


