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
#include <ShapeUpgrade_Tool.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_RemoveInternalWires.hxx>
#include <Standard_Type.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>

void bind_ShapeUpgrade_RemoveInternalWires(py::module &mod){

py::class_<ShapeUpgrade_RemoveInternalWires, opencascade::handle<ShapeUpgrade_RemoveInternalWires>, ShapeUpgrade_Tool> cls_ShapeUpgrade_RemoveInternalWires(mod, "ShapeUpgrade_RemoveInternalWires", "Removes all internal wires having area less than specified min area");

// Constructors
cls_ShapeUpgrade_RemoveInternalWires.def(py::init<>());
cls_ShapeUpgrade_RemoveInternalWires.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Fields

// Methods
cls_ShapeUpgrade_RemoveInternalWires.def("Init", (void (ShapeUpgrade_RemoveInternalWires::*)(const TopoDS_Shape &)) &ShapeUpgrade_RemoveInternalWires::Init, "Initialize by a Shape.", py::arg("theShape"));
cls_ShapeUpgrade_RemoveInternalWires.def("Perform", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::Perform, "Removes all internal wires having area less than area specified as minimal allowed area");
cls_ShapeUpgrade_RemoveInternalWires.def("Perform", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)(const TopTools_SequenceOfShape &)) &ShapeUpgrade_RemoveInternalWires::Perform, "If specified sequence of shape contains - 1.wires then these wires will be removed if they have area less than allowed min area. 2.faces than internal wires from these faces will be removed if they have area less than allowed min area.", py::arg("theSeqShapes"));
cls_ShapeUpgrade_RemoveInternalWires.def("GetResult", (TopoDS_Shape (ShapeUpgrade_RemoveInternalWires::*)() const) &ShapeUpgrade_RemoveInternalWires::GetResult, "Get result shape");
cls_ShapeUpgrade_RemoveInternalWires.def("MinArea", (Standard_Real & (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::MinArea, "Set min area allowed for holes( all holes having area less than mi area will be removed)");
cls_ShapeUpgrade_RemoveInternalWires.def("RemoveFaceMode", (Standard_Boolean & (ShapeUpgrade_RemoveInternalWires::*)()) &ShapeUpgrade_RemoveInternalWires::RemoveFaceMode, "Set mode which manage removing faces which have outer wires consisting only from edges belonginig to removed internal wires. By default it is equal to true.");
cls_ShapeUpgrade_RemoveInternalWires.def("RemovedFaces", (const TopTools_SequenceOfShape & (ShapeUpgrade_RemoveInternalWires::*)() const) &ShapeUpgrade_RemoveInternalWires::RemovedFaces, "Returns sequence of removed faces.");
cls_ShapeUpgrade_RemoveInternalWires.def("RemovedWires", (const TopTools_SequenceOfShape & (ShapeUpgrade_RemoveInternalWires::*)() const) &ShapeUpgrade_RemoveInternalWires::RemovedWires, "Returns sequence of removed faces.");
cls_ShapeUpgrade_RemoveInternalWires.def("Status", (Standard_Boolean (ShapeUpgrade_RemoveInternalWires::*)(const ShapeExtend_Status) const) &ShapeUpgrade_RemoveInternalWires::Status, "Queries status of last call to Perform() : OK - nothing was done :DONE1 - internal wires were removed :DONE2 - small faces were removed. :FAIL1 - initial shape is not specified :FAIL2 - specified sub-shape is not belonged to inotial shape.", py::arg("theStatus"));
cls_ShapeUpgrade_RemoveInternalWires.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_RemoveInternalWires::get_type_name, "None");
cls_ShapeUpgrade_RemoveInternalWires.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_RemoveInternalWires::get_type_descriptor, "None");
cls_ShapeUpgrade_RemoveInternalWires.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_RemoveInternalWires::*)() const) &ShapeUpgrade_RemoveInternalWires::DynamicType, "None");

// Enums

}