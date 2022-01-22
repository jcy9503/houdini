# Useage:
# Save this script as "make_denoise_script.py" in the directory that 
# contains the undenoised openexr files - they will have "variance" in their names.
# On Linux and OSX open a terminal and cd to the openexr directory. 
# On Windows open a CMD window and cd to the openexr directory.
# Enter this command
#   python make_denoise_script.py
# On Linux and OSX a script named "run_batch_denoise" will be created. To execute
# the script enter this command in the terminal.
#   ./run_batch_denoise
# On Windows the script will be named "run_batch_denoise.bat". To run the script
# double click the file.
# Denoising will begin immediately.
#
import os
import os.path
import glob
import inspect
import re
  
#Find the path to the .exrs directory
scptpth = inspect.getframeinfo(inspect.currentframe()).filename
dirpath = os.path.dirname(os.path.abspath(scptpth))

#Get a listing of all the variance .exr files
glob_patt = os.path.join(dirpath, '*variance*')
paths = glob.glob(glob_patt)
paths.sort()
  
#Define regular expression pattern
patt = re.compile('(\w+)[._](\d+)[._](exr)')
  
#Create list of frame numbers
framelist = []
for path in paths:
	fname = os.path.basename(path)
	fsearch = re.search(patt, fname)
	num = fsearch.group(2)
	framelist.append(num)
  
frames = (",".join(framelist))
	
#Define file information and join with full path and frame numbers
frame = os.path.basename(paths[0])
fsearch = re.search(patt, frame)
txt = fsearch.group(1)
  
myframe = ('%s.{%s}.exr'%(txt,frames))
mypath = os.path.join(dirpath, myframe)
  
#Create batch denoise file
if os.name == 'posix':
	filepath = os.path.join(dirpath, 'run_batch_denoise')
	f = open(filepath, 'w')
	
	f.write('denoise --crossframe -v variance -f default.filter.json '+mypath+'\n')
	f.write('read\n')
	f.close()
	print '"run_batch_denoise" successfully created in project directory'
else:
	filepath = os.path.join(projpath, 'run_batch_denoise.bat')
	f = open(filepath, 'w')
	
	f.write('denoise --crossframe -v variance -f default.filter.json '+mypath+'\n')
	f.write('pause\n')
	f.close()
	print '"run_batch_denoise.bat" successfully created in project directory'
if os.name != 'nt':
	os.chmod(filepath, 0777)
