/*
    Author: R3vo

    Date: 2023-06-01

    Description:
    Opens all ENH displays to check for missing ;, translations or UI sizes.

    Parameter(s):
    -

    Returns:
    -
*/

#include "\x\enh\addons\main\script_component.hpp"

if (!is3DEN) exitWith {};

ENH_Displays = "'ENH_' in configName _x && getNumber (_x >> 'IDD') != 0" configClasses configFile apply {configName _x};
ENH_Displays_Index = 0;

findDisplay IDD_DISPLAY3DEN displayAddEventHandler ["KeyDown",
{
    params ["", "_key"];

    if (_key in [DIK_LEFT, DIK_RIGHT]) then
    {
        ENH_Displays_Index = ENH_Displays_Index + ([1, -1] select (_key == DIK_LEFT));
        ENH_Displays_Index = ENH_Displays_Index max 0 min (count ENH_Displays - 1);

        if !(isNull (uiNamespace getVariable ["ENH_Displays_Current", displayNull])) then
        {
            ENH_Displays_Current closeDisplay 1;
            uiNamespace setVariable ["ENH_Displays_Current", displayNull];
        };

        private _nextDisplay = ENH_Displays#ENH_Displays_Index;

        uiNamespace setVariable ["ENH_Displays_Current", findDisplay IDD_DISPLAY3DEN createDisplay _nextDisplay];
        systemChat format ["Display: %1 (%2/%3)", _nextDisplay, ENH_Displays_Index + 1, count ENH_Displays];
    };
}];