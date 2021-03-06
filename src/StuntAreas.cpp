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

#include "StuntAreas.h"

void StuntArea::Fixup(char *masterBuffer)
{
	name.string.Fixup(masterBuffer);
	partName.string.Fixup(masterBuffer);
}

ES_INLINE void StuntAreas::Fixup(char *masterBuffer)
{
	for (auto &s : stuntAreas)
		s.Fixup(masterBuffer);
}

StuntAreas_wrap::StuntAreas_wrap(void *_data, ADF *_main): data(static_cast<StuntAreas*>(_data)) {}
void StuntAreas_wrap::Fixup(char *masterBuffer) { data->Fixup(masterBuffer); }
