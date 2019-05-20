/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Searches the config file for useable textures.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

#define IS_PAA ((_string find ".paa") > -1)
#define IS_JPG ((_string find ".jpg") > -1)
#define NOT_ALLOWED ((_string find "<img image=" > -1)) //Wrong format

private ["_string","_toSearch","_disp","_ctrlProg","_ctrlProgText","_fnc_findTextures","_class","_classes"];
disableSerialization;

Enh_foundTextures = [];
_toSearch = [];


_disp = findDisplay 140000;
_ctrlProg = _disp displayCtrl 1001;
_ctrlProgText = _disp displayCtrl 1002;

_fnc_findTextures =
{
	params ["_class"];
	{
		_string = getText _x;
		if (IS_PAA || IS_JPG) then {Enh_foundTextures pushBackUnique _string};
		true
	} count configProperties [_class];
};

{
	_classes = ("true" configClasses _x);
	for "_i" from 0 to (count _classes -1) do
	{
		_toSearch pushBack (_classes # _i);
	};
	true
} count ("true" configClasses configFile);

Enh_numToSearch = count _toSearch;
{
	Enh_numSearched = _forEachIndex + 1;
	_x call _fnc_findTextures;
} forEach _toSearch;

true