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
#include <gp_Ax2d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin2d.hxx>
#include <gce_MakeLin2d.hxx>

void bind_gce_MakeLin2d(py::module &mod){

py::class_<gce_MakeLin2d, gce_Root> cls_gce_MakeLin2d(mod, "gce_MakeLin2d", "This class implements the following algorithms used to create Lin2d from gp.");

// Constructors
cls_gce_MakeLin2d.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_gce_MakeLin2d.def(py::init<const gp_Pnt2d &, const gp_Dir2d &>(), py::arg("P"), py::arg("V"));
cls_gce_MakeLin2d.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("B"), py::arg("C"));
cls_gce_MakeLin2d.def(py::init<const gp_Lin2d &, const Standard_Real>(), py::arg("Lin"), py::arg("Dist"));
cls_gce_MakeLin2d.def(py::init<const gp_Lin2d &, const gp_Pnt2d &>(), py::arg("Lin"), py::arg("Point"));
cls_gce_MakeLin2d.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_gce_MakeLin2d.def_static("operator new_", (void * (*)(size_t)) &gce_MakeLin2d::operator new, "None", py::arg("theSize"));
// cls_gce_MakeLin2d.def_static("operator delete_", (void (*)(void *)) &gce_MakeLin2d::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeLin2d::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeLin2d.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeLin2d::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeLin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeLin2d.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeLin2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeLin2d.def("Value", (gp_Lin2d (gce_MakeLin2d::*)() const) &gce_MakeLin2d::Value, "Returns the constructed line. Exceptions StdFail_NotDone if no line is constructed.");
cls_gce_MakeLin2d.def("Operator", (gp_Lin2d (gce_MakeLin2d::*)() const) &gce_MakeLin2d::Operator, "None");

// Enums

}