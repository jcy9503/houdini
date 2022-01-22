# When run in a dirctory that contains .mov files this python script
# will create a file called "convertToMP4". When "convertToMP4" is
# run it will use ffmpeg to convert the .mov movies to .mp4 movies.
import os
import inspect
import glob

# ffmpeg -i input.mov -q:v 0 output.mp4
# 
scriptpath = inspect.getframeinfo(inspect.currentframe()).filename
parentpath = os.path.dirname(os.path.abspath(scriptpath))

glob_pattern = os.path.join(parentpath, '*.mov')

movies = glob.glob(glob_pattern)
converter_path = ''
if os.name == 'nt':
	converter_path = os.path.join(parentpath, 'convertToMP4.bat')
else:
	converter_path = os.path.join(parentpath, 'convertToMP4')
	
out = open(converter_path, 'w')

for mov in movies:
	mov_name = os.path.basename(mov)[:-4]
	mp4_path = os.path.join(parentpath, mov_name + '.mp4')
	out.write('ffmpeg -i %s -q:v 0 %s\n' % (mov, mp4_path))
out.close()

if os.name != 'nt':
	os.chmod(converter_path, 0777)
