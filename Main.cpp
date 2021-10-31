#include "Blitzcord.h"

discord::Core* core{};
discord::Activity activity{};

//CORE FUNCTIONS
//--------------
BLITZ3D(void) BlitzcordCreateCore(cchar id)
{
	long long convertedLong = atoll(id);
	int upperID = longUpper(convertedLong);
	int lowerID = longLower(convertedLong);

	auto result = discord::Core::Create(mergeLong(upperID, lowerID), DiscordCreateFlags_NoRequireDiscord, &core);
	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}

BLITZ3D(void) BlitzcordRunCallbacks()
{
	::core->RunCallbacks();
}

//ACTIVITY FUNCTIONS
//------------------
BLITZ3D(void) BlitzcordSetActivityState(cchar state)
{
	activity.SetState(state);
}

BLITZ3D(void) BlitzcordSetActivityDetails(cchar details)
{
	activity.SetDetails(details);
}

BLITZ3D(void) BlitzcordSetActivityType(int type)
{
	activity.SetType((discord::ActivityType)type);
}

BLITZ3D(void) BlitzcordClearActivity()
{
	core->ActivityManager().ClearActivity([](discord::Result result) {});
}

BLITZ3D(void) BlitzcordUpdateActivity()
{
	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}

//SMALL IMAGE FUNCTIONS
//---------------------
BLITZ3D(void) BlitzcordSetSmallImage(cchar image)
{
	activity.GetAssets().SetSmallImage(image);
}

BLITZ3D(void) BlitzcordSetSmallText(cchar text)
{
	activity.GetAssets().SetSmallText(text);
}

BLITZ3D(cchar) BlitzcordGetSmallImage()
{
	return activity.GetAssets().GetSmallImage();
}

BLITZ3D(cchar) BlitzcordGetSmallText()
{
	return activity.GetAssets().GetSmallText();
}

//LARGE IMAGE FUNCTIONS
//---------------------
BLITZ3D(void) BlitzcordSetLargeImage(cchar image)
{
	activity.GetAssets().SetLargeImage(image);
}

BLITZ3D(void) BlitzcordSetLargeText(cchar text)
{
	activity.GetAssets().SetLargeText(text);
}

BLITZ3D(cchar) BlitzcordGetLargeImage()
{
	return activity.GetAssets().GetLargeImage();
}

BLITZ3D(cchar) BlitzcordGetLargeText()
{
	return activity.GetAssets().GetLargeText();
}

//TIMESTAMP FUNCTIONS
//-------------------
BLITZ3D(void) BlitzcordSetTimestampStart(cchar timestamp)
{
	long long convertedLong = atoll(timestamp);
	int upperLong = longUpper(convertedLong);
	int lowerLong = longLower(convertedLong);

	activity.GetTimestamps().SetStart(mergeLong(upperLong, lowerLong));
}

BLITZ3D(void) BlitzcordSetTimestampEnd(cchar timestamp)
{
	long long convertedLong = atoll(timestamp);
	int upperLong = longUpper(convertedLong);
	int lowerLong = longLower(convertedLong);

	activity.GetTimestamps().SetEnd(mergeLong(upperLong, lowerLong));
}

BLITZ3D(int) BlitzcordGetTimestampStartUpper()
{
	return longUpper(activity.GetTimestamps().GetStart());
}

BLITZ3D(int) BlitzcordGetTimestampStartLower()
{
	return longLower(activity.GetTimestamps().GetStart());
}

BLITZ3D(int) BlitzcordGetTimestampEndUpper()
{
	return longUpper(activity.GetTimestamps().GetEnd());
}

BLITZ3D(int) BlitzcordGetTimestampEndLower()
{
	return longLower(activity.GetTimestamps().GetEnd());
}

//UNIX TIMESTAMP FUNCTIONS
//------------------------
BLITZ3D(cchar) BlitzcordGetCurrentTimestamp()
{
	auto clockNow = std::chrono::system_clock::now();

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockNow.time_since_epoch()).count()).c_str());
}

BLITZ3D(cchar) BlitzcordGetTimestampPlus(int hours, int minutes, int seconds)
{
	auto clockNow = std::chrono::system_clock::now();
	auto clockAdded = clockNow + std::chrono::hours(hours) + std::chrono::minutes(minutes) + std::chrono::seconds(seconds);

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockAdded.time_since_epoch()).count()).c_str());
}

BLITZ3D(cchar) BlitzcordGetTimestampMinus(int hours, int minutes, int seconds)
{
	auto clockNow = std::chrono::system_clock::now();
	auto clockSubstracted = clockNow - std::chrono::hours(hours) - std::chrono::minutes(minutes) - std::chrono::seconds(seconds);

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockSubstracted.time_since_epoch()).count()).c_str());
}

//LONG SPLITTING
//--------------
BLITZ3D(int) StringToUpperLong(cchar stringLong)
{
	return longUpper(atoll(stringLong));
}

BLITZ3D(int) StringToLowerLong(cchar stringLong)
{
	return longLower(atoll(stringLong));
}

BLITZ3D(cchar) LongToString(int upperLong, int lowerLong)
{
	return _strdup(std::to_string(mergeLong(upperLong, lowerLong)).c_str());
}

int longUpper(uint64 value)
{
	return value >> 32;
}

int longLower(uint64 value)
{
	return value & 0xffffffff;
}

uint64 mergeLong(int upperLong, int lowerLong)
{
	return((uint64)upperLong << 32) | (uint32)lowerLong;
}