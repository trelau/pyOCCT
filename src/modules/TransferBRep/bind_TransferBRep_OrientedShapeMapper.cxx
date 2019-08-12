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
#include <Transfer_Finder.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TransferBRep_OrientedShapeMapper.hxx>

void bind_TransferBRep_OrientedShapeMapper(py::module &mod){

py::class_<TransferBRep_OrientedShapeMapper, opencascade::handle<TransferBRep_OrientedShapeMapper>, Transfer_Finder> cls_TransferBRep_OrientedShapeMapper(mod, "TransferBRep_OrientedShapeMapper", "None");

// Constructors
cls_TransferBRep_OrientedShapeMapper.def(py::init<const TopoDS_Shape &>(), py::arg("akey"));

// Fields

// Methods
cls_TransferBRep_OrientedShapeMapper.def("Value", (const TopoDS_Shape & (TransferBRep_OrientedShapeMapper::*)() const) &TransferBRep_OrientedShapeMapper::Value, "Returns the contained value");
cls_TransferBRep_OrientedShapeMapper.def("Equates", (Standard_Boolean (TransferBRep_OrientedShapeMapper::*)(const opencascade::handle<Transfer_Finder> &) const) &TransferBRep_OrientedShapeMapper::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
cls_TransferBRep_OrientedShapeMapper.def("ValueType", (opencascade::handle<Standard_Type> (TransferBRep_OrientedShapeMapper::*)() const) &TransferBRep_OrientedShapeMapper::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_TransferBRep_OrientedShapeMapper.def("ValueTypeName", (Standard_CString (TransferBRep_OrientedShapeMapper::*)() const) &TransferBRep_OrientedShapeMapper::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_TransferBRep_OrientedShapeMapper.def_static("get_type_name_", (const char * (*)()) &TransferBRep_OrientedShapeMapper::get_type_name, "None");
cls_TransferBRep_OrientedShapeMapper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TransferBRep_OrientedShapeMapper::get_type_descriptor, "None");
cls_TransferBRep_OrientedShapeMapper.def("DynamicType", (const opencascade::handle<Standard_Type> & (TransferBRep_OrientedShapeMapper::*)() const) &TransferBRep_OrientedShapeMapper::DynamicType, "None");

// Enums

}