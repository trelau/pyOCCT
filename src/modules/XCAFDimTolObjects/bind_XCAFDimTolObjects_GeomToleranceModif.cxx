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
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>

void bind_XCAFDimTolObjects_GeomToleranceModif(py::module &mod){

py::enum_<XCAFDimTolObjects_GeomToleranceModif>(mod, "XCAFDimTolObjects_GeomToleranceModif", "Defines modifirs")
	.value("XCAFDimTolObjects_GeomToleranceModif_Any_Cross_Section", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Any_Cross_Section)
	.value("XCAFDimTolObjects_GeomToleranceModif_Common_Zone", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Common_Zone)
	.value("XCAFDimTolObjects_GeomToleranceModif_Each_Radial_Element", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Each_Radial_Element)
	.value("XCAFDimTolObjects_GeomToleranceModif_Free_State", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Free_State)
	.value("XCAFDimTolObjects_GeomToleranceModif_Least_Material_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Least_Material_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Line_Element", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Line_Element)
	.value("XCAFDimTolObjects_GeomToleranceModif_Major_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Major_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Maximum_Material_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Maximum_Material_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Minor_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Minor_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Not_Convex", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Not_Convex)
	.value("XCAFDimTolObjects_GeomToleranceModif_Pitch_Diameter", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Pitch_Diameter)
	.value("XCAFDimTolObjects_GeomToleranceModif_Reciprocity_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Reciprocity_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Separate_Requirement", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Separate_Requirement)
	.value("XCAFDimTolObjects_GeomToleranceModif_Statistical_Tolerance", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Statistical_Tolerance)
	.value("XCAFDimTolObjects_GeomToleranceModif_Tangent_Plane", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_Tangent_Plane)
	.value("XCAFDimTolObjects_GeomToleranceModif_All_Around", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_All_Around)
	.value("XCAFDimTolObjects_GeomToleranceModif_All_Over", XCAFDimTolObjects_GeomToleranceModif::XCAFDimTolObjects_GeomToleranceModif_All_Over)
	.export_values();


}