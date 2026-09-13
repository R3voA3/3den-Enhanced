#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-05-21

    Description:
    Draws building positions and building class names for the garrison feature.
    Also updates garrison values.

    Parameter(s):
    0: BOOLEAN - True to enable, false to disable

    Returns:
    -
*/

params [["_enable", false]];

if _enable then
{
    ENH_Garrison_OnEachFrame_EH = addMissionEventHandler ["EachFrame",
    {
        // Fetch updated values every 5 frames
        if ((missionNamespace getVariable ["ENH_Garrison_LastFrame", 0]) + 10 <= diag_frameNo) then
        {
            call ENH_fnc_garrison_updatevalues;
            ENH_Garrison_LastFrame = diag_frameNo;
        };

        ENH_Garrison_ValidBuildings apply
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
    }];
}
else
{
    // Remove icons if EH already exists and exit
    // Make sure variable still exists as some events reset them before
    removeMissionEventHandler ["EachFrame", if (!isNil "ENH_Garrison_OnEachFrame_EH") then {ENH_Garrison_OnEachFrame_EH} else {-1}];
};
