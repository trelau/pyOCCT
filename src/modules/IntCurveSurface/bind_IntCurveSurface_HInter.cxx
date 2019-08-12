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
#include <IntCurveSurface_Intersection.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntCurveSurface_ThePolygonOfHInter.hxx>
#include <IntCurveSurface_ThePolyhedronOfHInter.hxx>
#include <Bnd_BoundSortBox.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntCurveSurface_HInter.hxx>

void bind_IntCurveSurface_HInter(py::module &mod){

py::class_<IntCurveSurface_HInter, std::unique_ptr<IntCurveSurface_HInter, Deleter<IntCurveSurface_HInter>>, IntCurveSurface_Intersection> cls_IntCurveSurface_HInter(mod, "IntCurveSurface_HInter", "None");

// Constructors
cls_IntCurveSurface_HInter.def(py::init<>());

// Fields

// Methods
// cls_IntCurveSurface_HInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_HInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_HInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_HInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_HInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_HInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_HInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_HInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_HInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_HInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface", py::arg("Curve"), py::arg("Surface"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given.", py::arg("Curve"), py::arg("Polygon"), py::arg("Surface"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const IntCurveSurface_ThePolygonOfHInter &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &, Bnd_BoundSortBox &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Curve is already sampled and its polygon : <Polygon> is given. The Surface is also sampled and <Polyhedron> is given.", py::arg("Curve"), py::arg("ThePolygon"), py::arg("Surface"), py::arg("Polyhedron"), py::arg("BndBSB"));
cls_IntCurveSurface_HInter.def("Perform", (void (IntCurveSurface_HInter::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_HInter::Perform, "Compute the Intersection between the curve and the surface. The Surface is already sampled and its polyhedron : <Polyhedron> is given.", py::arg("Curve"), py::arg("Surface"), py::arg("Polyhedron"));

// Enums

}