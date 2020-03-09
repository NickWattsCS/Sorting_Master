import time
import matplotlib as plotter
import subprocess

numbers = [10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000]
sorts = ["-i", "-m", "-h", "-q", "-c", "-r", "-b"]
runtimes = []

for type in sorts:
  for entry in numbers:
    begin = time.clock()
    Popen(['./sort', type, '--size', entry])
    end = time.clock()
    runtimes.push(end - begin)

  plotter.plot(numbers, runtimes)
  plot.show()
