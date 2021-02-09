# Generates TOC (first level only) from markup text contained in clipboard. Final TOC is saved in temp.txt in the folder where this script is located

from tkinter import Tk
from tkinter import simpledialog

window = Tk()
window.withdraw()
clipboardText = window.clipboard_get() #Shows an error when clipboard is empty. Can be ignored for now
file = open("temp.txt", "w+") #w+ = read and write
file.write(clipboardText)
file.close()
path = simpledialog.askstring("Path", "Enter the path: Format: https://github.com/R3voA3/3den-Enhanced/wiki/Customisation")

file = open("temp.txt", "r")

lines = file.readlines()
toc = "<p align=""center"">\n  <b>Content</b><br>\n"
for line in lines:
  if line.startswith("# "):
    line = line.replace("\n", "")
    lineClean = line.strip("# ")
    lineLink = lineClean.replace(" ", "-").lower()
    toc += '  <a href="{}#{}">{}</a> |\n'.format(path,lineLink, lineClean)
toc = toc.strip("|\n") #Strip | and line break from last entry
toc += "\n</p>\n"

#print(toc)
#print(clipboardText)

file = open("temp.txt", "w+") #w+ = read and write
file.write(toc)
file.close()