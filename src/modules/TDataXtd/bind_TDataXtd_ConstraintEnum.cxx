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
#include <TDataXtd_ConstraintEnum.hxx>

void bind_TDataXtd_ConstraintEnum(py::module &mod){

py::enum_<TDataXtd_ConstraintEnum>(mod, "TDataXtd_ConstraintEnum", "The terms of this enumeration define the types of available constraint. ==================")
	.value("TDataXtd_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_RADIUS)
	.value("TDataXtd_DIAMETER", TDataXtd_ConstraintEnum::TDataXtd_DIAMETER)
	.value("TDataXtd_MINOR_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_MINOR_RADIUS)
	.value("TDataXtd_MAJOR_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_MAJOR_RADIUS)
	.value("TDataXtd_TANGENT", TDataXtd_ConstraintEnum::TDataXtd_TANGENT)
	.value("TDataXtd_PARALLEL", TDataXtd_ConstraintEnum::TDataXtd_PARALLEL)
	.value("TDataXtd_PERPENDICULAR", TDataXtd_ConstraintEnum::TDataXtd_PERPENDICULAR)
	.value("TDataXtd_CONCENTRIC", TDataXtd_ConstraintEnum::TDataXtd_CONCENTRIC)
	.value("TDataXtd_COINCIDENT", TDataXtd_ConstraintEnum::TDataXtd_COINCIDENT)
	.value("TDataXtd_DISTANCE", TDataXtd_ConstraintEnum::TDataXtd_DISTANCE)
	.value("TDataXtd_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_ANGLE)
	.value("TDataXtd_EQUAL_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_EQUAL_RADIUS)
	.value("TDataXtd_SYMMETRY", TDataXtd_ConstraintEnum::TDataXtd_SYMMETRY)
	.value("TDataXtd_MIDPOINT", TDataXtd_ConstraintEnum::TDataXtd_MIDPOINT)
	.value("TDataXtd_EQUAL_DISTANCE", TDataXtd_ConstraintEnum::TDataXtd_EQUAL_DISTANCE)
	.value("TDataXtd_FIX", TDataXtd_ConstraintEnum::TDataXtd_FIX)
	.value("TDataXtd_RIGID", TDataXtd_ConstraintEnum::TDataXtd_RIGID)
	.value("TDataXtd_FROM", TDataXtd_ConstraintEnum::TDataXtd_FROM)
	.value("TDataXtd_AXIS", TDataXtd_ConstraintEnum::TDataXtd_AXIS)
	.value("TDataXtd_MATE", TDataXtd_ConstraintEnum::TDataXtd_MATE)
	.value("TDataXtd_ALIGN_FACES", TDataXtd_ConstraintEnum::TDataXtd_ALIGN_FACES)
	.value("TDataXtd_ALIGN_AXES", TDataXtd_ConstraintEnum::TDataXtd_ALIGN_AXES)
	.value("TDataXtd_AXES_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_AXES_ANGLE)
	.value("TDataXtd_FACES_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_FACES_ANGLE)
	.value("TDataXtd_ROUND", TDataXtd_ConstraintEnum::TDataXtd_ROUND)
	.value("TDataXtd_OFFSET", TDataXtd_ConstraintEnum::TDataXtd_OFFSET)
	.export_values();


}