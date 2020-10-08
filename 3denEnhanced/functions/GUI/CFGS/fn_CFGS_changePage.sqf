params ["_control", "_selectedIndex"];
_tv = (ctrlParent _control displayCtrl 2000);
_tvFavorites = (ctrlParent _control displayCtrl 4000);

_tv ctrlEnable ([true,false] select _selectedIndex);
_tv ctrlSetFade _selectedIndex;

_tvFavorites ctrlEnable ([false,true] select _selectedIndex);
_tvFavorites ctrlSetFade ([1,0] select _selectedIndex);

_tvFavorites ctrlCommit 0;
_tv ctrlCommit 0;

uiNamespace setVariable ["ENH_CFGS_ActiveList",[_tv,_tvFavorites] select _selectedIndex];

true