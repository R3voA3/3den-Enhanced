// Defines ISDEV macro on release, written by jokoho482 modified for 3den Enhanced by R3vo

if (HEMTT.is_release())
{
    // Get "script_component.hpp" file and read it
    let macro_path = HEMTT_VFS.join("addons/main/script_component.hpp");
    let macro_hpp = macro_path.open_file().read();

    // Replace macro definition
    macro_hpp.replace("#define ISDEV", "//#define ISDEV");
    print("ISDEV macro was disabled.");

    // Overwrite existing file with new content
    macro_path.create_file().write(macro_hpp);
}
