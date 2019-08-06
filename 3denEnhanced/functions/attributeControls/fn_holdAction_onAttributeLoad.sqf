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
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_revive_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_forceRespawn_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_hack_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_reviveMedic_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_search_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff1_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_takeOff2_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unbind_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_passleadership_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_requestleadership_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_secure_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsdown_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_thumbsup_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_unloaddevice_ca.paa",\
	"\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_loaddevice_ca.paa"\
]

params ["_ctrlGroup","_value"];

_value params
[
	"_actionName",
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

(_ctrlGroup controlsGroupCtrl 100) ctrlSetText _actionName;

//Fill icon combos
_ctrlIdleIcon = _ctrlGroup controlsGroupCtrl 101;
{
	_ctrlIdleIcon lbAdd _x;
	_ctrlIdleIcon lbSetPicture [_forEachIndex,_x];
	if (_x isEqualTo _iconIdle) then
	{
		_ctrlIdleIcon lbSetCurSel _forEachIndex;
	};
} forEach DEFAULT_ICONS;

_ctrlProgressIcon = _ctrlGroup controlsGroupCtrl 102;
{
	_ctrlProgressIcon lbAdd _x;
	_ctrlProgressIcon lbSetPicture [_forEachIndex,_x];
	if (_x isEqualTo _iconProgress) then
	{
		_ctrlProgressIcon lbSetCurSel _forEachIndex;
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

//Fill templates combo WIP
_ctrlTemplates = _ctrlGroup controlsGroupCtrl 115;
{
	_ctrlTemplates lbAdd _x;
 	if (_x isEqualTo _template) then
	{
		_ctrlTemplates lbSetCurSel _forEachIndex;
	};
} forEach ["Custom","Hack","Search","Download","Custom","Hack","Search","Download"];