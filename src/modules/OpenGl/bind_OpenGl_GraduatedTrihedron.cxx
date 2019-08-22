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
#include <OpenGl_Element.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Workspace.hxx>
#include <OpenGl_Context.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <OpenGl_Vec.hxx>
#include <Quantity_Color.hxx>
#include <OpenGl_AspectLine.hxx>
#include <OpenGl_Text.hxx>
#include <OpenGl_PrimitiveArray.hxx>
#include <OpenGl_GraduatedTrihedron.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_AspectText.hxx>

void bind_OpenGl_GraduatedTrihedron(py::module &mod){

/*
py::class_<OpenGl_GraduatedTrihedron, OpenGl_Element> cls_OpenGl_GraduatedTrihedron(mod, "OpenGl_GraduatedTrihedron", "This class allows to render Graduated Trihedron, i.e. trihedron with grid. it is based on Graphic3d_GraduatedTrihedron parameters and support its customization on construction level only.");

// Constructors
cls_OpenGl_GraduatedTrihedron.def(py::init<>());

// Fields

// Methods
// cls_OpenGl_GraduatedTrihedron.def_static("operator new_", (void * (*)(size_t)) &OpenGl_GraduatedTrihedron::operator new, "None", py::arg("theSize"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete_", (void (*)(void *)) &OpenGl_GraduatedTrihedron::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_GraduatedTrihedron::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_GraduatedTrihedron::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_GraduatedTrihedron::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_GraduatedTrihedron.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_GraduatedTrihedron::operator delete, "None", py::arg(""), py::arg(""));
cls_OpenGl_GraduatedTrihedron.def("Render", (void (OpenGl_GraduatedTrihedron::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_GraduatedTrihedron::Render, "Draw the element.", py::arg("theWorkspace"));
cls_OpenGl_GraduatedTrihedron.def("Release", (void (OpenGl_GraduatedTrihedron::*)(OpenGl_Context *)) &OpenGl_GraduatedTrihedron::Release, "Release OpenGL resources.", py::arg("theCtx"));
cls_OpenGl_GraduatedTrihedron.def("SetValues", (void (OpenGl_GraduatedTrihedron::*)(const Graphic3d_GraduatedTrihedron &)) &OpenGl_GraduatedTrihedron::SetValues, "Setup configuration.", py::arg("theData"));
cls_OpenGl_GraduatedTrihedron.def("SetMinMax", (void (OpenGl_GraduatedTrihedron::*)(const OpenGl_Vec3 &, const OpenGl_Vec3 &)) &OpenGl_GraduatedTrihedron::SetMinMax, "Sets up-to-date values of scene bounding box. Can be used in callback mechanism to get up-to-date values.", py::arg("theMin"), py::arg("theMax"));

// Enums
*/

}