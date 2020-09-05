/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hide terrain objects attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   BOOLEAN: true
*/

private _types = ["BUILDING","BUNKER","BUSH","BUSSTOP","CHAPEL","CHURCH","CROSS","FENCE","FOREST",
"FOREST BORDER","FOREST SQUARE","FOREST TRIANGLE","FORTRESS","FOUNTAIN","FUELSTATION","HIDE","HOSPITAL",
"HOUSE","LIGHTHOUSE","MAIN ROAD","POWER LINES","POWERSOLAR","POWERWAVE","POWERWIND","QUAY","RAILWAY","ROAD",
"ROCK","ROCKS","RUIN","SHIPWRECK","SMALL TREE","STACK","TOURISM",
"TRACK","TRAIL","TRANSMITTER","TREE","VIEW-TOWER","WALL","WATERTOWER"];

params ["_ctrlGroup","_value"];

private _ctrlLB  = _ctrlGroup controlsGroupCtrl 110;
private _selectedTypes = _value select 1;

(_ctrlGroup controlsGroupCtrl 100) lbSetCurSel (_value select 0);

{
	private _state = if (_x in _selectedTypes) then
	{
		["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa",1];
	}
	else
	{
		["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa",0];
	};

	_ctrlLB lbAdd _x;
	_ctrlLB lbSetPicture [_forEachIndex,_state select 0];
	_ctrlLB lbSetValue [_forEachIndex,_state select 1];
} foreach _types;

true