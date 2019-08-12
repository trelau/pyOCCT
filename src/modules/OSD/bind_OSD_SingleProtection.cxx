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
#include <OSD_SingleProtection.hxx>

void bind_OSD_SingleProtection(py::module &mod){

py::enum_<OSD_SingleProtection>(mod, "OSD_SingleProtection", "Access rights for files. R means Read, W means Write, X means eXecute and D means Delete. On UNIX, the right to Delete is combined with Write access. So if 'W'rite is not set and 'D'elete is, 'W'rite will be set and if 'W' is set, 'D' will be too.")
	.value("OSD_None", OSD_SingleProtection::OSD_None)
	.value("OSD_R", OSD_SingleProtection::OSD_R)
	.value("OSD_W", OSD_SingleProtection::OSD_W)
	.value("OSD_RW", OSD_SingleProtection::OSD_RW)
	.value("OSD_X", OSD_SingleProtection::OSD_X)
	.value("OSD_RX", OSD_SingleProtection::OSD_RX)
	.value("OSD_WX", OSD_SingleProtection::OSD_WX)
	.value("OSD_RWX", OSD_SingleProtection::OSD_RWX)
	.value("OSD_D", OSD_SingleProtection::OSD_D)
	.value("OSD_RD", OSD_SingleProtection::OSD_RD)
	.value("OSD_WD", OSD_SingleProtection::OSD_WD)
	.value("OSD_RWD", OSD_SingleProtection::OSD_RWD)
	.value("OSD_XD", OSD_SingleProtection::OSD_XD)
	.value("OSD_RXD", OSD_SingleProtection::OSD_RXD)
	.value("OSD_WXD", OSD_SingleProtection::OSD_WXD)
	.value("OSD_RWXD", OSD_SingleProtection::OSD_RWXD)
	.export_values();


}