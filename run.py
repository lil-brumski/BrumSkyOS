import subprocess
import os

if os.path.exists('build'):
   subprocess.run(["./BrumSkyOS.o"], cwd = 'build')
else:
   print("Error: 'build' does not exist!\nRun the setup.py first before running this one.")
   