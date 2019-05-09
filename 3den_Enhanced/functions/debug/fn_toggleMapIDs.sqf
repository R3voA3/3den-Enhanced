/*
	Author: Revo

	Description:
	Opens the map and toggles the map IDs on/off.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true
*/

if (get3DENActionState "toggleMap" == 0) then
{
	do3DENAction "toggleMap";
};

do3DENAction "ToggleMapIDs";

true