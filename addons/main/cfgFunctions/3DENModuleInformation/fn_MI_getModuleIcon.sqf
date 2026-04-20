params ["_cfgModule"];
// TODO: header 2025-10-06 R3vo
private _configName = configName _cfgModule;
private _cfgVehicles = configFile >> "CfgVehicles";
private _icon = "";

call
{
    // Get it from vehicle class
    if (isClass (_cfgVehicles >> _configName)) exitWith
    {
        _icon = getText (configFile >> "CfgVehicles" >> _configName >> "icon");
    };

    // Get it from vehicle class that is defined in module config
    if (_icon == "" && {getText (_cfgModule >> "vehicle") != ""}) exitWith
    {
        _icon = getText (_cfgVehicles >> (getText (_cfgModule >> "vehicle")) >> "icon");
    };

    // Get it from empty detector (for triggers) class that is defined in module config
    // if (_icon == "" && {getText (_cfgModule >> "vehicle") != ""}) exitWith
    // {
    //     _icon = getText (configFile >> "CfgNonAIVehicles" >> (getText (_cfgModule >> "vehicle")) >> "icon");
    // };

    // Get it from module config
    if (_icon == "") exitWith
    {
        _icon = getText (_cfgModule >> "icon");
    };
};

// Check if we have a file or need to convert it
if (_icon != "" && {!fileExists _icon}) then
{
    _icon = getText (configFile >> "CfgVehicleIcons" >> _icon);
};

// Last resort, if it's not a file we hardcode it
if (!fileExists _icon) then
{
    _icon = switch (_configName) do
    {
        case "TriggerUnlock";
        case "TriggerLock";
        case "TriggerArea": {"a3\3den\data\displays\display3den\panelright\modetriggers_ca.paa"};
        default {"a3\weapons_f\data\placeholder_co.paa"};
    };
};

_icon
