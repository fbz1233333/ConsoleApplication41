#include "DataStruct.h"

using namespace datastruct;

std::map<std::string, _Path::FileType> _Path::typeMap = {
	{"obj", FileType::Model},
	{"fbx", FileType::Model},
	{"png", FileType::Texture2D},
	{"jpg", FileType::Texture2D},
};

_Path::FileType datastruct::_Path::GetOriginType()
{
	if(typeMap.find(GetSuffix())!=typeMap.end()){
		return typeMap[GetSuffix()];
	}
	return FileNone;
}

datastruct::_Path::_Path()
{
}

_Path::_Path(std::string string)
{
	strcpy(data, string.c_str());
}

std::ofstream* datastruct::_Path::GetOfStream()
{
	// TODO: 在此处插入 return 语句

	std::string string(data);
	std::ofstream *ofs = new std::ofstream();
	ofs->open(string, std::ios::out |std::ios::binary);
	return ofs;
}

std::ifstream* _Path::GetIfStream()
{
	std::string string(data);

	std::ifstream* ifs = new std::ifstream();
	ifs->open(string.c_str(), std::ios::in | std::ios::binary);
	if (ifs->is_open()) {
		return ifs;
	}
}

std::string _Path::GetSuffix()
{
	std::string string(data);
	return string.substr(string.find_last_of('.') + 1);
}

std::string _Path::GetNameNoSuffix()
{
	std::string string(data);
	return string.substr(0, string.find_last_of('.'));
}

std::string datastruct::_Path::GetContent()
{
	std::string string(data);
	std::string vertexCode;
	std::ifstream vShaderFile;
	vShaderFile.open(string.c_str());
	std::stringstream vStream;
	vStream << vShaderFile.rdbuf();
	return vStream.str();
}

bool datastruct::_Path::IsEmpty()
{
	std::string string(data);
	return string.empty();
}

void datastruct::_Path::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, sizeof(_Path));
}

void datastruct::_Path::Save(std::ofstream & ofs)
{
	ofs.write((char*)this, sizeof(_Path));
}



void DataStruct::Load(std::ifstream & ifs)
{
	ifs.read((char*)this, sizeof(*this));
}

void datastruct::DataStruct::Save(std::ofstream & ofs)
{
	ofs.write((char*)this, sizeof(*this));
}

datastruct::_Name::_Name()
{
}

datastruct::_Name::_Name(std::string str)
{
	strcpy(this->data, str.c_str());
}
