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
#include <Geom_BezierCurve.hxx>
#include <GeomFill_FillingStyle.hxx>
#include <Geom_BezierSurface.hxx>
#include <GeomFill_BezierCurves.hxx>

void bind_GeomFill_BezierCurves(py::module &mod){

py::class_<GeomFill_BezierCurves, std::unique_ptr<GeomFill_BezierCurves, Deleter<GeomFill_BezierCurves>>> cls_GeomFill_BezierCurves(mod, "GeomFill_BezierCurves", "This class provides an algorithm for constructing a Bezier surface filled from contiguous Bezier curves which form its boundaries. The algorithm accepts two, three or four Bezier curves as the boundaries of the target surface. A range of filling styles - more or less rounded, more or less flat - is available. A BezierCurves object provides a framework for: - defining the boundaries, and the filling style of the surface - implementing the construction algorithm - consulting the result. Warning Some problems may show up with rational curves.");

// Constructors
cls_GeomFill_BezierCurves.def(py::init<>());
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("Type"));

// Fields

// Methods
// cls_GeomFill_BezierCurves.def_static("operator new_", (void * (*)(size_t)) &GeomFill_BezierCurves::operator new, "None", py::arg("theSize"));
// cls_GeomFill_BezierCurves.def_static("operator delete_", (void (*)(void *)) &GeomFill_BezierCurves::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_BezierCurves::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_BezierCurves.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_BezierCurves::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_BezierCurves::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_BezierCurves::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "Initializes or reinitializes this algorithm with two, three, or four curves - C1, C2, C3, and C4 - and Type, one of the following filling styles: - GeomFill_Stretch - the style with the flattest patch - GeomFill_Coons - a rounded style of patch with less depth than that of Curved - GeomFill_Curved - the style with the most rounded patch. Exceptions Standard_ConstructionError if the curves are not contiguous.", py::arg("C1"), py::arg("C2"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Surface", (const opencascade::handle<Geom_BezierSurface> & (GeomFill_BezierCurves::*)() const) &GeomFill_BezierCurves::Surface, "Returns the Bezier surface resulting from the computation performed by this algorithm.");

// Enums

}