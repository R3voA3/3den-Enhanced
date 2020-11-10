/*
    Author: R3vo

    Date: 2020-10-15

    Description:
    Exports all ENH and ENHO context menu actions in markdown format for the Github 3den Enhanced wiki to the clipboard. Supports two levels.

    Parameter(s):
    -

    Returns:
    BOOLEAN: true
*/

private _menuStipEntries = "configName _x select [0,3] == 'ENH'" configClasses (configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items");
private _export = format ["_**Number of added entries: %1**_",count _menuStipEntries] + endl + "___" + endl + endl + endl;

{
	if !(getArray (_x >> "items") isEqualTo []) then
    {//Main
        private _text = getText (_x >> "text");
        _export = _export + "# " + _text + endl;
        { //Folder
            private _cfg = configFile >> "Display3DEN" >> "Controls" >> "MenuStrip" >> "Items" >> _x;
            private _text = getText (_cfg >> "text");
            private _action = getText (_cfg >> "action");
            private _headline = "### ";
            private _link = getText (_cfg >> "weblink");

            if (_action == "") then
            {
                _export = _export + _headline + _text;
            }
            else
            {
                _export = _export + _headline + _text + endl + "Action: " + "```" + _action + "```";
            };

            if (_link != "") then {_export = _export + endl + "Weblink: " + _link};
            _export = _export + endl + endl;
        } forEach (getArray (_x >> "items"));
    };
} forEach _menuStipEntries;


copyToClipboard _export;

true