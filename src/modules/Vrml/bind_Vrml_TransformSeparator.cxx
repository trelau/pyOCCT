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
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_TransformSeparator.hxx>

void bind_Vrml_TransformSeparator(py::module &mod){

py::class_<Vrml_TransformSeparator> cls_Vrml_TransformSeparator(mod, "Vrml_TransformSeparator", "defines a TransformSeparator node of VRML specifying group properties. This group node is similar to separator node in that it saves state before traversing its children and restores it afterwards. This node can be used to isolate transformations to light sources or objects.");

// Constructors
cls_Vrml_TransformSeparator.def(py::init<>());

// Fields

// Methods
// cls_Vrml_TransformSeparator.def_static("operator new_", (void * (*)(size_t)) &Vrml_TransformSeparator::operator new, "None", py::arg("theSize"));
// cls_Vrml_TransformSeparator.def_static("operator delete_", (void (*)(void *)) &Vrml_TransformSeparator::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_TransformSeparator.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_TransformSeparator::operator new[], "None", py::arg("theSize"));
// cls_Vrml_TransformSeparator.def_static("operator delete[]_", (void (*)(void *)) &Vrml_TransformSeparator::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_TransformSeparator.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_TransformSeparator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_TransformSeparator.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_TransformSeparator::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_TransformSeparator.def("Print", (Standard_OStream & (Vrml_TransformSeparator::*)(Standard_OStream &)) &Vrml_TransformSeparator::Print, "None", py::arg("anOStream"));

// Enums

}