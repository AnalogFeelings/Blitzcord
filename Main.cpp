#include "Blitzcord.h"

discord::Core* core{};
discord::Activity activity{};

//CORE FUNCTIONS
//--------------
BLITZ3D(int) BlitzcordCreateCore(cstring id)
{
	long long convertedLong = atoll(id);

	discord::Result result = discord::Core::Create(convertedLong, DiscordCreateFlags_NoRequireDiscord, &core);

	return (int)result;
}

BLITZ3D(void) BlitzcordRunCallbacks()
{
	if (core == nullptr) return;
	::core->RunCallbacks();
}

//ACTIVITY FUNCTIONS
//------------------
BLITZ3D(void) BlitzcordSetActivityState(cstring state)
{
	if (core == nullptr) return;
	activity.SetState(state);
}

BLITZ3D(void) BlitzcordSetActivityDetails(cstring details)
{
	if (core == nullptr) return;
	activity.SetDetails(details);
}

BLITZ3D(void) BlitzcordSetActivityType(int type)
{
	if (core == nullptr) return;
	activity.SetType((discord::ActivityType)type);
}

BLITZ3D(void) BlitzcordClearActivity()
{
	if (core == nullptr) return;
	core->ActivityManager().ClearActivity([](discord::Result result) {});
}

BLITZ3D(void) BlitzcordUpdateActivity()
{
	if (core == nullptr) return;
	core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
}

//SMALL IMAGE FUNCTIONS
//---------------------
BLITZ3D(void) BlitzcordSetSmallImage(cstring image)
{
	if (core == nullptr) return;
	activity.GetAssets().SetSmallImage(image);
}

BLITZ3D(void) BlitzcordSetSmallText(cstring text)
{
	if (core == nullptr) return;
	activity.GetAssets().SetSmallText(text);
}

BLITZ3D(cstring) BlitzcordGetSmallImage()
{
	if (core == nullptr) return "";
	return activity.GetAssets().GetSmallImage();
}

BLITZ3D(cstring) BlitzcordGetSmallText()
{
	if (core == nullptr) return "";
	return activity.GetAssets().GetSmallText();
}

//LARGE IMAGE FUNCTIONS
//---------------------
BLITZ3D(void) BlitzcordSetLargeImage(cstring image)
{
	if (core == nullptr) return;
	activity.GetAssets().SetLargeImage(image);
}

BLITZ3D(void) BlitzcordSetLargeText(cstring text)
{
	if (core == nullptr) return;
	activity.GetAssets().SetLargeText(text);
}

BLITZ3D(cstring) BlitzcordGetLargeImage()
{
	if (core == nullptr) return "";
	return activity.GetAssets().GetLargeImage();
}

BLITZ3D(cstring) BlitzcordGetLargeText()
{
	if (core == nullptr) return "";
	return activity.GetAssets().GetLargeText();
}

//TIMESTAMP FUNCTIONS
//-------------------
BLITZ3D(void) BlitzcordSetTimestampStart(cstring timestamp)
{
	if (core == nullptr) return;
	long long convertedLong = atoll(timestamp);

	activity.GetTimestamps().SetStart(convertedLong);
}

BLITZ3D(void) BlitzcordSetTimestampEnd(cstring timestamp)
{
	if (core == nullptr) return;
	long long convertedLong = atoll(timestamp);

	activity.GetTimestamps().SetEnd(convertedLong);
}

BLITZ3D(int) BlitzcordGetTimestampStartUpper()
{
	if (core == nullptr) return INT_MAX;
	return longUpper(activity.GetTimestamps().GetStart());
}

BLITZ3D(int) BlitzcordGetTimestampStartLower()
{
	if (core == nullptr) return INT_MAX;
	return longLower(activity.GetTimestamps().GetStart());
}

BLITZ3D(int) BlitzcordGetTimestampEndUpper()
{
	if (core == nullptr) return INT_MAX;
	return longUpper(activity.GetTimestamps().GetEnd());
}

BLITZ3D(int) BlitzcordGetTimestampEndLower()
{
	if (core == nullptr) return INT_MAX;
	return longLower(activity.GetTimestamps().GetEnd());
}

//UNIX TIMESTAMP FUNCTIONS
//------------------------
BLITZ3D(cstring) BlitzcordGetCurrentTimestamp()
{
	auto clockNow = std::chrono::system_clock::now();

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockNow.time_since_epoch()).count()).c_str());
}

BLITZ3D(cstring) BlitzcordGetTimestampPlus(int hours, int minutes, int seconds)
{
	auto clockNow = std::chrono::system_clock::now();
	auto clockAdded = clockNow + std::chrono::hours(hours) + std::chrono::minutes(minutes) + std::chrono::seconds(seconds);

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockAdded.time_since_epoch()).count()).c_str());
}

BLITZ3D(cstring) BlitzcordGetTimestampMinus(int hours, int minutes, int seconds)
{
	auto clockNow = std::chrono::system_clock::now();
	auto clockSubstracted = clockNow - std::chrono::hours(hours) - std::chrono::minutes(minutes) - std::chrono::seconds(seconds);

	return _strdup(std::to_string(std::chrono::duration_cast<std::chrono::seconds>(clockSubstracted.time_since_epoch()).count()).c_str());
}

//LONG SPLITTING
//--------------
BLITZ3D(int) StringToUpperLong(cstring stringLong)
{
	return longUpper(atoll(stringLong));
}

BLITZ3D(int) StringToLowerLong(cstring stringLong)
{
	return longLower(atoll(stringLong));
}

BLITZ3D(cstring) LongToString(int upperLong, int lowerLong)
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