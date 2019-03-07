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

#include "RBNClasses.h"
#include "RBSClasses.h"
#include "RBMClassesJC2.h"
#include "RBMClassesJC3.h"
#include "RBMClassesHU.h"
#include "datas/reflectorRegistry.hpp"
#include "datas/macroLoop.hpp"

#define ADFRegisterClass(classname) {classname::HASH, &RBMCreateClass<classname>},

template<class C> RBMMasterBlock *RBMCreateClass() { return new C{}; }

static const std::map<uint64, RBMMasterBlock *(*)()> RBMClassStorage =
{
	StaticFor(ADFRegisterClass, 
	RBNGeneral,
	RBNCarPaint,
	RBNCharacter,
	RBNWindow,
	RBNXXXX,

	RBSGeneral,
	RBSCarPaint,
	RBSCharacter,
	RBSWindow,
	RBSXXXX,

	RBMCarPaintSimple,
	RBMFoliageBark,
	RBMVegetationFoliage,
	RBMBillboardFoliage,
	RBMHalo,
	RBMLambert,
	RBMGeneral,
	RBMFacade,
	RBMCarPaint,
	RBMWindow,
	RBMDeformWindow,
	RBMMerged,
	RBMSkinnedGeneral,

	RBMFoliageBark2,
	RBMVegetationFoliage3,
	RBMGeneralSimple,
	RBMWaterHull,
	RBMSimpleGeometry,
	RBMBavariumShiled,
	RBMLayered,
	RBMWindow1,
	RBMLandmark,
	RBMGeneralMK3,
	RBMGeneral6,
	RBMCarLight,
	RBMCarPaint14,
	RBMGeneral3,
	RBMCharacter6,
	RBMCharacter9,
	RBMRoad,
	RBMGeneralSimple3,

	RBMSkinnedGeneral0,
	RBMGeneral0,
	RBMUIOverlay,
	RBMScope,
	RBMSkinnedGeneralDecal,
	RBMFacade0
	)
};

static int RegisteredEnums = 0;

RBMMasterBlock *RBMMasterBlock::ConstructClass(uint64 classHash)
{
	return RBMClassStorage.count(classHash) ? RBMClassStorage.at(classHash)() : nullptr;
}

RBMMasterBlock::RBMMasterBlock()
{
	if (RegisteredEnums)
		return;

	REGISTER_ENUM(RBMCarPaintSimpleFlags);
	REGISTER_ENUM(RBMGeneralFlags);
	REGISTER_ENUM(RBMFacadeFlags);
	REGISTER_ENUM(RBMSkinnedGeneralFlags);
	REGISTER_ENUM(RBMSkinnedGeneralTechnique);
	RegisteredEnums = 0xff;
}