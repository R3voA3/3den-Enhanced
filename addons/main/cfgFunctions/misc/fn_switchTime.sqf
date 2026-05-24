#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Switches time quickly to 12 o'clock and sets fog, overcast and rain to 0 for easier editing. Calling the function again, will reset the time to the original one.

    Parameter(s):
    -

    Returns:
    BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

if (isNil "ENH_savedEnvironment") then
{
    ENH_savedEnvironment = [dayTime, fog, overcast, rain];
    0 setFog 0;
    0 setOvercast 0;
    0 setRain 0;
    forceWeatherChange;
    skipTime (12 - dayTime);
}
else
{
    ENH_savedEnvironment params ["_dayTime", "_fog", "_overcast", "_rain"];
    0 setFog _fog;
    0 setOvercast _overcast;
    0 setRain _rain;
    forceWeatherChange;
    skipTime (_dayTime - dayTime);
    ENH_savedEnvironment = nil;
};

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true
