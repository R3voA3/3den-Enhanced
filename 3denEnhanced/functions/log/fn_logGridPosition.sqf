/*
	Author: Revo

	Description:
	Logs grid position to clipboard.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

private _posClick = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;

copyToClipboard (mapGridPosition _posClick);
["Enh_DataCopied"] call BIS_fnc_3DENNotification;

true