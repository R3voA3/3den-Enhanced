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

    // TODO: There seems to be an issue in ACE 2025-04-27 R3vo
    // Sometimes the +/- buttons add 5 without shift being pressed
    // See https://discord.com/channels/976165959041679380/976224730422063214/1365758746961248356
    [_entity, _entity, true] call ACE_arsenal_fnc_openBox;
};
