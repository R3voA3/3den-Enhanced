/*
   Author: R3vo

   Date: 2020-02-20

   Description:
   Called  onTerrainNew. Removes blacklisted factions from asset browser.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true / false
*/

private _blacklist = profileNamespace getVariable ["ENH_BlacklistedAssets",[]];

if (_blacklist isEqualTo []) exitWith {false};

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

{
	_ctrlTV = _display3DEN displayCtrl _x;
	for "_i" from ((_ctrlTV tvCount []) - 1) to 0 step -1 do
	{
		if ((_ctrlTV tvData [_i]) in _blacklist) then
		{
			_ctrlTV tvDelete [_i];
		};
	};
} forEach _tvIDCs;

true