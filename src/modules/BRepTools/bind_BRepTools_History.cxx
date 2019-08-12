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
#include <Standard_Transient.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepTools_History.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_MapOfShape.hxx>

void bind_BRepTools_History(py::module &mod){

py::class_<BRepTools_History, opencascade::handle<BRepTools_History>, Standard_Transient> cls_BRepTools_History(mod, "BRepTools_History", "The history keeps the following relations between the input shapes (S1, ..., Sm) and output shapes (T1, ..., Tn): 1) an output shape Tj is generated from an input shape Si: Tj <= G(Si); 2) a output shape Tj is modified from an input shape Si: Tj <= M(Si); 3) an input shape (Si) is removed: R(Si) == 1.");

// Constructors
cls_BRepTools_History.def(py::init<>());

// Fields

// Methods
cls_BRepTools_History.def_static("IsSupportedType_", (Standard_Boolean (*)(const TopoDS_Shape &)) &BRepTools_History::IsSupportedType, "Returns 'true' if the type of the shape is supported by the history.", py::arg("theShape"));
cls_BRepTools_History.def("AddGenerated", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::AddGenerated, "Set the second shape as generated one from the first shape.", py::arg("theInitial"), py::arg("theGenerated"));
cls_BRepTools_History.def("AddModified", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::AddModified, "Set the second shape as modified one from the first shape.", py::arg("theInitial"), py::arg("theModified"));
cls_BRepTools_History.def("Remove", (void (BRepTools_History::*)(const TopoDS_Shape &)) &BRepTools_History::Remove, "Set the shape as removed one.", py::arg("theRemoved"));
cls_BRepTools_History.def("ReplaceGenerated", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::ReplaceGenerated, "Set the second shape as the only generated one from the first one.", py::arg("theInitial"), py::arg("theGenerated"));
cls_BRepTools_History.def("ReplaceModified", (void (BRepTools_History::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepTools_History::ReplaceModified, "Set the second shape as the only modified one from the first one.", py::arg("theInitial"), py::arg("theModified"));
cls_BRepTools_History.def("Clear", (void (BRepTools_History::*)()) &BRepTools_History::Clear, "Clears the history.");
cls_BRepTools_History.def("Generated", (const TopTools_ListOfShape & (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::Generated, "Returns all shapes generated from the shape.", py::arg("theInitial"));
cls_BRepTools_History.def("Modified", (const TopTools_ListOfShape & (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::Modified, "Returns all shapes modified from the shape.", py::arg("theInitial"));
cls_BRepTools_History.def("IsRemoved", (Standard_Boolean (BRepTools_History::*)(const TopoDS_Shape &) const) &BRepTools_History::IsRemoved, "Returns 'true' if the shape is removed.", py::arg("theInitial"));
cls_BRepTools_History.def("Merge", (void (BRepTools_History::*)(const opencascade::handle<BRepTools_History> &)) &BRepTools_History::Merge, "Merges the next history to this history.", py::arg("theHistory23"));
cls_BRepTools_History.def("Merge", (void (BRepTools_History::*)(const BRepTools_History &)) &BRepTools_History::Merge, "Merges the next history to this history.", py::arg("theHistory23"));
cls_BRepTools_History.def("Dump", (void (BRepTools_History::*)(Standard_OStream &)) &BRepTools_History::Dump, "Prints the brief description of the history into a stream", py::arg("theS"));
cls_BRepTools_History.def_static("get_type_name_", (const char * (*)()) &BRepTools_History::get_type_name, "None");
cls_BRepTools_History.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_History::get_type_descriptor, "None");
cls_BRepTools_History.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_History::*)() const) &BRepTools_History::DynamicType, "None");

// Enums
py::enum_<BRepTools_History::TRelationType>(cls_BRepTools_History, "TRelationType", "The types of the historical relations.")
	.value("TRelationType_Removed", BRepTools_History::TRelationType::TRelationType_Removed)
	.value("TRelationType_Generated", BRepTools_History::TRelationType::TRelationType_Generated)
	.value("TRelationType_Modified", BRepTools_History::TRelationType::TRelationType_Modified)
	.export_values();

}