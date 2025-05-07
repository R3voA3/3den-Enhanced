// Read the contents of mod.cpp
// let attributeFilePath = "addons/main/attributesMission/addObjectsToZeus.hpp";

// let expressionFile = HEMTT_RFS.join("/addons/main/attributeCode/addObjectsToZeus_expression.sqf").open_file().read();
let expressionFile = HEMTT_RFS.join("addons/main/attributeCode/addObjectsToZeus_expression.sqf").open_file().read();
// let attributeFile = HEMTT_RFS.join(attributeFilePath).open_file().read();

while expressionFile.contains("  ") {
    expressionFile.replace("  ", " ");
    print("1");
};

expressionFile.replace('"', "'");
expressionFile.replace("\r\n ", "");
expressionFile.replace("\r\n", "");
expressionFile.replace("\\", "");
expressionFile.replace("{ ", "{");
expressionFile.replace(" }", "}");
expressionFile.replace("; ", ";");

// HEMTT_OUT.create_file("test.txt");
HEMTT_OUT.join("version.txt").create_file().write(expressionFile);
// attributeFile.replace("EXPRESSION_PLACEHOLDER", expressionFile);

// print ((HEMTT_RFS).join("addons/main/attributeCode/addObjectsToZeus_expression.sqf"));
