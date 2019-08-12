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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepToTopoDS_BuilderError.hxx>
#include <StepToTopoDS_TranslateShellError.hxx>
#include <StepToTopoDS_TranslateFaceError.hxx>
#include <StepToTopoDS_TranslateEdgeError.hxx>
#include <StepToTopoDS_TranslateVertexError.hxx>
#include <StepToTopoDS_TranslateVertexLoopError.hxx>
#include <StepToTopoDS_TranslatePolyLoopError.hxx>
#include <Standard_TypeDef.hxx>
#include <StepToTopoDS_GeometricToolError.hxx>
#include <StepToTopoDS_Root.hxx>
#include <StepToTopoDS_TranslateShell.hxx>
#include <StepToTopoDS_TranslateFace.hxx>
#include <StepToTopoDS_TranslateEdgeLoop.hxx>
#include <StepToTopoDS_TranslateEdge.hxx>
#include <StepToTopoDS_TranslateVertex.hxx>
#include <StepToTopoDS_TranslatePolyLoop.hxx>
#include <StepToTopoDS_TranslateVertexLoop.hxx>
#include <StepToTopoDS_TranslateCompositeCurve.hxx>
#include <StepToTopoDS_TranslateCurveBoundedSurface.hxx>
#include <StepToTopoDS_Builder.hxx>
#include <StepToTopoDS_MakeTransformed.hxx>
#include <StepToTopoDS_GeometricTool.hxx>
#include <StepToTopoDS_Tool.hxx>
#include <StepToTopoDS_CartesianPointHasher.hxx>
#include <StepToTopoDS_PointPair.hxx>
#include <StepToTopoDS_PointPairHasher.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <StepToTopoDS.hxx>

void bind_StepToTopoDS(py::module &mod){

py::class_<StepToTopoDS, std::unique_ptr<StepToTopoDS, Deleter<StepToTopoDS>>> cls_StepToTopoDS(mod, "StepToTopoDS", "This package implements the mapping between AP214 Shape representation and CAS.CAD Shape Representation. The source schema is Part42 (which is included in AP214)");

// Constructors

// Fields

// Methods
// cls_StepToTopoDS.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS.def_static("DecodeBuilderError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_BuilderError)) &StepToTopoDS::DecodeBuilderError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeShellError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateShellError)) &StepToTopoDS::DecodeShellError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeFaceError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateFaceError)) &StepToTopoDS::DecodeFaceError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeEdgeError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateEdgeError)) &StepToTopoDS::DecodeEdgeError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeVertexError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateVertexError)) &StepToTopoDS::DecodeVertexError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeVertexLoopError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslateVertexLoopError)) &StepToTopoDS::DecodeVertexLoopError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodePolyLoopError_", (opencascade::handle<TCollection_HAsciiString> (*)(const StepToTopoDS_TranslatePolyLoopError)) &StepToTopoDS::DecodePolyLoopError, "None", py::arg("Error"));
cls_StepToTopoDS.def_static("DecodeGeometricToolError_", (Standard_CString (*)(const StepToTopoDS_GeometricToolError)) &StepToTopoDS::DecodeGeometricToolError, "None", py::arg("Error"));

// Enums

}