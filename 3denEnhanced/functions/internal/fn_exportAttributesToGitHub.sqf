/*
  Author: R3vo

  Date: 2020-10-20

  Description:
  Exports attribute to GitHub wiki in markdown format. Copies result to clipboard.

  Parameter(s):
  0: BOOLEAN - True for entity attributes, false for mission attributes

  Returns:
  BOOLEAN: true
*/

params [["_entityAttributes", true]];

private _export = "";
private _counter = 0;
private _config = configNull;
private _configClasses = [];

// Switch between mission attributes and entity attributes
if (_entityAttributes) then
{
  _config = configFile >> "Cfg3DEN";
  _configClasses = ["Group", "Marker", "Object", "Trigger", "Waypoint", "Logic", "Comment"];
}
else
{
  _config = configFile >> "Cfg3DEN" >> "Mission";
  _configClasses = ["GargabeCollection", "Intel", "Multiplayer", "Preferences", "Scenario"];
};

{
  private _attributeCategories = "true" configClasses (_config >> _x >> "AttributeCategories");
  {
    private _attributes = "configName _x select [0, 3] == 'ENH'" configClasses (_x >> "attributes");
    private _categoryName = getText (_x >> "displayName");
    {
      if ("Subcategory" in configName _x) then
      {
        private _displayName = "Subcategory (Used for describing the following attributes)";
        private _tooltip = getText (_x >> "description");
        if (_forEachIndex == 0) then
        {
          _export = _export + "# " + _categoryName + endl + endl + "## " + _displayName + endl + "Description: " + _tooltip + endl;
        }
        else
        {
          _export = _export + "## " + _displayName + endl + "Description: " + _tooltip + endl;
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
          _export = _export + "## " + _displayName + endl + "Description: " + _tooltip + endl + endl + "Property: " + "```" + _property + "```" + endl + endl + "DefaultValue: " + "```" + _defaultValue + "```" + endl + endl;
        };
      };
      _counter = _counter + 1;
    } forEach _attributes;
  } forEach _attributeCategories;
} forEach _configClasses;

_export = format ["_**Number of added entries: %1**_", _counter] + endl + "___" + endl + endl + endl + _export;

copyToClipboard _export;

true