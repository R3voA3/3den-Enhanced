/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the mission ending attribute. Called when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Array with booleans, attribute value

   Returns:
   BOOLEAN: true
*/

params ["_ctrlGroup","_value"];
_value params ["_threshold","_debriefing","_isWin","_side"];

[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,""] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 100,_ctrlGroup controlsGroupCtrl 101,"",_threshold] call BIS_fnc_initSliderValue;

#define DEBRIEFING_CLASSES (("isClass _x" configClasses (configFile >> "CfgDebriefing")) + ("isClass _x" configClasses (missionConfigFile >> "CfgDebriefing")))

private _ctrlDebriefings = _ctrlGroup controlsGroupCtrl 102;
{
	private _title = getText (_x >> "title");
	private _subtitle = getText (_x >> "subtitle");
	private _description = getText (_x >> "description");
	private _configName = toLower configName _x;//We make everything lower case, just to be sure (Is BIS_fnc_endMission case sensitiv?)

	_ctrlDebriefings lbAdd _configName;
	_ctrlDebriefings lbSetTooltip 
	[
		_forEachIndex,
		 format ["Title: %1\nSubtitle: %2\nDescription: %3",_title,_subtitle,_description]
	];
	if (_configName isEqualTo _debriefing) then
	{
		_ctrlDebriefings lbSetCurSel _forEachIndex;
	};
} forEach DEBRIEFING_CLASSES;

(_ctrlGroup controlsGroupCtrl 103) cbSetChecked _isWin;
(_ctrlGroup controlsGroupCtrl 104) lbSetCurSel ([west,east,independent,civilian] find _side);

true