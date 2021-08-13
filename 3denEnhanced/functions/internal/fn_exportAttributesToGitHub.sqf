/*
  Author: R3vo

  Date: 2021-06-20

  Description:
  Exports attribute to GitHub wiki in markdown format.

  Parameter(s):
  0: STRING - Class whose attributes should be exported. Can be:
  - "GROUP"
  - "OBJECT"
  - "MARKER"
  - "TRIGGER"
  - "WAYPOINTS"
  - "LOGIC"
  - "COMMENT"
  - "GARBAGECOLLECTION"
  - "INTEL"
  - "MULTIPLAYER"
  - "PREFERENCES"
  - "SCENARIO"

  Returns:
  -
*/

params [["_class", "Scenario"]];

private _export = "";
private _counter = 0;
private _config = configNull;
private _configClasses = [];

if (_class in ["Group", "Marker", "Object", "Trigger", "Waypoint", "Logic", "Comment"]) then
{
  _config = configFile >> "Cfg3DEN" >> _class;
};

if (_class in ["GargabeCollection", "Intel", "Multiplayer", "Preferences", "Scenario"]) then
{
  _config = configFile >> "Cfg3DEN" >> "Mission" >> _class;
};

if (isNull _config) exitWith {systemChat "Wrong input. Check function header!"};

private _attributeCategories = "true" configClasses (_config >> "AttributeCategories");
{
  private _attributes = "configName _x select [0, 3] == 'ENH'" configClasses (_x >> "attributes");
  private _categoryName = getText (_x >> "displayName");
  {
    if ("Subcategory" in configName _x) then
    {
      private _tooltip = getText (_x >> "description");
      if (_forEachIndex == 0) then //Used subcategories as description for the category
      {
        _export = _export + "# " + _categoryName + endl + endl + "Description: " + _tooltip + endl + endl;
      };
    }
    else
    {
      private _displayName = getText (_x >> "displayName");
      private _tooltip = getText (_x >> "tooltip");
      if (_tooltip == "") then {_tooltip = _displayName};
      private _defaultValue = getText (_x >> "defaultValue");
      private _property = getText (_x >> "property");
      if (_forEachIndex == 0) then
      {
        _export = _export + "# " + _categoryName + endl + endl + "## " + _displayName + endl + "Description: " + _tooltip + endl + endl + "Property: " + "```" + _property + "```" + endl + endl + "DefaultValue: " + "```" + _defaultValue + "```" + endl + endl;
      }
      else
      {
        _export = _export + "## " + _displayName + endl + "Description: " + _tooltip + endl + endl + "Property: " + "```" + _property + "```" + endl + endl + endl + "DefaultValue: " + "```" + _defaultValue + "```" + endl + endl;
      };
    };
    _counter = _counter + 1;
  } forEach _attributes;
} forEach _attributeCategories;

_export = format ["_**Number of added entries: %1**_", _counter] + endl + "___" + endl + endl + endl + _export;

uinamespace setVariable ["display3DENCopy_data", ["Menu Strip Documentation", _export]];
findDisplay 313 createDisplay "display3denCopy";