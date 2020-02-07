/*
	Author: Revo

	Description:
	Shows a notification about the version 4.3.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true
*/

waitUntil {isNil "ENH_NotificationShowing"};
ENH_NotificationShowing = true;

if (profileNamespace getVariable ["ENH_NotificationVersion_Seen",false]) exitWith {false}; 

[	//No localisation needed, just a temporary message
	"You are now using version 4.3. The version comes with <t color='#ff0000'>overhauled mission attributes</t>. Upon opening mission attributes for the first time an error message will be shown. You can fix that by re-setting the attributes. Additionally, the <t color='#ff0000'>Task Patrol</t> attribute was updated and needs to be re-set, too.",
	"3den Enhanced v4.3",
	["Roger that",
		{
			profileNamespace setVariable ["ENH_NotificationVersion_Seen",true];
			ENH_NotificationShowing = nil;
		}
	],
	[
		"Cancel",
		{
			ENH_NotificationShowing = nil;
		}
	],
	"\3denEnhanced\data\logoSmall.paa"
] call BIS_fnc_3DENShowMessage;

true