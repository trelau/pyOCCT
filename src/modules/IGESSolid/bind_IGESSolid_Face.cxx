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
#include <Standard_TypeDef.hxx>
#include <IGESSolid_HArray1OfLoop.hxx>
#include <IGESSolid_Loop.hxx>
#include <IGESSolid_Face.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Face(py::module &mod){

py::class_<IGESSolid_Face, opencascade::handle<IGESSolid_Face>, IGESData_IGESEntity> cls_IGESSolid_Face(mod, "IGESSolid_Face", "defines Face, Type <510> Form Number <1> in package IGESSolid Face entity is a bound (partial) which has finite area");

// Constructors
cls_IGESSolid_Face.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Face.def("Init", (void (IGESSolid_Face::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean, const opencascade::handle<IGESSolid_HArray1OfLoop> &)) &IGESSolid_Face::Init, "This method is used to set the fields of the class Face - aSurface : Pointer to the underlying surface - outerLoopFlag : True means the first loop is the outer loop - loops : Array of loops bounding the face", py::arg("aSurface"), py::arg("outerLoopFlag"), py::arg("loops"));
cls_IGESSolid_Face.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_Face::*)() const) &IGESSolid_Face::Surface, "returns the underlying surface of the face");
cls_IGESSolid_Face.def("NbLoops", (Standard_Integer (IGESSolid_Face::*)() const) &IGESSolid_Face::NbLoops, "returns the number of the loops bounding the face");
cls_IGESSolid_Face.def("HasOuterLoop", (Standard_Boolean (IGESSolid_Face::*)() const) &IGESSolid_Face::HasOuterLoop, "checks whether there is an outer loop or not");
cls_IGESSolid_Face.def("Loop", (opencascade::handle<IGESSolid_Loop> (IGESSolid_Face::*)(const Standard_Integer) const) &IGESSolid_Face::Loop, "returns the Index'th loop that bounds the face raises exception if Index < 0 or Index >= NbLoops", py::arg("Index"));
cls_IGESSolid_Face.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Face::get_type_name, "None");
cls_IGESSolid_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Face::get_type_descriptor, "None");
cls_IGESSolid_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Face::*)() const) &IGESSolid_Face::DynamicType, "None");

// Enums

}