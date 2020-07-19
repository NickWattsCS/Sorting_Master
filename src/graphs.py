import time
from matplotlib import pyplot as plotter
import subprocess

numbers = [10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000]
sorts = ["-i", "-m", "-h", "-q", "-c", "-r", "-b"]
runtimes = []

for type in sorts:
  for entry in numbers:
    begin = time.clock()
    process = subprocess.Popen(['./sort', type, '--size', str(entry)])
    process.wait()
    end = time.clock()
    runtimes.append(end - begin)

  plotter.plot(numbers, runtimes)
  plotter.xlabel("Number of entries")
  plotter.ylabel("Time")

  if type is "-i":
    plotter.title("Insertion Sort Time Complexity")
  elif type is "-m":
    plotter.title("Merge Sort Time Complexity")
  elif type is "-h":
    plotter.title("Heap Sort Time Complexity")
  elif type is "-q":
    plotter.title("Quicksort Time Complexity")
  elif type is "-c":
    plotter.title("Counting Sort Time Complexity")
  elif type is "-r":
    plotter.title("Radix Sort Time Complexity")
  elif type is "-b":
    plotter.title("Bucket Sort Time Complexity")

  plotter.show()

  runtimes.clear()
