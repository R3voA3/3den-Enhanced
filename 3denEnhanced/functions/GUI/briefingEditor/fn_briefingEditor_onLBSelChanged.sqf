/*
   Author: R3vo

   Date: 2019-06-20

   Description:
   Used by Enh_BriefingEditor GUI. Triggers when HTML tag combo selection has changed.

   Parameter(s):
   0: CONTROL - Combo box control
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/

disableSerialization;

params ["_ctrlCombo","_selectedIndex"];

private _display = ctrlParent _ctrlCombo;

private _ctrlFirstParam = _display displayCtrl 200;
private _ctrlFirstParamValue = _display displayCtrl 210;
private _ctrlSecondParam = _display displayCtrl 220;
private _ctrlSecondParamValue = _display displayCtrl 230;
private _ctrlThirdParam = _display displayCtrl 240;
private _ctrlThirdParamValue = _display displayCtrl 250;
private _ctrlLBColours = _display displayCtrl 100;
private _ctrlLBFonts = _display displayCtrl 70;
private _ctrlLBMarkers = _display displayCtrl 60;

private _fnc_setupCtrls =
{
	params [["_states",[true,true,true]],["_texts",["","",""]],["_lbStates",[false,false,false]]];
	{
		_x ctrlEnable (_states # _forEachIndex);
	} forEach [_ctrlFirstParamValue,_ctrlSecondParamValue,_ctrlThirdParamValue];
	{
		_x ctrlSetText ((_texts # _forEachIndex) call BIS_fnc_localize);//To be replaced with localize command later
	} forEach [_ctrlFirstParam,_ctrlSecondParam,_ctrlThirdParam];
	{
		_x ctrlEnable (_lbStates # _forEachIndex);
	} forEach [_ctrlLBColours,_ctrlLBFonts,_ctrlLBMarkers];
};

switch (_selectedIndex) do 
{
	case 0:
	{ 
		[[false,false,false],["","",""]] call _fnc_setupCtrls;
	};
	case 1:
	{ 
		[[true,false,false],["STR_ENH_briefingEditor_text","",""],[false,false,true]] call _fnc_setupCtrls;
	};
	case 2:
	{ 
		[[true,true,true],["STR_ENH_briefingEditor_path","STR_ENH_briefingEditor_width","STR_ENH_briefingEditor_height"]] call _fnc_setupCtrls;
	};
	case 3:
	{
		[[true,true,false],["STR_ENH_briefingEditor_size","STR_ENH_briefingEditor_text",""],[true,true,false]] call _fnc_setupCtrls;
	};
	case 4;
	case 5:
	{
		[[true,true,false],["STR_ENH_briefingEditor_expression","STR_ENH_briefingEditor_text",""]] call _fnc_setupCtrls;
	};
};

true