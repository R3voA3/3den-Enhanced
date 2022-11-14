#define COLOR_ATTRIBUTE [7/255, 113/255, 135/255, 1]
#define COLOR_ENTITY [228/255, 197/255, 175/255, 1]
#define COLOR_VALUE [158/255, 206/255, 154/255, 1]

if (!is3DEN) exitWith {};

disableSerialization;

params ["_display"];

private _ctrlTV = _display displayCtrl 11;
uiNamespace setVariable ["ENH_AttributeSearch_Display", _display];

all3DENEntities params ["_objects", "_groups", "_triggers", "_systems",  "_waypoints"];

// Allow users to add own attributes
private _attributes = profileNamespace getVariable
[
  "ENH_AttributeSearch",
  [
    ["init", [""]],
    ["presenceCondition", ["true"]],
    ["condition", ["this", "true"]],
    ["onActivation", [""]],
    ["onDeactivation", [""]],
    ["name", [""]],
    ["effectCondition", ["true"]]
  ]
];

{
	_ctrlTV tvAdd [[], toUpper (_x#0)];
	_ctrlTV tvSetColor [[_forEachIndex], COLOR_ATTRIBUTE];
	systemChat str (_x#0);
} forEach _attributes;

ENH_AttributeSearch_AttributesCounter_Total = 0;
ENH_AttributeSearch_AttributesCounter_Valid = 0;

// Fill tree view
{
	ENH_AttributeSearch_TempIndex = 0;
	private _entity = _x;
	{
		_x params ["_attributeName", "_ignoredValues"];

		_ignoredValues = _ignoredValues + [""];
		private _attributeValue = _entity get3DENAttribute _attributeName select 0;

		if (!isNil "_attributeValue" && {!(_attributeValue in _ignoredValues)}) then
		{
			private _varName = _entity get3DENAttribute "name" select 0;
			private _entityIndex = if (_varName != "") then
			{
				_ctrlTV tvAdd [[ENH_AttributeSearch_TempIndex], str _entity + toString [9] + " (" + _varName + ")"];
			}
			else
			{
				_ctrlTV tvAdd [[ENH_AttributeSearch_TempIndex], str _entity];
			};

			_ctrlTV tvSetColor [[ENH_AttributeSearch_TempIndex, _entityIndex], COLOR_ENTITY];
			_ctrlTV tvSetValue [[ENH_AttributeSearch_TempIndex, _entityIndex], get3DENEntityID _entity];

			private _valueTextIndex = _ctrlTV tvAdd [[ENH_AttributeSearch_TempIndex, _entityINdex], _attributeValue];
			_ctrlTV tvSetColor [[ENH_AttributeSearch_TempIndex, _entityIndex, _valueTextIndex], COLOR_VALUE];
			_ctrlTV tvSetTooltip [[ENH_AttributeSearch_TempIndex, _entityIndex, _valueTextIndex], _attributeValue];
			ENH_AttributeSearch_AttributesCounter_Valid = ENH_AttributeSearch_AttributesCounter_Valid + 1;
		};

		ENH_AttributeSearch_TempIndex = ENH_AttributeSearch_TempIndex + 1;
		ENH_AttributeSearch_AttributesCounter_Total = ENH_AttributeSearch_AttributesCounter_Total + 1;
	} forEach _attributes;
} forEach (_objects + _groups + _systems + _triggers + _waypoints);

ENH_AttributeSearch_TempIndex = nil;

// Remove empty nodes
for "_index" from ((count _attributes) - 1) to 0 step -1 do
{
	if (_ctrlTV tvCount [_index] == 0) then {_ctrlTV tvDelete [_index]};
};

// Update counter
_display displayCtrl 12 ctrlSetText format ["%1/%2", ENH_AttributeSearch_AttributesCounter_Valid, ENH_AttributeSearch_AttributesCounter_Total];

// Set button text
_display displayCtrl 13 ctrlEnable false;
_display displayCtrl 13 ctrlSetText format ["%1..", localize "STR_3DEN_Display3DEN_MenuBar_Attributes_text"];



_ctrlTV ctrlAddEventHandler ["TreeSelChanged",
{
	params ["_ctrlTV", "_selectionPath"];

	// Disable Edit Attributes button
	if (count _selectionPath < 3) exitWith
	{
		ctrlParent _ctrlTV displayCtrl 13 ctrlEnable false;

		// Move camera
		if (count _selectionPath == 2) exitWith
		{
			private _id = (_ctrlTV tvValue _selectionPath);
			private _entity = get3DENEntity _id;

			move3DENCamera
			[
				ATLToASL (_entity get3DENAttribute "position" select 0),
				true
			];
		};
	};

	// Enable Edit Attributes button
	if (count _selectionPath == 3) exitWith
	{
		ctrlParent _ctrlTV displayCtrl 13 ctrlEnable true;
	};
}];

ENH_fnc_attributeSearch_editAttributes =
{
	params ["_ctrlTV", "_selectionPath"];

	if (count _selectionPath != 3) exitWith {};

	// Get ID of parent item
	_selectionPath resize 2;
	private _id = (_ctrlTV tvValue _selectionPath);
	set3DENSelected [_id];

	[] spawn
	{
		(uiNamespace getVariable ["ENH_AttributeSearch_Display", displayNull]) closeDisplay 1;
		waitUntil {isNull (uiNamespace getVariable ["ENH_AttributeSearch_Display", displayNull])};
		do3DENAction "OpenAttributes";

		// Wait until Edit Attributes display is present
		waitUntil {!isNull findDisplay 315};

		// Wait until Edit Attributes display is destroyed
		waitUntil {isNull findDisplay 315};

		// Create attribute search display again
		findDisplay 313 createDisplay "ENH_AttributeSearch";
	};
};

_ctrlTV ctrlAddEventHandler ["TreeDblClick",
{
	_this call ENH_fnc_attributeSearch_editAttributes;
}];

(ctrlParent _ctrlTV displayCtrl 13) ctrlAddEventHandler ["ButtonClick",
{
	private _ctrlTV = ctrlParent (_this#0) displayCtrl 11;
	[_ctrlTV, tvCurSel _ctrlTV] call ENH_fnc_attributeSearch_editAttributes;
}];