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
#include <SelectMgr_StateOfSelection.hxx>

void bind_SelectMgr_StateOfSelection(py::module &mod){

py::enum_<SelectMgr_StateOfSelection>(mod, "SelectMgr_StateOfSelection", "different state of a Selection in a ViewerSelector...")
	.value("SelectMgr_SOS_Activated", SelectMgr_StateOfSelection::SelectMgr_SOS_Activated)
	.value("SelectMgr_SOS_Deactivated", SelectMgr_StateOfSelection::SelectMgr_SOS_Deactivated)
	.value("SelectMgr_SOS_Sleeping", SelectMgr_StateOfSelection::SelectMgr_SOS_Sleeping)
	.value("SelectMgr_SOS_Any", SelectMgr_StateOfSelection::SelectMgr_SOS_Any)
	.value("SelectMgr_SOS_Unknown", SelectMgr_StateOfSelection::SelectMgr_SOS_Unknown)
	.export_values();


}