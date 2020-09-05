/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hide terrain objects attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

private _types = ["BUILDING","BUNKER","BUSH","BUSSTOP","CHAPEL","CHURCH","CROSS","FENCE","FOREST",
"FOREST BORDER","FOREST SQUARE","FOREST TRIANGLE","FORTRESS","FOUNTAIN","FUELSTATION","HIDE","HOSPITAL",
"HOUSE","LIGHTHOUSE","MAIN ROAD","POWER LINES","POWERSOLAR","POWERWAVE","POWERWIND","QUAY","RAILWAY","ROAD",
"ROCK","ROCKS","RUIN","SHIPWRECK","SMALL TREE","STACK","TOURISM",
"TRACK","TRAIL","TRANSMITTER","TREE","VIEW-TOWER","WALL","WATERTOWER"];

private _ctrlLB = _ctrlGroup controlsGroupCtrl 110;
private _selectedTypes = [];

for "_i" from 0 to lbSize _ctrlLB -1 do
{
	if (_ctrlLB lbValue _i > 0) then
	{
		_selectedTypes pushBack (_types select _i);
	};
};

[lbCurSel (_ctrlGroup controlsGroupCtrl 100),_selectedTypes]