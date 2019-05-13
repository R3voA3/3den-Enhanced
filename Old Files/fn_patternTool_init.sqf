/*
   Author: Revo

   Description:
   Opens the GUI "Enh_PatternTools" and sets up all control values properly.

   Parameter(s):
   STRING: patternType ("line","circular","fillArea")

   Returns:
   BOOLEAN - true
*/

#define GET_CTRL(IDC) (_disp displayCtrl IDC)
#define GET_PROF_VAR(NAME,DEF_VALUE) (profileNamespace getVariable [NAME,DEF_VALUE])

if(!is3DEN) exitWith {false};

disableSerialization;
_disp = (findDisplay 313) createDisplay 'Enh_PatternTool';

_ctrlRad = GET_CTRL(1404);
_ctrlSpace = GET_CTRL(1403);
_ctrlA = GET_CTRL(1400);
_ctrlB = GET_CTRL(1401);
_ctrlNum = GET_CTRL(1402);
Enh_pattern_type = param [0,"line",[""]];

_ctrlA ctrlSetText GET_PROF_VAR('Enh_patternTool_a','150');
_ctrlB ctrlSetText GET_PROF_VAR('Enh_patternTool_a','150');
_ctrlNum ctrlSetText GET_PROF_VAR('Enh_patternTool_count','10');
_ctrlSpace ctrlSetText GET_PROF_VAR('Enh_patternTool_spacing','3');
_ctrlRad ctrlSetText GET_PROF_VAR('Enh_patternTool_radius','3');

switch (Enh_pattern_type) do
{
	case "line":
	{
		{
			_x ctrlEnable false;
			_x ctrlSetFade 0.5;
			_x ctrlCommit 0;
		} forEach [_ctrlRad,_ctrlA,_ctrlB,_ctrlNum];
		ctrlSetFocus _ctrlSpace;
	};
	case "circular":
	{
		{
			_x ctrlEnable false;
			_x ctrlSetFade 0.5;
			_x ctrlCommit 0;
		} forEach [_ctrlSpace,_ctrlA,_ctrlB,_ctrlNum];
		ctrlSetFocus _ctrlRad;
	};
	case "fillArea":
	{
		{
			_x ctrlEnable false;
			_x ctrlSetFade 0.5;
			_x ctrlCommit 0;
		} forEach [_ctrlRad,_ctrlSpace];
		ctrlSetFocus _ctrlA;
	};
};

true