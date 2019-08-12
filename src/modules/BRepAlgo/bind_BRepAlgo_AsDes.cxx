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
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepAlgo_AsDes.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>

void bind_BRepAlgo_AsDes(py::module &mod){

py::class_<BRepAlgo_AsDes, opencascade::handle<BRepAlgo_AsDes>, Standard_Transient> cls_BRepAlgo_AsDes(mod, "BRepAlgo_AsDes", "SD to store descendants and ascendants of Shapes.");

// Constructors
cls_BRepAlgo_AsDes.def(py::init<>());

// Fields

// Methods
cls_BRepAlgo_AsDes.def("Clear", (void (BRepAlgo_AsDes::*)()) &BRepAlgo_AsDes::Clear, "None");
cls_BRepAlgo_AsDes.def("Add", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_AsDes::Add, "Stores <SS> as a futur subshape of <S>.", py::arg("S"), py::arg("SS"));
cls_BRepAlgo_AsDes.def("Add", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &BRepAlgo_AsDes::Add, "Stores <SS> as futurs SubShapes of <S>.", py::arg("S"), py::arg("SS"));
cls_BRepAlgo_AsDes.def("HasAscendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const) &BRepAlgo_AsDes::HasAscendant, "None", py::arg("S"));
cls_BRepAlgo_AsDes.def("HasDescendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const) &BRepAlgo_AsDes::HasDescendant, "None", py::arg("S"));
cls_BRepAlgo_AsDes.def("Ascendant", (const TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const) &BRepAlgo_AsDes::Ascendant, "Returns the Shape containing <S>.", py::arg("S"));
cls_BRepAlgo_AsDes.def("Descendant", (const TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &) const) &BRepAlgo_AsDes::Descendant, "Returns futur subhapes of <S>.", py::arg("S"));
cls_BRepAlgo_AsDes.def("ChangeDescendant", (TopTools_ListOfShape & (BRepAlgo_AsDes::*)(const TopoDS_Shape &)) &BRepAlgo_AsDes::ChangeDescendant, "Returns futur subhapes of <S>.", py::arg("S"));
cls_BRepAlgo_AsDes.def("Replace", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_AsDes::Replace, "Replace <OldS> by <NewS>. <OldS> disapear from <me>.", py::arg("OldS"), py::arg("NewS"));
cls_BRepAlgo_AsDes.def("Remove", (void (BRepAlgo_AsDes::*)(const TopoDS_Shape &)) &BRepAlgo_AsDes::Remove, "Remove <S> from me.", py::arg("S"));
cls_BRepAlgo_AsDes.def("HasCommonDescendant", (Standard_Boolean (BRepAlgo_AsDes::*)(const TopoDS_Shape &, const TopoDS_Shape &, TopTools_ListOfShape &) const) &BRepAlgo_AsDes::HasCommonDescendant, "Returns True if (S1> and <S2> has common Descendants. Stores in <LC> the Commons Descendants.", py::arg("S1"), py::arg("S2"), py::arg("LC"));
cls_BRepAlgo_AsDes.def_static("get_type_name_", (const char * (*)()) &BRepAlgo_AsDes::get_type_name, "None");
cls_BRepAlgo_AsDes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAlgo_AsDes::get_type_descriptor, "None");
cls_BRepAlgo_AsDes.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAlgo_AsDes::*)() const) &BRepAlgo_AsDes::DynamicType, "None");

// Enums

}