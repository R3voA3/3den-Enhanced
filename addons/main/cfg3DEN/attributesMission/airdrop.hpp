class ENH_Airdrop
{
    collapsed = 1;
    displayName = "$STR_ENH_MAIN_AIRDROP_DISPLAYNAME";
    class Attributes
    {
        class ENH_Airdrop_Subcategory
        {
            description = "$STR_ENH_MAIN_AIRDROP_DESCRIPTION";
            property = "ENH_Airdrop_Subcategory";
            control = "ENH_SubCategoryNoHeader2_Fixed";
        };
        class ENH_Airdrop
        {
            displayName = "$STR_ENH_MAIN_AIRDROP_DISPLAYNAME";
            property = "ENH_Airdrop";
            control = "ENH_Airdrop";
            expression =
            "\
                if (!is3DEN && ((_value # 0) isNotEqualTo []) && isServer) then\
                {\
                    _value spawn\
                    {\
                        scriptName 'ENH_Attribute_Airdrop';\
                        params ['_classes', '_center', '_condition', '_alt', '_r', '_side'];\
                        _condition = compile _condition;\
                        waitUntil {sleep 1; call _condition};\
                        private _group = createGroup _side;\
                        playSound3D ['A3\Data_F_Warlords\sfx\flyby.wss', objNull, false, _center vectorAdd [0, 0, 100], 2.5];\
                        ENH_Airdrop_Units = [];\
                        {\
                            _center set [2, _center # 2 + random [-20, 0, 20]];\
                            private _unit = _group createUnit [_x, _center, [], 0, 'NONE'];\
                            private _para = createVehicle ['Steerable_Parachute_F', _center getPos [_r * sqrt random 1, random 360], [], 0, 'FLY'];\
                            _unit moveInDriver _para;\
                            ENH_Airdrop_Units pushBack _unit;\
                        } forEach _classes;\
                    };\
                }";
            defaultValue = "[[], [0, 0, 0], 'false', 500, 200, west]";
        };
    };
};
