/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Exports path of selected lb entry by pressing CTRL + C.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

params ["_ctrl","_key","_mod"];

if (_key isEqualTo 46 && _mod) then
{
	private _path = _ctrl lbText (lbCurSel _ctrl);
	if (_path isEqualTo "") exitWith {false};
	copyToClipboard str _path;
	["Enh_DataCopied"] call BIS_fnc_3DENNotification;
};

true