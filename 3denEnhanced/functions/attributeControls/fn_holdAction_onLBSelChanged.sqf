/*
   Author: R3vo

   Date: 2019-07-15

   Description:
   Used by the hold action attribute. Called when a different template is selected. Calls Enh_fnc_holdAction_onAttributeLoad with differnt _value.

   Parameter(s):
   0: CONTROL - List box control
   1: NUMBER - Selected index

   Returns:
   BOOLEAN: true
*/
/*
params ["_ctrlLB","_selectedIndex"];

#define CTRL_GROUP ctrlParentControlsGroup _ctrlLB

switch {_selectedIndex} do
{
	case 0://Custom, do nothing
	{
		//[CTRL_GROUP,] call Enh_fnc_holdAction_onAttributeLoad;
	};
	case 1:
	{
		private _value =
		[
			"Hack System",
			"\a3\ui_f\data\igui\cfg\holdactions\holdaction_connect_ca.paa",
			"\a3\ui_f\data\igui\cfg\holdactions\holdaction_hack_ca.paa",
			"(_this distance _target < 2)",
			"true",{hint "Hacking started";},
			{hint format ["Decrypting Password:\n%1",selectRandom ["dsf02430","DFJfw0j0)5","jwßkw5ß0´=)§$","ß45?§$=I1JF AF)JASD"]];},
			{hint "Hacking completed";},
			{hint "Hacking stopped";},
			10,
			1000,
			false,
			true
		];
		[CTRL_GROUP,_value] call Enh_fnc_holdAction_onAttributeLoad;
	};
};

true