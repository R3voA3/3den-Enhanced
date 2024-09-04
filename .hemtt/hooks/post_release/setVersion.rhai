// Updates mod version in mod.cpp

let strVersion = HEMTT.project().version().to_string();
let destination = HEMTT_OUT.join("version.txt");

destination.create_file().write(strVersion);

// Update version in mod.cpp
let strFileContent = HEMTT_OUT.join("mod.cpp").open_file().read();
strFileContent.replace("0.0.0", strVersion);
HEMTT_OUT.join("mod.cpp").create_file().write(strFileContent);