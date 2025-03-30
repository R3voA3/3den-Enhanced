const ROOT = HEMTT_RFS;
const TODO_TAG = "//TODO";
const ALLOWED_EXTENSIONS = ["hpp", "ext", "sqf", "xml", "txt", "inc", "rhai"];

fn get_folders(path) {
    if (path.to_string().contains("/.hemttout/") != true) {
        let folders = path.list();

        for item in folders {
            if (item.is_dir()) {
                get_folders(item);
            } else {
                if (is_extension_allowed(item)) {
                    read_file(item);
                }
            };
        };
    };
};

fn read_file(path) {
    let fileContent = path.open_file().read();
    let fileLines = fileContent.to_string().split("\n"); // Split at each new line to get line index
    let lineIndex = 1;

    for line in fileLines {
        let columnIndex = line.to_string().index_of(global::TODO_TAG, 0);

        while columnIndex > -1 {
            print_path(path, lineIndex, columnIndex);
            columnIndex = line.to_string().index_of(global::TODO_TAG, columnIndex + global::TODO_TAG.len());
        };

        lineIndex += 1;
    };
};

fn is_extension_allowed(path) {
    let extension = path.to_string().split(".").get(-1);
    global::ALLOWED_EXTENSIONS.contains(extension);
};

fn print_path(path, lineIndex, columnIndex) {
    let pathArray = path.to_string().split(global::ROOT.to_string() + "/");

    print ("To-Do entry found in: " + pathArray.get(-1) +
    ":" + lineIndex.to_string() + ":" + columnIndex.to_string());
}

get_folders(global::ROOT);
