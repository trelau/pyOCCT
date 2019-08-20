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
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Switch.hxx>

void bind_Vrml_Switch(py::module &mod){

py::class_<Vrml_Switch, std::unique_ptr<Vrml_Switch>> cls_Vrml_Switch(mod, "Vrml_Switch", "defines a Switch node of VRML specifying group properties. This group node traverses one, none, or all of its children. One can use this node to switch on and off the effects of some properties or to switch between different properties. The whichChild field specifies the index of the child to traverse, where the first child has index 0. A value of -1 (the default) means do not traverse any children. A value of -3 traverses all children, making the switch behave exactly like a regular Group.");

// Constructors
cls_Vrml_Switch.def(py::init<>());
cls_Vrml_Switch.def(py::init<const Standard_Integer>(), py::arg("aWhichChild"));

// Fields

// Methods
// cls_Vrml_Switch.def_static("operator new_", (void * (*)(size_t)) &Vrml_Switch::operator new, "None", py::arg("theSize"));
// cls_Vrml_Switch.def_static("operator delete_", (void (*)(void *)) &Vrml_Switch::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Switch.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Switch::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Switch.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Switch::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Switch.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Switch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Switch.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Switch::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Switch.def("SetWhichChild", (void (Vrml_Switch::*)(const Standard_Integer)) &Vrml_Switch::SetWhichChild, "None", py::arg("aWhichChild"));
cls_Vrml_Switch.def("WhichChild", (Standard_Integer (Vrml_Switch::*)() const) &Vrml_Switch::WhichChild, "None");
cls_Vrml_Switch.def("Print", (Standard_OStream & (Vrml_Switch::*)(Standard_OStream &) const) &Vrml_Switch::Print, "None", py::arg("anOStream"));

// Enums

}