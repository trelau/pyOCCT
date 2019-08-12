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
#include <Transfer_ActorOfFinderProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Finder.hxx>
#include <Transfer_Binder.hxx>
#include <Transfer_FinderProcess.hxx>
#include <StepShape_ShapeDefinitionRepresentation.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <STEPControl_StepModelType.hxx>
#include <TopoDS_Shape.hxx>
#include <STEPControl_ActorWrite.hxx>
#include <Standard_Type.hxx>
#include <StepShape_NonManifoldSurfaceShapeRepresentation.hxx>
#include <Standard_Transient.hxx>
#include <STEPConstruct_ContextTool.hxx>

void bind_STEPControl_ActorWrite(py::module &mod){

py::class_<STEPControl_ActorWrite, opencascade::handle<STEPControl_ActorWrite>, Transfer_ActorOfFinderProcess> cls_STEPControl_ActorWrite(mod, "STEPControl_ActorWrite", "This class performs the transfer of a Shape from TopoDS to AP203 or AP214 (CD2 or DIS)");

// Constructors
cls_STEPControl_ActorWrite.def(py::init<>());

// Fields

// Methods
cls_STEPControl_ActorWrite.def("Recognize", (Standard_Boolean (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &)) &STEPControl_ActorWrite::Recognize, "None", py::arg("start"));
cls_STEPControl_ActorWrite.def("Transfer", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &STEPControl_ActorWrite::Transfer, "None", py::arg("start"), py::arg("FP"));
cls_STEPControl_ActorWrite.def("TransferSubShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, opencascade::handle<StepGeom_Axis2Placement3d> & a2, const opencascade::handle<Transfer_FinderProcess> & a3) -> opencascade::handle<Transfer_Binder> { return self.TransferSubShape(a0, a1, a2, a3); });
cls_STEPControl_ActorWrite.def("TransferSubShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, opencascade::handle<StepGeom_Axis2Placement3d> & a2, const opencascade::handle<Transfer_FinderProcess> & a3, const opencascade::handle<TopTools_HSequenceOfShape> & a4) -> opencascade::handle<Transfer_Binder> { return self.TransferSubShape(a0, a1, a2, a3, a4); });
cls_STEPControl_ActorWrite.def("TransferSubShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Boolean)) &STEPControl_ActorWrite::TransferSubShape, "None", py::arg("start"), py::arg("SDR"), py::arg("AX1"), py::arg("FP"), py::arg("shapeGroup"), py::arg("isManifold"));
cls_STEPControl_ActorWrite.def("TransferShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, const opencascade::handle<Transfer_FinderProcess> & a2) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1, a2); });
cls_STEPControl_ActorWrite.def("TransferShape", [](STEPControl_ActorWrite &self, const opencascade::handle<Transfer_Finder> & a0, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> & a1, const opencascade::handle<Transfer_FinderProcess> & a2, const opencascade::handle<TopTools_HSequenceOfShape> & a3) -> opencascade::handle<Transfer_Binder> { return self.TransferShape(a0, a1, a2, a3); });
cls_STEPControl_ActorWrite.def("TransferShape", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_Boolean)) &STEPControl_ActorWrite::TransferShape, "None", py::arg("start"), py::arg("SDR"), py::arg("FP"), py::arg("shapeGroup"), py::arg("isManifold"));
cls_STEPControl_ActorWrite.def("TransferCompound", (opencascade::handle<Transfer_Binder> (STEPControl_ActorWrite::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<StepShape_ShapeDefinitionRepresentation> &, const opencascade::handle<Transfer_FinderProcess> &)) &STEPControl_ActorWrite::TransferCompound, "None", py::arg("start"), py::arg("SDR"), py::arg("FP"));
cls_STEPControl_ActorWrite.def("SetMode", (void (STEPControl_ActorWrite::*)(const STEPControl_StepModelType)) &STEPControl_ActorWrite::SetMode, "None", py::arg("M"));
cls_STEPControl_ActorWrite.def("Mode", (STEPControl_StepModelType (STEPControl_ActorWrite::*)() const) &STEPControl_ActorWrite::Mode, "None");
cls_STEPControl_ActorWrite.def("SetGroupMode", (void (STEPControl_ActorWrite::*)(const Standard_Integer)) &STEPControl_ActorWrite::SetGroupMode, "None", py::arg("mode"));
cls_STEPControl_ActorWrite.def("GroupMode", (Standard_Integer (STEPControl_ActorWrite::*)() const) &STEPControl_ActorWrite::GroupMode, "None");
cls_STEPControl_ActorWrite.def("SetTolerance", (void (STEPControl_ActorWrite::*)(const Standard_Real)) &STEPControl_ActorWrite::SetTolerance, "None", py::arg("Tol"));
cls_STEPControl_ActorWrite.def("IsAssembly", (Standard_Boolean (STEPControl_ActorWrite::*)(TopoDS_Shape &) const) &STEPControl_ActorWrite::IsAssembly, "Customizable method to check whether shape S should be written as assembly or not Default implementation uses flag GroupMode and analyses the shape itself NOTE: this method can modify shape", py::arg("S"));
cls_STEPControl_ActorWrite.def_static("get_type_name_", (const char * (*)()) &STEPControl_ActorWrite::get_type_name, "None");
cls_STEPControl_ActorWrite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &STEPControl_ActorWrite::get_type_descriptor, "None");
cls_STEPControl_ActorWrite.def("DynamicType", (const opencascade::handle<Standard_Type> & (STEPControl_ActorWrite::*)() const) &STEPControl_ActorWrite::DynamicType, "None");

// Enums

}