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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESGeom_HArray1OfTransformationMatrix.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESSolid_SolidAssembly.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SolidAssembly(py::module &mod){

py::class_<IGESSolid_SolidAssembly, opencascade::handle<IGESSolid_SolidAssembly>, IGESData_IGESEntity> cls_IGESSolid_SolidAssembly(mod, "IGESSolid_SolidAssembly", "defines SolidAssembly, Type <184> Form <0> in package IGESSolid Solid assembly is a collection of items which possess a shared fixed geometric relationship.");

// Constructors
cls_IGESSolid_SolidAssembly.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SolidAssembly.def("Init", (void (IGESSolid_SolidAssembly::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESGeom_HArray1OfTransformationMatrix> &)) &IGESSolid_SolidAssembly::Init, "This method is used to set the fields of the class SolidAssembly - allItems : the collection of items - allMatrices : transformation matrices corresponding to each item raises exception if the length of allItems & allMatrices do not match", py::arg("allItems"), py::arg("allMatrices"));
cls_IGESSolid_SolidAssembly.def("HasBrep", (Standard_Boolean (IGESSolid_SolidAssembly::*)() const) &IGESSolid_SolidAssembly::HasBrep, "Tells if at least one item is a Brep, from FormNumber");
cls_IGESSolid_SolidAssembly.def("SetBrep", (void (IGESSolid_SolidAssembly::*)(const Standard_Boolean)) &IGESSolid_SolidAssembly::SetBrep, "Sets or Unsets the status 'HasBrep' from FormNumber Default is False", py::arg("hasbrep"));
cls_IGESSolid_SolidAssembly.def("NbItems", (Standard_Integer (IGESSolid_SolidAssembly::*)() const) &IGESSolid_SolidAssembly::NbItems, "returns the number of items in the collection");
cls_IGESSolid_SolidAssembly.def("Item", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidAssembly::*)(const Standard_Integer) const) &IGESSolid_SolidAssembly::Item, "returns the Index'th item raises exception if Index <= 0 or Index > NbItems()", py::arg("Index"));
cls_IGESSolid_SolidAssembly.def("TransfMatrix", (opencascade::handle<IGESGeom_TransformationMatrix> (IGESSolid_SolidAssembly::*)(const Standard_Integer) const) &IGESSolid_SolidAssembly::TransfMatrix, "returns the transformation matrix of the Index'th item raises exception if Index <= 0 or Index > NbItems()", py::arg("Index"));
cls_IGESSolid_SolidAssembly.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidAssembly::get_type_name, "None");
cls_IGESSolid_SolidAssembly.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidAssembly::get_type_descriptor, "None");
cls_IGESSolid_SolidAssembly.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidAssembly::*)() const) &IGESSolid_SolidAssembly::DynamicType, "None");

// Enums

}