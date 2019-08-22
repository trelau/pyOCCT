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
#include <Vrml_WWWAnchorMap.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_WWWAnchor.hxx>

void bind_Vrml_WWWAnchor(py::module &mod){

py::class_<Vrml_WWWAnchor> cls_Vrml_WWWAnchor(mod, "Vrml_WWWAnchor", "defines a WWWAnchor node of VRML specifying group properties. The WWWAnchor group node loads a new scene into a VRML browser when one of its children is closen. Exactly how a user 'chooses' a child of the WWWAnchor is up to the VRML browser. WWWAnchor with an empty ('') name does nothing when its children are chosen. WWWAnchor behaves like a Separator, pushing the traversal state before traversing its children and popping it afterwards.");

// Constructors
cls_Vrml_WWWAnchor.def(py::init<>());
cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &>(), py::arg("aName"));
cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("aName"), py::arg("aDescription"));
cls_Vrml_WWWAnchor.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &, const Vrml_WWWAnchorMap>(), py::arg("aName"), py::arg("aDescription"), py::arg("aMap"));

// Fields

// Methods
// cls_Vrml_WWWAnchor.def_static("operator new_", (void * (*)(size_t)) &Vrml_WWWAnchor::operator new, "None", py::arg("theSize"));
// cls_Vrml_WWWAnchor.def_static("operator delete_", (void (*)(void *)) &Vrml_WWWAnchor::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_WWWAnchor.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_WWWAnchor::operator new[], "None", py::arg("theSize"));
// cls_Vrml_WWWAnchor.def_static("operator delete[]_", (void (*)(void *)) &Vrml_WWWAnchor::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_WWWAnchor.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_WWWAnchor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_WWWAnchor.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_WWWAnchor::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_WWWAnchor.def("SetName", (void (Vrml_WWWAnchor::*)(const TCollection_AsciiString &)) &Vrml_WWWAnchor::SetName, "None", py::arg("aName"));
cls_Vrml_WWWAnchor.def("Name", (TCollection_AsciiString (Vrml_WWWAnchor::*)() const) &Vrml_WWWAnchor::Name, "None");
cls_Vrml_WWWAnchor.def("SetDescription", (void (Vrml_WWWAnchor::*)(const TCollection_AsciiString &)) &Vrml_WWWAnchor::SetDescription, "None", py::arg("aDescription"));
cls_Vrml_WWWAnchor.def("Description", (TCollection_AsciiString (Vrml_WWWAnchor::*)() const) &Vrml_WWWAnchor::Description, "None");
cls_Vrml_WWWAnchor.def("SetMap", (void (Vrml_WWWAnchor::*)(const Vrml_WWWAnchorMap)) &Vrml_WWWAnchor::SetMap, "None", py::arg("aMap"));
cls_Vrml_WWWAnchor.def("Map", (Vrml_WWWAnchorMap (Vrml_WWWAnchor::*)() const) &Vrml_WWWAnchor::Map, "None");
cls_Vrml_WWWAnchor.def("Print", (Standard_OStream & (Vrml_WWWAnchor::*)(Standard_OStream &) const) &Vrml_WWWAnchor::Print, "None", py::arg("anOStream"));

// Enums

}