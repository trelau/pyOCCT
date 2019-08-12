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
#include <OSD_KindFile.hxx>

void bind_OSD_KindFile(py::module &mod){

py::enum_<OSD_KindFile>(mod, "OSD_KindFile", "Specifies the type of files.")
	.value("OSD_FILE", OSD_KindFile::OSD_FILE)
	.value("OSD_DIRECTORY", OSD_KindFile::OSD_DIRECTORY)
	.value("OSD_LINK", OSD_KindFile::OSD_LINK)
	.value("OSD_SOCKET", OSD_KindFile::OSD_SOCKET)
	.value("OSD_UNKNOWN", OSD_KindFile::OSD_UNKNOWN)
	.export_values();


}