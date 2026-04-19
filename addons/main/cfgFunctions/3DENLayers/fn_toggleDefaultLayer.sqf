#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2026-04-18

    Description:
    Sets selected layer as default layer.

    Parameter(s):
    BOOLEAN: True to set selected layer as default, false to remove default layer.

    Return Value:
    NOTHING
*/

params [["_setDefaultLayer", [true]]];

private _allLayers = all3DENEntities param [6, []];
private _defaultLayers = _allLayers select {_x get3DENAttribute "ENH_DefaultLayer" select 0};

[localize "STR_ENH_DEFAULT_LAYER_RESET_DEFAULT", nil, TEXTURE_LAYER]collect3DENHistory
{
    // In case multiple layers were set to be default layers
    while {call ENH_fnc_getDefaultLayer != -1} do
    {
        private _defaultLayer = call ENH_fnc_getDefaultLayer;
        private _layerName = _defaultLayer get3DENAttribute "Name" select 0;

        _defaultLayer set3DENAttribute ["Name", _layerName regexReplace ["\[DEF\] ", ""]];
        _defaultLayer set3DENAttribute ["ENH_DefaultLayer", false];
    };
};

private _selectedLayer = [["Layer"]] call ENH_fnc_all3DENSelected param [0, -1];

// Set default layer if wanted
if (_setDefaultLayer && {_selectedLayer != -1}) then
{
    [localize "STR_ENH_DEFAULT_LAYER_SET_AS_DEFAULT", nil, TEXTURE_LAYER]collect3DENHistory
    {
        _selectedLayer set3DENAttribute ["ENH_DefaultLayer", true];
        _selectedLayer set3DENAttribute
        [
            "Name", "[DEF] " + (_selectedLayer get3DENAttribute "Name" select 0)
        ];
    };
};

nil
