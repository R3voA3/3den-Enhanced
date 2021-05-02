from pathlib import Path

#path = r"C:\Users\rober\OneDrive\Dokumente\Arma 3 - Other Profiles\R3vo\missions\TESTING\scriptLibrary.VR\description.ext"

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

read_descriptionExt(path)