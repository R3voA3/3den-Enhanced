/*
	Author: Revo

	Description:
	Used by the ENH_TexturFinder GUI. Exports path of selected lb entry by pressing CTRL + C.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

params ["_ctrlLB","_key","","_ctrl"];

if (_key isEqualTo 46 && _ctrl) then
{
	private _path = _ctrlLB lbText (lbCurSel _ctrlLB);
	if (_path isEqualTo "") exitWith {false};
	copyToClipboard str _path;
	["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};

true