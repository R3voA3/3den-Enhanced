#include "\x\enh\addons\main\script_component.hpp"

false call ENH_fnc_garrison_draw;

remove3DENEventHandler ["OnBeforeMissionPreview", if (!isNil "ENH_Garrison_OnBeforeMissionPreview_EH") then {ENH_Garrison_OnBeforeMissionPreview_EH} else {-1}];
remove3DENEventHandler ["OnMissionNew", if (!isNil "ENH_Garrison_OnBeforeMissionPreview_EH") then {ENH_Garrison_OnMissionNew_EH} else {-1}];
remove3DENEventHandler ["OnMissionLoad", if (!isNil "ENH_Garrison_OnBeforeMissionPreview_EH") then {ENH_Garrison_OnMissionLoad_EH} else {-1}];
remove3DENEventHandler ["OnTerrainNew", if (!isNil "ENH_Garrison_OnBeforeMissionPreview_EH") then {ENH_Garrison_OnTerrainNew_EH} else {-1}];
remove3DENEventHandler ["OnSelectionChange", if (!isNil "ENH_Garrison_OnSelectionChange_EH") then {ENH_Garrison_OnSelectionChange_EH} else {-1}];
remove3DENEventHandler ["OnDeleteUnits", if (!isNil "ENH_Garrison_OnDeleteUnits_EH") then {ENH_Garrison_OnDeleteUnits_EH} else {-1}];

delete3DENEntities [if (!isNil "ENH_Garrison_AreaHelper") then {ENH_Garrison_AreaHelper} else {objNull}];

profileNamespace setVariable ["ENH_Garrison_Classes", ctrlText (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_GARRISON_BLACKLIST_VALUE)];
saveProfileNamespace;

ctrlDelete (findDisplay IDD_DISPLAY3DEN displayCtrl IDC_GARRISON_GROUP);
