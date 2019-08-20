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
#include <TopoDS_Face.hxx>
#include <gp_Dir.hxx>
#include <Draft_Modification.hxx>
#include <Draft_FaceInfo.hxx>
#include <Draft_EdgeInfo.hxx>
#include <Draft_VertexInfo.hxx>
#include <Draft.hxx>

void bind_Draft(py::module &mod){

py::class_<Draft, std::unique_ptr<Draft>> cls_Draft(mod, "Draft", "None");

// Constructors

// Fields

// Methods
// cls_Draft.def_static("operator new_", (void * (*)(size_t)) &Draft::operator new, "None", py::arg("theSize"));
// cls_Draft.def_static("operator delete_", (void (*)(void *)) &Draft::operator delete, "None", py::arg("theAddress"));
// cls_Draft.def_static("operator new[]_", (void * (*)(size_t)) &Draft::operator new[], "None", py::arg("theSize"));
// cls_Draft.def_static("operator delete[]_", (void (*)(void *)) &Draft::operator delete[], "None", py::arg("theAddress"));
// cls_Draft.def_static("operator new_", (void * (*)(size_t, void *)) &Draft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Draft.def_static("operator delete_", (void (*)(void *, void *)) &Draft::operator delete, "None", py::arg(""), py::arg(""));
cls_Draft.def_static("Angle_", (Standard_Real (*)(const TopoDS_Face &, const gp_Dir &)) &Draft::Angle, "Returns the draft angle of the face <F> using the direction <Direction>. The method is valid for : - Plane faces, - Cylindrical or conical faces, when the direction of the axis of the surface is colinear with the direction. Otherwise, the exception DomainError is raised.", py::arg("F"), py::arg("Direction"));

// Enums

}