#pragma once

#include "discord/discord.h"
#include <string>
#include <stdlib.h>
#include <chrono>

#define uint64 unsigned long long
#define uint32 unsigned int
#define cchar const char*

#define BLITZ3D(x) extern "C" __declspec(dllexport) x _stdcall

//CORE FUNCTIONS
BLITZ3D(void) BlitzcordCreateCore(cchar id);
BLITZ3D(void) BlitzcordRunCallbacks();

//ACTIVITY FUNCTIONS
BLITZ3D(void) BlitzcordSetActivityState(cchar state);
BLITZ3D(void) BlitzcordSetActivityDetails(cchar details);
BLITZ3D(void) BlitzcordSetActivityType(int type);
BLITZ3D(void) BlitzcordClearActivity();
BLITZ3D(void) BlitzcordUpdateActivity();

//SMALL IMAGE FUNCTIONS
BLITZ3D(void) BlitzcordSetSmallImage(cchar image);
BLITZ3D(void) BlitzcordSetSmallText(cchar text);
BLITZ3D(cchar) BlitzcordGetSmallImage();
BLITZ3D(cchar) BlitzcordGetSmallText();

//LARGE IMAGE FUNCTIONS
BLITZ3D(void) BlitzcordSetLargeImage(cchar image);
BLITZ3D(void) BlitzcordSetLargeText(cchar text);
BLITZ3D(cchar) BlitzcordGetLargeImage();
BLITZ3D(cchar) BlitzcordGetLargeText();

//TIMESTAMP FUNCTIONS
BLITZ3D(void) BlitzcordSetTimestampStart(cchar timestamp);
BLITZ3D(void) BlitzcordSetTimestampEnd(cchar timestamp);
BLITZ3D(int) BlitzcordGetTimestampStartUpper();
BLITZ3D(int) BlitzcordGetTimestampStartLower();
BLITZ3D(int) BlitzcordGetTimestampEndUpper();
BLITZ3D(int) BlitzcordGetTimestampEndLower();

//UNIX TIMESTAMP FUNCTIONS
BLITZ3D(cchar) BlitzcordGetCurrentTimestamp();
BLITZ3D(cchar) BlitzcordGetTimestampPlus(int hours, int minutes, int seconds);
BLITZ3D(cchar) BlitzcordGetTimestampMinus(int hours, int minutes, int seconds);

//LONG SPLITTING FUNCTIONS, SINCE BLITZBASIC DOES NOT SUPPORT LONGS.
BLITZ3D(int) StringToUpperLong(cchar stringLong);
BLITZ3D(int) StringToLowerLong(cchar stringLong);
BLITZ3D(cchar) LongToString(int upperLong, int lowerLong);

int longUpper(uint64 value);
int longLower(uint64 value);
uint64 mergeLong(int upperLong, int lowerLong);
