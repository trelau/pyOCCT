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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <BRepOffset_MakeSimpleOffset.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepTools_Modifier.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>

void bind_BRepOffset_MakeSimpleOffset(py::module &mod){

py::class_<BRepOffset_MakeSimpleOffset, std::unique_ptr<BRepOffset_MakeSimpleOffset>> cls_BRepOffset_MakeSimpleOffset(mod, "BRepOffset_MakeSimpleOffset", "Limitations: According to the algorithm nature result depends on the smoothness of input data. Smooth (G1-continuity) input shape will lead to the good result.");

// Constructors
cls_BRepOffset_MakeSimpleOffset.def(py::init<>());
cls_BRepOffset_MakeSimpleOffset.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("theInputShape"), py::arg("theOffsetValue"));

// Fields

// Methods
cls_BRepOffset_MakeSimpleOffset.def("Initialize", (void (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &, const Standard_Real)) &BRepOffset_MakeSimpleOffset::Initialize, "Initialies shape for modifications.", py::arg("theInputShape"), py::arg("theOffsetValue"));
cls_BRepOffset_MakeSimpleOffset.def("Perform", (void (BRepOffset_MakeSimpleOffset::*)()) &BRepOffset_MakeSimpleOffset::Perform, "Computes offset shape.");
cls_BRepOffset_MakeSimpleOffset.def("GetErrorMessage", (TCollection_AsciiString (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetErrorMessage, "Gets error message.");
cls_BRepOffset_MakeSimpleOffset.def("GetError", (BRepOffsetSimple_Status (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetError, "Gets error code.");
cls_BRepOffset_MakeSimpleOffset.def("GetBuildSolidFlag", (Standard_Boolean (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetBuildSolidFlag, "Gets solid building flag.");
cls_BRepOffset_MakeSimpleOffset.def("SetBuildSolidFlag", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Boolean)) &BRepOffset_MakeSimpleOffset::SetBuildSolidFlag, "Sets solid building flag.", py::arg("theBuildFlag"));
cls_BRepOffset_MakeSimpleOffset.def("GetOffsetValue", (Standard_Real (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetOffsetValue, "Gets offset value.");
cls_BRepOffset_MakeSimpleOffset.def("SetOffsetValue", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::SetOffsetValue, "Sets offset value.", py::arg("theOffsetValue"));
cls_BRepOffset_MakeSimpleOffset.def("GetTolerance", (Standard_Real (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetTolerance, "Gets tolerance (used for handling singularities).");
cls_BRepOffset_MakeSimpleOffset.def("SetTolerance", (void (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::SetTolerance, "Sets tolerance (used for handling singularities).", py::arg("theValue"));
cls_BRepOffset_MakeSimpleOffset.def("IsDone", (Standard_Boolean (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::IsDone, "Gets done state.");
cls_BRepOffset_MakeSimpleOffset.def("GetResultShape", (const TopoDS_Shape & (BRepOffset_MakeSimpleOffset::*)() const) &BRepOffset_MakeSimpleOffset::GetResultShape, "Returns result shape.");
// cls_BRepOffset_MakeSimpleOffset.def("GetSafeOffset", (Standard_Real (BRepOffset_MakeSimpleOffset::*)(const Standard_Real)) &BRepOffset_MakeSimpleOffset::GetSafeOffset, "Computes max safe offset value for the given tolerance.", py::arg("theExpectedToler"));
cls_BRepOffset_MakeSimpleOffset.def("Generated", (const TopoDS_Shape (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &) const) &BRepOffset_MakeSimpleOffset::Generated, "Returnes result shape for the given one (if exists).", py::arg("theShape"));
cls_BRepOffset_MakeSimpleOffset.def("Modified", (const TopoDS_Shape (BRepOffset_MakeSimpleOffset::*)(const TopoDS_Shape &) const) &BRepOffset_MakeSimpleOffset::Modified, "Returnes modified shape for the given one (if exists).", py::arg("theShape"));

// Enums

}