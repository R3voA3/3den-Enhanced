/*
	Author: Revo

	Description:
	Switches time quickly to 12 o'clock and sets fog, overcast and rain to 0 for easier editing. Calling the function again, will reset the time to the original one.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

if (isNil "Enh_savedEnvironment") then
{
	Enh_savedEnvironment = [daytime,fog,overcast,rain];
	0 setFog 0;
	0 setOvercast 0;
	0 setRain 0;
	forceWeatherChange;
	skipTime (12 - daytime);
}
else
{
	Enh_savedEnvironment params ["_daytime","_fog","_overcast","_rain"];
	0 setFog _fog;
	0 setOvercast _overcast;
	0 setRain _rain;
	forceWeatherChange;
	skipTime (_daytime - daytime);
	Enh_savedEnvironment = nil;
};

["Enh_actionPerformed"] call BIS_fnc_3DENNotification;

true