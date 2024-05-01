// class ENH_MenuStripBlacklist: Title
// {
//   attributeLoad = "[_this] call ENH_fnc_menuStripBlacklist_onAttributeLoad";
//   attributeSave = "";
//   h = QUOTE(9.5 * CTRL_DEFAULT_H + 10 * pixelH);
//   class Controls: Controls
//   {
//     class Title: Title {};
//     class Value: ctrlListbox;
//     {
//       idc = 100;
//       x = QUOTE(ATTRIBUTE_TITLE_W * GRID_W);
//       w = QUOTE(ATTRIBUTE_CONTENT_W * GRID_W);
//       h = QUOTE(8.5 * CTRL_DEFAULT_H);
//     };
//     class Reset: ENH_ResetButton_Base
//     {
//       y = QUOTE(8.5 * CTRL_DEFAULT_H + 5 * pixelH);
//     };
//   };
// };