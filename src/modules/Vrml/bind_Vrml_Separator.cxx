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
#include <Vrml_SeparatorRenderCulling.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_Separator.hxx>

void bind_Vrml_Separator(py::module &mod){

py::class_<Vrml_Separator, std::unique_ptr<Vrml_Separator, Deleter<Vrml_Separator>>> cls_Vrml_Separator(mod, "Vrml_Separator", "defines a Separator node of VRML specifying group properties. This group node performs a push (save) of the traversal state before traversing its children and a pop (restore) after traversing them. This isolates the separator's children from the rest of the scene graph. A separator can include lights, cameras, coordinates, normals, bindings, and all other properties. Separators can also perform render culling. Render culling skips over traversal of the separator's children if they are not going to be rendered, based on the comparison of the separator's bounding box with the current view volume. Culling is controlled by the renderCulling field. These are set to AUTO by default, allowing the implementation to decide whether or not to cull.");

// Constructors
cls_Vrml_Separator.def(py::init<const Vrml_SeparatorRenderCulling>(), py::arg("aRenderCulling"));
cls_Vrml_Separator.def(py::init<>());

// Fields

// Methods
// cls_Vrml_Separator.def_static("operator new_", (void * (*)(size_t)) &Vrml_Separator::operator new, "None", py::arg("theSize"));
// cls_Vrml_Separator.def_static("operator delete_", (void (*)(void *)) &Vrml_Separator::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Separator.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Separator::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Separator.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Separator::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Separator.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Separator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Separator.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Separator::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Separator.def("SetRenderCulling", (void (Vrml_Separator::*)(const Vrml_SeparatorRenderCulling)) &Vrml_Separator::SetRenderCulling, "None", py::arg("aRenderCulling"));
cls_Vrml_Separator.def("RenderCulling", (Vrml_SeparatorRenderCulling (Vrml_Separator::*)() const) &Vrml_Separator::RenderCulling, "None");
cls_Vrml_Separator.def("Print", (Standard_OStream & (Vrml_Separator::*)(Standard_OStream &)) &Vrml_Separator::Print, "None", py::arg("anOStream"));

// Enums

}