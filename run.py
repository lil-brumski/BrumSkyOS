import subprocess
import os

if os.path.exists('build'):
   if os.path.exists('build/BrumSkyOS.o'):
      subprocess.run(["./BrumSkyOS.o"], cwd = 'build')
   else:
      print("Bro...there isn't an executable in the build directory, try running the setup.py file first.")
else:
   print("Error: 'build' does not exist!\nRun the setup.py first before running this one.")
   