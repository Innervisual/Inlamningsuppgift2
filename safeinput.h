#ifndef SAFEINPUT_H
#define SAFEINPUT_H

typedef void (*Callback)(void);

int readInt();
int readIntWithCallback(Callback errorCallback);
int readIntWithCallbackAndExitChar(void (*invalidInputCallback)(), char exitChar);

#endif // SAFEINPUT_H
