#pragma once

#include "discord/discord.h"
#include <string>
#include <stdlib.h>
#include <chrono>
#include <limits>

#define uint64 unsigned long long
#define uint32 unsigned int
#define cstring const char*

#define BLITZ3D(x) extern "C" __declspec(dllexport) x _stdcall

//CORE FUNCTIONS
BLITZ3D(int) BlitzcordCreateCore(cstring id);
BLITZ3D(void) BlitzcordRunCallbacks();

//ACTIVITY FUNCTIONS
BLITZ3D(void) BlitzcordSetActivityState(cstring state);
BLITZ3D(void) BlitzcordSetActivityDetails(cstring details);
BLITZ3D(void) BlitzcordSetActivityType(int type);
BLITZ3D(void) BlitzcordClearActivity();
BLITZ3D(void) BlitzcordUpdateActivity();

//SMALL IMAGE FUNCTIONS
BLITZ3D(void) BlitzcordSetSmallImage(cstring image);
BLITZ3D(void) BlitzcordSetSmallText(cstring text);
BLITZ3D(cstring) BlitzcordGetSmallImage();
BLITZ3D(cstring) BlitzcordGetSmallText();

//LARGE IMAGE FUNCTIONS
BLITZ3D(void) BlitzcordSetLargeImage(cstring image);
BLITZ3D(void) BlitzcordSetLargeText(cstring text);
BLITZ3D(cstring) BlitzcordGetLargeImage();
BLITZ3D(cstring) BlitzcordGetLargeText();

//TIMESTAMP FUNCTIONS
BLITZ3D(void) BlitzcordSetTimestampStart(cstring timestamp);
BLITZ3D(void) BlitzcordSetTimestampEnd(cstring timestamp);
BLITZ3D(int) BlitzcordGetTimestampStartUpper();
BLITZ3D(int) BlitzcordGetTimestampStartLower();
BLITZ3D(int) BlitzcordGetTimestampEndUpper();
BLITZ3D(int) BlitzcordGetTimestampEndLower();

//UNIX TIMESTAMP FUNCTIONS
BLITZ3D(cstring) BlitzcordGetCurrentTimestamp();
BLITZ3D(cstring) BlitzcordGetTimestampPlus(int hours, int minutes, int seconds);
BLITZ3D(cstring) BlitzcordGetTimestampMinus(int hours, int minutes, int seconds);

//LONG SPLITTING FUNCTIONS, SINCE BLITZBASIC DOES NOT SUPPORT LONGS.
BLITZ3D(int) StringToUpperLong(cstring stringLong);
BLITZ3D(int) StringToLowerLong(cstring stringLong);
BLITZ3D(cstring) LongToString(int upperLong, int lowerLong);

int longUpper(uint64 value);
int longLower(uint64 value);
uint64 mergeLong(int upperLong, int lowerLong);
