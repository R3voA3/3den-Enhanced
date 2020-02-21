/*
   Author: R3vo

   Date: 2020-02-11

   Description:
   Used by the ENH_VariableViewer GUI. Called when listNbox selection changed.

   Parameter(s):
   0: DISPLAY - ENH_VariableViewer GUI. Used to fill the listNBox with data.

   Returns:
   BOOLEAN: true
*/

params ["_display"];

private _ctrlLNB = _display displayCtrl 1000;
private _ctrlVariableCount = _display displayCtrl 3000;
private _ctrlProgress = _display displayCtrl 7000;
private _namespace = call ENH_fnc_variableViewer_getNamespace;
private _value = "";
private _varCount = count allVariables _namespace;
private _hideFunctions = profileNamespace getVariable ["ENH_VariableViewer_HideFunctions",false];

lbClear _ctrlLNB;

//Hide all vars of type "CODE" if filter enabled
private _allVariables = if (_hideFunctions) then
{
	allVariables _namespace select
	{
		typeName (_namespace getVariable _x) != "CODE"
	};
}
else
{
	allVariables _namespace;
};

{
	_value = _namespace getVariable _x;
	if !(isNil "_value") then
	{
		_ctrlLNB lnbAddRow 
		[
			_x,
			format ["%1",_value],
			typeName _value
		];
	};
	_ctrlProgress progressSetPosition linearConversion 
	[
		0,
		_varCount,
		_forEachIndex + 1,
		0,
		1
	];
} forEach _allVariables;//(if (_hideFunctions) then {allVariables _namespace select {typeName (_namespace getVariable _x) != "CODE")}} else {allVariables _namespace});//Hide all vars of type "CODE"

_ctrlLNB lnbSort [0,false];
_ctrlVariableCount ctrlSetText format ["#%1",_varCount];

true