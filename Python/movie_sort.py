import glob
from datetime import date

path = '/home/brenchley/Videos/series/*'

files= glob.glob(path)

for file in files:     
   print file[30:]