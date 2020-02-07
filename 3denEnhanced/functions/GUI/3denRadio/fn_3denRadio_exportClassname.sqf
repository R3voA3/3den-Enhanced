/*
	Author: Revo

	Description:
	Exports classname of selected song and copies it to the clipboard.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

disableSerialization;

private _ctrl = param [0,controlNull,[controlNull]];
private _key = param [1,46,[1]];
private _mod = param [3,true,[true]];

if (_key isEqualTo 46 && _mod) then //CTRL + C
{
	private _class = _ctrl lnbData [lnbCurSelRow _ctrl,0];
	if (_class isEqualTo "") then
	{
		_class = _ctrl lbData (lbCurSel _ctrl);
	};
	copyToClipboard str _class;
	["ENH_DataCopied"] call BIS_fnc_3DENNotification;
};

true