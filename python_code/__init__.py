from pathlib import Path
import glob
import os
import re

path = r"C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR\description.ext"
pathSounds = r"C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR\sounds"

def read_descriptionExt(path):
  try:
    file = open(path)
    content = file.readlines()
    file.close()
    return content
  except:
    file = open(path, 'x+')
    content = file.readlines()
    file.close()
  return content

def write_descriptionExt(path, content):
  file = open(path, 'w+')
  file.writelines(content)
  file.close()
  return True

def EXT_read(path_to_file):
  path_to_file = str(path_to_file).replace("\\", "/") # Convert path
  if os.path.exists(path_to_file):
    EXT_file = open(path_to_file, encoding="utf-8")
    content = ""
    for line in EXT_file.readlines():
      content += line
    print(content)
    return content
  else:
    return ("File {} does not exist!".format(path_to_file))

def findSoundFiles(path):
 # try:
   soundFolder = Path(path).iterdir()
   text = "class CfgMusic\n{\n\ttracks[] = {};\n"
   for soundFile in soundFolder:
    text = text + "\tclass " + soundFile.name + "\n" + "\t{\n" + "\t\tname = " +\
    soundFile.name + "\n" + "\t\tsound[] = " + "\\music\\" + soundFile.name + "\n\t};\n"
   print(text)
  #except:
   print("'sounds' folder does not exist!")
   return "'sounds' folder does not exist!"

#findSoundFiles(pathSounds)

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

def get_mission_files():
  path = r"C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR"
  mission_files = []
  files_and_folders = Path(path).iterdir()

  for item in files_and_folders:
    if item.is_dir():
      folder = Path(item).iterdir()
      files_in_folder = []
      files_in_folder.append(os.path.basename(item))
      #print(os.path.basename(item))
      for file in folder:
        files_in_folder.append(os.path.basename(file))
        #print("|")
        #print("-----" + os.path.basename(file))
      mission_files.append(files_in_folder)
    else:
      mission_files.append(os.path.basename(item))
  #print(mission_files)
  return mission_files

#get_mission_files()