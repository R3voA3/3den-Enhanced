#include "\x\enh\addons\main\script_component.hpp"

private _entity = get3DENSelected "Object" param [0, objNull];

if (!isNull _entity) then
{
    ENH_MiniMapState = "Preferences" get3DENMissionAttribute "ENH_MinimapSize";
    ENH_ace_arsenal_displayClosed_eh_id = -1;

    if (ENH_MiniMapState != 0) then
    {
        // If minimap was enabled, disable it and reenable it when arsenal is closed
        "Preferences" set3DENMissionAttribute ["ENH_MinimapSize", 0];

        ENH_ace_arsenal_displayClosed_eh_id = ["ace_arsenal_displayClosed",
        {
            "Preferences" set3DENMissionAttribute
            [
                "ENH_MinimapSize",
                missionNamespace getVariable ["ENH_MiniMapState", 0]
            ];

            ["ace_arsenal_displayClosed", ENH_ace_arsenal_displayClosed_eh_id] call CBA_fnc_removeEventHandler;

            ENH_MiniMapState = nil;
            ENH_ace_arsenal_displayClosed_eh_id = nil;
        }] call CBA_fnc_addEventHandler;
    };

    [_entity] spawn
    {
        params ["_entity"];
        sleep 0.1;
        [_entity, _entity, true] call ace_arsenal_fnc_openBox;
    };
};
