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
#include <GeomAbs_Shape.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Standard_OStream.hxx>
#include <GeomConvert_ApproxSurface.hxx>

void bind_GeomConvert_ApproxSurface(py::module &mod){

py::class_<GeomConvert_ApproxSurface> cls_GeomConvert_ApproxSurface(mod, "GeomConvert_ApproxSurface", "A framework to convert a surface to a BSpline surface. This is done by approximation to a BSpline surface within a given tolerance.");

// Constructors
cls_GeomConvert_ApproxSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Tol3d"), py::arg("UContinuity"), py::arg("VContinuity"), py::arg("MaxDegU"), py::arg("MaxDegV"), py::arg("MaxSegments"), py::arg("PrecisCode"));
cls_GeomConvert_ApproxSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("Surf"), py::arg("Tol3d"), py::arg("UContinuity"), py::arg("VContinuity"), py::arg("MaxDegU"), py::arg("MaxDegV"), py::arg("MaxSegments"), py::arg("PrecisCode"));

// Fields

// Methods
// cls_GeomConvert_ApproxSurface.def_static("operator new_", (void * (*)(size_t)) &GeomConvert_ApproxSurface::operator new, "None", py::arg("theSize"));
// cls_GeomConvert_ApproxSurface.def_static("operator delete_", (void (*)(void *)) &GeomConvert_ApproxSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomConvert_ApproxSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomConvert_ApproxSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomConvert_ApproxSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomConvert_ApproxSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomConvert_ApproxSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomConvert_ApproxSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomConvert_ApproxSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomConvert_ApproxSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomConvert_ApproxSurface.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomConvert_ApproxSurface::*)() const) &GeomConvert_ApproxSurface::Surface, "Returns the BSpline surface resulting from the approximation algorithm.");
cls_GeomConvert_ApproxSurface.def("IsDone", (Standard_Boolean (GeomConvert_ApproxSurface::*)() const) &GeomConvert_ApproxSurface::IsDone, "Returns Standard_True if the approximation has be done");
cls_GeomConvert_ApproxSurface.def("HasResult", (Standard_Boolean (GeomConvert_ApproxSurface::*)() const) &GeomConvert_ApproxSurface::HasResult, "Returns true if the approximation did come out with a result that is not NECESSARILY within the required tolerance or a result that is not recognized with the wished continuities.");
cls_GeomConvert_ApproxSurface.def("MaxError", (Standard_Real (GeomConvert_ApproxSurface::*)() const) &GeomConvert_ApproxSurface::MaxError, "Returns the greatest distance between a point on the source conic surface and the BSpline surface resulting from the approximation (>0 when an approximation has been done, 0 if no approximation )");
cls_GeomConvert_ApproxSurface.def("Dump", (void (GeomConvert_ApproxSurface::*)(Standard_OStream &) const) &GeomConvert_ApproxSurface::Dump, "Prints on the stream o informations on the current state of the object.", py::arg("o"));

// Enums

}