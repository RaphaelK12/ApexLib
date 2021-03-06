/*  Apex Engine Format Library
	Copyright(C) 2014-2019 Lukas Cone

	This program is free software : you can redistribute it and / or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once
#include <vector>
#include "datas/reflector.hpp"
#include "AdfBaseObject.h"

namespace pugi 
{
	class xml_node;
};

REFLECTOR_CREATE(ADFDescriptorType, ENUM, 1, CLASS,
	Primitive,
	Structure,
	Pointer,
	Array,
	InlineArray,
	String,
	UnknownType,
	BitField,
	Enumeration,
	StringHash)

class ADF : public IADF
{
public:
	typedef std::vector<std::string *> CPPRegistry;
	struct Descriptor;

	struct Instance
	{
		ApexHash nameHash;
		ApexHash typeHash;
		int offset;
		int size;
		int64 nameIndex;

		StringHash *name;
		ADFInstance *instance;
		char *instanceBuffer;
		Instance(): name(nullptr), instance(nullptr), instanceBuffer(nullptr) {}
		~Instance();
	};

	struct DescriptorBase
	{
		int numMembers;
		virtual int Load(BinReader *rd, ADF *base);
		virtual void XMLDump(pugi::xml_node *master) const;
		virtual void CPPDump(const Descriptor *main, CPPRegistry &classes) const;
		virtual ~DescriptorBase() {}
	};

	struct DescriptorStructure : DescriptorBase
	{
		struct Member
		{
			int64 nameIndex;
			ApexHash typeHash;
			int	size;
			short offset;
			char pad, bitOffset;
			ApexHash defType;
			int64 defValue;

			StringHash *name;
		};
		std::vector<Member> members;
		int Load(BinReader *rd, ADF *base);
		void XMLDump(pugi::xml_node *master) const;
		void CPPDump(const Descriptor *main, CPPRegistry &classes) const;
	};

	struct DescriptorExplicitEnum : DescriptorBase
	{
		struct Member 
		{
			int64 nameIndex;
			int value;
			StringHash *name;
		};
		std::vector<Member> members;
		int Load(BinReader *rd, ADF *base);
		void XMLDump(pugi::xml_node *master) const;
		void CPPDump(const Descriptor *main, CPPRegistry &classes) const;
	};


	struct Descriptor
	{
		ADFDescriptorType type;
		int size,
			allignemt;
		ApexHash nameHash;
		int64 nameIndex;
		int flags;
		ApexHash elementTypeHash;
		int elementSize;

		StringHash *name;
		DescriptorBase *descriptorData;
		ADF *main;

		int Load(BinReader *rd, ADF *base);
		void XMLDump(pugi::xml_node *node) const;
		void CPPDump(CPPRegistry &classes) const;
		~Descriptor();
	};

	int ID;
	int version;
	int numInstances;
	int instancesOffset;
	int numDefinitions;
	int definitionsOffset;
	int numHashes;
	int hashesOffset;
	int numNames;
	int namesOffset;
	int fileSize;
	int null[5];
	std::string comment;

	std::vector<StringHash*> hashes;
	std::vector<StringHash*> names;
	typedef std::vector<Instance*> Instances_type;
	Instances_type instances;
	std::vector<Descriptor> descriptors;
public:
	int Load(BinReader *rd, bool supressErrors = false);
	int LoadAsRenderBlockModel(BinReader *rd, bool supressErrors = false);
	int DumpDefinitions(const char *fileName) const;
	int DumpDefinitions(const wchar_t *fileName) const;
	int DumpDefinitions(pugi::xml_node &node) const;
	int ExportDefinitionsToCPP(const char *fileName) const;
	int ExportDefinitionsToCPP(const wchar_t *fileName) const;
	int ExportDefinitionsToCPP(std::ostream &str) const;


	ADFInstance *FindInstance(ApexHash hash, int numSkips = 0);
	Instance *FindRawInstance(ApexHash hash, int numSkips = 0);
	using IADF::FindInstance;
	StringHash *AddStringHash(const char* input);
	ES_FORCEINLINE StringHash *AddStringHash(const std::string input) { return AddStringHash(input.c_str()); }
	std::string *FindString(ApexHash hash);
	StringHash *FindStringHash(ApexHash hash);
	void AddInstance(ADFInstance *instance, ApexHash hash);
	~ADF();
	ADF();
	ADFInstance *ConstructInstance(ApexHash classHash, void *data);
	bool InstanceContructoreExits(ApexHash classHash);
};