/*
  Author: R3vo

  Date: 2019-08-30

  Description:
  Draws the hitpoints of selected object.

  Parameter(s):
  -

  Returns:
  -
*/

["ENH_actionPerformed"] call BIS_fnc_3DENNotification;

//Remove icons if EH already exists and exit
if (["ENH_EH_DrawHitpoints_ID", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) exitWith {};

["ENH_EH_DrawHitpoints_ID", "onEachFrame",
  {
    private _object = (get3DENSelected "Object" # 0);
    getAllHitPointsDamage _object params ["_hitPoints", "_selections"];
    {
      drawIcon3D
      [
        "\a3\ui_f\data\igui\cfg\targeting\hitprediction_ca.paa",
        [1,1,1,1],
        ASLToAGL (_object modelToWorldVisualWorld (_object selectionPosition [_selections # _forEachIndex, "HitPoints"])),
        1,
        1,
        0,
        _x,
        true,
        1.5 * (1 / (getResolution select 3)) * pixelGrid //Scale font with GUI size etc.
      ];
    } forEach _hitPoints;
  }
] call BIS_fnc_addStackedEventHandler;