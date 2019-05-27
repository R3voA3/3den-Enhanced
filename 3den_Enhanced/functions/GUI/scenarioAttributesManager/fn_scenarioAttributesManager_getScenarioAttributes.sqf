/*
   Author: R3vo

   Date:  2019-05-27

   Description:
   Used by the Enh_Enh_ScenarioAttributesManager GUI.
   Returns all Scenario Attributes.

   Parameter(s):
   -

   Returns:
   ARRAY: Array in format [["section","attributeName",attributeValue]]
*/
private _attributeValues = [];
private _sections = [configfile >> "Cfg3DEN" >> "Mission",0,false] call BIS_fnc_returnChildren;
private _attributeName = "";
private _value = 0;

{
	private _section = configName _x;
	private _children = [configfile >> "Cfg3DEN" >> "Mission" >> _section >> "AttributeCategories",2,false] call BIS_fnc_returnChildren;
	{
		_attributeName = getText (_x >> "data");
		private _attributeValue = _section get3DENMissionAttribute _attributeName;//By default get _attributeValue by data config entry
		if (isNil "_attributeValue") then
		{
			_attributeName = configName _x;
			_attributeValue = _section get3DENMissionAttribute _attributeName;//If _attributeValue is nil, try to get it by the attribute name
			if (isNil "_attributeValue") then
			{
				_attributeName = getText (_x >> "property");
				_attributeValue = _section get3DENMissionAttribute _attributeName;//If data is still nil, use property config entry

			};
		};
		if (!isNil "_attributeValue") then
		{
			_attributeValues pushBack [_section,_attributeName,_attributeValue];
		};
	} forEach _children;
} forEach _sections;

_attributeValues