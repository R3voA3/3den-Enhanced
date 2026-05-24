#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Measures the distance between two positions.

    Parameter(s):
    -

    Returns:
    BOOLEAN: true
*/

disableSerialization;// For BIS_fnc_3DENNotification

// Make sure the old EH was deleted
waitUntil {isNil "ENH_EH_DrawDist" && {isNil "ENH_MeasureDist_Markers"}};

if (isNil "ENH_Pos_Start") then
{
    ENH_Pos_Start = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
    ["ENH_SelectSecondPoint"] call BIS_fnc_3DENNotification;
}
else
{
    // Measure distance and display 3D line
    ENH_Pos_End = (uiNamespace getVariable "bis_fnc_3DENEntityMenu_data") # 0;
    private _dist3D = ENH_Pos_Start distance ENH_Pos_End;
    private _dist2D = ENH_Pos_Start distance2D ENH_Pos_End;
    private _travelTime = (_dist3D / (14.15 * 1000) * 3600) call ENH_fnc_floatToTime;// 14.15 is the average speed of a soldier (km/h)

    // Display information
    [
        format
        [
            localize "STR_ENH_MAIN_MEASUREDISTANCE_DATA",
            round _dist2D,
            round _dist3D,
            _travelTime
        ],
        0,
        20
    ] call BIS_fnc_3DENNotification;

    if (get3DENActionState "toggleMap" == 1) then
    {
        ENH_MeasureDist_Markers = [ENH_Pos_Start, ENH_Pos_End, 50] call BIS_fnc_markerPath;
        sleep 5;
        {deleteMarker _x} forEach ENH_MeasureDist_Markers;
        ENH_MeasureDist_Markers = nil;
    }
    else
    {
        ENH_EH_DrawDist = addMissionEventHandler ["Draw3D",
        {

            drawLine3D [ASLToAGL ENH_Pos_Start, ASLToAGL ENH_Pos_End, [1, 0, 0, 1]];

        }];
        sleep 5;
        removeMissionEventHandler ["Draw3D", ENH_EH_DrawDist];
        ENH_EH_DrawDist = nil;
    };

    ENH_Pos_Start = nil;
    ENH_Pos_End = nil;
};

true
