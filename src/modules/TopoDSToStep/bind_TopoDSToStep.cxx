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
#include <TopoDSToStep_BuilderError.hxx>
#include <TopoDSToStep_MakeFaceError.hxx>
#include <TopoDSToStep_MakeWireError.hxx>
#include <TopoDSToStep_MakeEdgeError.hxx>
#include <TopoDSToStep_MakeVertexError.hxx>
#include <Transfer_FinderProcess.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <TopoDSToStep_Root.hxx>
#include <TopoDSToStep_MakeManifoldSolidBrep.hxx>
#include <TopoDSToStep_MakeBrepWithVoids.hxx>
#include <TopoDSToStep_MakeFacetedBrep.hxx>
#include <TopoDSToStep_MakeFacetedBrepAndBrepWithVoids.hxx>
#include <TopoDSToStep_MakeShellBasedSurfaceModel.hxx>
#include <TopoDSToStep_MakeGeometricCurveSet.hxx>
#include <TopoDSToStep_Builder.hxx>
#include <TopoDSToStep_WireframeBuilder.hxx>
#include <TopoDSToStep_FacetedTool.hxx>
#include <TopoDSToStep_MakeStepFace.hxx>
#include <TopoDSToStep_MakeStepWire.hxx>
#include <TopoDSToStep_MakeStepEdge.hxx>
#include <TopoDSToStep_MakeStepVertex.hxx>
#include <TopoDSToStep.hxx>

void bind_TopoDSToStep(py::module &mod){

py::class_<TopoDSToStep> cls_TopoDSToStep(mod, "TopoDSToStep", "This package implements the mapping between CAS.CAD Shape representation and AP214 Shape Representation. The target schema is pms_c4 (a subset of AP214)");

// Constructors

// Fields

// Methods
// cls_TopoDSToStep.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep.def_static("DecodeBuilderError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_BuilderError)) &TopoDSToStep::DecodeBuilderError, "None", py::arg("E"));
cls_TopoDSToStep.def_static("DecodeFaceError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeFaceError)) &TopoDSToStep::DecodeFaceError, "None", py::arg("E"));
cls_TopoDSToStep.def_static("DecodeWireError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeWireError)) &TopoDSToStep::DecodeWireError, "None", py::arg("E"));
cls_TopoDSToStep.def_static("DecodeEdgeError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeEdgeError)) &TopoDSToStep::DecodeEdgeError, "None", py::arg("E"));
cls_TopoDSToStep.def_static("DecodeVertexError_", (opencascade::handle<TCollection_HAsciiString> (*)(const TopoDSToStep_MakeVertexError)) &TopoDSToStep::DecodeVertexError, "Returns a new shape without undirect surfaces.", py::arg("E"));
cls_TopoDSToStep.def_static("AddResult_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &)) &TopoDSToStep::AddResult, "Adds an entity into the list of results (binders) for shape stored in FinderProcess", py::arg("FP"), py::arg("Shape"), py::arg("entity"));
cls_TopoDSToStep.def_static("AddResult_", (void (*)(const opencascade::handle<Transfer_FinderProcess> &, const TopoDSToStep_Tool &)) &TopoDSToStep::AddResult, "Adds all entities recorded in Tool into the map of results (binders) stored in FinderProcess", py::arg("FP"), py::arg("Tool"));

// Enums

}