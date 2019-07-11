/*
   Author: Revo

   Description:
   Used by the Enh_FunctionViewer GUI. Called when selection of tv tree control has changed.

   Parameter(s):
   0: CONTROL - Tree Control
   1: ARRAY - Path

   Returns:
   BOOLEAN: true
*/

params ["_ctrlTV", "_path"];

if (count _path < 4) exitWith {false};

private _disp = ctrlParent _ctrlTV;
private _ctrlCode = _disp displayCtrl 1401;
private _ctrlFncName = _disp displayCtrl 1402;
private _ctrlFncPath = _disp displayCtrl 1403;
private _ctrlLines = _disp displayCtrl 1404;
private _data = _ctrlTV tvData _path;

private _fncName = (_data splitString "%") # 0;
private _fncPath = (_data splitString "%") # 1;

_ctrlFncName ctrlSetText _fncName;
_ctrlFncPath ctrlSetText _fncPath;
_ctrlCode ctrlSetText loadFile _fncPath;

private _textHeight = (1.2 max (ctrlTextHeight _ctrlCode));
private _numLines = round (_textHeight / 0.0315);//0.0315 = Height of one line
_linesText = "";

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

//profileNamespace setVariable ["Enh_FunctionsViewer_LastViewed",_path]; Doesn't work when search was used
//systemChat format ["Path: %1",_path];

true