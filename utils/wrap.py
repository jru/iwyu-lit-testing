
import sys
import subprocess

p = subprocess.Popen(sys.argv[1:], stdout=sys.stdout, stderr=sys.stderr)
p.communicate()
