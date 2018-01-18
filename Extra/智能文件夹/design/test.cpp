
QList<QDir> searchDirectory(QDir directory)
{
	QList<QDir> fileList;
	QQueue<QDir> dirQueue;
	dirQueue.append(directory);

	while(!dirQueue.empty())
	{
		QDir curDir = dirQueue.pop();
		QFileInfoList curDirList = curDir.entryInfoList();
		for(int i=0;i<curDirList.size();i++)
		{
			if(curDirList[i] is Directory) // curDirList[i] is a directory.
			{
				dirQueue.push(curDirList[i])
			}
			else // curDirList[i] is a file.
			{
				fileList.append(curDirList[i])
			}
		}
	}
	return fileList;
}