//file operations
// adout reading , writing ,judging exist and so on

#ifndef __CALFILE__H__
#define __CALFILE__H__
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

class CalFile{

public:
	enum OPEN_MODE{
		READ_ONLY = 0,
	};

	enum FIlE_STATE{
		CLOSE = 0,
		OPENING,
		WRITING,
		READING
	};

public:
	CalFile();
	CalFile(char* fileName);
	~CalFile();
	bool exist(char* fileName);
	bool isOpen();
	int open(char* fileName, OPEN_MODE mode = READ_ONLY);
	std::string read();
	void write(char* filename);
	void close();
private:
	char* m_fileName;

public:
	FIlE_STATE m_fileState;
};

#endif //__CALFILE__H__