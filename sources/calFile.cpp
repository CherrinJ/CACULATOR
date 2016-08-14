#include "calFile.h"

using namespace std;

CalFile::CalFile()
	:m_fileState(CLOSE)
{}

CalFile::CalFile(char* fileName)
	:m_fileName(fileName)
	,m_fileState(CLOSE)
{}

CalFile::~CalFile()
{}

bool CalFile::exist(char* fileName)
{
	if(open(fileName) == 0)
	{
		return true;
	}
	return false;
}

int CalFile::open(char* fileName, OPEN_MODE mode)
{
	fstream file;
	file.open(fileName ,ios_base::in);
	if(file)
	{
		printf("opened file %s already!\n",fileName);
		m_fileName = fileName;
		m_fileState = OPENING;
		return 0;
	}
	else
	{
		printf("the file %s does not exist, please check!\n",fileName);
		return -1;
	}
}

bool CalFile::isOpen()
{
	if(m_fileState == OPENING)
	{
		return true;
	}
	return false;
}

string CalFile::read()
{
	ifstream ifile;
	ifile.open(m_fileName, ios::out);
	//can not using string or char* ,or the end of file will be eceptional
	char buffer[256];

	if (!ifile)
	{
		exit(1);
	}
	m_fileState = READING;
	//now only can read one line, need to implement to read the whole file
	ifile.getline(buffer,20);
	//while(!ifile.eof()) //judging end of the file dis not actual
	//{	
	//}
	printf("buffer = %s \n",buffer);

	return (string)buffer;
}

void CalFile::close()
{
	fstream file(m_fileName);
	file.close();
}

