import os
import subprocess

if not os.path.exists('build'):
   subprocess.run(["mkdir", "build"])
   subprocess.run(["cmake", ".."], cwd = "build")
   subprocess.run(["make"], cwd = "build") 
else:
   subprocess.run(["cmake", ".."], cwd = "build")
   subprocess.run(["make"], cwd = "build")