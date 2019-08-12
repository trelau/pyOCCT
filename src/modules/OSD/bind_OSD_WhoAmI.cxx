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
#include <OSD_WhoAmI.hxx>

void bind_OSD_WhoAmI(py::module &mod){

py::enum_<OSD_WhoAmI>(mod, "OSD_WhoAmI", "Allows great accuracy for error management. This is private.")
	.value("OSD_WDirectory", OSD_WhoAmI::OSD_WDirectory)
	.value("OSD_WDirectoryIterator", OSD_WhoAmI::OSD_WDirectoryIterator)
	.value("OSD_WEnvironment", OSD_WhoAmI::OSD_WEnvironment)
	.value("OSD_WFile", OSD_WhoAmI::OSD_WFile)
	.value("OSD_WFileNode", OSD_WhoAmI::OSD_WFileNode)
	.value("OSD_WFileIterator", OSD_WhoAmI::OSD_WFileIterator)
	.value("OSD_WPath", OSD_WhoAmI::OSD_WPath)
	.value("OSD_WProcess", OSD_WhoAmI::OSD_WProcess)
	.value("OSD_WProtection", OSD_WhoAmI::OSD_WProtection)
	.value("OSD_WHost", OSD_WhoAmI::OSD_WHost)
	.value("OSD_WDisk", OSD_WhoAmI::OSD_WDisk)
	.value("OSD_WChronometer", OSD_WhoAmI::OSD_WChronometer)
	.value("OSD_WTimer", OSD_WhoAmI::OSD_WTimer)
	.value("OSD_WPackage", OSD_WhoAmI::OSD_WPackage)
	.value("OSD_WEnvironmentIterator", OSD_WhoAmI::OSD_WEnvironmentIterator)
	.export_values();


}