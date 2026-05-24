#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Description:
    Used by the ENH_ModuleInformation GUI. Called onLoad.

    Parameter(s):
    0: DISPLAY - Module Information GUI

    Returns:
    NOTHING
*/

disableSerialization;

params ["_display"];

private _module = get3DENSelected "Logic" param [0, objNull];

if (isNull _module) exitWith {};

_display setVariable ["Module", _module];
private _moduleInformation = [[configOf _module] call ENH_fnc_MI_getInformationData] call ENH_fnc_MI_formatInformationData;

CTRL(IDC_MODULEINFORMATION_DESCRIPTION) call ENH_fnc_MI_resizeInformationControl;

[_display, typeOf _module] call ENH_fnc_MI_createSyncPreview;

CTRL(IDC_MODULEINFORMATION_SYNC_TYPE_SELECTOR) ctrlAddEventHandler ["ToolBoxSelChanged",
{
    params ["_ctrlTB", "_selectedIndex"];

    private _displayModuleInformation = ctrlParent _ctrlTB;
    private _module = _displayModuleInformation getVariable "Module";

    if (_selectedIndex > 0) then
    {
        [_displayModuleInformation , typeOf _module] call ENH_fnc_MI_createSyncPreviewTree;
    }
    else
    {

        [_displayModuleInformation, typeOf _module] call ENH_fnc_MI_createSyncPreview;
    };
}];
