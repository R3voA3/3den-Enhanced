#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-18

    Description:
    Shows custom shape when hovering over a marker.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - true, or false if disabled
*/

if !(profileNamespace getVariable ["ENH_EditorPreferences_Interface_ShowCustomMarkerShape", true]) exitWith
{
    ctrlDelete (findDisplay IDD_DISPLAY3DEN getVariable ["ENH_MarkerPreview_Control", controlNull]);
    false
};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

get3DENMouseOver params [["_type", ""], ["_entity", ""]];

if (_type == "Marker") then
{
    private _attributes =  createHashMapFromArray (_entity get3DENAttributes "");
    private _customMarkerShape = _attributes getOrDefault ["ENH_markerShape", "NONE"];

    // Exit early if none of the custom attributes are set
    if (_customMarkerShape == "NONE") exitWith {false};

    private _ctrlPreviewIcon = _display3DEN getVariable ["ENH_MarkerPreview_Control", controlNull];

    if (isNull _ctrlPreviewIcon) then
    {
        _ctrlPreviewIcon = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_NONE];
    };

    private _position = getMousePosition vectorAdd [3 * GRID_W, -3 * GRID_H];
    _ctrlPreviewIcon ctrlSetPosition [_position#0, _position#1, 5 * GRID_W, CTRL_DEFAULT_H];
    _ctrlPreviewIcon ctrlCommit 0;

    _display3DEN setVariable ["ENH_MarkerPreview_Control", _ctrlPreviewIcon];

    // The following attributes are only valid for area markers
    if (_customMarkerShape != "NONE") then
    {
        _ctrlPreviewIcon ctrlSetText format ["\x\enh\addons\main\data\%1_ca.paa", _customMarkerShape];
    };
}
else
{
    ctrlDelete (_display3DEN getVariable ["ENH_MarkerPreview_Control", controlNull]);
};

true
