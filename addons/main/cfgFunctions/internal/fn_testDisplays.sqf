#include "\x\enh\addons\main\script_component.hpp"

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

if (!is3DEN) exitWith {};

spawn
{
    with uiNamespace do
    {
        private _displaysClasses = "'ENH_' in configName _x && getNumber (_x >> 'IDD') != 0" configClasses configFile apply {configName _x};

        {
            private _displayClass = _x;
            private _display = findDisplay IDD_DISPLAY3DEN createDisplay _displayClass;

            waitUntil {!isNull _display};

            diag_log "#############################################################";
            diag_log "#############################################################";
            diag_log format ["Display %1 is currently being tested.", _displayClass];
            diag_log "#############################################################";
            diag_log "#############################################################";

            sleep 1;

            if !(isNull _display) then
            {
                _display closeDisplay 1;
            };
        } forEach _displaysClasses;
    };
};
