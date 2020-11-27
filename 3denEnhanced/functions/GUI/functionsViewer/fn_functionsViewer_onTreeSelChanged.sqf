/*
  Author: Revo

  Description:
  Used by the ENH_FunctionViewer GUI. Called when selection of tv tree control has changed.

  Parameter(s):
  0: CONTROL - Tree Control
  1: ARRAY - Path

  Returns:
  BOOLEAN: true
*/

disableSerialization;

params ["_ctrlTV", "_path"];

private _disp = ctrlParent _ctrlTV;
private _ctrlCode = _disp displayCtrl 1401;
private _ctrlFncName = _disp displayCtrl 1402;
private _ctrlFncPath = _disp displayCtrl 1403;
private _ctrlLines = _disp displayCtrl 1404;
private _ctrlBiki = _disp displayCtrl 1900;
private _data = _ctrlTV tvData _path;
private _linesText = "";

if (_data isEqualTo "") exitWith {false};

_data = call compile _data;
_data params ["_fileName","_filePath"];//Filename is also Function name
systemChat _fileName;
profileNamespace setVariable ["ENH_FunctionsViewer_LastViewed",_filePath];

_ctrlFncName ctrlSetText _fileName;
_ctrlFncPath ctrlSetText _filePath;

_ctrlCode ctrlSetText (switch (profileNamespace getVariable 'ENH_FunctionsViewer_LoadFileIndex') do
{
  case 0: {loadFile _filePath};
  case 1: {preprocessFile _filePath};
  case 2: {preprocessFileLineNumbers _filePath};
});

_ctrlBIKI ctrlSetURL "https://community.bistudio.com/wiki/" + _fileName;
_ctrlBiki ctrlEnable (_fileName select [0,3] in ["BIS","BIN"]);

private _textHeight = (1.2 max (ctrlTextHeight _ctrlCode));
private _numLines = round (_textHeight / 0.0315);//0.0315 = Height of one line

//Get the number of lines that should be displayed
for "_i" from 1 to _numLines do
{
  _linesText = _linesText + format ["%1<br/>",_i];
};

//When new function is selected, change scroll width and height dynamically
_ctrlCode ctrlSetPositionH _textHeight;
_ctrlCode ctrlCommit 0;

_ctrlLines ctrlSetPositionH _textHeight;
_ctrlLines ctrlCommit 0;
_ctrlLines ctrlSetStructuredText parseText _linesText;

true