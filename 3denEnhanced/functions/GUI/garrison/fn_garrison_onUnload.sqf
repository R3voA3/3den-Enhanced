#include "\3denEnhanced\ENH_defineCommon.hpp"

delete3DENEntities [uiNamespace getVariable ["ENH_Garrison_AreaHelper_3DENID", -1]];
false call ENH_fnc_garrison_drawBuildingInfo;

ctrlDelete (findDisplay IDD_3DEN displayCtrl IDC_GARRISON_GROUP);