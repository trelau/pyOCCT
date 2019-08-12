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
#include <XCAFDimTolObjects_GeomToleranceType.hxx>

void bind_XCAFDimTolObjects_GeomToleranceType(py::module &mod){

py::enum_<XCAFDimTolObjects_GeomToleranceType>(mod, "XCAFDimTolObjects_GeomToleranceType", "Defines types of geom tolerance")
	.value("XCAFDimTolObjects_GeomToleranceType_None", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_None)
	.value("XCAFDimTolObjects_GeomToleranceType_Angularity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Angularity)
	.value("XCAFDimTolObjects_GeomToleranceType_CircularRunout", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_CircularRunout)
	.value("XCAFDimTolObjects_GeomToleranceType_CircularityOrRoundness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_CircularityOrRoundness)
	.value("XCAFDimTolObjects_GeomToleranceType_Coaxiality", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Coaxiality)
	.value("XCAFDimTolObjects_GeomToleranceType_Concentricity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Concentricity)
	.value("XCAFDimTolObjects_GeomToleranceType_Cylindricity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Cylindricity)
	.value("XCAFDimTolObjects_GeomToleranceType_Flatness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Flatness)
	.value("XCAFDimTolObjects_GeomToleranceType_Parallelism", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Parallelism)
	.value("XCAFDimTolObjects_GeomToleranceType_Perpendicularity", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Perpendicularity)
	.value("XCAFDimTolObjects_GeomToleranceType_Position", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Position)
	.value("XCAFDimTolObjects_GeomToleranceType_ProfileOfLine", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_ProfileOfLine)
	.value("XCAFDimTolObjects_GeomToleranceType_ProfileOfSurface", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_ProfileOfSurface)
	.value("XCAFDimTolObjects_GeomToleranceType_Straightness", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Straightness)
	.value("XCAFDimTolObjects_GeomToleranceType_Symmetry", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_Symmetry)
	.value("XCAFDimTolObjects_GeomToleranceType_TotalRunout", XCAFDimTolObjects_GeomToleranceType::XCAFDimTolObjects_GeomToleranceType_TotalRunout)
	.export_values();


}