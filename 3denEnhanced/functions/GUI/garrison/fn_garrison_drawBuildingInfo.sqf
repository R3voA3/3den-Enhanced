/*
  Author: R3vo

  Date: 2021-05-21

  Description:
  Draws building positions and building class names for the garrison feature.

  Parameter(s):
  0: BOOLEAN - True to enable, false to disable

  Returns:
  -
*/

params [["_enable", false]];

if (_enable) then
{
  //Get all building positions from nearby buildings
  ["ENH_EH_DrawBuildingPositions_ID", "onEachFrame",
    {
      ENH_Garrison_Buildigns_InArea apply
      {
        drawIcon3D
        [
          "\a3\modules_f\data\editterrainobject\icon32_ca.paa",
          [0.27, 0.8, 0.37, 1],
          getPos _x,
          0.5,
          0.5,
          0,
          typeOf _x,
          2
        ];
        {
          drawIcon3D
          [
            "\A3\modules_f\data\iconStrategicMapMission_ca.paa",
            [0.37, 0.65, 1, 1],
            _x,
            0.5,
            0.5,
            0,
            str _forEachIndex,
            2
          ];
        } forEach (_x buildingPos -1);
      };
    }
  ] call BIS_fnc_addStackedEventHandler;
}
else
{
  //Remove icons if EH already exists and exit
  ["ENH_EH_DrawBuildingPositions_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
};