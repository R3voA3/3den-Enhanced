#include "\x\enh\addons\main\script_component.hpp"

/*
    Author: R3vo

    Date: 2021-10-11

    Description:
    Makes sure menu strip entries are properly checked.

    Parameter(s):
    -

    Returns:
    -
*/

disableSerialization;

private _display = uiNamespace getVariable ["ENH_Display_FunctionsViewer", displayNull];
private _ctrlMenu = CTRL(IDC_FUNCTIONSVIEWER_MENU);
private _configIndex = profileNamespace getVariable ["ENH_FunctionsViewer_ConfigIndex", 0];
private _modeIndex = profileNamespace getVariable ["ENH_FunctionsViewer_ModeIndex", 0];
private _loadFileIndex = profileNamespace getVariable ["ENH_FunctionsViewer_LoadFileIndex", 0];
private _showOtherFiles = profileNamespace getVariable ["ENH_FunctionsViewer_ShowOtherFiles", false];

for "_i" from 0 to 13 do
{
    _ctrlMenu menuSetCheck [[0, _i], false];
    _ctrlMenu menuEnable [[0, _i], true];
};

// Config mode or other file mode
_ctrlMenu menuSetCheck [[0, 0], _configIndex == 0 && !_showOtherFiles];
_ctrlMenu menuSetCheck [[0, 1], _configIndex == 1 && !_showOtherFiles];
_ctrlMenu menuSetCheck [[0, 2], _configIndex == 2 && !_showOtherFiles];
_ctrlMenu menuSetCheck [[0, 3], _showOtherFiles];

// Display mode of files (full, categories, functions only)
_ctrlMenu menuSetCheck [[0, 5], _modeIndex == 0];
_ctrlMenu menuSetCheck [[0, 6], _modeIndex == 1];
_ctrlMenu menuSetCheck [[0, 7], _modeIndex == 2];

// Load mode (loadFile, preprocessFile, preprocessFileLineNumbers)
_ctrlMenu menuSetCheck [[0, 9], _loadFileIndex == 0];
_ctrlMenu menuSetCheck [[0, 10], _loadFileIndex == 1];
_ctrlMenu menuSetCheck [[0, 11], _loadFileIndex == 2];

// Disable entries that are not available
_ctrlMenu menuEnable [[0, 2], isClass (campaignConfigFile >> "CfgFunction")];
_ctrlMenu menuEnable [[1, 4], getNumber (missionConfigFile >> "allowFunctionsRecompile") > 0 || is3DEN || is3DENPreview];
_ctrlMenu menuEnable [[1, 5], getNumber (missionConfigFile >> "allowFunctionsRecompile") > 0 || is3DEN || is3DENPreview];

// If we load other files then sorting has no effect
_ctrlMenu menuEnable [[0, 5], !_showOtherFiles];
_ctrlMenu menuEnable [[0, 6], !_showOtherFiles];
_ctrlMenu menuEnable [[0, 7], !_showOtherFiles];

if (_modeIndex == 3) then
{
    _ctrlMenu menuSetCheck [[0, 5], false];
    _ctrlMenu menuSetCheck [[0, 6], false];
    _ctrlMenu menuSetCheck [[0, 7], false];
};

// As this function is called everytime a setting is changed we save the namespace here
saveProfileNamespace;
