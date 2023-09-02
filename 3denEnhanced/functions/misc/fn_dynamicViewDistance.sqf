/*
  Author: R3vo

  Date: 2020-11-02

  Description:
  Changes view distance and object view distance according to camera altitude.

  Parameter(s):
  -

  Returns:
  -
*/

if (profileNamespace getVariable ['ENH_EditorPreferences_DynamicViewDistance', false]) then
{

  ENH_DynamicViewDistance_EH_ID = addMissionEventHandler ["EachFrame",
  {
    private _vd = linearConversion [0, 2000, getPosASL get3DENCamera # 2, 200, 12000, true];
    setViewDistance _vd;
    setObjectViewDistance _vd / 2;
  }];
}
else
{
  removeMissionEventHandler ["EachFrame", missionNamespace getVariable ["ENH_DynamicViewDistance_EH_ID", -1]];
};

// Return settings value
profileNamespace getVariable ['ENH_EditorPreferences_DynamicViewDistance', false];