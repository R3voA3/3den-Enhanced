#  Author: R3vo

#  Date: 2020-12-18

#  Description:
#  Saves stringtable stats (translation progress) into a text file in markdown format.

#  Parameter(s):
#  -

#  Returns:
#  -

import xml.etree.ElementTree as ET
from tkinter import filedialog
from tkinter import *
import time
import sys

#Open file dialog and get stringtable.xml
root = Tk()
root.filename = filedialog.askopenfilename(initialdir = "C:/",title = "Select file",filetypes = (("xml files","*.xml"),("all files","*.*")))
if (root.filename == ""):
  #sys.exit("No file selected. Script terminated!")
  quit("No file selected. Script terminated!")
tree = ET.parse(root.filename)
root = tree.getroot()
#Set up variables and consts
LANGUAGES = ("English", "Chinesesimp", "Czech", "French", "German", "Italian", "Polish", "Portuguese", "Russian", "Spanish")
COUNT_LANGUAGES = len(LANGUAGES)

#Create a list with only zeros, one for each lanuage
translation_count_per_language = [0] * COUNT_LANGUAGES

#Get the translation data. keys = STR_ENH..., tag = <English> ...
countKeys = 0
countTags = 0

for elem in root:
  countKeys += 1
  for subelem in elem:
    index = LANGUAGES.index(subelem.tag)
    translation_count_per_language[index] += 1
    countTags += 1


#Time to format everything into a markdown table
directory = filedialog.askdirectory (initialdir = "C:/",title = "Select a directory")

#Create file on desktop to store the output in
file = open(directory + "/translationProgress.txt","w+")

#Print headline
file.write("# Translation Progress\n")

#Print time of last update
localtime = time.asctime( time.localtime(time.time()) )
file.write(f"**Last update:** {localtime}\n")

#Print first table showing keys, translation and total progress
totalProgress = round(countTags / (countKeys * COUNT_LANGUAGES) * 100, 2)

file.write("| Number of Keys | Number of Translations | Total Progress |\n")
file.write("|----------|:-----------------:|--------:|\n")
file.write(f"| {countKeys} | {countTags} | {totalProgress} %|\n")
file.write("\n")

#Print translation progress in % per language
index = 0
#translation_count_per_language.sort(reverse=True)

file.write("| Language | Missing Entries | Progress |\n")
file.write("|----------|:-----------------:|--------:|\n")

for languageCount in translation_count_per_language:
  translationProgress = round(languageCount / countKeys * 100, 2)
  file.write("| | | |\n")

  if countKeys - languageCount == 0:
    file.write (f"|**{LANGUAGES[index]}** | **-** | **{translationProgress} %**\n")
  else:
      file.write (f"|{LANGUAGES[index]} | {countKeys - languageCount} | {translationProgress} %\n")
  index += 1

file.close()