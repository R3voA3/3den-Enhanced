/*
   Author: R3vo

   Date: 2020-10-15

   Description:
   Exports all ENH and ENHO context menu actions in markdown format for the Github 3den Enhanced wiki to the clipboard.

   Parameter(s):
   -

   Returns:
   BOOLEAN: true
*/

private _contextMenuEntries = "configName _x select [0,3] == 'ENH'" configClasses (configFile >> "Display3DEN" >> "ContextMenu" >> "Items");

private _export = format ["_**Number of added entries: %1**_",count _contextMenuEntries] + endl + "___" + endl + endl + endl;

{
	private _text = getText (_x >> "text");
	private _action = getText (_x >> "action");
	private _conditionShow = getText (_x >> "conditionShow");
	_export = _export + "## " + _text + endl + "Action: " + "```" + _action + "```" + endl + endl +  "Condition Show: " + "```" + _conditionShow + "```" + endl;
} forEach _contextMenuEntries;

copyToClipboard _export;

true