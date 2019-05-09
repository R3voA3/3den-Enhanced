/*
   Author: Revo

   Description:
   Updates the Colour Picker GUI (Enh_colourPicker.hpp)

   Parameter(s):
   -
   Returns:
   BOOLEAN - true
*/

private _input = param [0,"",[""]];

disableSerialization;

private _display = findDisplay 110000;
private _redCtrl = _display displayCtrl 1400;
private _greenCtrl = _display displayCtrl 1401;
private _blueCtrl = _display displayCtrl 1402;
private _alphaCtrl = _display displayCtrl 1403;
private _finColourCtrl = _display displayCtrl 1200;

private _r = ctrlText _redCtrl;
private _g = ctrlText _greenCtrl;
private _b = ctrlText _blueCtrl;
private _a = ctrlText _alphaCtrl;

if (_input isEqualTo "export") exitWith
{
	copyToClipboard (str [_r,_g,_b,_a] + "//RGBA");
	["Enh_DataCopied"] call BIS_fnc_3DENNotification;
	true
};

_finColourCtrl ctrlSetText format ["#(argb,8,8,3)color(%1,%2,%3,%4)",_r,_g,_b,_a];

true

