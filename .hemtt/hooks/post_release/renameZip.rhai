//Rename zipped file to old 3den Enhanced standard
let releases = HEMTT_RFS.join("releases");
let src = releases.join(HEMTT.project().prefix() + "-latest.zip");
let dst = releases.join("@" + HEMTT.project().name() + " v" + HEMTT.project().version() + ".zip");

if src.is_file()
{ // support --no-archive
	if !src.move(dst)
	{
		fatal("Failed to move " + src + " to " + dst);
	}
	else
	{
		print("Zip file created: " + dst)
	}
}