# from pathlib import Path
import glob

def findFilesSpecific():
    matches = \
        glob.glob("**\*.cpp", recursive=True) + \
        glob.glob("**\*.hpp", recursive=True) + \
        glob.glob("**\*.py", recursive=True) + \
        glob.glob("**\*.inc", recursive=True) + \
        glob.glob("**\*.ps1", recursive=True) + \
        glob.glob("**\*.md", recursive=True) + \
        glob.glob("**\*.bat", recursive=True) + \
        glob.glob("**\*.xml", recursive=True)

    for x in matches:
        checkForEmptyLastLine(x)

def checkForEmptyLastLine(path):
    last_line = ""

    try:
        file = open(path, 'r+')

        with file as f:
            for line in f:
                pass
            last_line = line

            lines = last_line.split("\n")

            # Check if we were able to split it. If not, we need to add a final line
            # However, if list is > 2 and 2nd entry is "" then we have an empty line already
            if (len(lines) < 2 or (lines[1] != "")):
                    f.write("\n")
    except:
        file.close

findFilesSpecific()
