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
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeSegment.hxx>

void bind_GC_MakeSegment(py::module &mod){

py::class_<GC_MakeSegment, std::unique_ptr<GC_MakeSegment>, GC_Root> cls_GC_MakeSegment(mod, "GC_MakeSegment", "Implements construction algorithms for a line segment in 3D space. Makes a segment of Line from the 2 points <P1> and <P2>. The result is a Geom_TrimmedCurve curve. A MakeSegment object provides a framework for: - defining the construction of the line segment, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed line segment.");

// Constructors
cls_GC_MakeSegment.def(py::init<const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const Standard_Real, const Standard_Real>(), py::arg("Line"), py::arg("U1"), py::arg("U2"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const gp_Pnt &, const Standard_Real>(), py::arg("Line"), py::arg("Point"), py::arg("Ulast"));
cls_GC_MakeSegment.def(py::init<const gp_Lin &, const gp_Pnt &, const gp_Pnt &>(), py::arg("Line"), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_GC_MakeSegment.def_static("operator new_", (void * (*)(size_t)) &GC_MakeSegment::operator new, "None", py::arg("theSize"));
// cls_GC_MakeSegment.def_static("operator delete_", (void (*)(void *)) &GC_MakeSegment::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeSegment::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeSegment.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeSegment::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeSegment.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeSegment.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeSegment::*)() const) &GC_MakeSegment::Value, "Returns the constructed line segment.");

// Enums

}