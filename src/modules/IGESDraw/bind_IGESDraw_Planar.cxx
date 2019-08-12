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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESDraw_Planar.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_Planar(py::module &mod){

py::class_<IGESDraw_Planar, opencascade::handle<IGESDraw_Planar>, IGESData_IGESEntity> cls_IGESDraw_Planar(mod, "IGESDraw_Planar", "defines IGESPlanar, Type <402> Form <16> in package IGESDraw");

// Constructors
cls_IGESDraw_Planar.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_Planar.def("Init", (void (IGESDraw_Planar::*)(const Standard_Integer, const opencascade::handle<IGESGeom_TransformationMatrix> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_Planar::Init, "This method is used to set the fields of the class Planar - nbMats : Number of Transformation matrices - aTransformationMatrix : Pointer to the Transformation matrix - allEntities : Pointers to the entities specified", py::arg("nbMats"), py::arg("aTransformationMatrix"), py::arg("allEntities"));
cls_IGESDraw_Planar.def("NbMatrices", (Standard_Integer (IGESDraw_Planar::*)() const) &IGESDraw_Planar::NbMatrices, "returns the number of Transformation matrices in <me>");
cls_IGESDraw_Planar.def("NbEntities", (Standard_Integer (IGESDraw_Planar::*)() const) &IGESDraw_Planar::NbEntities, "returns the number of Entities in the plane pointed to by this associativity");
cls_IGESDraw_Planar.def("IsIdentityMatrix", (Standard_Boolean (IGESDraw_Planar::*)() const) &IGESDraw_Planar::IsIdentityMatrix, "returns True if TransformationMatrix is Identity Matrix, i.e:- No Matrix defined.");
cls_IGESDraw_Planar.def("TransformMatrix", (opencascade::handle<IGESGeom_TransformationMatrix> (IGESDraw_Planar::*)() const) &IGESDraw_Planar::TransformMatrix, "returns the Transformation matrix moving data from the XY plane into space or zero");
cls_IGESDraw_Planar.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_Planar::*)(const Standard_Integer) const) &IGESDraw_Planar::Entity, "returns the Entity on the specified plane, indicated by EntityIndex raises an exception if EntityIndex <= 0 or EntityIndex > NbEntities()", py::arg("EntityIndex"));
cls_IGESDraw_Planar.def_static("get_type_name_", (const char * (*)()) &IGESDraw_Planar::get_type_name, "None");
cls_IGESDraw_Planar.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_Planar::get_type_descriptor, "None");
cls_IGESDraw_Planar.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_Planar::*)() const) &IGESDraw_Planar::DynamicType, "None");

// Enums

}