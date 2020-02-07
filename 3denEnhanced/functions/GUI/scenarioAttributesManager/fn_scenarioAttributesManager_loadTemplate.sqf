/*
   Author: R3vo

   Date: 2019-05-24

   Description:
   Used by the ENH_ENH_ScenarioAttributesManager_TemplateData GUI. 
   Loads the data from currently selected item from template listbox and adds it to the tree view.
   
   Parameter(s):
   0: CONTROL - Control listbox
   1: NUMBER - Index of selected item

   Returns:
   BOOLEAN: true / false
*/

params ["_ctrlLB","_selectedItem"];

private _display = ctrlParent _ctrlLB;
private _ctrlTV = _display displayCtrl 1500;

tvClear _ctrlTV;

//Get only the data stored in the selected item
private _templateData = _ctrlLB lbData _selectedItem;

//Attributes are stored as string. Call and compile them to convert them to an array
_templateData = call compile _templateData;
_attributes = _templateData # 2;

if (_templateData isEqualTo []) exitWith {false};

//Add base categories and a custom one used for modded attributes
_ctrlTV tvAdd [[],"Intel"];
_ctrlTV tvAdd [[],"Scenario"];
_ctrlTV tvAdd [[],"Multiplayer"];
_ctrlTV tvAdd [[],"GarbageCollection"];
_ctrlTV tvAdd [[],"Preferences"];
_ctrlTV tvAdd [[],"Custom Category"];

//Put all attributes into their corresponding categories
{
	private _baseIndex = switch (_x # 0) do 
	{
		case "Intel": {0};
		case "Scenario": {1};
		case "Multiplayer": {2};
		case "GarbageCollection": {3};
		case "Preferences": {4};
		default {5};
	};
	//_x # 0 => Attribute Section
	//_x # 1 => PropertyName
	//_x # 2 => Attribute Value
	//_x # 3 => Attribute Display Name
	private _index = _ctrlTV tvAdd [[_baseIndex],format ["%1 (%2)",_x # 3,_x # 1]];
	_ctrlTV tvSetData [[_baseIndex,_index],str _x];
	_ctrlTV tvSetTooltip [[_baseIndex,_index],str (_x # 2)];
	_ctrlTV tvSort [[_baseIndex],false];
} forEach _attributes;

true