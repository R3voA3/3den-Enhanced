/*
  Author: R3vo

  Date: 2020-11-02

  Description:
  Changes view distance and object view distance according to camera hight.

  Parameter(s):
  -

  Returns:
  -
*/

if ("Preferences" get3DENMissionAttribute "ENH_DynamicViewDistance") then
{
  ["ENH_DynamicViewDistance", "onEachFrame",
  {
    private _vd = linearConversion [0, 2000, getPosASL get3DENCamera # 2, 500, 12000,true];
    setViewDistance _vd;
    setObjectViewDistance _vd / 2;
  }] call BIS_fnc_addStackedEventHandler;
}
else
{
  ["ENH_DynamicViewDistance", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};