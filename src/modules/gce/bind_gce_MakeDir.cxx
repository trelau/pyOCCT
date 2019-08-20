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
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gce_MakeDir.hxx>

void bind_gce_MakeDir(py::module &mod){

py::class_<gce_MakeDir, std::unique_ptr<gce_MakeDir>, gce_Root> cls_gce_MakeDir(mod, "gce_MakeDir", "This class implements the following algorithms used to create a Dir from gp. * Create a Dir parallel to another and passing through a point. * Create a Dir passing through 2 points. * Create a Dir from its axis (Ax1 from gp). * Create a Dir from a point and a direction.");

// Constructors
cls_gce_MakeDir.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_gce_MakeDir.def(py::init<const gp_XYZ &>(), py::arg("Coord"));
cls_gce_MakeDir.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Xv"), py::arg("Yv"), py::arg("Zv"));
cls_gce_MakeDir.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gce_MakeDir.def_static("operator new_", (void * (*)(size_t)) &gce_MakeDir::operator new, "None", py::arg("theSize"));
// cls_gce_MakeDir.def_static("operator delete_", (void (*)(void *)) &gce_MakeDir::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeDir::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeDir.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeDir::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeDir.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeDir::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeDir.def("Value", (const gp_Dir & (gce_MakeDir::*)() const) &gce_MakeDir::Value, "Returns the constructed unit vector. Exceptions StdFail_NotDone if no unit vector is constructed.");
cls_gce_MakeDir.def("Operator", (const gp_Dir & (gce_MakeDir::*)() const) &gce_MakeDir::Operator, "None");

// Enums

}