#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-18

    Description:
    Shows custom marker color and shape when hovering over a marker.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - true, or false if disabled
*/

if !(profileNamespace getVariable ["ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape", true]) exitWith
{
    ctrlDelete (findDisplay IDD_DISPLAY3DEN getVariable ["ENH_MarkerPreview_Control", controlNull]);
    false
};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

get3DENMouseOver params [["_type", ""], ["_entity", ""]];

if (_type == "Marker") then
{
    private _attributes =  createHashMapFromArray (_entity get3DENAttributes "");

    _attributes get "ENH_markerColor" params ["_customColorEnabled", "_colorString"];

    private _customMarkerShape = _attributes get "ENH_markerShape";

    // Exit early if none of the custom attributes are set
    if (!_customColorEnabled && {(isNil "_customMarkerShape" || {_customMarkerShape == "NONE"})}) exitWith {false};

    private _ctrlPreviewIcon = _display3DEN getVariable ["ENH_MarkerPreview_Control", controlNull];

    if (isNull _ctrlPreviewIcon) then
    {
        _ctrlPreviewIcon = _display3DEN ctrlCreate ["ctrlStaticPictureKeepAspect", IDC_NONE];
    };

    private _position = getMousePosition vectorAdd [3 * GRID_W, -3 * GRID_H];

    _ctrlPreviewIcon ctrlSetPosition [_position#0, _position#1, 5 * GRID_W, CTRL_DEFAULT_H];
    _ctrlPreviewIcon ctrlCommit 0;

    _display3DEN setVariable ["ENH_MarkerPreview_Control", _ctrlPreviewIcon];

    if (_customColorEnabled) then
    {
        private _colorRGB = _colorString splitString "#,()" apply {parseNumber _x};
        _ctrlPreviewIcon ctrlSetTextColor (_colorRGB + [1]);
    }
    else
    {
        private _markerBaseColor = _attributes get "BaseColor";

        if (_markerBaseColor != "Default") then
        {
            private _colorRGBA = [getArray (configFile >> "CfgMarkerColors" >> _markerBaseColor >> "color")] call BIS_fnc_colorConfigToRGBA;
            _ctrlPreviewIcon ctrlSetTextColor _colorRGBA;
        };
    };

    // The following attributes are only valid for area markers
    private _markerShape = _attributes get "MarkerType";

    if (_markerShape > -1) then
    {
        private _customMarkerShape = _attributes get "ENH_markerShape";

        if (isNil "_customMarkerShape" || {_customMarkerShape == "NONE"}) then
        {
            _ctrlPreviewIcon ctrlSetText (["a3\3den\data\attributes\shape\rectangle_ca.paa", "a3\3den\data\attributes\shape\ellipse_ca.paa"] select _markerShape);
        }
        else
        {
            _ctrlPreviewIcon ctrlSetText format ["\x\enh\addons\main\data\%1_ca.paa", _customMarkerShape];
        };
    }
    else
    {
        _ctrlPreviewIcon ctrlSetText (getText (configFile >> "CfgMarkers" >> _attributes get "ItemClass" >> "icon"));
    };
}
else
{
    ctrlDelete (_display3DEN getVariable ["ENH_MarkerPreview_Control", controlNull]);
};

true
