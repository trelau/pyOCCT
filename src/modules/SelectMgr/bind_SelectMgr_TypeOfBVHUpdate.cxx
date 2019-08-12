/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <SelectMgr_TypeOfBVHUpdate.hxx>

void bind_SelectMgr_TypeOfBVHUpdate(py::module &mod){

py::enum_<SelectMgr_TypeOfBVHUpdate>(mod, "SelectMgr_TypeOfBVHUpdate", "Keeps track for BVH update state for each SelectMgr_Selection entity in a following way: - Add : 2nd level BVH does not contain any of the selection's sensitive entities and they must be added; - Remove : all sensitive entities of the selection must be removed from 2nd level BVH; - Renew : 2nd level BVH already contains sensitives of the selection, but the its complete update and removal is required. Therefore, sensitives of the selection with this type of update must be removed from 2nd level BVH and added after recomputation. - Invalidate : the 2nd level BVH needs to be rebuilt; - None : entities of the selection are up to date.")
	.value("SelectMgr_TBU_Add", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Add)
	.value("SelectMgr_TBU_Remove", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Remove)
	.value("SelectMgr_TBU_Renew", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Renew)
	.value("SelectMgr_TBU_Invalidate", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Invalidate)
	.value("SelectMgr_TBU_None", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_None)
	.export_values();


}