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
#include <StdPrs_Volume.hxx>

void bind_StdPrs_Volume(py::module &mod){

py::enum_<StdPrs_Volume>(mod, "StdPrs_Volume", "defines the way how to interpret input shapes Volume_Autodetection to perform Autodetection (would split input shape into two groups) Volume_Closed as Closed volumes (to activate back-face culling and capping plane algorithms) Volume_Opened as Open volumes (shells or solids with holes)")
	.value("StdPrs_Volume_Autodetection", StdPrs_Volume::StdPrs_Volume_Autodetection)
	.value("StdPrs_Volume_Closed", StdPrs_Volume::StdPrs_Volume_Closed)
	.value("StdPrs_Volume_Opened", StdPrs_Volume::StdPrs_Volume_Opened)
	.export_values();


}