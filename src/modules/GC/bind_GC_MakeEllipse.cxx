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
#include <GC_Root.hxx>
#include <Standard.hxx>
#include <gp_Elips.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Ellipse.hxx>
#include <GC_MakeEllipse.hxx>

void bind_GC_MakeEllipse(py::module &mod){

py::class_<GC_MakeEllipse, std::unique_ptr<GC_MakeEllipse, Deleter<GC_MakeEllipse>>, GC_Root> cls_GC_MakeEllipse(mod, "GC_MakeEllipse", "This class implements construction algorithms for an ellipse in 3D space. The result is a Geom_Ellipse ellipse. A MakeEllipse object provides a framework for: - defining the construction of the ellipse, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed ellipse.");

// Constructors
cls_GC_MakeEllipse.def(py::init<const gp_Elips &>(), py::arg("E"));
cls_GC_MakeEllipse.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GC_MakeEllipse.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Fields

// Methods
// cls_GC_MakeEllipse.def_static("operator new_", (void * (*)(size_t)) &GC_MakeEllipse::operator new, "None", py::arg("theSize"));
// cls_GC_MakeEllipse.def_static("operator delete_", (void (*)(void *)) &GC_MakeEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeEllipse::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeEllipse.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeEllipse.def("Value", (const opencascade::handle<Geom_Ellipse> & (GC_MakeEllipse::*)() const) &GC_MakeEllipse::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");

// Enums

}