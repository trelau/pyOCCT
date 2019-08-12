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
#include <OSD_SysType.hxx>

void bind_OSD_SysType(py::module &mod){

py::enum_<OSD_SysType>(mod, "OSD_SysType", "Thisd is a set of possible system types. 'Default' means SysType of machine operating this process. This can be used with the Path class. All UNIX-like are grouped under 'UnixBSD' or 'UnixSystemV'. Such systems are Solaris, NexTOS ... A category of systems accept MSDOS-like path such as WindowsNT and OS2.")
	.value("OSD_Unknown", OSD_SysType::OSD_Unknown)
	.value("OSD_Default", OSD_SysType::OSD_Default)
	.value("OSD_UnixBSD", OSD_SysType::OSD_UnixBSD)
	.value("OSD_UnixSystemV", OSD_SysType::OSD_UnixSystemV)
	.value("OSD_VMS", OSD_SysType::OSD_VMS)
	.value("OSD_OS2", OSD_SysType::OSD_OS2)
	.value("OSD_OSF", OSD_SysType::OSD_OSF)
	.value("OSD_MacOs", OSD_SysType::OSD_MacOs)
	.value("OSD_Taligent", OSD_SysType::OSD_Taligent)
	.value("OSD_WindowsNT", OSD_SysType::OSD_WindowsNT)
	.value("OSD_LinuxREDHAT", OSD_SysType::OSD_LinuxREDHAT)
	.value("OSD_Aix", OSD_SysType::OSD_Aix)
	.export_values();


}