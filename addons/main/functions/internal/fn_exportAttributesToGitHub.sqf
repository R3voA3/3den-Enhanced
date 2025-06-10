#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2023-12-28

    Description:
    Exports attribute to GitHub wiki in media wiki format.

    Parameter(s):
    -

    Returns:
    -
*/

private _export = "__NOTOC__" + endl;
private _counter = 0;
private _config = configNull;

["Scenario", "Intel", "Multiplayer", "GargabeCollection", "Preferences", "Object", "Group", "Marker", "Trigger", "Waypoint", "Logic", "Comment"] apply
{
    private _class = _x;

    if (toUpper _class in ["GROUP", "MARKER", "OBJECT", "TRIGGER", "WAYPOINT", "LOGIC", "COMMENT"]) then
    {
        _config = configFile >> "Cfg3DEN" >> _class;
    };

    if (toUpper _class in ["GARGABECOLLECTION", "INTEL", "MULTIPLAYER", "PREFERENCES", "SCENARIO"]) then
    {
        _config = configFile >> "Cfg3DEN" >> "Mission" >> _class;
    };

    // Check if there are actually custom attributes in this config
    if ([_config, 3] call BIS_fnc_returnChildren select {configName _x select [0, 3] == "ENH"} isEqualTo [] ) then {continue};

    _export = _export + format ["= %1 Attributes =", _class] + endl;

    private _attributeCategories = "true" configClasses (_config >> "AttributeCategories");
    private _hasSubCategory = false;
    {
        private _attributes = "configName _x select [0, 3] == 'ENH'" configClasses (_x >> "attributes");
        private _categoryName = getText (_x >> "displayName");
        {
            if ("Subcategory" in configName _x) then
            {
                private _description = getText (_x >> "description");
                _description = format ["Description: %1", _description];

                if (_forEachIndex == 0) then // Use subcategories as description for the category
                {
                    _export = _export + format ["=== %1 Subcategory ===", _categoryName] + endl + _description + endl;
                    _hasSubCategory = true;
                };
            }
            else
            {
                private _displayName = getText (_x >> "displayName");
                private _description = getText (_x >> "tooltip");

                if (_description != "") then
                {
                    _description = format ["%2Description: %1%2%2", _description, endl];
                };

                private _defaultValue = getText (_x >> "defaultValue");
                _defaultValue = format ["Default Value: %1```sqf%1%2%1```", endl, _defaultValue];

                private _property = getText (_x >> "property");
                _property = format ["Property: ''%1''", _property];

                if _hasSubCategory then
                {
                    _displayName = format ["==== %1 ====", _displayName] + endl;
                }
                else
                {
                    _displayName = format ["=== %1 ===", _displayName];
                };

                if (_forEachIndex == 0) then
                {
                    _export = _export + format ["== %1 ==", _categoryName] + endl + _displayName + _description + _property + endl + endl + _defaultValue + endl + endl;
                }
                else
                {
                    _export = _export + _displayName + endl + _property + endl + endl + endl + _defaultValue + endl + endl;
                };
            };
            _counter = _counter + 1;
        } forEach _attributes;
    } forEach _attributeCategories;
};

_export = format ["'''Total number of Attributes: %1'''", _counter] + endl + endl + _export;

_export = _export regexReplace ["\\n", endl];

uiNamespace setVariable ["display3DENCopy_data", ["Menu Strip Documentation", _export]];
findDisplay IDD_DISPLAY3DEN createDisplay "display3denCopy";
