#  Author: R3vo

#  Date: 2020-12-18

#  Description:
#  Scans all mod files for used stringtable keys and compares them with keys in stringtable.xml. All unused keys will be printed
#  in the console.

#  Parameter(s):
#  -

#  Returns:
#  -

from pathlib import Path
import xml.etree.ElementTree as ET
import re
usedKeys = []

def validateFile(path):
  if path.is_file():
    if ".hpp" in path.name or ".sqf" in path.name:#make sure only valid file extensions are scanned
      #print (path.name)
      #print (path.read_text())
      scanFile(path)

def scanFile(path):
  fileText = path.read_text()
  global word
  words = re.split('"|;|[|]| |=|;|,|{|}|\n',fileText) #split things up
  for word in words:
    if "STR_ENH" in word:
      if word.startswith("$"):
        word = word.replace("$","")
      if word not in usedKeys: #only safe unique keys
        usedKeys.insert(0,word)

def getUsedKeysFromFiles():
  path = Path(r'C:\Users\rober\OneDrive\Games\Arma 3\Arma 3 Mods\3den-Enhanced\3denEnhanced')
  filesInPath = path.iterdir()
  for dir in filesInPath:
    validateFile(dir)
    if dir.is_dir():
      for file in dir.iterdir():
        validateFile(file)
        if file.is_dir():
          for subFile in file.iterdir():
            validateFile(subFile)
            if subFile.is_dir():
              for subSubFile in subFile.iterdir():
                validateFile(subSubFile)

def getKeysFromStringtable():
  pathXML = r"C:\Users\rober\OneDrive\Games\Arma 3\Arma 3 Mods\3den-Enhanced\3denEnhanced\stringtable.xml"
  tree = ET.parse(pathXML)
  root = tree.getroot()
  global keysInXML
  keysInXML = []
  for elem in root:
    if elem not in keysInXML:
      keyName = str(elem.attrib).replace("{'ID': '","")
      keyName = keyName.replace("'}","")
      keysInXML.insert(0,keyName)

def compareLists(keysInXML, usedKeys):
  for key in keysInXML:
    if key not in usedKeys:
      print(key)

getUsedKeysFromFiles()
getKeysFromStringtable()
compareLists(keysInXML, usedKeys)

#print(len(usedKeys))
#print(len(keysInXML))

if len(keysInXML) - len(usedKeys) <= 0:
  print("There are no unused keys.")
else:
  print (f"There are currently {len(keysInXML) - len(usedKeys)} unused keys in the stringtable.xml file.")