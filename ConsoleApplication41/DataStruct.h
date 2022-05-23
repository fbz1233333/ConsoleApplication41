#pragma once
#include "std.h"
#include <string>
namespace datastruct {
	class _Name {
	public:
		char data[64];
		_Name();
		_Name(std::string str);
	};
	class _Path {
	public:
		enum FileType {
			FileNone, Mesh, Model, Texture2D
		};
	public:
		static std::map<std::string, FileType> typeMap;
		char data[1024];
		_Path();
		_Path(std::string string);
		std::ofstream* GetOfStream();
		std::ifstream* GetIfStream();
		FileType GetOriginType();
		std::string GetSuffix();
		std::string GetNameNoSuffix();
		std::string GetContent();
		bool IsEmpty();
		void Load(std::ifstream& ifs);
		void Save(std::ofstream& ofs);
	};
	
	class DataStruct
	{
	public:
		void Load(std::ifstream& ifs);
		void Save(std::ofstream& ofs);
	};

}
