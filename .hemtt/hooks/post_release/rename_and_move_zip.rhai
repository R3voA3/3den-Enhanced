// Renames zip file of release and deletes unused zip files

// Get releases folder
let releases = HEMTT_RFS.join("releases");

// Get "enh_latest.zip" file
let prefix = HEMTT.project().prefix();
let src = releases.join(prefix + "-latest.zip");

// Set file name to vX.X.X
let version = HEMTT.project().version();
let dst = releases.join("v" + version + ".zip");

// Sanity check
if src.is_file() // support --no-archive
{
    print("Moving zip to " + dst);
    if !src.move(dst)
    {
        fatal("Failed to move " + src + " to " + dst);
    }
}

// Delete unused "enh-latest.zip"
releases.join(prefix + "-" + version + ".zip").remove_file();
