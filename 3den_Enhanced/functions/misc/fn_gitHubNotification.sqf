/*
   Author: Revo

   Description:
   Shows a notification about the GitHub repository for 3den Enhanced.

   Parameter(s):
   -
   Returns:
  BOOLEAN -  true
*/

if (profileNamespace getVariable ["Enh_NotificationGithub_Seen",false]) exitWith {false}; 

[
	"3den Enhanced is now available on GitHub. Go to <t color='#ff0000'>Menu Strip -> About -> Help Translating (GitHub)...</t> or <t colorLink='#ff0000'><a href='https://github.com/RevoArma3/3den-Enhanced'>CLICK HERE</a></t>. Add your own ideas, translations or fix bugs. Have fun!",
	"3den Enhanced on GitHub",
	["Roger that",
		{
			profileNamespace setVariable ["Enh_NotificationGithub_Seen",true];
		}
	],
	"Cancel",
	"\3denEnhanced\data\Enh_logoSmall.paa"
] call BIS_fnc_3DENShowMessage;

true