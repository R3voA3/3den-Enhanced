class ENH_SPR
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_SPR";
    class Attributes
    {
        class ENH_SPR_Subcategory
        {
            description = "$STR_ENH_MAIN_SPR_DESCRIPTION";
            property = "ENH_SPR_Subcategory";
            control = "ENH_SubCategoryNoHeader2_Fixed";
        };
        class ENH_SPR
        {
            displayName = "$STR_ENH_MAIN_SPR";
            property = "ENH_SPR";
            control = "ENH_SPR";
            expression =
            "if (!is3DEN && _value # 0 > 0 && !isMultiplayer) then\
            {\
                ENH_SPR_Ruleset = _value param [0, 0];\
                ENH_SPR_Delay = _value param [1, 20];\
                ENH_SPR_CanDie = _value param [2, false];\
                ENH_SPR_RestoreLoadout = _value param [3, false];\
                ENH_SPR_OnRespawnCode = compile (_value param [4, '']);\
                ENH_SPR_Positions =\
                [\
                    allMapMarkers select {'respawn_east' in toLower _x} apply {getMarkerPos _x},\
                    allMapMarkers select {'respawn_west' in toLower _x} apply {getMarkerPos _x},\
                    allMapMarkers select {'respawn_guerilla' in toLower _x} apply {getMarkerPos _x},\
                    allMapMarkers select {'respawn_civilian' in toLower _x} apply {getMarkerPos _x}\
                ];\
                {\
                    _x setVariable ['ENH_SPR_OriginalSide', side group _x];\
                    _x setVariable ['ENH_SPR_OriginalLoadout', getUnitLoadout _x];\
                    _x addEventHandler ['handleDamage',\
                    {\
                        params ['_unit', '', '_damage', '', '', '_index'];\
                        if (!alive _unit || lifeState _unit isEqualTo 'INCAPACITATED') exitWith {0};\
                        if (_unit getVariable ['ENH_SPR_Tickets', 0] == 0) then\
                        {\
                            _unit removeEventHandler ['handleDamage', _thisEventHandler];\
                            _damage;\
                        };\
                        if (ENH_SPR_CanDie && _index in [1, 2] && _damage >= 1) exitWith\
                        {\
                            _unit removeEventHandler ['handleDamage', _thisEventHandler];\
                            1;\
                        };\
                        if (_index < 8 && (_damage min 0.95) == 0.95) then\
                        {\
                            setAccTime 1;\
                            _unit allowDamage false;\
                            _unit setCaptive true;\
                            _unit setUnconscious true;\
                            _unit setVariable ['ENH_SPR_Tickets', (_unit getVariable ['ENH_SPR_Tickets', 0]) - 1];\
                            if (isPlayer _unit) then {enableTeamSwitch false} else {removeSwitchableUnit _unit};\
                            moveOut _unit;\
                            _unit spawn ENH_fnc_SPR_respawnTimer;\
                        };\
                        _damage min 0.95;\
                    }];\
                } forEach (allUnits select {_x getVariable ['ENH_SPR_Tickets', 0] > 0});\
                \
                ENH_fnc_SPR_respawn =\
                {\
                    scriptName 'ENH_Attribute_SPR_Respawn';\
                    params ['_unit'];\
                    if (isPlayer _unit) then {enableTeamSwitch true} else {addSwitchableUnit _unit};\
                    if (ENH_SPR_RestoreLoadout) then {_unit setUnitLoadout (_unit getVariable 'ENH_SPR_OriginalLoadout')};\
                    private _sideID = (_unit getVariable 'ENH_SPR_OriginalSide') call BIS_fnc_sideID;\
                    private _positions = ENH_SPR_Positions select _sideID;\
                    if (_positions isNotEqualTo []) then\
                    {\
                        switch (ENH_SPR_Ruleset) do\
                        {\
                            case 3:\
                            {\
                                _unit setPos (([_positions, [], {_unit distance _x}, 'ASCEND'] call BIS_fnc_sortBy) select 0);\
                            };\
                            case 2:\
                            {\
                                _unit setPos selectRandom _positions;\
                            };\
                        };\
                    };\
                    _unit setUnconscious false;\
                    _unit allowDamage true;\
                    _unit setDamage 0;\
                    _unit switchMove '';\
                    _unit call ENH_SPR_OnRespawnCode;\
                    _unit spawn\
                    {\
                        sleep 8;\
                        _this setCaptive false;\
                    };\
                };\
                \
                ENH_fnc_SPR_respawnTimer =\
                {\
                    scriptName 'ENH_Attribute_SPR_RespawnTimer';\
                    params ['_unit'];\
                    private _respawnTime = time + ENH_SPR_Delay;\
                    if (isPlayer _unit) then\
                    {\
                        private _ctrlRespawnTimer = (call BIS_fnc_displayMission) ctrlCreate ['RscStructuredText',-1];\
                        _ctrlRespawnTimer ctrlSetPosition [0.25, 0, 0.5, 0.06];\
                        _ctrlRespawnTimer ctrlSetBackgroundColor [0, 0, 0, 0.1];\
                        _ctrlRespawnTimer ctrlCommit 0;\
                        ENH_SPR_OriginalVolume = [soundVolume, musicVolume, radioVolume, speechVolume, environmentVolume];\
                        0 cutText ['', 'BLACK OUT', 0.3];\
                        0.3 fadeSound 0;\
                        0.3 fadeMusic 0;\
                        0.3 fadeRadio 0;\
                        0.3 fadeSpeech 0;\
                        0.3 fadeEnvironment 0;\
                        showChat false;\
                        while {time < _respawnTime} do\
                        {\
                            _ctrlRespawnTimer ctrlSetStructuredText parseText format ['<t size=''1.25'' color=''#218a36'' align=''center''>%1</t>', [(_respawnTime - time), 'HH:MM'] call BIS_fnc_timeToString];\
                            sleep 0.1;\
                        };\
                        ctrlDelete _ctrlRespawnTimer;\
                        0 cutText ['', 'BLACK IN', 8];\
                        8 fadeSound (ENH_SPR_OriginalVolume # 0);\
                        8 fadeMusic (ENH_SPR_OriginalVolume # 1);\
                        8 fadeRadio (ENH_SPR_OriginalVolume # 2);\
                        8 fadeSpeech (ENH_SPR_OriginalVolume # 3);\
                        8 fadeEnvironment (ENH_SPR_OriginalVolume # 4);\
                        showChat true;\
                        [\
                            ['Respawned'],\
                            [format ['GRID: %1', mapGridPosition _unit]],\
                            [format ['Tickets left: %1', _unit getVariable 'ENH_SPR_Tickets']]\
                        ] spawn BIS_fnc_EXP_camp_SITREP;\
                    }\
                    else\
                    {\
                        private _respawnEH = -1;\
                        if ((side player getFriend (_unit getVariable 'ENH_SPR_OriginalSide')) >= 0.6) then\
                        {\
                            _respawnEH = addMissionEventHandler\
                            [\
                                'draw3D',\
                                {\
                                    drawIcon3D ['\a3\Modules_f\data\portraitRespawn_ca.paa', [0.13, 0.54, 0.21, 0.8], ASLToAGL ((_thisArgs # 0) modelToWorldVisualWorld [0, 0, 1]), 1, 1, 0, str round ((_thisArgs # 1) - time), 2];\
                                },\
                                [_unit, _respawnTime]\
                            ];\
                        };\
                        sleep ENH_SPR_Delay;\
                        removeMissionEventHandler ['draw3D', _respawnEH];\
                        [str _unit, 'onEachFrame'] call BIS_fnc_removeStackedEventHandler;\
                    };\
                    _unit call ENH_fnc_SPR_respawn;\
                };\
            }";
            defaultValue = "[0, 20, false, false, '']";
        };
    };
};
