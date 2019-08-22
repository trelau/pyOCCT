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
#include <TCollection_AsciiString.hxx>
#include <gp_Vec.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_WWWInline.hxx>

void bind_Vrml_WWWInline(py::module &mod){

py::class_<Vrml_WWWInline> cls_Vrml_WWWInline(mod, "Vrml_WWWInline", "defines a WWWInline node of VRML specifying group properties. The WWWInline group node reads its children from anywhere in the World Wide Web. Exactly when its children are read is not defined; reading the children may be delayed until the WWWInline is actually displayed. WWWInline with an empty ('') name does nothing. WWWInline behaves like a Separator, pushing the traversal state before traversing its children and popping it afterwards. By defaults: myName ('') myBboxSize (0,0,0) myBboxCenter (0,0,0)");

// Constructors
cls_Vrml_WWWInline.def(py::init<>());
cls_Vrml_WWWInline.def(py::init<const TCollection_AsciiString &, const gp_Vec &, const gp_Vec &>(), py::arg("aName"), py::arg("aBboxSize"), py::arg("aBboxCenter"));

// Fields

// Methods
// cls_Vrml_WWWInline.def_static("operator new_", (void * (*)(size_t)) &Vrml_WWWInline::operator new, "None", py::arg("theSize"));
// cls_Vrml_WWWInline.def_static("operator delete_", (void (*)(void *)) &Vrml_WWWInline::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_WWWInline.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_WWWInline::operator new[], "None", py::arg("theSize"));
// cls_Vrml_WWWInline.def_static("operator delete[]_", (void (*)(void *)) &Vrml_WWWInline::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_WWWInline.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_WWWInline::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_WWWInline.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_WWWInline::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_WWWInline.def("SetName", (void (Vrml_WWWInline::*)(const TCollection_AsciiString &)) &Vrml_WWWInline::SetName, "None", py::arg("aName"));
cls_Vrml_WWWInline.def("Name", (TCollection_AsciiString (Vrml_WWWInline::*)() const) &Vrml_WWWInline::Name, "None");
cls_Vrml_WWWInline.def("SetBboxSize", (void (Vrml_WWWInline::*)(const gp_Vec &)) &Vrml_WWWInline::SetBboxSize, "None", py::arg("aBboxSize"));
cls_Vrml_WWWInline.def("BboxSize", (gp_Vec (Vrml_WWWInline::*)() const) &Vrml_WWWInline::BboxSize, "None");
cls_Vrml_WWWInline.def("SetBboxCenter", (void (Vrml_WWWInline::*)(const gp_Vec &)) &Vrml_WWWInline::SetBboxCenter, "None", py::arg("aBboxCenter"));
cls_Vrml_WWWInline.def("BboxCenter", (gp_Vec (Vrml_WWWInline::*)() const) &Vrml_WWWInline::BboxCenter, "None");
cls_Vrml_WWWInline.def("Print", (Standard_OStream & (Vrml_WWWInline::*)(Standard_OStream &) const) &Vrml_WWWInline::Print, "None", py::arg("anOStream"));

// Enums

}