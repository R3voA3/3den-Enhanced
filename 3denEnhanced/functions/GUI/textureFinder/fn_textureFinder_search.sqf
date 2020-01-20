/*
   Author: R3vo

   Date: 2020-01-21

   Description:
   Used to search listBox of Texture Viewer.

   Parameter(s):
   0: CONTROL - Button control

   Returns:
   BOOLEAN: true
*/

#define TEXTURE_SEARCH_START "\a3\3DEN\Data\Displays\Display3DEN\search_start_ca.paa"
#define TEXTURE_SEARCH_END "\a3\3DEN\Data\Displays\Display3DEN\search_end_ca.paa"

params ["_ctrlButton"];

private _display = ctrlParent _ctrlButton;
private _ctrlLB = _display displayCtrl 1500;
private _ctrlSearch = _display displayCtrl 1600;
private _ctrlSearchButton = _display displayCtrl 1700;

private _lbSize = lbSize _ctrlLB;
private _searchFor = toLower ctrlText _ctrlSearch;

if (isNil "Enh_TextureFinder_SearchStarted") then 
{
		private _toDelete = [];
		_ctrlSearchButton ctrlSetText TEXTURE_SEARCH_END;

		for "_i" from 0 to _lbSize -1 do
		{
			if !(_searchFor in toLower (_ctrlLB lbText _i)) then 
			{
				_toDelete pushBack _i;
			};
		};

		//Delete highest index first so indexes won't change after deletion
		reverse _toDelete;

		{	
			_ctrlLB lbDelete _x;
		} forEach _toDelete;
		Enh_TextureFinder_SearchStarted = true;
}
else
{
		_ctrlSearch ctrlSetText "";
		_ctrlSearchButton ctrlSetText TEXTURE_SEARCH_START;

		[] spawn Enh_fnc_textureFinder_fillTextureLB;
		Enh_TextureFinder_SearchStarted = nil;
};

true