params ['_display'];

if !(is3DEN) exitWith {false};

if (([["Object","Logic","Trigger","Marker"]] call Enh_fnc_all3DENSelected) isEqualTo []) exitWith 
{
	["Enh_NoEntitiesSelected"] call BIS_fnc_3DENNotification; 
	_display closeDisplay 1; 
	false
};

private _ctrlVarName = _display displayCtrl 1000;
_ctrlVarName ctrlSetText (profileNamespace getVariable ['Enh_NameObjects_LastVarName',profileName]);

true