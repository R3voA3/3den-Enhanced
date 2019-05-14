[] spawn 
{ 
    disableSerialization; 

    _display = findDisplay 313 createDisplay "RscDisplayEmpty"; 

    _edit = _display ctrlCreate ["RscEdit", 645]; 
    _edit ctrlSetPosition [0,0,1,0.04]; 
    _edit ctrlSetBackgroundColor [0,0,0,1]; 
    _edit ctrlCommit 0; 

    _tv = _display ctrlCreate ["RscTreeSearch", -1];
    _tv ctrlSetFont "EtelkaMonospacePro";  
    _tv ctrlSetFontHeight 0.03;  
    _tv ctrlSetPosition [0,0.06,1,0.94]; 
    _tv ctrlSetBackgroundColor [0,0,0,1]; 
    _tv ctrlCommit 0; 
    _tv ctrlAddEventHandler ["TreeDblClick",
    {
        params ["_control", "_selectionPath"];
        systemChat (_control tvText _selectionPath);
        switch (_selectionpath # 0) do 
        {
            case 0: {profileNamespace setVariable [(_control tvText _selectionPath),nil]};
            case 1: {missionNamespace setVariable [(_control tvText _selectionPath),nil]};
            case 2: {uiNamespace setVariable [(_control tvText _selectionPath),nil]};
            case 3: {parsingNamespace setVariable [(_control tvText _selectionPath),nil]};
        };
        _control tvDelete _selectionPath;
    }];
	//Profile Namespace
    _tv tvAdd [[],"Profil Namespace Variables"];
    {   
        _tv tvAdd [[0],_x];
        _tv tvSetTooltip [[0,_foreachindex], str (profileNamespace getVariable _x)];
    } forEach (allVariables profileNamespace); 
    _tv tvSort [[0], false];
    systemChat format ["Profil Namespace Variables %1",_tv tvCount [0]];

	//Mission Namespace
    _tv tvAdd [[],"Mission Namespace Variables"];
    {   
        _tv tvAdd [[1],_x];
        _tv tvSetTooltip [[1,_foreachindex], str (missionNamespace getVariable _x)];
        counter = counter + 1;
    } forEach (allVariables missionNamespace);

    _tv tvSort [[1], false];
    systemChat format ["Mission Namespace Variables %1",_tv tvCount [1]];

	//UI Namespace
    _tv tvAdd [[],"UI Namespace Variables"];
    {   
        _tv tvAdd [[2],_x];
        _tv tvSetTooltip [[2,_foreachindex], str (uiNamespace getVariable _x)];
    } forEach (allVariables uiNamespace);

    _tv tvSort [[2], false];
    systemChat format ["UI Namespace Variables %1",_tv tvCount [2]];

	//Parsing Namespace
    _tv tvAdd [[],"Parsing Namespace Variables"];
    {   
        _tv tvAdd [[3],_x];
        _tv tvSetTooltip [[3,_foreachindex], str (uiNamespace getVariable _x)];
    } forEach (allVariables uiNamespace);

    _tv tvSort [[3], false];
    systemChat format ["Parsing Namespace Variables %1",_tv tvCount [3]];
   
 };