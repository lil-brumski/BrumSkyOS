import os
import subprocess

if not os.path.exists('build'):
   subprocess.run(["mkdir", "build"])
   subprocess.run(["cmake", "..", "-DBRUSTA=OFF"], cwd = "build")
   subprocess.run(["make"], cwd = "build") 
else:
   subprocess.run(["cmake", ".."], cwd = "build")
   subprocess.run(["make"], cwd = "build")
   if os.path.exists("build/BrumSkyOS"):
      print("Run the executable located in the 'build' directory like this: ./BrumSkyOS")
   else:
      print("Error: BrumSkyOS wasn't built!")