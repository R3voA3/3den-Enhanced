/*
   Author: Revo

   Description:
   Used by the ENH_FunctionViewer GUI. Called on load.

   Parameter(s):
   0: DISPLAY - Display

   Returns:
   BOOLEAN: true
*/

disableSerialization;

params ["_display"];

private _ctrlTV = _display displayCtrl 1500;

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

_display displayCtrl 1900 ctrlEnable false;

//Disable recompile buttons if recompiling isn't allowed
if (getNumber (missionConfigfile >> "allowFunctionsRecompile") == 0) then
{
	(_display displayCtrl 1600) ctrlEnable false;
	(_display displayCtrl 1601) ctrlEnable false;
};

_display displayAddEventHandler ["keyDown",//Focus Search
{
	params ["_display", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 33 && _ctrl) then
	{
		ctrlSetFocus (_display displayCtrl 1400);
	}
}];

_display displayAddEventHandler ["keyDown",//Copy
{
	params ["_display", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 45 && _ctrl) then
	{
		(_display displayCtrl 1602) call ENH_fnc_functionsViewer_copy;
	}
}];

//Set number of functions
(_display displayCtrl 1405) ctrlSetText str count ENH_FunctionsData;

//Set filters to last used or default value
(_display displayCtrl 1700) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex",0]);
(_display displayCtrl 1800) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex",0]);

//Set up tree view
_ctrlTV call ENH_fnc_FunctionsViewer_fillCtrlTV;

true