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
#include <gp_Pnt2d.hxx>
#include <gp_Ax2d.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Transformation.hxx>
#include <GCE2d_MakeMirror.hxx>

void bind_GCE2d_MakeMirror(py::module &mod){

py::class_<GCE2d_MakeMirror> cls_GCE2d_MakeMirror(mod, "GCE2d_MakeMirror", "This class implements elementary construction algorithms for a symmetrical transformation in 2D space about a point or axis. The result is a Geom2d_Transformation transformation. A MakeMirror object provides a framework for: - defining the construction of the transformation, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_GCE2d_MakeMirror.def(py::init<const gp_Pnt2d &>(), py::arg("Point"));
cls_GCE2d_MakeMirror.def(py::init<const gp_Ax2d &>(), py::arg("Axis"));
cls_GCE2d_MakeMirror.def(py::init<const gp_Lin2d &>(), py::arg("Line"));
cls_GCE2d_MakeMirror.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("Point"), py::arg("Direc"));

// Fields

// Methods
// cls_GCE2d_MakeMirror.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeMirror::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeMirror.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeMirror::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeMirror.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeMirror::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeMirror.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeMirror::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeMirror.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeMirror::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeMirror.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeMirror::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeMirror.def("Value", (const opencascade::handle<Geom2d_Transformation> & (GCE2d_MakeMirror::*)() const) &GCE2d_MakeMirror::Value, "Returns the constructed transformation.");

// Enums

}