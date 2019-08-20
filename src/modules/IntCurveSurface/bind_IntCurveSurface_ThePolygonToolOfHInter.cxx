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
#include <Bnd_Box.hxx>
#include <IntCurveSurface_ThePolygonOfHInter.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_ThePolygonToolOfHInter.hxx>

void bind_IntCurveSurface_ThePolygonToolOfHInter(py::module &mod){

py::class_<IntCurveSurface_ThePolygonToolOfHInter, std::unique_ptr<IntCurveSurface_ThePolygonToolOfHInter>> cls_IntCurveSurface_ThePolygonToolOfHInter(mod, "IntCurveSurface_ThePolygonToolOfHInter", "None");

// Constructors

// Fields

// Methods
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonToolOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolygonToolOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolygonToolOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Bounding_", (const Bnd_Box & (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Bounding, "Give the bounding box of the polygon.", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::DeflectionOverEstimation, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Closed_", (Standard_Boolean (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Closed, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("NbSegments_", (Standard_Integer (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::NbSegments, "None", py::arg("thePolygon"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("BeginOfSeg_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolygonOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolygonToolOfHInter::BeginOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("EndOfSeg_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolygonOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolygonToolOfHInter::EndOfSeg, "Give the point of range Index in the Polygon.", py::arg("thePolygon"), py::arg("Index"));
cls_IntCurveSurface_ThePolygonToolOfHInter.def_static("Dump_", (void (*)(const IntCurveSurface_ThePolygonOfHInter &)) &IntCurveSurface_ThePolygonToolOfHInter::Dump, "None", py::arg("thePolygon"));

// Enums

}