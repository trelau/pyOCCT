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
#include <AIS_StandardDatum.hxx>

void bind_AIS_StandardDatum(py::module &mod){

py::enum_<AIS_StandardDatum>(mod, "AIS_StandardDatum", "Declares the type of standard datum of an Interactive Object.")
	.value("AIS_SD_None", AIS_StandardDatum::AIS_SD_None)
	.value("AIS_SD_Point", AIS_StandardDatum::AIS_SD_Point)
	.value("AIS_SD_Axis", AIS_StandardDatum::AIS_SD_Axis)
	.value("AIS_SD_Trihedron", AIS_StandardDatum::AIS_SD_Trihedron)
	.value("AIS_SD_PlaneTrihedron", AIS_StandardDatum::AIS_SD_PlaneTrihedron)
	.value("AIS_SD_Line", AIS_StandardDatum::AIS_SD_Line)
	.value("AIS_SD_Circle", AIS_StandardDatum::AIS_SD_Circle)
	.value("AIS_SD_Plane", AIS_StandardDatum::AIS_SD_Plane)
	.export_values();


}