/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Exports path of selected lb entry by pressing CTRL + C.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true / false
*/

disableSerialization;

private _ctrl = param [0,controlNull,[controlNull]];
private _key = param [1,46,[1]];
private _mod = param [3,true,[true]];

if (_key isEqualTo 46 && _mod) then
{
	private _class = _ctrl lbText (lbCurSel _ctrl);
	if (_class isEqualTo "") exitWith {false};
	copyToClipboard str _class;
	["Enh_DataCopied"] call BIS_fnc_3DENNotification;
};

true
