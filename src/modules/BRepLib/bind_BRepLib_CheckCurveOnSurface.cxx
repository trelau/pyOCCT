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
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <GeomLib_CheckCurveOnSurface.hxx>
#include <BRepLib_CheckCurveOnSurface.hxx>

void bind_BRepLib_CheckCurveOnSurface(py::module &mod){

py::class_<BRepLib_CheckCurveOnSurface> cls_BRepLib_CheckCurveOnSurface(mod, "BRepLib_CheckCurveOnSurface", "Computes the max distance between edge and its 2d representation on the face.");

// Constructors
cls_BRepLib_CheckCurveOnSurface.def(py::init<>());
cls_BRepLib_CheckCurveOnSurface.def(py::init<const TopoDS_Edge &, const TopoDS_Face &>(), py::arg("theEdge"), py::arg("theFace"));

// Fields

// Methods
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &BRepLib_CheckCurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *)) &BRepLib_CheckCurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_CheckCurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_CheckCurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_CheckCurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_CheckCurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_CheckCurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_CheckCurveOnSurface.def("Init", (void (BRepLib_CheckCurveOnSurface::*)(const TopoDS_Edge &, const TopoDS_Face &)) &BRepLib_CheckCurveOnSurface::Init, "Sets the data for the algorithm", py::arg("theEdge"), py::arg("theFace"));
cls_BRepLib_CheckCurveOnSurface.def("Perform", [](BRepLib_CheckCurveOnSurface &self) -> void { return self.Perform(); });
cls_BRepLib_CheckCurveOnSurface.def("Perform", (void (BRepLib_CheckCurveOnSurface::*)(const Standard_Boolean)) &BRepLib_CheckCurveOnSurface::Perform, "Performs the calculation If isTheMultyTheadDisabled == TRUE then computation will be made without any parallelization.", py::arg("isTheMultyTheradDisabled"));
cls_BRepLib_CheckCurveOnSurface.def("Curve", (const opencascade::handle<Geom_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::Curve, "Returns source 3D-Curve");
cls_BRepLib_CheckCurveOnSurface.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::PCurve, "Returns mine 2D-Curve");
cls_BRepLib_CheckCurveOnSurface.def("PCurve2", (const opencascade::handle<Geom2d_Curve> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::PCurve2, "Returns 2nd 2D-Curve (if it exists, e.g. for seam-edge)");
cls_BRepLib_CheckCurveOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::Surface, "Returns source surface");
cls_BRepLib_CheckCurveOnSurface.def("Range", [](BRepLib_CheckCurveOnSurface &self, Standard_Real & theFirst, Standard_Real & theLast){ self.Range(theFirst, theLast); return std::tuple<Standard_Real &, Standard_Real &>(theFirst, theLast); }, "Returns first and last parameter of the curves (2D- and 3D-curves are considered to have same range)", py::arg("theFirst"), py::arg("theLast"));
cls_BRepLib_CheckCurveOnSurface.def("IsDone", (Standard_Boolean (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::IsDone, "Returns true if the max distance has been found");
cls_BRepLib_CheckCurveOnSurface.def("ErrorStatus", (Standard_Integer (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::ErrorStatus, "Returns error status The possible values are: 0 - OK; 1 - null curve or surface or 2d curve; 2 - invalid parametric range; 3 - error in calculations.");
cls_BRepLib_CheckCurveOnSurface.def("MaxDistance", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::MaxDistance, "Returns max distance");
cls_BRepLib_CheckCurveOnSurface.def("MaxParameter", (Standard_Real (BRepLib_CheckCurveOnSurface::*)() const) &BRepLib_CheckCurveOnSurface::MaxParameter, "Returns parameter in which the distance is maximal");

// Enums

}