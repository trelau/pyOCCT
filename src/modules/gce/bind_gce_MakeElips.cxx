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
#include <gp_Pnt.hxx>
#include <gp_Elips.hxx>
#include <gce_MakeElips.hxx>

void bind_gce_MakeElips(py::module &mod){

py::class_<gce_MakeElips, gce_Root> cls_gce_MakeElips(mod, "gce_MakeElips", "This class implements the following algorithms used to create an ellipse from gp.");

// Constructors
cls_gce_MakeElips.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gce_MakeElips.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Fields

// Methods
// cls_gce_MakeElips.def_static("operator new_", (void * (*)(size_t)) &gce_MakeElips::operator new, "None", py::arg("theSize"));
// cls_gce_MakeElips.def_static("operator delete_", (void (*)(void *)) &gce_MakeElips::operator delete, "None", py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator new[]_", (void * (*)(size_t)) &gce_MakeElips::operator new[], "None", py::arg("theSize"));
// cls_gce_MakeElips.def_static("operator delete[]_", (void (*)(void *)) &gce_MakeElips::operator delete[], "None", py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator new_", (void * (*)(size_t, void *)) &gce_MakeElips::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gce_MakeElips.def_static("operator delete_", (void (*)(void *, void *)) &gce_MakeElips::operator delete, "None", py::arg(""), py::arg(""));
cls_gce_MakeElips.def("Value", (const gp_Elips & (gce_MakeElips::*)() const) &gce_MakeElips::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");
cls_gce_MakeElips.def("Operator", (const gp_Elips & (gce_MakeElips::*)() const) &gce_MakeElips::Operator, "None");

// Enums

}