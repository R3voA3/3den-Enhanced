/*
	Author: Revo

	Description:
	Logs all mission attribute values to the clipboard.

	Parameter(s):
	-

	Returns:
	ARRAY - All scenario attributes
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
		_attributeValue = _section get3DENMissionAttribute _attributeName;//By default get value by data config entry
		if (isNil "_attributeValue") then
		{
			_attributeName = configName _x;
			_attributeValue = _section get3DENMissionAttribute _attributeName;//If value is nil, try to get it by the attribute name
			if (isNil "_attributeValue") then
			{
				_attributeName = getText (_x >> "property");
				_attributeValue = _section get3DENMissionAttribute _attributeName;//If data is still nil, use property config entry

			};
		};
		if !(isNil "_attributeValue") then//If there are still values which are nil, they are either categories, internal oder never fully implemented attributes by BIS
		{
			_attributeValues pushBack [_section,_attributeName,_attributeValue];
		};
	} forEach _children;
} forEach _sections;

private _export = [_attributeValues] call Enh_fnc_exportWithLB;

copyToClipboard _export;
["Enh_DataCopied"] call BIS_fnc_3DENNotification;

_export