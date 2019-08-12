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
#include <IGESSolid_HArray1OfFace.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Shell.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Shell(py::module &mod){

py::class_<IGESSolid_Shell, opencascade::handle<IGESSolid_Shell>, IGESData_IGESEntity> cls_IGESSolid_Shell(mod, "IGESSolid_Shell", "defines Shell, Type <514> Form Number <1> in package IGESSolid Shell entity is a connected entity of dimensionality 2 which divides R3 into two arcwise connected open subsets, one of which is finite. Inside of the shell is defined to be the finite region. From IGES-5.3, Form can be <1> for Closed or <2> for Open");

// Constructors
cls_IGESSolid_Shell.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Shell.def("Init", (void (IGESSolid_Shell::*)(const opencascade::handle<IGESSolid_HArray1OfFace> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_Shell::Init, "This method is used to set the fields of the class Shell - allFaces : the faces comprising the shell - allOrient : the orientation flags of the shell raises exception if length of allFaces & allOrient do not match", py::arg("allFaces"), py::arg("allOrient"));
cls_IGESSolid_Shell.def("IsClosed", (Standard_Boolean (IGESSolid_Shell::*)() const) &IGESSolid_Shell::IsClosed, "Tells if a Shell is Closed, i.e. if its FormNumber is 1 (this is the default)");
cls_IGESSolid_Shell.def("SetClosed", (void (IGESSolid_Shell::*)(const Standard_Boolean)) &IGESSolid_Shell::SetClosed, "Sets or Unsets the Closed status (FormNumber = 1 else 2)", py::arg("closed"));
cls_IGESSolid_Shell.def("NbFaces", (Standard_Integer (IGESSolid_Shell::*)() const) &IGESSolid_Shell::NbFaces, "returns the number of the face entities in the shell");
cls_IGESSolid_Shell.def("Face", (opencascade::handle<IGESSolid_Face> (IGESSolid_Shell::*)(const Standard_Integer) const) &IGESSolid_Shell::Face, "returns the Index'th face entity of the shell raises exception if Index <= 0 or Index > NbFaces()", py::arg("Index"));
cls_IGESSolid_Shell.def("Orientation", (Standard_Boolean (IGESSolid_Shell::*)(const Standard_Integer) const) &IGESSolid_Shell::Orientation, "returns the orientation of Index'th face w.r.t the direction of the underlying surface raises exception if Index <= 0 or Index > NbFaces()", py::arg("Index"));
cls_IGESSolid_Shell.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Shell::get_type_name, "None");
cls_IGESSolid_Shell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Shell::get_type_descriptor, "None");
cls_IGESSolid_Shell.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Shell::*)() const) &IGESSolid_Shell::DynamicType, "None");

// Enums

}