if (_value isEqualType true) then {_value = 2};\
if (!is3DEN && isServer && _value > 0) then\
{\
    _value spawn\
    {\
        params ["_value"];\
        waitUntil {sleep 1; allCurators isNotEqualTo []};\
        if (_value == 1 || _value == 2) then\
        {\
            allCurators apply {_x addCuratorEditableObjects [allMissionObjects "", true]};\
        };\
        if (_value == 2) then\
        {\
            addMissionEventHandler ["EntityCreated",\
            {\
                params ["_entity"];\
                allCurators apply {_x addCuratorEditableObjects [[_entity], true]};\
            }];\
        };\
    };\
};\
