/*
  Author: R3vo

  Date: 2020-10-15

  Description:
  Exports all ENH and ENHO functions in markdown format for the Github 3den Enhanced wiki wiki to the clipboard.

  Parameter(s):
  -

  Returns:
  BOOLEAN: true
*/

startLoadingScreen ["start"];

private _allENHFunctions = (call (uiNamespace getVariable ["BIS_functions_list",{[]}])) select {_x select [0,3] == "ENH"};
_allENHFunctions sort true;

private _export = format ["_**Number of added entries: %1**_",count _allENHFunctions] + endl + "___" + endl + endl + endl;

{
private _meta = _x call BIS_fnc_functionMeta;

private _file = loadFile (_meta select 0);
private _headerStart = _file find "/*";
private _headerEnd = _file find "*/";
private _headerLength = _headerEnd - _headerStart;
private _fileHeader = _file select [_headerStart + 2,_headerLength - 2];

if (_fileHeader == "" || _headerStart > 5) then {_fileHeader = "N/A"};

_export = _export + endl + "## " + _x + endl + "```"  + _fileHeader + "```";

} forEach _allENHFunctions;

copyToClipboard _export;

endLoadingScreen;

true