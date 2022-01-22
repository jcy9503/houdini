#!/usr/bin/python

# Wrapper to run Houdini with custom environment
import os, subprocess, sys

#sys.path.append("C:/Program Files/Side Effects Software/Houdini 18.0.287/houdini/python2.7libs")

houdini = 'C:/Program Files/Side Effects Software/Houdini 18.5.696/bin/hindie.exe'

#Add HOME dir


#os.environ['HOME'] = '{}'.format("j:/OpenClass/HOU")

#os.environ['HOME'] = "j:/OpenClass/HOU"

#HOME := 'J:/HOU'

# Add Arnold to Path
#os.environ['PATH'] = '$PATH;{}'.format("C:/htoa/htoa-5.0.1_r5e954ab_houdini-18.0.287/htoa-5.0.1_r5e954ab_houdini-18.0.287/scripts/bin")
#os.environ['HOUDINI_PATH'] = '{};&'.format("C:/htoa/htoa-5.0.1_r5e954ab_houdini-18.0.287/htoa-5.0.1_r5e954ab_houdini-18.0.287")


if __name__ == "__main__":
    
    # Run Houdini
    subprocess.Popen(houdini)

