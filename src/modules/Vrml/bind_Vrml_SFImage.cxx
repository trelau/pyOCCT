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
#include <Standard_TypeDef.hxx>
#include <Vrml_SFImageNumber.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Vrml_SFImage.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_SFImage(py::module &mod){

py::class_<Vrml_SFImage, opencascade::handle<Vrml_SFImage>, Standard_Transient> cls_Vrml_SFImage(mod, "Vrml_SFImage", "defines SFImage type of VRML field types.");

// Constructors
cls_Vrml_SFImage.def(py::init<>());
cls_Vrml_SFImage.def(py::init<const Standard_Integer, const Standard_Integer, const Vrml_SFImageNumber, const opencascade::handle<TColStd_HArray1OfInteger> &>(), py::arg("aWidth"), py::arg("aHeight"), py::arg("aNumber"), py::arg("anArray"));

// Fields

// Methods
cls_Vrml_SFImage.def("SetWidth", (void (Vrml_SFImage::*)(const Standard_Integer)) &Vrml_SFImage::SetWidth, "None", py::arg("aWidth"));
cls_Vrml_SFImage.def("Width", (Standard_Integer (Vrml_SFImage::*)() const) &Vrml_SFImage::Width, "None");
cls_Vrml_SFImage.def("SetHeight", (void (Vrml_SFImage::*)(const Standard_Integer)) &Vrml_SFImage::SetHeight, "None", py::arg("aHeight"));
cls_Vrml_SFImage.def("Height", (Standard_Integer (Vrml_SFImage::*)() const) &Vrml_SFImage::Height, "None");
cls_Vrml_SFImage.def("SetNumber", (void (Vrml_SFImage::*)(const Vrml_SFImageNumber)) &Vrml_SFImage::SetNumber, "None", py::arg("aNumber"));
cls_Vrml_SFImage.def("Number", (Vrml_SFImageNumber (Vrml_SFImage::*)() const) &Vrml_SFImage::Number, "None");
cls_Vrml_SFImage.def("SetArray", (void (Vrml_SFImage::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &Vrml_SFImage::SetArray, "None", py::arg("anArray"));
cls_Vrml_SFImage.def("Array", (opencascade::handle<TColStd_HArray1OfInteger> (Vrml_SFImage::*)() const) &Vrml_SFImage::Array, "None");
cls_Vrml_SFImage.def("ArrayFlag", (Standard_Boolean (Vrml_SFImage::*)() const) &Vrml_SFImage::ArrayFlag, "None");
cls_Vrml_SFImage.def_static("get_type_name_", (const char * (*)()) &Vrml_SFImage::get_type_name, "None");
cls_Vrml_SFImage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_SFImage::get_type_descriptor, "None");
cls_Vrml_SFImage.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_SFImage::*)() const) &Vrml_SFImage::DynamicType, "None");

// Enums

}