// Creates a version.txt file after release
// which is then read by the publish.ps1 file

let mod_version = HEMTT.project().version().to_string();
HEMTT_OUT.join("version.txt").create_file().write(mod_version);
