/*
  Author: R3vo

  Description:
  Counts all selected 3DEN entities and updates statusbar accordingly. Called when Eden selection is changed or when editor preferences are set.

  Parameter(s):
  0: STRING - Mode, can be INIT to show/hide controls or RUN to simply update the controls. Default: RUN

  Returns:
  -
*/

#include "\3denEnhanced\defines\defineCommon.inc"

params [["_mode", "run"]];

disableSerialization;

private _display = findDisplay 313;
private _conditionHide = (102 * (pixelW * pixelGrid * 0.50) >= (safezoneW - 60 * (pixelW * pixelGrid * 0.50)) - 109 * (pixelW * pixelGrid * 0.50) - 2 * (2 * pixelW));

//Hide control if screen is too small or gui scale too big. We wait 20 seconds because this command can crash Arma
if (_conditionHide) then
{
  [] spawn
  {
    waitUntil {sleep 1; is3DEN};
    "Preferences" set3DENMissionAttribute ["ENH_Statusbar_EntityCounter", false];
  };
};

private _enabled = ("Preferences" get3DENMissionAttribute "ENH_Statusbar_EntityCounter") && !_conditionHide;

switch (_mode) do
{
  case "init":
  {
    for "_i" from IDC_STATUSBAR_NUMMARKERS to IDC_STATUSBAR_ICONOBJECTS do
    {
      (_display displayCtrl _i) ctrlShow _enabled;
    };
  };
  case "run":
  {
    if !(_enabled) exitWith {};
    {
      _x params ["_idc", "_type"];
      (_display displayCtrl _idc) ctrlSetText (str count get3DENSelected _type);
    } forEach [
      [IDC_STATUSBAR_NUMMARKERS, "Marker"],
      [IDC_STATUSBAR_NUMSYSTEMS, "Logic"],
      [IDC_STATUSBAR_NUMWAYPOINTS, "Waypoint"],
      [IDC_STATUSBAR_NUMTRIGGERS, "Trigger"],
      [IDC_STATUSBAR_NUMGROUPS, "Group"],
      [IDC_STATUSBAR_NUMOBJECTS, "Object"]
    ];
  };
};