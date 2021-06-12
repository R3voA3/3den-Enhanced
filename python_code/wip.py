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