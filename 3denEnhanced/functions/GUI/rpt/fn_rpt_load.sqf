/*
     Author: R3vo

     Date: 2020-11-08

     Description:
     Used by the ENH_RPT GUI. Used to load all RPT entries. Needs other mod

     Parameter(s):
     0: DISPLAY - ENH_RPT
     1: STRING - Mode, can be "onLoad" and "reload"

     Returns:
     -
*/

#define CTRL_GROUP_WIDTH (200 * pixelW * pixelGrid * 0.50)
#define CTRL_GROUP_HEIGHT (99 * pixelH * pixelGrid * 0.50)
#define SIZEEX 4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5

disableSerialization;

params ["_display","_mode"];

if (_display isEqualType controlNull) then {_display = ctrlparent _display};

private _ctrlEditLines = _display displayCtrl 200;
private _wantedLines = switch (_mode) do
{
     case "onLoad":
     {
          private _return = profileNamespace getVariable ["ENH_ShowRPT_LinesCount",100];
          _ctrlEditLines ctrlSetText str _return;
          _return
     };
     case "reload":
     {
          parseNumber ctrlText _ctrlEditLines;
     };
};

[_wantedLines, _display, _ctrlEditLines] spawn
{
     if !(isNil "ENH_ShowRPT_Loading") exitWith {};//Prevent the user from starting cycle multiple times
     ENH_ShowRPT_Loading = true;
     params ["_wantedLines", "_display", "_ctrlEditLines"];

     private _ctrlProgress = _display displayCtrl 300;
     private _ctrlEdit = _display displayCtrl 100;
     _ctrlEdit ctrlSetText "Please wait..."; //Performance is better if text control is almost empty

     private _content = "";

     private _linesCount = ["count_rpt_lines",[]] call TER_fnc_pyTerEden;
     _wantedLines = _wantedLines min _linesCount;
     private _firstLine = _linesCount - _wantedLines;
     _ctrlEditLines ctrlSetText str _wantedLines;

     private _longestLine = 0;

     if (_linesCount isEqualTo []) exitWith {systemChat ".rpt is empty"};

     for "_line" from _firstLine to _linesCount do
     {
          private _lineText = (["load_rpt_line",[_line]] call TER_fnc_pyTerEden);
          _longestLine = _longestLine max  (_lineText getTextWidth ["RobotoCondensedLight",SIZEEX]);
          _ctrlProgress progressSetPosition ((_line - _firstLine) / _linesCount); //Give the user an indication how many lines he is viewing from the total available ones
          _content = _content + endl + (["load_rpt_line",[_line]] call TER_fnc_pyTerEden);
     };

     profileNamespace setVariable ["ENH_ShowRPT_LinesCount",_wantedLines];

     //Change width before adding text. It seems to only work this way. Wait until width is set
     _ctrlEdit ctrlSetPositionW (_longestLine max CTRL_GROUP_WIDTH); //Longest line and not smaller then ctrlGroup width
     _ctrlEdit ctrlCommit 0;
     waitUntil {ctrlCommitted _ctrlEdit};

     _ctrlEdit ctrlSetText _content;
     _ctrlEdit ctrlSetPositionH (ctrlTextHeight _ctrlEdit max CTRL_GROUP_HEIGHT);
     _ctrlEdit ctrlCommit 0;

     ENH_ShowRPT_Loading = nil;
};