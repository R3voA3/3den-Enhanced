/*
  Author: R3vo

  Date: 2021-06-17

  Description:
  Used to create object or marker with given classname. Used in the ENH_SpawnObject GUI.

  Parameter(s):
  0: CONTROL - Button

  Returns:
  -
*/

#include "\3denEnhanced\ENH_defineCommon.hpp"

disableSerialization;

params ["_ctrlButton"];

private _modeID = lbCurSel (ctrlParent _ctrlButton displayCtrl 10);
private _modeStr = ["object", "marker"] select _modeID;
private _class = ctrlText (ctrlParent _ctrlButton displayCtrl 20);

//Remove quotes if present, bugged in v2.04, gonna hopefully be fixed in v2.06
_class = _class trim ["""", 0];

//Validate
if (_class isEqualTo "") exitWith
{
  (ctrlParent _ctrlButton displayCtrl 20) spawn
  {
    disableSerialization;
    private _ctrlHighlight = [_this, 5] call BIS_fnc_highlightControl;
    sleep 2;
    ctrlDelete _ctrlHighlight;
  };
};
if (_modeStr == "object" && {"true" configClasses (configFile >> "CfgVehicles") findIf {configName _x == _class} == -1}) exitWith {[localize "STR_ENH_FUNCTIONS_BATCHREPLACE_ERROR", 1] call BIS_fnc_3DENNotification};
if (_modeStr == "marker" && {"true" configClasses (configFile >> "CfgMarkers") findIf {configName _x == _class} == -1}) exitWith {[localize "STR_ENH_FUNCTIONS_BATCHREPLACE_ERROR", 1] call BIS_fnc_3DENNotification};

create3DENEntity [_modeStr, _class, screenToWorld [0.5, 0.5], true];
if (_modeStr == "marker" && (get3DENActionState "ToggleMap" == 0)) then {do3DENAction "ToggleMap"};

move3DENCamera [screenToWorld [0.5, 0.5], true];