/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the airdrop attribute. Call when attribute is loaded.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   BOOLEAN: true
*/

private _options =
[
	["STR_ENH_debugOptions_showUnits_displayName","STR_ENH_debugOptions_showUnits_tooltip"],
	["STR_ENH_debugOptions_bulletTracking_displayName","STR_ENH_debugOptions_bulletTracking_tooltip"],
	["STR_ENH_debugOptions_zeus_displayName",""],
	["STR_ENH_debugOptions_arsenal_displayName",""],
	["STR_ENH_debugOptions_garage_displayName",""],
	["STR_ENH_debugOptions_invulnerability_displayName",""],
	["STR_ENH_captive_displayName","STR_ENH_captive_tooltip"],
	["STR_ENH_debugOptions_stamina_displayName",""],
	["STR_ENH_debugOptions_awareness_displayName","STR_ENH_debugOptions_awareness_tooltip"],
	["STR_ENH_debugOptions_FPS_displayName",""],
	["STR_ENH_debugOptions_killBLUFOR_displayName","STR_ENH_debugOptions_killUnits_tooltip"],
	["STR_ENH_debugOptions_killOPFOR_displayName","STR_ENH_debugOptions_killUnits_tooltip"],
	["STR_ENH_debugOptions_killINDFOR_displayName","STR_ENH_debugOptions_killUnits_tooltip"],
	["STR_ENH_debugOptions_killCIVFOR_displayName","STR_ENH_debugOptions_killUnits_tooltip"],
	["STR_ENH_debugOptions_killCursor_displayName","STR_ENH_debugOptions_killUnits_tooltip"],
	["STR_ENH_debugOptions_drawIcons_displayName","STR_ENH_debugOptions_drawIcons_tooltip"]
];

params ["_ctrlGroup"];

private _ctrlLB  = _ctrlGroup controlsGroupCtrl 100;
private _enabledOptions = profileNamespace getVariable ["Enh_DebugOptions_Settings",[]];

{
	_x params ["_displayName","_tooltip"];
	
	private _state = if (_forEachIndex in _enabledOptions) then
	{
		["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureChecked_ca.paa",1];
	}
	else
	{
		["\a3\3DEN\Data\Controls\ctrlCheckbox\baseline_textureUnchecked_ca.paa",0];
	};

	_ctrlLB lbAdd localize _displayName;
	_ctrlLB lbSetTooltip [_forEachIndex,localize _tooltip];
	_ctrlLB lbSetPicture [_forEachIndex,_state select 0];
	_ctrlLB lbSetValue [_forEachIndex,_state select 1];
} foreach _options;

true