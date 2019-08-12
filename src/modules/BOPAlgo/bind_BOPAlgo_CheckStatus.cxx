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
#include <BOPAlgo_CheckStatus.hxx>

void bind_BOPAlgo_CheckStatus(py::module &mod){

py::enum_<BOPAlgo_CheckStatus>(mod, "BOPAlgo_CheckStatus", "None")
	.value("BOPAlgo_CheckUnknown", BOPAlgo_CheckStatus::BOPAlgo_CheckUnknown)
	.value("BOPAlgo_BadType", BOPAlgo_CheckStatus::BOPAlgo_BadType)
	.value("BOPAlgo_SelfIntersect", BOPAlgo_CheckStatus::BOPAlgo_SelfIntersect)
	.value("BOPAlgo_TooSmallEdge", BOPAlgo_CheckStatus::BOPAlgo_TooSmallEdge)
	.value("BOPAlgo_NonRecoverableFace", BOPAlgo_CheckStatus::BOPAlgo_NonRecoverableFace)
	.value("BOPAlgo_IncompatibilityOfVertex", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfVertex)
	.value("BOPAlgo_IncompatibilityOfEdge", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfEdge)
	.value("BOPAlgo_IncompatibilityOfFace", BOPAlgo_CheckStatus::BOPAlgo_IncompatibilityOfFace)
	.value("BOPAlgo_OperationAborted", BOPAlgo_CheckStatus::BOPAlgo_OperationAborted)
	.value("BOPAlgo_GeomAbs_C0", BOPAlgo_CheckStatus::BOPAlgo_GeomAbs_C0)
	.value("BOPAlgo_InvalidCurveOnSurface", BOPAlgo_CheckStatus::BOPAlgo_InvalidCurveOnSurface)
	.value("BOPAlgo_NotValid", BOPAlgo_CheckStatus::BOPAlgo_NotValid)
	.export_values();


}