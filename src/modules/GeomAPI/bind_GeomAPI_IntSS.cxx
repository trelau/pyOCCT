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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Curve.hxx>
#include <GeomInt_IntSS.hxx>
#include <GeomAPI_IntSS.hxx>

void bind_GeomAPI_IntSS(py::module &mod){

py::class_<GeomAPI_IntSS, std::unique_ptr<GeomAPI_IntSS>> cls_GeomAPI_IntSS(mod, "GeomAPI_IntSS", "This class implements methods for computing the intersection curves between two surfaces. The result is curves from Geom. The 'domain' used for a surface is the natural parametric domain unless the surface is a RectangularTrimmedSurface from Geom.");

// Constructors
cls_GeomAPI_IntSS.def(py::init<>());
cls_GeomAPI_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"));

// Fields

// Methods
// cls_GeomAPI_IntSS.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_IntSS::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_IntSS.def_static("operator delete_", (void (*)(void *)) &GeomAPI_IntSS::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_IntSS::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_IntSS.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_IntSS::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_IntSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_IntSS.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_IntSS::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_IntSS.def("Perform", (void (GeomAPI_IntSS::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real)) &GeomAPI_IntSS::Perform, "Initializes an algorithm with the given arguments and computes the intersection curves between the two surfaces S1 and S2. Parameter Tol defines the precision of curves computation. For most cases the value 1.0e-7 is recommended to use. Warning Use function IsDone to verify that the intersections are successfully computed.", py::arg("S1"), py::arg("S2"), py::arg("Tol"));
cls_GeomAPI_IntSS.def("IsDone", (Standard_Boolean (GeomAPI_IntSS::*)() const) &GeomAPI_IntSS::IsDone, "Returns True if the intersection was successful.");
cls_GeomAPI_IntSS.def("NbLines", (Standard_Integer (GeomAPI_IntSS::*)() const) &GeomAPI_IntSS::NbLines, "Returns the number of computed intersection curves. Exceptions StdFail_NotDone if the computation fails.");
cls_GeomAPI_IntSS.def("Line", (const opencascade::handle<Geom_Curve> & (GeomAPI_IntSS::*)(const Standard_Integer) const) &GeomAPI_IntSS::Line, "Returns the computed intersection curve of index Index. Exceptions StdFail_NotDone if the computation fails. Standard_OutOfRange if Index is out of range [1, NbLines] where NbLines is the number of computed intersection curves.", py::arg("Index"));

// Enums

}