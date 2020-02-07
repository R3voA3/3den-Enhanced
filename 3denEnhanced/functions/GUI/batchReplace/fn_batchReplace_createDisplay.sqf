/*
   Author: R3vo

   Date: 2019-07-30

   Description:
   Creates the ENH_BatchReplace GUI if objects are selected, if not it shows an error message.

   Parameter(s):
   0: DISPLAY - Display

   Returns:
   BOOLEAN: true / false
*/

if !(is3DEN) exitWith {false};

if ((get3DENSelected "Object") isEqualTo []) exitWith 
{
	["ENH_NoEntitiesSelected"] call BIS_fnc_3DENNotification; 
	false
};

findDisplay 313 createDisplay "ENH_BatchReplace";

true