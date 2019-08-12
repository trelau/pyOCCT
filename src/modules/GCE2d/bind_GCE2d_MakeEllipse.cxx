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
#include <GCE2d_Root.hxx>
#include <Standard.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Ellipse.hxx>
#include <GCE2d_MakeEllipse.hxx>

void bind_GCE2d_MakeEllipse(py::module &mod){

py::class_<GCE2d_MakeEllipse, std::unique_ptr<GCE2d_MakeEllipse, Deleter<GCE2d_MakeEllipse>>, GCE2d_Root> cls_GCE2d_MakeEllipse(mod, "GCE2d_MakeEllipse", "This class implements the following algorithms used to create Ellipse from Geom2d. * Create an Ellipse from two apex and the center. Defines an ellipse in 2D space. The parametrization range is [0,2*PI]. The ellipse is a closed and periodic curve. The center of the ellipse is the 'Location' point of its axis placement 'XAxis'. The 'XAxis' of the ellipse defines the origin of the parametrization, it is the major axis of the ellipse. The YAxis is the minor axis of the ellipse.");

// Constructors
cls_GCE2d_MakeEllipse.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_GCE2d_MakeEllipse.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GCE2d_MakeEllipse.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Fields

// Methods
// cls_GCE2d_MakeEllipse.def_static("operator new_", (void * (*)(size_t)) &GCE2d_MakeEllipse::operator new, "None", py::arg("theSize"));
// cls_GCE2d_MakeEllipse.def_static("operator delete_", (void (*)(void *)) &GCE2d_MakeEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_MakeEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_MakeEllipse::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_MakeEllipse.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_MakeEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_MakeEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_MakeEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_MakeEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_MakeEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_MakeEllipse.def("Value", (const opencascade::handle<Geom2d_Ellipse> & (GCE2d_MakeEllipse::*)() const) &GCE2d_MakeEllipse::Value, "Returns the constructed ellipse. Exceptions StdFail_NotDone if no ellipse is constructed.");

// Enums

}