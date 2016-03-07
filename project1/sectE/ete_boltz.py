import sys
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.mlab as mlab
from scipy import stats

__author__ = "Brandon Wood"

file = open(sys.argv[1])
HEADER_LINES = 0
for x in range(HEADER_LINES):
    file.readline()

ete_list = []

for line in file:
    tokens = line.split()
    ete_list.append(float(tokens[0]))

plt.rc('savefig',dpi=500)
#print ete_list


"""____________________________Stats__________________________________"""

avg = np.average(ete_list)
print avg
#print ete_list[1]
#mode = stats.mode(ete_list)
#print mode
stdev = np.std(ete_list)
print stdev
ete_sq = np.square(ete_list)
mean_sq_ete = np.average(ete_sq)
print mean_sq_ete
#print ete_sq[1]
#plot root mean squared
#rms = np.sqrt(ete_sq)
#rms_avg = np.average(rms)
#rms_stdev = np.std(rms)
#print rms_avg
#print rms_stdev

"""_____________________________Histogram_______________________________"""

plt.figure()
plt.ylabel('$P(R)$')
plt.xlabel('$end-to-end$ $distance$ $R$$(\AA)$')
n, bins, patches = plt.hist(ete_list, 75, normed=1, alpha=0.5)

maxwell = stats.maxwell
params = maxwell.fit(ete_list, floc=0)
x = np.linspace(0, 120, 300)

y = mlab.normpdf(bins, avg, stdev)
plt.plot(bins, y, 'r--', lw=2)
plt.plot(x, maxwell.pdf(x, *params), 'y-', lw=2)
plt.legend(['$Gaussian$ $Distribution$', '$Maxwell-Boltzmann$ $Distribution$'], loc='best')
plt.savefig('ete_boltz.png', bbox_inches='tight')

