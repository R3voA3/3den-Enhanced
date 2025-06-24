#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2025-06-18

    Description:
    Shows custom marker color and shape when hovering over a marker.

    Parameter(s):
    -

    Return Value:
    BOOLEAN - true, false when exited early
*/

if !(profileNamespace getVariable ["ENH_EditorPreferences_Interface_ShowCustomMarkerColorAndShape", true]) exitWith {false};

private _display3DEN = findDisplay IDD_DISPLAY3DEN;

get3DENMouseOver params [["_type", "test"], ["_entity", "test"]];

if (_type == "Marker") then
{
    // if (_display3DEN getVariable ["ENH_PreviewMarker_OnBeforeMissioNPreview_EH_ID", -1] == -1) then
    // {
    //     private _ID = add3DENEventHandler ["OnBeforeMissionPreview",
    //     {
    //         private _display3DEN = findDisplay IDD_DISPLAY3DEN;
    //         _marker = _display3DEN getVariable ["ENH_PreviewMarker", ""];

    //         if (_marker != "") then
    //         {
    //             deleteMarkerLocal _marker;

    //             private _originalAlpha = _display3DEN getVariable ["ENH_PreviewMarker_AlphaBefore", -1];

    //             if (_originalAlpha != -1) then
    //             {
    //                 _marker set3DENAttribute ["Alpha", _originalAlpha];
    //                 _display3DEN setVariable ["ENH_PreviewMarker_AlphaBefore", -1];
    //             };
    //         };
    //     }];

    //     findDisplay IDD_DISPLAY3DEN setVariable ["ENH_PreviewMarker_OnBeforeMissioNPreview_EH_ID", _ID];
    // };


    private _attributes =  createHashMapFromArray (_entity get3DENAttributes "");
    private _marker = _display3DEN getVariable ["ENH_PreviewMarker", ""];

    if (_marker == "") then
    {
        _marker = createMarkerLocal
        [
            _attributes get "MarkerName",
            _attributes get "Position"
        ];
    };

    // Save original alpha value
    // private _3DENMarker = _marker;

    // // Make sure we are only saving original value once, otherwise original value becomes forced 0 value
    // private _originalAlpha = _attributes get "Alpha";
    // if (_originalAlpha != 0) then
    // {
    //     if (_display3DEN getVariable ["ENH_PreviewMarker_AlphaBefore", -1] == -1) then
    //     {
    //         _display3DEN setVariable ["ENH_PreviewMarker_AlphaBefore", _originalAlpha];
    //     };

    //     // Hide 3DEN marker while previewing custom color or shape
    //     ignore3DENHistory {_3DENMarker set3DENAttribute ["Alpha", 0]};
    // };

    _marker setMarkerDirLocal (_attributes get "Rotation");
    _marker setMarkerSizeLocal ((_attributes get "Size2") vectorMultiply 2);

    _attributes get "ENH_markerColor" params ["_customColorEnabled", "_colorHTML"];

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
        // private _3DENMarker = _marker;

        // private _alphaBefore = _display3DEN getVariable ["ENH_PreviewMarker_AlphaBefore", 1];

        // ignore3DENHistory {_3DENMarker set3DENAttribute ["Alpha", _alphaBefore]};

        deleteMarkerLocal _marker;

        _display3DEN setVariable ["ENH_PreviewMarker", ""];
        // _display3DEN setVariable ["ENH_PreviewMarker_AlphaBefore", -1];
    };
};

true
