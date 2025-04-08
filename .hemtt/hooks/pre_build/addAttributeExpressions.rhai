// Update version in mod.cpp

// Read the contents of mod.cpp
let attributeFilePath = "/addons/main/attributesMission/addObjectsToZeus.hpp";

let expressionFile = HEMTT_VFS.join("/addons/main/attributeCode/ENH_AddObjectsToZeus_expression.sqf").open_file().read();
let attributeFile = HEMTT_VFS.join(attributeFilePath).open_file().read();

expressionFile.replace('"', "'");

print(expressionFile);

attributeFile.replace("EXPRESSION_PLACEHOLDER", expressionFile);

HEMTT_VFS.join(attributeFilePath).create_file().write(attributeFile);

// // Replace the placeholder version with the actual version
// modcpp.replace("0.0.0", HEMTT.project().version().to_string_short());

// // Write the new contents over the old contents
// HEMTT_VFS.join("mod.cpp").create_file().write(modcpp);
