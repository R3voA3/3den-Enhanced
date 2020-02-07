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

params ["_disp"];

private _ctrlTV = _disp displayCtrl 1500;

ENH_FunctionsData = call ENH_fnc_functionsViewer_getFunctionsData;

if (round (ctrlfade (findDisplay 313 displayctrl 1023)) < 1) then
{
	"showinterface" call BIS_fnc_3DENInterface
};

//Disable recompile buttons if recompiling isn't allowed
if (getNumber (missionConfigfile >> "allowFunctionsRecompile") == 0) then
{
	(_disp displayCtrl 1600) ctrlEnable false;
	(_disp displayCtrl 1601) ctrlEnable false;
};

_disp displayAddEventHandler ["keyDown",//Focus Search
{
	params ["_disp", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 33 && _ctrl) then
	{
		ctrlSetFocus (_disp displayCtrl 1400);
	}
}];

_disp displayAddEventHandler ["keyDown",//Copy
{
	params ["_disp", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 45 && _ctrl) then
	{
		call ENH_fnc_functionsViewer_copy;
	}
}];

//Set number of functions
(_disp displayCtrl 1405) ctrlSetText str count ENH_FunctionsData;

//Set filters to last used or default value
(_disp displayCtrl 1700) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex",0]);
(_disp displayCtrl 1800) lbSetCurSel (profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex",0]);

//Set up tree view
_ctrlTV call ENH_fnc_FunctionsViewer_fillCtrlTV;

true