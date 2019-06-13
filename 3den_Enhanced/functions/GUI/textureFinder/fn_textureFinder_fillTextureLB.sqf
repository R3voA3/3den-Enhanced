/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Fills the GUI with all found textures.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

private ["_disp","_ctrl","_fnc_addToList"];

disableSerialization;

if (isNil "Enh_TextureFinder_Textures") exitWith {false};

_disp = findDisplay 140000;
_ctrl = _disp displayCtrl 1500;

_fnc_addToList = 
{
	params ["_texturePath"];
	private _index = _ctrl lbAdd _texturePath;
	_ctrl lbSetPictureRight [_index,_texturePath];
	_ctrl lbSetTooltip [_index,localize "STR_ENH_functions_fillTextureLB_tooltip"];
};

lbClear _ctrl;
{
	switch (Enh_TextureFinder_Filter) do 
	{
		case 0://No filter applied, add every texture
		{
			[_x] call _fnc_addToList;
		};
		case 1://Do nothing if JPG is in the texture path and filter is set to hide JPG
		{
			if !(_x find "jpg" > -1) then 
			{
				[_x] call _fnc_addToList;
			};
		};
		case 2://Do nothing if PAA is in the texture path and filter is set to hide PAA
		{
			if !(_x find "paa" > -1) then 
			{
				[_x] call _fnc_addToList;
			};
		};
	};
} forEach Enh_TextureFinder_Textures;

lbSort _ctrl;

true