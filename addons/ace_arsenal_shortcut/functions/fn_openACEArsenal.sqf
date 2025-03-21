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

    // Exec in 5 frames
    addMissionEventHandler ["EachFrame",
    {
        if (diag_frameNo > _thisArgs#0 + 5) then
        {
            [_thisArgs#1, _thisArgs#1, true] call ace_arsenal_fnc_openBox;
            removeMissionEventHandler [_thisEvent, _thisEventHandler];
        }
    }, [diag_frameNo, _entity]];
};
