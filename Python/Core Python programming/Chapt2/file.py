numChapt = 2
numExer = 16

for i in range(numExer):
	fileName = 'Chapt' + '%d.%d' % (numChapt , i+1) + '.py'
	file = open(fileName,'w')
	file.close()
