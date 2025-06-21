#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-18

    Description:
    Shows custom marker color and shape when hovering over a marker.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - true
*/

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

get3DENMouseOver params [["_type", "test"], ["_entity", "test"]];

if (_type == "Marker") then
{
    private _attributes =  createHashMapFromArray (_entity get3DENAttributes "");
    _attributes get "ENH_markerColor" params ["_customColorEnabled", "_colorHTML"];

    private _customMarkerShape = _attributes get "ENH_markerShape";

    // Exit early if none of the custom attributes are set
    if (!_customColorEnabled && {(isNil "_customMarkerShape" || {_customMarkerShape == "NONE"})}) exitWith {false};

    private _marker = _display3DEN getVariable ["ENH_PreviewMarker", ""];

    if (_marker == "") then
    {
        _marker = createMarkerLocal
        [
            _attributes get "MarkerName",
            _attributes get "Position"
        ];
    };

    _marker setMarkerDirLocal (_attributes get "Rotation");
    _marker setMarkerSizeLocal ((_attributes get "Size2") vectorMultiply 2);

    if (_customColorEnabled) then
    {
        _marker setMarkerColorLocal _colorHTML;
    }
    else
    {
        private _markerBaseColor = _attributes get "BaseColor";

        if (_markerBaseColor != "Default") then
        {
            _marker setMarkerColorLocal _markerBaseColor;
        };
    };

    // The following attributes are only valid for area markers
    private _markerShape = _attributes get "MarkerType";

    if (_markerShape > -1) then
    {
        private _customMarkerShape = _attributes get "ENH_markerShape";

        if (isNil "_customMarkerShape" || {_customMarkerShape == "NONE"}) then
        {
            _marker setMarkerShapeLocal (["RECTANGLE", "ELLIPSE"] select _markerShape);
        }
        else
        {
            _marker setMarkerShapeLocal _customMarkerShape;
        };

        _marker setMarkerBrushLocal (_attributes get "Brush");
    }
    else
    {
        _marker setMarkerTypeLocal (_attributes get "ItemClass");
        _marker setMarkerShapeLocal "ICON";
    };

    _display3DEN setVariable ["ENH_PreviewMarker", _marker];
}
else
{
    private _marker = _display3DEN getVariable ["ENH_PreviewMarker", ""];

    if (_marker isEqualType "" && {_marker != ""}) then
    {
        deleteMarkerLocal _marker;
        _display3DEN setVariable ["ENH_PreviewMarker", ""];
    };
};

true
