#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2019-08-20

    Description:
    Retrieves data of currently used Arma 3 version and formats this information so it can directly be used in bug reports or similar.

    Parameter(s):
    -

    Returns:
    -
*/

private _patches = "true" configClasses (configFile >> "CfgPatches");
private _name = "";

_patches = _patches apply
{
    _name = getText (_x >> "name");
    if (_name == "") then
    {
        configName _x
    }
    else
    {
        _name
    };
};

_patches sort true;

private _textProductInfo = format
[
    "Game: %1 (%2)" +
    endl +
    "Version: %3.%4" +
    endl +
    "Branch: %5" +
    endl +
    "Mods enabled: %6" +
    endl +
    "Operating System: %7" +
    endl +
    "Architecture: %8" +
    endl +
    "Steam Branch: %9",
    productVersion # 0,
    productVersion # 1,
    (productVersion # 2) / 100,
    productVersion # 3,
    productVersion # 4,
    productVersion # 5,
    productVersion # 6,
    productVersion # 7,
    productVersion # 8
];

private _textResolution = format
[
    "UI:" +
    endl +
    "Width: %1" +
    endl +
    "Height: %2" +
    endl +
    "View Port Width: %3" +
    endl +
    "View Port Height: %4" +
    endl +
    "Aspect Ratio: %5" +
    endl +
    "UI Scale: %6" +
    endl +
    "FOV Top: %7" +
    endl +
    "FOV Left: %8" +
    endl +
    "Triple Head Enabled: %9" +
    endl +
    "Texture Quality: %10",
    getResolution # 0,
    getResolution # 1,
    getResolution # 2,
    getResolution # 3,
    getResolution # 4,
    getResolution # 5,
    getResolution # 6,
    getResolution # 7,
    getResolution # 8,
    getResolution # 9
];

private _textVideoSettings = "";

{
    _textVideoSettings = _textVideoSettings + format ["%1: %2" + endl, _x, _y];
} forEach getVideoOptions;

private _text = format
[
    "%1" +
    endl +
    endl +
    "%2" +
    endl +
    endl +
    "Video Options:" +
    endl +
    "%3" +
    endl +
    "Mods:" +
    endl +
    "%4",
    _textProductInfo,
    _textResolution,
    _textVideoSettings,
    _patches joinString endl
];

uiNamespace setVariable ["display3DENCopy_data", ["", _text]];
findDisplay IDD_DISPLAY3DEN createDisplay "display3denCopy";
