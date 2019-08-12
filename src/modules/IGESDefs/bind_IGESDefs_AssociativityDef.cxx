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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDefs_AssociativityDef.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_AssociativityDef(py::module &mod){

py::class_<IGESDefs_AssociativityDef, opencascade::handle<IGESDefs_AssociativityDef>, IGESData_IGESEntity> cls_IGESDefs_AssociativityDef(mod, "IGESDefs_AssociativityDef", "defines IGES Associativity Definition Entity, Type <302> Form <5001 - 9999> in package IGESDefs. This class permits the preprocessor to define an associativity schema. i.e., by using it preprocessor defines the type of relationship.");

// Constructors
cls_IGESDefs_AssociativityDef.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_AssociativityDef.def("Init", (void (IGESDefs_AssociativityDef::*)(const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &)) &IGESDefs_AssociativityDef::Init, "This method is used to set the fields of the class AssociativityDef - requirements : Back Pointers requirements - orders : Class Orders - numItems : Number of Items per Class - items : Items in each class raises exception if lengths of the arrays are not the same.", py::arg("requirements"), py::arg("orders"), py::arg("numItems"), py::arg("items"));
cls_IGESDefs_AssociativityDef.def("SetFormNumber", (void (IGESDefs_AssociativityDef::*)(const Standard_Integer)) &IGESDefs_AssociativityDef::SetFormNumber, "None", py::arg("form"));
cls_IGESDefs_AssociativityDef.def("NbClassDefs", (Standard_Integer (IGESDefs_AssociativityDef::*)() const) &IGESDefs_AssociativityDef::NbClassDefs, "returns the Number of class definitions");
cls_IGESDefs_AssociativityDef.def("IsBackPointerReq", (Standard_Boolean (IGESDefs_AssociativityDef::*)(const Standard_Integer) const) &IGESDefs_AssociativityDef::IsBackPointerReq, "returns 1 if the theBackPointerReqs(ClassNum) = 1 returns 0 if the theBackPointerReqs(ClassNum) = 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
cls_IGESDefs_AssociativityDef.def("BackPointerReq", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const) &IGESDefs_AssociativityDef::BackPointerReq, "returns 1 or 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
cls_IGESDefs_AssociativityDef.def("IsOrdered", (Standard_Boolean (IGESDefs_AssociativityDef::*)(const Standard_Integer) const) &IGESDefs_AssociativityDef::IsOrdered, "returns 1 if theClassOrders(ClassNum) = 1 (ordered class) returns 0 if theClassOrders(ClassNum) = 2 (unordered class) raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
cls_IGESDefs_AssociativityDef.def("ClassOrder", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const) &IGESDefs_AssociativityDef::ClassOrder, "returns 1 or 2 raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
cls_IGESDefs_AssociativityDef.def("NbItemsPerClass", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer) const) &IGESDefs_AssociativityDef::NbItemsPerClass, "returns no. of items per class entry raises exception if ClassNum <= 0 or ClassNum > NbClassDefs()", py::arg("ClassNum"));
cls_IGESDefs_AssociativityDef.def("Item", (Standard_Integer (IGESDefs_AssociativityDef::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_AssociativityDef::Item, "returns ItemNum'th Item of ClassNum'th Class raises exception if ClassNum <= 0 or ClassNum > NbClassDefs() ItemNum <= 0 or ItemNum > NbItemsPerClass(ClassNum)", py::arg("ClassNum"), py::arg("ItemNum"));
cls_IGESDefs_AssociativityDef.def_static("get_type_name_", (const char * (*)()) &IGESDefs_AssociativityDef::get_type_name, "None");
cls_IGESDefs_AssociativityDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_AssociativityDef::get_type_descriptor, "None");
cls_IGESDefs_AssociativityDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_AssociativityDef::*)() const) &IGESDefs_AssociativityDef::DynamicType, "None");

// Enums

}