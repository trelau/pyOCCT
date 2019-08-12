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
#include <gce_Root.hxx>
#include <Standard.hxx>
#include <gp_Vec2d.hxx>
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <gce_MakeDir2d.hxx>

void bind_gce_MakeDir2d(py::module &mod){

py::class_<gce_MakeDir2d, std::unique_ptr<gce_MakeDir2d, Deleter<gce_MakeDir2d>>, gce_Root> cls_gce_MakeDir2d(mod, "gce_MakeDir2d", "This class implements the following algorithms used to create a Dir2d from gp. * Create a Dir2d with 2 points. * Create a Dir2d with a Vec2d. * Create a Dir2d with a XY from gp. * Create a Dir2d with a 2 Reals (Coordinates).");

// Constructors
cls_gce_MakeDir2d.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_gce_MakeDir2d.def(py::init<const gp_XY &>(), py::arg("Coord"));
cls_gce_MakeDir2d.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"));
cls_gce_MakeDir2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gce_MakeDir2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeDir2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeDir2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeDir2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeDir2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeDir2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeDir2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeDir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeDir2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeDir2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeDir2d.def("Value", (const gp_Dir2d & (gce_MakeDir2d::*)() const) &gce_MakeDir2d::Value, "Returns the constructed unit vector. Exceptions StdFail_NotDone if no unit vector is constructed.");
cls_gce_MakeDir2d.def("Operator", (const gp_Dir2d & (gce_MakeDir2d::*)() const) &gce_MakeDir2d::Operator, "None");

// Enums

}