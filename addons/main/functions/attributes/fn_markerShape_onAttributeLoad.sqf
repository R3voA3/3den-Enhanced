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

private _ctrlToolbox = controlNull;

// The load event provides the control, not the group
if (ctrlIDC _ctrlGroup == IDC_ATTRIBUTE_CONTROL_00) then
{
    _ctrlToolbox = _ctrlGroup;
    _ctrlGroup = ctrlParentControlsGroup _ctrlGroup;
}
else
{
    _ctrlToolbox = _ctrlGroup controlsGroupCtrl IDC_ATTRIBUTE_CONTROL_00;
};

private _selectedMarkersTypes = get3DENSelected "Marker" apply {_x get3DENAttribute "markerType"};

// Markers of type icon (-1) don't support marker shapes and become invisible
// So we better disable the attribute here
if ([-1] in _selectedMarkersTypes) then
{
    _ctrlToolbox lbSetCurSel -1;
    _ctrlToolbox ctrlEnable false;

    private _ctrlMessageDisabled = (ctrlParent _ctrlGroup) ctrlCreate ["ctrlStatic", -1, _ctrlGroup];
    _ctrlMessageDisabled ctrlSetPosition (ctrlPosition _ctrlToolbox);
    _ctrlMessageDisabled ctrlSetBackgroundColor [0.6, 0.6, 0.6, 0.7];
    _ctrlMessageDisabled ctrlSetText localize "$STR_ENH_MAIN_ATTRIBUTES_MARKER_SHAPE_DISABLED";
    _ctrlMessageDisabled ctrlCommit 0;
}
else
{
    _ctrlToolbox lbSetCurSel (CUSTOM_MARKER_SHAPES find _value);
};

true
