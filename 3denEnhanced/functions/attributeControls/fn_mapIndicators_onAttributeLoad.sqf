/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the map indicators attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Array with booleans, attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_showFriendly","_showEnemy","_showMines","_showPing"];

(_ctrlGroup controlsGroupCtrl 100) cbSetChecked _showFriendly;
(_ctrlGroup controlsGroupCtrl 101) cbSetChecked _showEnemy;
(_ctrlGroup controlsGroupCtrl 102) cbSetChecked _showMines;
(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _showPing;
	
true