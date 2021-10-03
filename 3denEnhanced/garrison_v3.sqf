ENH_Garrison_Center = get3DENSelected "Object" # 0;

ENH_Garrison_Center setVariable ["ENH_OldBuilding", objNull];

ENH_Garrison_Center addEventHandler ["dragged3DEN",
{
	private _buildings = nearestTerrainObjects [ENH_Garrison_Center, ["HOUSE", "BUILDING"], 10, true, true] select {_x buildingPos -1 isNotEqualTo []};
	if (_buildings isNotEqualTo []) then
	{
		_currBuilding = _buildings # 0;
		if ((ENH_Garrison_Center getVariable ["ENH_OldBuilding", objNull]) isEqualTo _currBuilding) exitWith {systemChat "No new building!"};
		ENH_Garrison_Center setVariable ["ENH_OldBuilding", _currBuilding];
		ENH_Garrison_Center setVariable ["ENH_CurrBuilding", _currBuilding];

		private _ehDraw3D = missionNamespace getVariable ["ENH_Garrison_Draw3D", -1];
		if (_ehDraw3D == -1) then
		{
			_ehDraw3D = addMissionEventHandler ["Draw3D",
			{
				private _building = ENH_Garrison_Center getVariable ["ENH_CurrBuilding", objNull];

				private _bbox = boundingBoxReal _building;

				_bbox params ["_point1","_point2"];

				_point1 params ["_x1","_y1","_z1"];
				_point2 params ["_x2","_y2","_z2"];

				_a = (_building modelToWorldVisual [_x1,_y1,_z1]);
				_b = (_building modelToWorldVisual [_x2,_y1,_z1]);
				_c = (_building modelToWorldVisual [_x2,_y1,_z2]);
				_d = (_building modelToWorldVisual [_x1,_y1,_z2]);
				_e = (_building modelToWorldVisual [_x1,_y2,_z1]);
				_f = (_building modelToWorldVisual [_x2,_y2,_z1]);
				_g = (_building modelToWorldVisual [_x2,_y2,_z2]);
				_h = (_building modelToWorldVisual [_x1,_y2,_z2]);

				private _edges =
				[
					[_a,_b,[0,0,0,1]],
					[_b,_c,[0,0,0,1]],
					[_c,_d,[0,0,0,1]],
					[_d,_a,[0,0,0,1]],
					[_e,_f,[0,0,0,1]],
					[_f,_g,[0,0,0,1]],
					[_g,_h,[0,0,0,1]],
					[_h,_e,[0,0,0,1]],
					[_a,_e,[0,0,0,1]],
					[_b,_f,[0,0,0,1]],
					[_c,_g,[0,0,0,1]],
					[_d,_h,[0,0,0,1]]
				];

				_buildingPositions = (_building buildingPos -1);
				systemChat str _buildingPositions;
				{
					drawIcon3D
					[
						"\A3\modules_f\data\iconStrategicMapMission_ca.paa",
						[1, 0.1, 1, 1],
						_x,
						0.5,
						0.5,
						0,
						str _forEachIndex
					];
				} forEach _buildingPositions;
				//systemChat str format ["Object: %1, BBox: %2", (ENH_Garrison_Center getVariable ["ENH_CurrBuilding", objNull]), _edges];

				{drawLine3D _x} forEach _edges;
			}];
			missionNamespace setVariable ["ENH_Garrison_Draw3D", _ehDraw3D];
		};
	};
}];

ENH_Garrison_Center addEventHandler ["AttributesChanged3DEN",
{
	private _building = ENH_Garrison_Center getVariable ["ENH_OldBuilding", objNull];
	if (isNull _building) exitWith {systemChat "No building available"};


	private _buildingPositions = _building buildingPos -1;
	private _selectedEntities = call ENH_fnc_all3DENSelected;
	private _source = if (count _buildingPositions <= count _selectedEntities) then
	{
		{
			(_selectedEntities # _forEachIndex) set3DENAttribute ["Position", _x];
		} forEach _buildingPositions;
	}
	else
	{
		{
			(_buildingPositions # _forEachIndex) set3DENAttribute ["Position", _x];
		} forEach _selectedEntities;
	};
}];