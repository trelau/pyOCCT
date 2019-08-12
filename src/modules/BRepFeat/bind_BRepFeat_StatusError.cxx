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
#include <BRepFeat_StatusError.hxx>

void bind_BRepFeat_StatusError(py::module &mod){

py::enum_<BRepFeat_StatusError>(mod, "BRepFeat_StatusError", "Discribes the error.")
	.value("BRepFeat_OK", BRepFeat_StatusError::BRepFeat_OK)
	.value("BRepFeat_BadDirect", BRepFeat_StatusError::BRepFeat_BadDirect)
	.value("BRepFeat_BadIntersect", BRepFeat_StatusError::BRepFeat_BadIntersect)
	.value("BRepFeat_EmptyBaryCurve", BRepFeat_StatusError::BRepFeat_EmptyBaryCurve)
	.value("BRepFeat_EmptyCutResult", BRepFeat_StatusError::BRepFeat_EmptyCutResult)
	.value("BRepFeat_FalseSide", BRepFeat_StatusError::BRepFeat_FalseSide)
	.value("BRepFeat_IncDirection", BRepFeat_StatusError::BRepFeat_IncDirection)
	.value("BRepFeat_IncSlidFace", BRepFeat_StatusError::BRepFeat_IncSlidFace)
	.value("BRepFeat_IncParameter", BRepFeat_StatusError::BRepFeat_IncParameter)
	.value("BRepFeat_IncTypes", BRepFeat_StatusError::BRepFeat_IncTypes)
	.value("BRepFeat_IntervalOverlap", BRepFeat_StatusError::BRepFeat_IntervalOverlap)
	.value("BRepFeat_InvFirstShape", BRepFeat_StatusError::BRepFeat_InvFirstShape)
	.value("BRepFeat_InvOption", BRepFeat_StatusError::BRepFeat_InvOption)
	.value("BRepFeat_InvShape", BRepFeat_StatusError::BRepFeat_InvShape)
	.value("BRepFeat_LocOpeNotDone", BRepFeat_StatusError::BRepFeat_LocOpeNotDone)
	.value("BRepFeat_LocOpeInvNotDone", BRepFeat_StatusError::BRepFeat_LocOpeInvNotDone)
	.value("BRepFeat_NoExtFace", BRepFeat_StatusError::BRepFeat_NoExtFace)
	.value("BRepFeat_NoFaceProf", BRepFeat_StatusError::BRepFeat_NoFaceProf)
	.value("BRepFeat_NoGluer", BRepFeat_StatusError::BRepFeat_NoGluer)
	.value("BRepFeat_NoIntersectF", BRepFeat_StatusError::BRepFeat_NoIntersectF)
	.value("BRepFeat_NoIntersectU", BRepFeat_StatusError::BRepFeat_NoIntersectU)
	.value("BRepFeat_NoParts", BRepFeat_StatusError::BRepFeat_NoParts)
	.value("BRepFeat_NoProjPt", BRepFeat_StatusError::BRepFeat_NoProjPt)
	.value("BRepFeat_NotInitialized", BRepFeat_StatusError::BRepFeat_NotInitialized)
	.value("BRepFeat_NotYetImplemented", BRepFeat_StatusError::BRepFeat_NotYetImplemented)
	.value("BRepFeat_NullRealTool", BRepFeat_StatusError::BRepFeat_NullRealTool)
	.value("BRepFeat_NullToolF", BRepFeat_StatusError::BRepFeat_NullToolF)
	.value("BRepFeat_NullToolU", BRepFeat_StatusError::BRepFeat_NullToolU)
	.export_values();


}