#include "\x\enh\addons\main\script_component.hpp"

private _entity = get3DENSelected "Object" param [0, objNull];

if (!isNull _entity) then
{
    ENH_MiniMapState = "Preferences" get3DENMissionAttribute "ENH_MinimapSize";
    ENH_ACE_Arsenal_DisplayClosed_EH_ID = -1;

    if (ENH_MiniMapState != 0) then
    {
        // If minimap was enabled, disable it and reenable it when arsenal is closed
        "Preferences" set3DENMissionAttribute ["ENH_MinimapSize", 0];

        ENH_ACE_Arsenal_DisplayClosed_EH_ID = ["ace_arsenal_displayClosed",
        {
            "Preferences" set3DENMissionAttribute
            [
                "ENH_MinimapSize",
                missionNamespace getVariable ["ENH_MiniMapState", 0]
            ];

            ["ace_arsenal_displayClosed", ENH_ACE_Arsenal_DisplayClosed_EH_ID] call CBA_fnc_removeEventHandler;

            ENH_MiniMapState = nil;
            ENH_ACE_Arsenal_DisplayClosed_EH_ID = nil;
        }] call CBA_fnc_addEventHandler;
    };

    // Exec in 5 frames later otherwise it doesn't work !?
    // This might actually be an ACE issue see
    // https://discord.com/channels/976165959041679380/976224730422063214/1365758746961248356
    // If this gets fixed by ACE, the following code can be drastically
    // simplefied
    // go back to [_thisArgs#1, _thisArgs#1, true] call ace_arsenal_fnc_openBox; then
    if (isNil "ENH_ACE_Arsenal_EachFrame_EH_ID") then
    {
        ENH_ACE_Arsenal_EachFrame_EH_ID = addMissionEventHandler ["EachFrame",
        {
            if (diag_frameNo > _thisArgs#0 + 10) then
            {
                // Store stuff because _fnc_open3DEN accesses that
                private _data = uiNamespace getVariable ["BIS_fnc_3DENEntityMenu_data", []];
                _data set [1, _thisArgs#1];
                uiNamespace setVariable ["BIS_fnc_3DENEntityMenu_data", _data];

                [] call ace_arsenal_fnc_open3DEN;

                removeMissionEventHandler [_thisEvent, _thisEventHandler];
                ENH_ACE_Arsenal_EachFrame_EH_ID = nil;
            }
        }, [diag_frameNo, _entity]];
    };
};
