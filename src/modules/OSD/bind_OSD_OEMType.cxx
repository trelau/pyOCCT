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
#include <OSD_OEMType.hxx>

void bind_OSD_OEMType(py::module &mod){

py::enum_<OSD_OEMType>(mod, "OSD_OEMType", "This is set of possible machine types used in OSD_Host::MachineType")
	.value("OSD_Unavailable", OSD_OEMType::OSD_Unavailable)
	.value("OSD_SUN", OSD_OEMType::OSD_SUN)
	.value("OSD_DEC", OSD_OEMType::OSD_DEC)
	.value("OSD_SGI", OSD_OEMType::OSD_SGI)
	.value("OSD_NEC", OSD_OEMType::OSD_NEC)
	.value("OSD_MAC", OSD_OEMType::OSD_MAC)
	.value("OSD_PC", OSD_OEMType::OSD_PC)
	.value("OSD_HP", OSD_OEMType::OSD_HP)
	.value("OSD_IBM", OSD_OEMType::OSD_IBM)
	.value("OSD_VAX", OSD_OEMType::OSD_VAX)
	.value("OSD_LIN", OSD_OEMType::OSD_LIN)
	.value("OSD_AIX", OSD_OEMType::OSD_AIX)
	.export_values();


}