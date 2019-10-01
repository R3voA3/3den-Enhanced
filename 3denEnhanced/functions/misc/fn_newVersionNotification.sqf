/*
	Author: Revo

	Description:
	Shows a notification about the version 4.3.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

waitUntil {isNil "Enh_NotificationShowing"};
Enh_NotificationShowing = true;

if (profileNamespace getVariable ["Enh_NotificationVersion_Seen",false]) exitWith {false}; 

[	//No localisation needed, just a temporary message
	"You are now using version 4.3. The version comes with <t color='#ff0000'>overhauled mission attributes</t>. Upon opening mission attributes for the first time an error message will be shown. You can fix that by re-setting the attributes. Additionally, the <t color='#ff0000'>Task Patrol</t> attribute was updated and needs to be re-set, too.",
	"3den Enhanced v4.3",
	["Roger that",
		{
			profileNamespace setVariable ["Enh_NotificationVersion_Seen",true];
			Enh_NotificationShowing = nil;
		}
	],
	[
		"Cancel",
		{
			Enh_NotificationShowing = nil;
		}
	],
	"\3denEnhanced\data\logoSmall.paa"
] call BIS_fnc_3DENShowMessage;

true