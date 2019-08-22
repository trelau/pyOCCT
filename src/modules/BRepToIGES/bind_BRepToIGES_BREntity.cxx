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
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <Transfer_FinderProcess.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Transient.hxx>
#include <BRepToIGES_BREntity.hxx>

void bind_BRepToIGES_BREntity(py::module &mod){

py::class_<BRepToIGES_BREntity> cls_BRepToIGES_BREntity(mod, "BRepToIGES_BREntity", "provides methods to transfer BRep entity from CASCADE to IGES.");

// Constructors
cls_BRepToIGES_BREntity.def(py::init<>());

// Fields

// Methods
// cls_BRepToIGES_BREntity.def_static("operator new_", (void * (*)(size_t)) &BRepToIGES_BREntity::operator new, "None", py::arg("theSize"));
// cls_BRepToIGES_BREntity.def_static("operator delete_", (void (*)(void *)) &BRepToIGES_BREntity::operator delete, "None", py::arg("theAddress"));
// cls_BRepToIGES_BREntity.def_static("operator new[]_", (void * (*)(size_t)) &BRepToIGES_BREntity::operator new[], "None", py::arg("theSize"));
// cls_BRepToIGES_BREntity.def_static("operator delete[]_", (void (*)(void *)) &BRepToIGES_BREntity::operator delete[], "None", py::arg("theAddress"));
// cls_BRepToIGES_BREntity.def_static("operator new_", (void * (*)(size_t, void *)) &BRepToIGES_BREntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepToIGES_BREntity.def_static("operator delete_", (void (*)(void *, void *)) &BRepToIGES_BREntity::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepToIGES_BREntity.def("Init", (void (BRepToIGES_BREntity::*)()) &BRepToIGES_BREntity::Init, "Initializes the field of the tool BREntity with default creating values.");
cls_BRepToIGES_BREntity.def("SetModel", (void (BRepToIGES_BREntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &BRepToIGES_BREntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
cls_BRepToIGES_BREntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (BRepToIGES_BREntity::*)() const) &BRepToIGES_BREntity::GetModel, "Returns the value of 'TheModel'");
cls_BRepToIGES_BREntity.def("GetUnit", (Standard_Real (BRepToIGES_BREntity::*)() const) &BRepToIGES_BREntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in meters.");
cls_BRepToIGES_BREntity.def("SetTransferProcess", (void (BRepToIGES_BREntity::*)(const opencascade::handle<Transfer_FinderProcess> &)) &BRepToIGES_BREntity::SetTransferProcess, "Set the value of 'TheMap'", py::arg("TP"));
cls_BRepToIGES_BREntity.def("GetTransferProcess", (opencascade::handle<Transfer_FinderProcess> (BRepToIGES_BREntity::*)() const) &BRepToIGES_BREntity::GetTransferProcess, "Returns the value of 'TheMap'");
cls_BRepToIGES_BREntity.def("TransferShape", (opencascade::handle<IGESData_IGESEntity> (BRepToIGES_BREntity::*)(const TopoDS_Shape &)) &BRepToIGES_BREntity::TransferShape, "Returns the result of the transfert of any Shape If the transfer has failed, this member return a NullEntity.", py::arg("start"));
cls_BRepToIGES_BREntity.def("AddFail", (void (BRepToIGES_BREntity::*)(const TopoDS_Shape &, const Standard_CString)) &BRepToIGES_BREntity::AddFail, "Records a new Fail message", py::arg("start"), py::arg("amess"));
cls_BRepToIGES_BREntity.def("AddWarning", (void (BRepToIGES_BREntity::*)(const TopoDS_Shape &, const Standard_CString)) &BRepToIGES_BREntity::AddWarning, "Records a new Warning message", py::arg("start"), py::arg("amess"));
cls_BRepToIGES_BREntity.def("AddFail", (void (BRepToIGES_BREntity::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &BRepToIGES_BREntity::AddFail, "Records a new Fail message", py::arg("start"), py::arg("amess"));
cls_BRepToIGES_BREntity.def("AddWarning", (void (BRepToIGES_BREntity::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &BRepToIGES_BREntity::AddWarning, "Records a new Warning message", py::arg("start"), py::arg("amess"));
cls_BRepToIGES_BREntity.def("HasShapeResult", (Standard_Boolean (BRepToIGES_BREntity::*)(const TopoDS_Shape &) const) &BRepToIGES_BREntity::HasShapeResult, "Returns True if start was already treated and has a result in 'TheMap' else returns False.", py::arg("start"));
cls_BRepToIGES_BREntity.def("GetShapeResult", (opencascade::handle<Standard_Transient> (BRepToIGES_BREntity::*)(const TopoDS_Shape &) const) &BRepToIGES_BREntity::GetShapeResult, "Returns the result of the transfer of the Shape 'start' contained in 'TheMap' . (if HasShapeResult is True).", py::arg("start"));
cls_BRepToIGES_BREntity.def("SetShapeResult", (void (BRepToIGES_BREntity::*)(const TopoDS_Shape &, const opencascade::handle<Standard_Transient> &)) &BRepToIGES_BREntity::SetShapeResult, "set in 'TheMap' the result of the transfer of the Shape 'start'.", py::arg("start"), py::arg("result"));
cls_BRepToIGES_BREntity.def("HasShapeResult", (Standard_Boolean (BRepToIGES_BREntity::*)(const opencascade::handle<Standard_Transient> &) const) &BRepToIGES_BREntity::HasShapeResult, "Returns True if start was already treated and has a result in 'TheMap' else returns False.", py::arg("start"));
cls_BRepToIGES_BREntity.def("GetShapeResult", (opencascade::handle<Standard_Transient> (BRepToIGES_BREntity::*)(const opencascade::handle<Standard_Transient> &) const) &BRepToIGES_BREntity::GetShapeResult, "Returns the result of the transfer of the Transient 'start' contained in 'TheMap' . (if HasShapeResult is True).", py::arg("start"));
cls_BRepToIGES_BREntity.def("SetShapeResult", (void (BRepToIGES_BREntity::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &BRepToIGES_BREntity::SetShapeResult, "set in 'TheMap' the result of the transfer of the Transient 'start'.", py::arg("start"), py::arg("result"));
cls_BRepToIGES_BREntity.def("GetConvertSurfaceMode", (Standard_Boolean (BRepToIGES_BREntity::*)() const) &BRepToIGES_BREntity::GetConvertSurfaceMode, "Returns mode for conversion of surfaces (value of parameter write.convertsurface.mode)");
cls_BRepToIGES_BREntity.def("GetPCurveMode", (Standard_Boolean (BRepToIGES_BREntity::*)() const) &BRepToIGES_BREntity::GetPCurveMode, "Returns mode for writing pcurves (value of parameter write.surfacecurve.mode)");

// Enums

}