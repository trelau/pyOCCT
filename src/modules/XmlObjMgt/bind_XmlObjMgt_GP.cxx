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
#include <Standard.hxx>
#include <XmlObjMgt_DOMString.hxx>
#include <gp_Trsf.hxx>
#include <gp_Mat.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_GP.hxx>

void bind_XmlObjMgt_GP(py::module &mod){

py::class_<XmlObjMgt_GP, std::unique_ptr<XmlObjMgt_GP, Deleter<XmlObjMgt_GP>>> cls_XmlObjMgt_GP(mod, "XmlObjMgt_GP", "Translation of gp (simple geometry) objects");

// Constructors

// Fields

// Methods
// cls_XmlObjMgt_GP.def_static("operator new_", (void * (*)(size_t)) &XmlObjMgt_GP::operator new, "None", py::arg("theSize"));
// cls_XmlObjMgt_GP.def_static("operator delete_", (void (*)(void *)) &XmlObjMgt_GP::operator delete, "None", py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator new[]_", (void * (*)(size_t)) &XmlObjMgt_GP::operator new[], "None", py::arg("theSize"));
// cls_XmlObjMgt_GP.def_static("operator delete[]_", (void (*)(void *)) &XmlObjMgt_GP::operator delete[], "None", py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator new_", (void * (*)(size_t, void *)) &XmlObjMgt_GP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlObjMgt_GP.def_static("operator delete_", (void (*)(void *, void *)) &XmlObjMgt_GP::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aTrsf"));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aMat"));
cls_XmlObjMgt_GP.def_static("Translate_", (XmlObjMgt_DOMString (*)(const gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("anXYZ"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Trsf &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_Mat &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));
cls_XmlObjMgt_GP.def_static("Translate_", (Standard_Boolean (*)(const XmlObjMgt_DOMString &, gp_XYZ &)) &XmlObjMgt_GP::Translate, "None", py::arg("aStr"), py::arg("T"));

// Enums

}