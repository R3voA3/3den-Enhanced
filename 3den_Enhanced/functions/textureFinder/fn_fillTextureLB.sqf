/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Fills the GUI with all found textures.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true / false
*/

private ["_disp","_ctrl"];

disableSerialization;

if (isNil "Enh_foundTextures") exitWith {false};

_disp = findDisplay 140000;
_ctrl = _disp displayCtrl 1500;

_tooltip = localize "STR_ENH_functions_fillTextureLB_tooltip";

lbClear _ctrl;
{
	_ctrl lbAdd _x;
	_ctrl lbSetPictureRight [_forEachIndex,_x];
	_ctrl lbSetTooltip [_forEachIndex,_tooltip];
} forEach Enh_foundTextures;

lbSort _ctrl;

true