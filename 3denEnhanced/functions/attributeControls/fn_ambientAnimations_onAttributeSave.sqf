/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the ambient animations attribute. Called when attribute is saved.

   Parameter(s):
   0: CONTROL - Controls group

   Returns:
   ARRAY: Attribute value
*/

params ["_ctrlGroup"];

//Selection animations to pass to the attribute
private _animSet = (_ctrlGroup controlsGroupCtrl 100) lbText lbCurSel (_ctrlGroup controlsGroupCtrl 100);
private _anims = switch (_animSet) do
{
   case "SHIELD_FROM_SUN":
   {
      ["Acts_ShieldFromSun_loop"];
   };
   case "STAND_IDLE_2":
   {
      ["acts_millerIdle"];
   };
   case "WORKING_AT_DESK":
   {
      ["acts_millerDisarming_deskLoop"];
   };
   case "HANDS_HELD_HIGH":
   {
      ["Acts_JetsMarshallingStop_loop"];
   };
   case "WARMUP":
   {
      ["Acts_AidlPercMstpSloWWpstDnon_warmup_6_loop"];
   };
   case "WARMUP_KNEELING":
   {
      ["Acts_AidlPercMstpSloWWrflDnon_warmup_6_loop"];
   };
   case "SIT_HANDCUFFED":
   {
      ["Acts_AidlPsitMstpSsurWnonDnon01","Acts_AidlPsitMstpSsurWnonDnon02","Acts_AidlPsitMstpSsurWnonDnon03","Acts_AidlPsitMstpSsurWnonDnon04","Acts_AidlPsitMstpSsurWnonDnon05"];
   };
   case "STAND_TALKING":
   {
      ["Acts_CivilTalking_1","Acts_CivilTalking_2"];
   };
   case "STAND_IDLE":
   {
      ["Acts_CivilIdle_1","Acts_CivilIdle_2"];
   };
   case "STAND_PISTOL":
   {
      ["Acts_Executioner_StandingLoop"];
   };
   default
   {
      (_animSet call BIS_fnc_ambientAnimGetParams) param [0,[]];
   };
};

//Make sure to exit with exact default value if nothing was set, so attribute data is not written to mission.sqf (Workaround)
if (_animSet isEqualTo "") exitWith {['',[],false,false]};

[
   _animSet,//Needs to be saved to restore the value when attribute is loaded
	_anims,
	cbChecked (_ctrlGroup controlsGroupCtrl 101),
   cbChecked (_ctrlGroup controlsGroupCtrl 102)
]