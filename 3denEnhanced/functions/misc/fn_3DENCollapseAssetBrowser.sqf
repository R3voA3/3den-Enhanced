/*
   Author: R3vo

   Date: 2020-02-20

   Description:
   Called  onTerrainNew. Collapes all tree views of the asset browser

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _collapse = profileNamespace getVariable ["ENH_CollapseAssetBrowser",false];

if (!_collapse) exitWith {false};

private _display3DEN = findDisplay 313;
private _ctrlTV = controlNull;
private _tvIDCs =
[
	61,//Groups BLUFOR
	62,//Groups OPFOR
	63,//Groups INDFOR
	64,//Groups CIVFOR
	56,//Objects BLUFOR
	57,//Objects OPFOR
	58,//Objects INDFOR
	59 //Objects CIVFOR
];

private _fnc_collapse =
{
	private _path = _this;
	if (count _path > 0) then
	{
		_ctrlTree tvcollapse _path;
	};
	for "_i" from 0 to (_ctrlTree tvcount _path) do
	{
		(_path + [_i]) call _fnc_collapse;
	};
};

{
	private _ctrlTree = _display3DEN displayctrl _x;
	[] call _fnc_collapse;
} foreach _tvIDCs;