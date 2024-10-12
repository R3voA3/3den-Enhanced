// Update version in mod.cpp

// Read the contents of mod.cpp
let modcpp = HEMTT_VFS.join("mod.cpp").open_file().read();

// Replace the placeholder version with the actual version
modcpp.replace("0.0.0", HEMTT.project().version().to_string_short());

// Write the new contents over the old contents
HEMTT_VFS.join("mod.cpp").create_file().write(modcpp);
