private _data =  //[<items>, <weapons>, <magazines>, <backpacks>]
[
  [],
  [],
  [],
  []
];

private _fnc_traverseChildren =
{
  params ["_path"];

  for "_i" from 0 to (_ctrlTV tvCount _path) do
  {
    private _newPath = _path + [_i];

    if (count _newPath == 3) then
    {
    if (_ctrlTV tvValue _newPath > 0) then
    {
      private _category = (uiNamespace getVariable ["ENH_ESE_itemsHashMap", createHashMap]) get (_ctrlTV tvData _newPath) select 4;
      diag_log _category;
    };
    };

    if (_ctrlTV tvCount _newPath > 0) then
    {
    [_newPath] call _fnc_traverseChildren;
    };
  };
};

[[]] call _fnc_traverseChildren;