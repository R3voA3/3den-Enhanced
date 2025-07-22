class DisplaySimulated;
class Display3DENPlace: DisplaySimulated
{
    class ControlsBackground
    {
        class PanelRightCreate: ctrlControlsGroupNoScrollbars
        {
            class Controls
            {
                class Create: ctrlControlsGroupNoScrollbars
                {
                    class Controls
                    {
                        class ModsButton: ctrlCombo
                        {
                            onLoad = "[_this#0] call ENH_fnc_assetBrowser_modFilter";
                        };
                    };
                };
            };
        };
    };
};
