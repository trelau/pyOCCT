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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax1.hxx>
#include <gce_MakeCirc.hxx>

void bind_gce_MakeCirc(py::module &mod){

py::class_<gce_MakeCirc, std::unique_ptr<gce_MakeCirc>, gce_Root> cls_gce_MakeCirc(mod, "gce_MakeCirc", "This class implements the following algorithms used to create Circ from gp.");

// Constructors
cls_gce_MakeCirc.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Circ &, const Standard_Real>(), py::arg("Circ"), py::arg("Dist"));
cls_gce_MakeCirc.def(py::init<const gp_Circ &, const gp_Pnt &>(), py::arg("Circ"), py::arg("Point"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Dir &, const Standard_Real>(), py::arg("Center"), py::arg("Norm"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pln &, const Standard_Real>(), py::arg("Center"), py::arg("Plane"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("Ptaxis"), py::arg("Radius"));
cls_gce_MakeCirc.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));

// Fields

// Methods
// cls_gce_MakeCirc.def_static("operator new_", (void * (*)(size_t)) &gce_MakeCirc::operator new, "None", py::arg("theSize"));
// cls_gce_MakeCirc.def_static("operator delete_", (void (*)(void *)) &gce_MakeCirc::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeCirc::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeCirc.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeCirc::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeCirc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeCirc.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeCirc::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeCirc.def("Value", (const gp_Circ & (gce_MakeCirc::*)() const) &gce_MakeCirc::Value, "Returns the constructed circle. Exceptions StdFail_NotDone if no circle is constructed.");
cls_gce_MakeCirc.def("Operator", (const gp_Circ & (gce_MakeCirc::*)() const) &gce_MakeCirc::Operator, "None");

// Enums

}