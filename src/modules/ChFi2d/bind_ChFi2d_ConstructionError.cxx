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
#include <ChFi2d_ConstructionError.hxx>

void bind_ChFi2d_ConstructionError(py::module &mod){

py::enum_<ChFi2d_ConstructionError>(mod, "ChFi2d_ConstructionError", "error that can occur during the fillet construction on planar wire//! the face is not planar//! the face is null//! the two faces used for the initialisation are uncompatible.//! the parameters as distances or angle for chamfer are less or equal to zero.//! the initialization has been succesfull.//! the algorithm could not find a solution.//! the vertex given to locate the fillet or the chamfer is not connected to 2 edges.//! the two edges connected to the vertex are tangent.//! the first edge is degenerated.//! the last edge is degenerated.//! the two edges are degenerated.//! One or the two edges connected to the vertex is a fillet or a chamfer One or the two edges connected to the vertex is not a line or a circle")
	.value("ChFi2d_NotPlanar", ChFi2d_ConstructionError::ChFi2d_NotPlanar)
	.value("ChFi2d_NoFace", ChFi2d_ConstructionError::ChFi2d_NoFace)
	.value("ChFi2d_InitialisationError", ChFi2d_ConstructionError::ChFi2d_InitialisationError)
	.value("ChFi2d_ParametersError", ChFi2d_ConstructionError::ChFi2d_ParametersError)
	.value("ChFi2d_Ready", ChFi2d_ConstructionError::ChFi2d_Ready)
	.value("ChFi2d_IsDone", ChFi2d_ConstructionError::ChFi2d_IsDone)
	.value("ChFi2d_ComputationError", ChFi2d_ConstructionError::ChFi2d_ComputationError)
	.value("ChFi2d_ConnexionError", ChFi2d_ConstructionError::ChFi2d_ConnexionError)
	.value("ChFi2d_TangencyError", ChFi2d_ConstructionError::ChFi2d_TangencyError)
	.value("ChFi2d_FirstEdgeDegenerated", ChFi2d_ConstructionError::ChFi2d_FirstEdgeDegenerated)
	.value("ChFi2d_LastEdgeDegenerated", ChFi2d_ConstructionError::ChFi2d_LastEdgeDegenerated)
	.value("ChFi2d_BothEdgesDegenerated", ChFi2d_ConstructionError::ChFi2d_BothEdgesDegenerated)
	.value("ChFi2d_NotAuthorized", ChFi2d_ConstructionError::ChFi2d_NotAuthorized)
	.export_values();


}