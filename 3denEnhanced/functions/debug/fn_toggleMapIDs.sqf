/*
    Author: R3vo

    Date: 2019-08-20

    Description:
    Opens the map and toggles the map IDs on/off.

    Parameter(s):
    -

    Returns:
    BOOLEAN: true
*/

if (get3DENActionState "toggleMap" == 0) then
{
    do3DENAction "toggleMap";
};

do3DENAction "ToggleMapIDs";

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

true