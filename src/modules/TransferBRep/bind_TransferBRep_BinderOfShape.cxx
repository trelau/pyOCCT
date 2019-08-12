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
#include <Transfer_Binder.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TransferBRep_BinderOfShape.hxx>

void bind_TransferBRep_BinderOfShape(py::module &mod){

py::class_<TransferBRep_BinderOfShape, opencascade::handle<TransferBRep_BinderOfShape>, Transfer_Binder> cls_TransferBRep_BinderOfShape(mod, "TransferBRep_BinderOfShape", "Allows direct binding between a starting Object and the Result of its transfer when it is Unique. The Result itself is defined as a formal parameter <Shape from TopoDS> Warning : While it is possible to instantiate BinderOfShape with any Type for the Result, it is not advisable to instantiate it with Transient Classes, because such Results are directly known and managed by TransferProcess & Co, through SimpleBinderOfTransient : this class looks like instantiation of BinderOfShape, but its method ResultType is adapted (reads DynamicType of the Result)");

// Constructors
cls_TransferBRep_BinderOfShape.def(py::init<>());
cls_TransferBRep_BinderOfShape.def(py::init<const TopoDS_Shape &>(), py::arg("res"));

// Fields

// Methods
cls_TransferBRep_BinderOfShape.def("ResultType", (opencascade::handle<Standard_Type> (TransferBRep_BinderOfShape::*)() const) &TransferBRep_BinderOfShape::ResultType, "Returns the Type permitted for the Result, i.e. the Type of the Parameter Class <Shape from TopoDS> (statically defined)");
cls_TransferBRep_BinderOfShape.def("ResultTypeName", (Standard_CString (TransferBRep_BinderOfShape::*)() const) &TransferBRep_BinderOfShape::ResultTypeName, "Returns the Type Name computed for the Result (dynamic)");
cls_TransferBRep_BinderOfShape.def("SetResult", (void (TransferBRep_BinderOfShape::*)(const TopoDS_Shape &)) &TransferBRep_BinderOfShape::SetResult, "Defines the Result", py::arg("res"));
cls_TransferBRep_BinderOfShape.def("Result", (const TopoDS_Shape & (TransferBRep_BinderOfShape::*)() const) &TransferBRep_BinderOfShape::Result, "Returns the defined Result, if there is one");
cls_TransferBRep_BinderOfShape.def("CResult", (TopoDS_Shape & (TransferBRep_BinderOfShape::*)()) &TransferBRep_BinderOfShape::CResult, "Returns the defined Result, if there is one, and allows to change it (avoids Result + SetResult). Admits that Result can be not yet defined Warning : a call to CResult causes Result to be known as defined");
cls_TransferBRep_BinderOfShape.def_static("get_type_name_", (const char * (*)()) &TransferBRep_BinderOfShape::get_type_name, "None");
cls_TransferBRep_BinderOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_BinderOfShape::get_type_descriptor, "None");
cls_TransferBRep_BinderOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_BinderOfShape::*)() const) &TransferBRep_BinderOfShape::DynamicType, "None");

// Enums

}