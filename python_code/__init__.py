import glob
import os
import shutil

def RPT_latest():
    path = os.getenv('LOCALAPPDATA') + r"\Arma 3"
    list_of_files = glob.glob(path + r'/*.rpt')

    if len(list_of_files) == 0:
        return ""
    else:
        return max(list_of_files, key = os.path.getctime)

def RPT_name():
    path_to_file = RPT_latest()
    return os.path.basename(path_to_file)

def RPT_size():
    path_to_file = RPT_latest()
    size = os.path.getsize(path_to_file)

    #Convert to kb
    return (size / 1024)

def RPT_read(line_count):
    path_to_file = RPT_latest()
    if path_to_file == "":
     return "No Files found!"
    RPT_file = open(path_to_file, encoding="utf-8")
    content = RPT_file.readlines()
    number_of_lines = len(content)

    if line_count > number_of_lines:
        line_count = number_of_lines

    start_index = number_of_lines - line_count
    print(start_index)
    RPT_content = ""

    counter = 0
    while start_index + counter < number_of_lines:
     RPT_content += content[start_index + counter]
     counter += 1
    RPT_file.close()
    return RPT_content

def BackupMissionSQM(missionroot, backuproot, prefix, timestamp):

    backupFolderPath = backuproot + "\\"

    if (not os.path.exists(backupFolderPath)):
        os.makedirs (backupFolderPath)

    shutil.copyfile(missionroot + "\\mission.sqm", backuproot + "\\"+ prefix + "mission.sqm" + "_" + timestamp)

def CommandPalette_Read_File(path):
    if not os.path.exists(path):
        return ""

    with open(path, 'r', encoding='utf-8') as file:
        content = file.read()

    return content
