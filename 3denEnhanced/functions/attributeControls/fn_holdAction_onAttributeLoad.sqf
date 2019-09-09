/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hold action attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group
   1: ARRAY - Attribute value

   Returns:
   BOOLEAN: true
*/

#define DEFAULT_ICONS [\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_revive_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_connect_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_forcerespawn_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_hack_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_revivemedic_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_search_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_takeoff1_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_takeoff2_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_unbind_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_passleadership_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_requestleadership_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_secure_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_thumbsdown_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_thumbsup_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_unloaddevice_ca.paa",\
	"\a3\ui_f\data\igui\cfg\holdactions\holdaction_loaddevice_ca.paa"\
]

params ["_ctrlGroup","_value"];

_value params
[
	"_name",
	"_iconIdle",
	"_iconProgress",
	"_conditionShow",
	"_conditionProgress",
	"_codeStart",
	"_codeProgress",
	"_codeCompletion",
	"_codeInterrupt",
	"_duration",
	"_priority",
	"_showUnconscious",
	"_showWindow",
	"_template"
];

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText _name;

//Fill icon combos
_ctrlIconIdle = _ctrlGroup controlsGroupCtrl 101;
{
	_ctrlIconIdle lbAdd _x;
	_ctrlIconIdle lbSetPicture [_forEachIndex,_x];
	if (_x isEqualTo _iconIdle) then
	{
		_ctrlIconIdle lbSetCurSel _forEachIndex;
	};
} forEach DEFAULT_ICONS;

_ctrlIconProgress = _ctrlGroup controlsGroupCtrl 102;
{
	_ctrlIconProgress lbAdd _x;
	_ctrlIconProgress lbSetPicture [_forEachIndex,_x];
	if (_x isEqualTo _iconProgress) then
	{
		_ctrlIconProgress lbSetCurSel _forEachIndex;
	};
} forEach DEFAULT_ICONS;

(_ctrlGroup controlsGroupCtrl 103) ctrlSetText _conditionShow;
(_ctrlGroup controlsGroupCtrl 104) ctrlSetText _conditionProgress;
(_ctrlGroup controlsGroupCtrl 105) ctrlSetText _codeStart;
(_ctrlGroup controlsGroupCtrl 106) ctrlSetText _codeProgress;
(_ctrlGroup controlsGroupCtrl 107) ctrlSetText _codeCompletion;
(_ctrlGroup controlsGroupCtrl 108) ctrlSetText _codeInterrupt;

[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"s"] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 109,_ctrlGroup controlsGroupCtrl 110,"s",_duration] call BIS_fnc_initSliderValue;

[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,""] call BIS_fnc_initSliderValue;
[_ctrlGroup controlsGroupCtrl 111,_ctrlGroup controlsGroupCtrl 112,"",_priority] call BIS_fnc_initSliderValue;

(_ctrlGroup controlsGroupCtrl 113) cbSetChecked _showUnconscious;
(_ctrlGroup controlsGroupCtrl 114) cbSetChecked _showWindow;

true