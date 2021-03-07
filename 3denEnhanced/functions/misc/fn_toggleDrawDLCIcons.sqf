/*
  Author: R3vo

  Date: 2019-08-30

  Description:
  Draws the mod icon next to the Eden entity.

  Parameter(s):
  -

  Returns:
  -
*/

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

//Remove icons if EH already exists and exit
if (["ENH_EH_DrawDLCIcons_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) exitWith {};

["ENH_EH_DrawDLCIcons_ID", "onEachFrame",
  {
    {
      //Stupid workaround because modParams spams .rpt file otherwise
      private _mod = configSourceMod (configFile >> "CfgVehicles" >> typeOf _x);
      if (_mod != "") then
      {
        drawIcon3D
        [
          (modParams [_mod, ["logoSmall"]]) # 0,
          [1, 1, 1, 0.8],
          _x modelToWorldVisual [0, 0, 0.5],
          0.5,
          0.5,
          0
        ];
      }
    } count ((vehicles + allUnits) select {get3DENCamera distance _x <= 100});
  }
] call BIS_fnc_addStackedEventHandler;