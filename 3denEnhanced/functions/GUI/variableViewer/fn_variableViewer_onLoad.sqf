/*
   Author: R3vo

   Date: 2020-02-11

   Description:
   Used by the ENH_VariableViewer GUI. Called on load.

   Parameter(s):
   0: Display - ENH_VariableViewer GUI

   Returns:
   BOOLEAN: true
*/

params ["_display"];

private _ctrlNamespace = _display displayCtrl 4000;
private _ctrlCheckbox = _display displayCtrl 9000;

_ctrlCheckbox cbSetChecked (profileNamespace getVariable ["ENH_VariableViewer_HideFunctions",false]);

//CTRL + F to focus search
_display displayAddEventHandler ["keyDown",//Focus Search
{
	params ["_display", "_key", "_shift", "_ctrl"];
	if (_key isEqualTo 33 && _ctrl) then
	{
		ctrlSetFocus (_display displayCtrl 2000);
	}
}];

//Get all locations
private _worldSizeHalfe = worldSize / 2;
ENH_VariableViewer_AllLocationTypes = [];
"ENH_VariableViewer_AllLocationTypes pushBack configName _x" configClasses (configFile >> "CfgLocationTypes");
private _allLocations = [];
{
	_allLocations pushBack _x;
} forEach nearestLocations [[_worldSizeHalfe,_worldSizeHalfe,0],ENH_VariableViewer_AllLocationTypes,_worldSizeHalfe * sqrt 2];

//Sort units, vehicles, groups and locations first, then add special namespaces so that they are at the beginning of the combo box
private _namespaces = allUnits + vehicles + allGroups + _allLocations;
_namespaces sort true;
_namespaces = ["missionNamespace","profileNamespace","parsingNamespace","uiNamespace","player","cursorTarget"] + _namespaces;

uiNamespace setVariable ["ENH_VariableViewer_Namespaces",_namespaces];

//We add special namespaces first, otherwise they are all named NAMESPACE
private _lastNamespace = uiNamespace getVariable ["ENH_VariableViewer_LastNamespace","missionNamespace"];
private _icon = "";
{
	if (_x isEqualType "") then
	{
		_ctrlNamespace lbAdd _x;
	}
	else
	{
		_ctrlNamespace lbAdd str _x;
	};
	if (_x isEqualTo _lastNamespace) then
	{
		_ctrlNamespace lbSetCurSel _forEachIndex;
	};
	switch (typeName _x) do
	{
		case "OBJECT":
		{
			_icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeObjects_ca.paa";
		};
		case "GROUP":
		{
			_icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelRight\modeGroups_ca.paa";
		};
		case "LOCATION":
		{
			_icon = "\a3\3DEN\Data\Displays\Display3DEN\PanelLeft\locationList_ca.paa";
		};
		case "STRING":
		{
			_icon = "\a3\Modules_F_Curator\Data\portraitLightning_ca.paa";
		};
	};
	_ctrlNamespace lbSetPicture [_forEachIndex,_icon];
} forEach _namespaces;

//Fill ListNbox
_display call ENH_fnc_variableViewer_fillLNB;

true