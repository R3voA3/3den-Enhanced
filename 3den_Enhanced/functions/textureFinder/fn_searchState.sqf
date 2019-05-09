/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Checks whether or not search can be started.

	Parameter(s):
	-
	Returns:
	BOOLEAN - true / false
*/

if !(isNil 'Enh_findTextures_handle') then
{
	if (scriptDone Enh_findTextures_handle) then
	{
		true
	}
	else
	{
		[localize "STR_ENH_searchState_pleaseWait",1] call BIS_fnc_3DENNotification;
		false
	};
}
else
{
	true
};