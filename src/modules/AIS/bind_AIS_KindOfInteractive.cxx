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
#include <AIS_KindOfInteractive.hxx>

void bind_AIS_KindOfInteractive(py::module &mod){

py::enum_<AIS_KindOfInteractive>(mod, "AIS_KindOfInteractive", "Declares the type of Interactive Object. This is one of the following: - the Datum - the Object - the Relation - the Dimension - the None type. The Datum is the construction element. These include points, lines, axes and planes. The object brings together topological shapes. The Relation includes dimensions and constraints. The Dimension includes length, radius, diameter and angle dimensions. When the object is of an unknown type, the None type is declared.")
	.value("AIS_KOI_None", AIS_KindOfInteractive::AIS_KOI_None)
	.value("AIS_KOI_Datum", AIS_KindOfInteractive::AIS_KOI_Datum)
	.value("AIS_KOI_Shape", AIS_KindOfInteractive::AIS_KOI_Shape)
	.value("AIS_KOI_Object", AIS_KindOfInteractive::AIS_KOI_Object)
	.value("AIS_KOI_Relation", AIS_KindOfInteractive::AIS_KOI_Relation)
	.value("AIS_KOI_Dimension", AIS_KindOfInteractive::AIS_KOI_Dimension)
	.export_values();


}