/*
   Author: R3vo

   Date: 2020-10-20

   Description:
   Used by the CfgSentences Browser GUI. Called when filter is changed.

   Parameter(s):
   0: CONTROL - Toolbox
   1: NUMBER - Index

   Returns:
   BOOLEAN: true
*/

params ["_ctrlFilter","_selectedIndex"];
[_ctrlFilter lbData _selectedIndex] call ENH_fnc_CFGS_getCfgSentences;

// Prevent player from searching the full list because the game would freeze. Also reset search
if ((_ctrlFilter lbData _selectedIndex) == "ALL") then
{
	(ctrlparent _ctrlFilter) displayCtrl 10000 ctrlEnable false;
}
else
{
	(ctrlparent _ctrlFilter) displayCtrl 10000 ctrlEnable true;
};
(ctrlparent _ctrlFilter) displayCtrl 10000 ctrlSetText "";

true