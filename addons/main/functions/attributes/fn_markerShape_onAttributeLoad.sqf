#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2024-11-02

    Description:
    Used by the marker shape attribute. Called when attribute is loaded.

    Parameter(s):
    0: CONTROL - Controls group
    1: ARRAY - Attribute value

    Returns:
    BOOLEAN: true
*/

params ["_ctrlGroup", "_value"];

private _selectedMarkers = get3DENSelected "Marker" apply {_x get3DENAttribute "markerType"};

// Markers of type icon (-1) don't support marker shapes and become invisible
// So we better disable the attribute here
// TODO: Add a little hint explaining why it's disabled 2025-06-17 R3vo
if (-1 in _selectedMarkers) then
{
    IDC_ATTRIBUTE_CONTROL_00 lbSetCurSel 0;
    IDC_ATTRIBUTE_CONTROL_00 ctrlEnable false;
    IDC_ATTRIBUTE_CONTROL_00 ctrlSetFade 0.8;
}
else
{
    private _index = CUSTOM_MARKER_SHAPES find _value;
    (_ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00) lbSetCurSel _index;
};
