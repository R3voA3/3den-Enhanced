/*
   Author: R3vo

   Date: 2019-05-27

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager GUI.
   Returns all Scenario Attributes.

   Parameter(s):
   -

   Returns:
   ARRAY: Array in format [["section","attributeName",attributeValue]]
*/

private _attributeValues = [];
private _sections = [configfile >> "Cfg3DEN" >> "Mission",0,false] call BIS_fnc_returnChildren;

{
	private _section = configName _x;
	private _children = [configfile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories",2,false] call BIS_fnc_returnChildren;
	{
		private _attributeDisplayName = getText (_x >> "displayName");
		private _attributeName = getText (_x >> "property");//By default get _attributeValue by propertyName
		private _attributeValue = _section get3DENMissionAttribute _attributeName;
		
		if (isNil "_attributeValue") then
		{
			_attributeName = getText (_x >> "data");
			_attributeValue = _section get3DENMissionAttribute _attributeName;//If it's still nil get_attributeValue by data config entry
		};
		if (!isNil "_attributeValue") then//If value is still nil, then it's an attribute description or a not correctly configured attribute
		{
			_attributeValues pushBack [_section,_attributeName,_attributeValue,_attributeDisplayName];
		};
	} forEach _children;
} forEach _sections;

_attributeValues