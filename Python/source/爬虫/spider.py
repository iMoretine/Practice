import requests
import os

for i in range(1,7):
    filepath = 'D:/picture/'+str(i)+'/'
    for j in range(1,609):
        filename = str(j) + '.jpg'
        if os.path.exists(filepath+filename):
            continue
        
        imgurl = 'http://3dxxxs.com/galls/%d/%d.jpg' % (i,j)
        try:
            img= requests.get(imgurl, timeout=60)

            fp = open(filepath+filename,'wb')
            fp.write(img.content)
            fp.close()
            print(imgurl+'...Done.')

        except requests.exceptions.ConnectionError:
            print('[ERROR] Cannot download image '+imgurl)
            continue